#include <QGuiApplication>
#include <QtAppManCommon/logging.h>
#include <QtAppManLauncher/launchermain.h>
#include <QtAppManLauncher/dbusapplicationinterface.h>
#include <QtAppManLauncher/dbusnotification.h>
#include "Controller/SettingEngine.h"

int main(int argc, char** argv){
    QtAM::Logging::initialize(argc, argv);
    QtAM::Logging::setApplicationId("Setting");
    qDebug()<<__LINE__;
    QtAM::LauncherMain::initialize();
    QGuiApplication app(argc,argv);
    QtAM::LauncherMain launcher;

    launcher.registerWaylandExtensions();
    launcher.loadConfiguration();
    launcher.setupLogging(false, launcher.loggingRules(), QString(), launcher.useAMConsoleLogger());
    launcher.setupDBusConnections();

    SettingEngine *engine = new SettingEngine();
    engine->initialized();
    QtAM::DBusApplicationInterface iface(launcher.p2pDBusName(), launcher.notificationDBusName());
    iface.initialize();
    QObject::connect(&iface, &QtAM::DBusApplicationInterface::quit, [&iface] () {
        iface.acknowledgeQuit();
    });
    return app.exec();
};
