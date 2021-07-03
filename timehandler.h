#ifndef TIMEHANDLER_H
#define TIMEHANDLER_H

#include <QApplication>

class TimeHandler
{
    public:
        TimeHandler(QString File);
        TimeHandler();
        void HandlerExec();
        unsigned int flag;//Success-fail flag
    private:
        QString FileName;


};


#endif // TIMEHANDLER_H
