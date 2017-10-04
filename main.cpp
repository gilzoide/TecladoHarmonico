#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <hexagon.h>
#include <qfluidsynth.h>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Hexagon>("com.gilzoide.hexagon", 0, 1, "Hexagon");
    qmlRegisterType<Fluidsynth>("com.gilzoide.fluidsynth", 0, 1, "Fluidsynth");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
