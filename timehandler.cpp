#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timehandler.h"
#include "initialfile.h"

#include <QFileDialog>
#include <QDebug>
#include <QTextStream>

TimeHandler::TimeHandler(QString File)
{
    FileName=File;
}

TimeHandler::TimeHandler()
{


}
void TimeHandler::HandlerExec()
{
    int countRows=0;
    InitialFile InFile(FileName);

    InFile.ReadInitFile();

    //FileName.remove(0, FileName.lastIndexOf("\\")+1).remove(".c");
    FileName.remove(".c");
    //qDebug()<<FileName;


    QFile *outputFile = new QFile(FileName+"_out.csv");

    if (outputFile->open(QIODevice::WriteOnly))
    {

        QTextStream stream(outputFile);

        while(countRows!=InFile.Values.size())
        {

            //stream << "something" << endl;
            stream << QString::number(countRows+1)+QString(";")+QString(InFile.Values[countRows])+QString(";")+InFile.TitlesOfModules[countRows]+QString(";") << endl;

            countRows++;
        }

        outputFile->close();
        delete outputFile;

    }



}








