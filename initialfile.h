#ifndef INITIALFILE_H
#define INITIALFILE_H

#include <QString>
#include <vector>



class InitialFile
{
public:
    std::vector<QString> Values;
    std::vector<QString> TitlesOfModules;

    void ReadInitFile();

    InitialFile(QString Name);
    InitialFile();
private:
    void RetrieveTitles(QString str);
    void RetrieveValues(QString str);
    QString InitialFileName;

};

#endif // INITIALFILE_H
