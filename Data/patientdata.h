#ifndef PATIENTDATA_H
#define PATIENTDATA_H

#include <QString>
class PatientData
{
public:
    PatientData();

    QString getPatientName();
    QString getFileImagePath();
    QString getFolderPatientPath();
    int getSyastole();
    int getDyastole();

    void setPatientName(QString data);
    void setFileImagePath(QString data);
    void setFolderPatientPath(QString data);
    void setSyastole(int val);
    void setDyastole(int val);

    void clear();

private:

    QString _patientName;
    QString _fileImagePath;
    QString _folderPatientPath;
    int _syastole;
    int _dyastole;
};

#endif // PATIENTDATA_H
