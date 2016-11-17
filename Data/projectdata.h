#ifndef PROJECTDATA_H
#define PROJECTDATA_H
#include <QString>
#include <QList>
#include "Data/patientdata.h"
#include "clusterdata.h"

class ProjectData
{
public:
    ProjectData();

    QString getClinicalDataPath();
    QString getClinicalPatientFilePath();

    void setClinicalDataPath(QString data);
    void setClinicalPatientFilePath(QString data);

    QString getProjectPath();
    void setProjectPath(QString data);

    QList <PatientData> getListPatients();
    void setListPatients(QList <PatientData>  list);

    ClusterData getClusterData();
    void  setClusterData(ClusterData data);


    void clear();

private:

    QString _projectPath;
    QString _clinicalDataPath;
    QString _clinicalPatientFilePath;
    QList <PatientData> _listPatients;

    ClusterData _clusterData;


};

#endif // PROJECTDATA_H
