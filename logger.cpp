#include "logger.h"




//===========================================
Logger::Logger(QObject *parent) : QObject(parent)
{
    logfile = new QFile("logfile.log");
    if (!logfile->open(QIODevice::WriteOnly)) {
        emit errorWithLogfile();
        delete logfile;
    }
}




//===========================================
Logger::~Logger()
{
    if (logfile) {
        if (logfile->isOpen()) {
            logfile->close();
        }
        delete logfile;
    }
}




//===========================================
void Logger::log(const QString *str)
{
    if (logfile) {
        logfile->write((char*)(str), sizeof(*str));
    }
}




//===========================================
Logger* Logger::instance()
{
    static Logger *logger = new Logger();
    return logger;
}




//===========================================
void Logger::i_log(const QString *str)
{
    Logger::instance()->log(str);
}




//===========================================
