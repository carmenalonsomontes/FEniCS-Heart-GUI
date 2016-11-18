#ifndef MANUALPATIENTNUMBERINGDIALOG_H
#define MANUALPATIENTNUMBERINGDIALOG_H

#include <QDialog>

#include <QList>
#include <QString>
#include <QStringList>

#include "Data/patientdata.h"

namespace Ui {
class ManualPatientNumberingDialog;
}

/**
 * @brief This class is intended to define the logic for the Manual Patient Numbering (Syastole/Dyastole) dialog
 *
 */
class ManualPatientNumberingDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Creation of the object
     *
     * @param parent
     */
    explicit ManualPatientNumberingDialog(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~ManualPatientNumberingDialog();

    /**
     * @brief Sets the current patient list information
     *
     * @param list
     */
    void setPatientList(QList<PatientData> list);
    /**
     * @brief Gets the current patient list information
     *
     * @return QList<PatientData>
     */
    QList<PatientData> getPatientList();

    /**
     * @brief Returns true if the user has accepted the changes made in this dialog
     *
     * @return bool
     */
    bool hasUserAcceptedChanges();


private slots:
    /**
     * @brief Previous button click
     *
     */
    void on_previousButton_clicked();

    /**
     * @brief Next button click
     *
     */
    void on_nextButton_clicked();

    /**
     * @brief Accept button click
     *
     */
    void on_buttonBox_accepted();

    /**
     * @brief Cancel button click
     *
     */
    void on_buttonBox_rejected();

private:
    Ui::ManualPatientNumberingDialog *ui; /**< TODO */
    QList<PatientData> _patientList; /**< TODO */
    QStringList _dyastoleValues; /**< TODO */
    QStringList _syastoleValues; /**< TODO */

    bool _userAcceptChanges; /**< TODO */

    int _MIN_IMAGES; /**< TODO */
    int _MAX_IMAGES; /**< TODO */
    int _CURRENT_PATIENT_INDEX; /**< TODO */


    /**
     * @brief load the information for the patient with that number
     *
     * @param _noPatient
     */
    void loadPatientInfo(int _noPatient);
    /**
     * @brief Show the patient image associated to the patient number
     *
     * @param _noPatient
     */
    void showPatientImage(int _noPatient);
    /**
     * @brief Update the numbering labesl in teh window according with the navigation
     *
     * @param pos
     */
    void updatePatientNumberingLabels(int pos);
    /**
     * @brief Update the current patient number in the dialgo
     *
     * @param _pos
     */
    void updateCurrentPatientNumber(int _pos);
    /**
     * @brief Update the patient information in the dialog
     *
     * @param pos
     */
    void updatePatientData(int pos);
    /**
     * @brief Save the patient information
     *
     * @param pos
     */
    void savePatientInfo(int pos);

    /**
     * @brief Initialize values of the dialot
     *
     */
    void initializeValues();
    /**
     * @brief update the values of the patients list
     *
     */
    void updatePatientListValues();
};

#endif // MANUALPATIENTNUMBERINGDIALOG_H
