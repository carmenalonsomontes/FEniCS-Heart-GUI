#ifndef LISTCLINICALWRITER_H
#define LISTCLINICALWRITER_H
#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>
#include "Data/projectdata.h"
#include "Data/patientdata.h"
#include <QTextStream>

class ListClinicalWriter
{
public:
    ListClinicalWriter();
    bool saveProjectData(ProjectData * _projectData, QString _path);
private:
    bool createListClinicalFile(QFile * _file,ProjectData * _projectData);

};

#endif // LISTCLINICALWRITER_H
