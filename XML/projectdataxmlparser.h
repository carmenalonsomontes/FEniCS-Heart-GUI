#ifndef PROJECTDATAXMLPARSER_H
#define PROJECTDATAXMLPARSER_H

#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

#include "Data/projectdata.h"
#include "Data/patientdata.h"
#include "Data/clusterdata.h"

class ProjectDataXMLParser
{
public:
    ProjectDataXMLParser();
    bool saveProjectData(ProjectData * _projectData, QString _path);
    void readProjectData(ProjectData * _projectData, QString _path);

  //  bool savePatientsData(QStringList<PatientData> _patientList, QString _path);
  //  void readPatientsData(QStringList<PatientData> _patientList, QString _path);


private:
    bool createNewProjectFile(QFile * _file,ProjectData * _projectData);

    void writeSimulationConfiguration(QXmlStreamWriter * xmlWriter, ProjectData * _projectData);
    void writePatientsData(QXmlStreamWriter * xmlWriter, ProjectData * _projectData);
    void writeClusterData(QXmlStreamWriter * xmlWriter, ProjectData * _projectData);
    void readClusterData(QXmlStreamReader * xmlReader, ProjectData * _projectData);

    void readSimulationConfiguration( QXmlStreamReader * xmlReader,ProjectData * _projectData);
    void readPatientsData(QXmlStreamReader * xmlReader, ProjectData * _projectData);


};

#endif // PROJECTDATAXMLPARSER_H
