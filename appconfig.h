#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QObject>

/**
 * @brief The AppConfig class is a C++ singleton class which manages/reads/writes config parameters for the application.
 */
class AppConfig : public QObject
{
    Q_OBJECT

public:
    ~AppConfig();
    static AppConfig* Instance();
    QString GetNASAKey();

private:
    AppConfig(QObject* parent = 0);
    static AppConfig* instance;

};

#endif // APPCONFIG_H
