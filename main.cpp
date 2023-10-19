#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Controller/SettingController.h"


int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);
    SettingController *controller = new SettingController();
    controller->initSettingController();

    return app.exec();
}
