#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QGuiApplication>
#include "StudentModel.h"
#include "tool.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc,argv);


    QQmlApplicationEngine engine;

    StudentModel model;
    engine.rootContext()->setContextProperty("$Model",&model); //注入模型
//    qmlRegisterType<StudentModel>("Com.Lc.Classes", 1, 0, "StudentModel");
    qmlRegisterType<Tool>("Com.Lc.Classes", 1, 0, "Tool");  //注入c++类  (注意的是这个类需要继承自QObject)

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
