#ifndef QJACK_H
#define QJACK_H

#include <QObject>
#include <jack/jack.h>
#include <jack/midiport.h>

#define MIDI_EVENT_SIZE 3

class QJack : public QObject {
    Q_OBJECT

public:
    explicit QJack(QObject *parent = nullptr);
    virtual ~QJack();

    Q_INVOKABLE void noteOn(quint8 note, quint8 velocity = 127);
    Q_INVOKABLE void noteOff(quint8 note);

    // Jack stuff
    jack_port_t *midiout;
    jack_client_t *client;
    jack_midi_data_t event_buffer[MIDI_EVENT_SIZE] = {0};

signals:
    void connectionError(QString error);

public slots:
};

#endif // QJACK_H
