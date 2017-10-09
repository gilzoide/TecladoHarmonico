#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <hexagon.h>
#include <qjack.h>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Hexagon>("com.gilzoide.hexagon", 0, 1, "Hexagon");
    qmlRegisterType<QJack>("com.gilzoide.jack", 0, 1, "Jack");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
