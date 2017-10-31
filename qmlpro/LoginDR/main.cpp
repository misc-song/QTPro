#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "dbaccess.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<DBAccess>("shj.qt",1,0,"DBAccess");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
