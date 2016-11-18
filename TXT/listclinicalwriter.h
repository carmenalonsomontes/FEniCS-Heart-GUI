#ifndef LISTCLINICALWRITER_H
#define LISTCLINICALWRITER_H
#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>
#include "Data/projectdata.h"
#include "Data/patientdata.h"
#include <QTextStream>

/**
 * @brief This class is intended to create and save the listClinical.txt file with the data
 * of all the patients
 *
 */
class ListClinicalWriter
{
public:
    /**
     * @brief Creation of the object
     *
     */
    ListClinicalWriter();
    /**
     * @brief This function save the data to the file listClinical.txt
     *
     * @param _projectData
     * @param _path
     * @return bool
     */
    bool saveProjectData(ProjectData * _projectData, QString _path);
private:
    /**
     * @brief This function writes the information into the file
     *
     * @param _file
     * @param _projectData
     * @return bool
     */
    bool createListClinicalFile(QFile * _file,ProjectData * _projectData);

};

#endif // LISTCLINICALWRITER_H
