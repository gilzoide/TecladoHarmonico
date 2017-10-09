#include "qjack.h"
#include <iostream>

using namespace std;

/// Jack callback
int process(jack_nframes_t nframes, void *arg) {
    QJack *qjack = (QJack *) arg;
    void *port_buffer = jack_port_get_buffer(qjack->midiout, nframes);
    jack_midi_clear_buffer(port_buffer);
    if(qjack->event_buffer[0]) {
        jack_midi_event_write(port_buffer, 0, qjack->event_buffer, MIDI_EVENT_SIZE);
        qjack->event_buffer[0] = 0;
    }
    return 0;
}

QJack::QJack(QObject *parent) : QObject(parent) {
    jack_options_t options = JackNullOption;
    jack_status_t status;
    client = jack_client_open("TecladoHarmonico", options, &status, NULL);
    if(client == NULL) {
        emit connectionError(QString("jack_client_open failed, error code = %1").arg(status));
    }
    else {
        if (status & JackServerStarted) {
            cerr << "JACK server started\n";
        }
        if (status & JackNameNotUnique) {
            cerr << "unique name `" << jack_get_client_name(client) << "' assigned\n";
        }
        jack_set_process_callback(client, &process, this);
        midiout = jack_port_register(client, "midiout", JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0);
        jack_activate(client);
    }
}

QJack::~QJack() {
    jack_client_close(client);
}

void QJack::noteOn(quint8 note, quint8 velocity) {
    event_buffer[1] = note;
    event_buffer[2] = velocity;
    event_buffer[0] = 0x90;
    cout << "note-on " << (int)note << endl;
}

void QJack::noteOff(quint8 note) {
    event_buffer[1] = note;
    event_buffer[0] = 0x80;
    cout << "note-off " << (int)note << endl;
}
