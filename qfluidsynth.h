/**
 * QML wrapper for a Fluidsynth
 */

#ifndef QFLUIDSYNTH_H
#define QFLUIDSYNTH_H

#include <fluidsynth.h>
#include <QObject>

class Fluidsynth : public QObject
{
    Q_OBJECT

public:
    explicit Fluidsynth(QObject *parent = nullptr);
    virtual ~Fluidsynth();

    Q_INVOKABLE void setOptions(const QVariantMap& opts);

signals:

private:
    fluid_settings_t *settings {nullptr};
    fluid_synth_t *synth {nullptr};
};

#endif // QFLUIDSYNTH_H
