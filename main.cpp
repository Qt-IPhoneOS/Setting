#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Controller/SettingEngine.h"


int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);
    SettingEngine *engine = new SettingEngine();
    engine->init();

    return app.exec();
}
