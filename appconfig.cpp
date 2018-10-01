#include "appconfig.h"

#include <QProcessEnvironment>

AppConfig* AppConfig::instance = 0;

AppConfig::AppConfig(QObject *parent): QObject(parent)
{}

AppConfig::~AppConfig() {
    if(instance) {
        delete instance;
        instance = NULL;
    }
}

AppConfig* AppConfig::Instance() {
    if(!instance) {
        instance = new AppConfig();
    }
    return instance;
}

/**
 * @brief AppConfig::GetNasaKey reads NASA_KEY from environment variables of the system
 * @return NASA API key in QString object
 */
QString AppConfig::GetNASAKey() {
    return QProcessEnvironment::systemEnvironment().value("NASA_KEY", "KEY-NOT-FOUND");
}
