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

/**
 * @brief This class is intended to provide the functionality to read/save the information related
 * for a specific project
 *
 */
class ProjectDataXMLParser
{
public:
    /**
     * @brief Creation of the object
     *
     */
    ProjectDataXMLParser();
    /**
     * @brief This function saves the information of the project in a specific file
     *
     * @param _projectData
     * @param _path
     * @return bool
     */
    bool saveProjectData(ProjectData * _projectData, QString _path);
    /**
     * @brief This function saves the information of the project in a specific file
     *
     * @param _projectData
     * @param _path
     */
    void readProjectData(ProjectData * _projectData, QString _path);

  //  bool savePatientsData(QStringList<PatientData> _patientList, QString _path);
  //  void readPatientsData(QStringList<PatientData> _patientList, QString _path);


private:
    /**
     * @brief This function creates a new file to save the information of the project
     *
     * @param _file
     * @param _projectData
     * @return bool
     */
    bool createNewProjectFile(QFile * _file,ProjectData * _projectData);

    /**
     * @brief This function writes the information of the simulation configuration
     *
     * @param xmlWriter
     * @param _projectData
     */
    void writeSimulationConfiguration(QXmlStreamWriter * xmlWriter, ProjectData * _projectData);
    /**
     * @brief This function writes the information of the patients
     *
     * @param xmlWriter
     * @param _projectData
     */
    void writePatientsData(QXmlStreamWriter * xmlWriter, ProjectData * _projectData);
    /**
     * @brief This function writes the information of the cluster
     *
     * @param xmlWriter
     * @param _projectData
     */
    void writeClusterData(QXmlStreamWriter * xmlWriter, ProjectData * _projectData);
    /**
     * @brief This function reads the information of the cluster
     *
     * @param xmlReader
     * @param _projectData
     */
    void readClusterData(QXmlStreamReader * xmlReader, ProjectData * _projectData);

    /**
     * @brief  This function reads the information of the simulation configuration
     *
     * @param xmlReader
     * @param _projectData
     */
    void readSimulationConfiguration( QXmlStreamReader * xmlReader,ProjectData * _projectData);
    /**
     * @brief This function writes the information of the patients
     *
     * @param xmlReader
     * @param _projectData
     */
    void readPatientsData(QXmlStreamReader * xmlReader, ProjectData * _projectData);


};

#endif // PROJECTDATAXMLPARSER_H
