#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "fileio.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    //  使用qmlRegisterType模板注册qml可用的C++类型
    //  模板的原型为:
    //  template<typename T>
    //  int qmlRegisterType(const char *uri, int versionMajor, int versionMinor, const char *qmlName);
    // 其中uri为资源的标志符 versionMajor主要版本 versionMinor 次要版本 qmlName qml名称
    // qmlRegisterType<MySliderItem>("com.mycompany.qmlcomponents", 1, 0, "Slider");
    qmlRegisterType<FileIO, 1>("FileIO", 1, 0, "FileIO");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
