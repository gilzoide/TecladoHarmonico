#include "qfluidsynth.h"

#include <QMap>
#include <QVariant>

Fluidsynth::Fluidsynth(QObject *parent) : QObject(parent) {
    settings = new_fluid_settings();
    synth = new_fluid_synth(settings);
}

Fluidsynth::~Fluidsynth() {
    delete_fluid_synth(synth);
    delete_fluid_settings(settings);
}

void Fluidsynth::setOptions(const QVariantMap& opts) {
    bool isInt;
    int intValue;
    QVariantMap::const_iterator it = opts.cbegin();
    while(it != opts.cend()) {
        intValue = it.value().toInt(&isInt);
        if(isInt) {
            fluid_settings_setint(settings, it.key().toUtf8().constData(), intValue);
        }
        else {
            fluid_settings_setstr(settings, it.key().toUtf8().constData(), it.value().toString().toUtf8().constData());
        }
        it++;
    }
}
