#ifndef LOGGER_H
#define LOGGER_H

#include "appsettings_global.h"
#include <QObject>
#include <QFile>

class APPSETTINGSSHARED_EXPORT Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);
    ~Logger();

    void    log     (const QString *str);

    static  Logger* instance();
    static  void    i_log   (const QString *str);

signals:
    void errorWithLogfile();

public slots:

private:
    QFile *logfile {nullptr};
};

#endif // LOGGER_H
