
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "rwfile.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<RWFile>("shj.qt",1,0,"RWFile");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
