#ifndef PROJECTDATA_H
#define PROJECTDATA_H
#include <QString>
#include <QList>
#include "Data/patientdata.h"
#include "clusterdata.h"

/**
 * @brief This class is intended to store all the information related with a specific project
 *
 */
class ProjectData
{
public:
    /**
     * @brief Creation of the object
     *
     */
    ProjectData();

    /**
     * @brief  Get the path where the Clinical Data patients are
     *
     * @return QString
     */
    QString getClinicalDataPath();
    /**
     * @brief Get the path where the clinical file of the patients (listClicinal.txt) is going to be stored
     *
     * @return QString
     */
    QString getClinicalPatientFilePath();

    /**
     * @brief Set the path where the Clinical Data patients are
     *
     * @param data
     */
    void setClinicalDataPath(QString data);
    /**
     * @brief Set the path where the clinical file of the patients (listClicinal.txt) is going to be stored
     *
     * @param data
     */
    void setClinicalPatientFilePath(QString data);

    /**
     * @brief Get the project path
     *
     * @return QString
     */
    QString getProjectPath();
    /**
     * @brief Set the project path
     *
     * @param data
     */
    void setProjectPath(QString data);

    /**
     * @brief Get the list of patient objects
     *
     * @return QList<PatientData>
     */
    QList <PatientData> getListPatients();
    /**
     * @brief Set the list of patient objects
     *
     * @param list
     */
    void setListPatients(QList <PatientData>  list);

    /**
     * @brief Get the cluster information
     *
     * @return ClusterData
     */
    ClusterData getClusterData();
    /**
     * @brief Set the cluster information
     *
     * @param data
     */
    void  setClusterData(ClusterData data);


    /**
     * @brief clears the information stored in the object
     *
     */
    void clear();

private:

    QString _projectPath; /**< TODO */
    QString _clinicalDataPath; /**< TODO */
    QString _clinicalPatientFilePath; /**< TODO */
    QList <PatientData> _listPatients; /**< TODO */

    ClusterData _clusterData; /**< TODO */


};

#endif // PROJECTDATA_H
