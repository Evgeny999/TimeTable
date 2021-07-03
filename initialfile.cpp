#include "initialfile.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>


InitialFile::InitialFile(QString Name)
{
    InitialFileName=Name;
}

InitialFile::InitialFile()
{

}
void InitialFile::ReadInitFile()
{

    int internalCount=0;
    int internalCount2=0;

    int flag_comment=0;





    QFile inputFile(InitialFileName);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if(line.contains("/*"))
          {
              flag_comment=1;

          }



         if((line.contains("(uint*)")||line.contains("(uint32_t*)"))&&line.contains("{")&&line.contains("}")&&(!flag_comment))
         {

            RetrieveTitles(line);
            RetrieveValues(line);





         }

         if(line.contains("*/"))
         {
             flag_comment=0;

         }




       }

       internalCount=0;
       internalCount2=0;

       while(internalCount!=Values.size())
       {

           internalCount++;
       }


       while(internalCount2!=TitlesOfModules.size())
       {

           internalCount2++;
       }


       inputFile.close();
    }
}
void InitialFile::RetrieveTitles(QString line)
{
    int internalCount2=0;
    QString tempStrTitles;

    internalCount2=line.indexOf('*');

    internalCount2++;

    while(line[internalCount2]==')'|| line[internalCount2]==' ')
    {
        internalCount2++;

    }

    while(line[internalCount2]!=',')
    {

        tempStrTitles.append(line[internalCount2]);

        internalCount2++;
    }

    TitlesOfModules.push_back(tempStrTitles);
    tempStrTitles.clear();



}
void InitialFile::RetrieveValues(QString line)
{
    int internalCount=0;
    QString tempStr;

    internalCount=line.indexOf('{');
    internalCount++;
    while(line[internalCount]!=',')
    {

        tempStr.append(line[internalCount]);

        internalCount++;
    }

    Values.push_back(tempStr);
    tempStr.clear();

}


