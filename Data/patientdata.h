#ifndef PATIENTDATA_H
#define PATIENTDATA_H

#include <QString>
/**
 * @brief This class is intended to store all the patient information within a project
 *
 */
class PatientData
{
public:
    /**
     * @brief Creation of the object
     *
     */
    PatientData();

    /**
     * @brief Get Patient Name
     *
     * @return QString
     */
    QString getPatientName();
    /**
     * @brief Get the path of the image file used to check dyastole/asystole
     *
     * @return QString
     */
    QString getFileImagePath();
    /**
     * @brief Get the root folder of the patients data folder
     *
     * @return QString
     */
    QString getFolderPatientPath();
    /**
     * @brief Get syastole value of the Patient
     *
     * @return int
     */
    int getSyastole();
    /**
     * @brief Get Dyastole value of the Patient
     *
     * @return int
     */
    int getDyastole();

    /**
     * @brief Set Patient Name
     *
     * @param data
     */
    void setPatientName(QString data);
    /**
     * @brief Set the path of the image file used to check dyastole/asystole
     *
     * @param data
     */
    void setFileImagePath(QString data);
    /**
     * @brief Set the root folder of the patients data folder
     *
     * @param data
     */
    void setFolderPatientPath(QString data);
    /**
     * @brief Set syastole value of the Patient
     *
     * @param val
     */
    void setSyastole(int val);
    /**
     * @brief Set Dyastole value of the Patient
     *
     * @param val
     */
    void setDyastole(int val);

    /**
     * @brief clears the information stored in the object
     *
     */
    void clear();

private:

    QString _patientName; /**< TODO */
    QString _fileImagePath; /**< TODO */
    QString _folderPatientPath; /**< TODO */
    int _syastole; /**< TODO */
    int _dyastole; /**< TODO */
};

#endif // PATIENTDATA_H
