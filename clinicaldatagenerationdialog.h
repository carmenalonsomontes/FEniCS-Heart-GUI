#ifndef CLINICALDATAGENERATIONDIALOG_H
#define CLINICALDATAGENERATIONDIALOG_H

#include <QDialog>
#include <QList>

#include <QTableWidgetItem>


#include "Data/projectdata.h"
#include "Data/patientdata.h"

namespace Ui {
class ClinicalDataGenerationDialog;
}

/**
 * @brief This class is intended to define the logic for the Clinical Data Generation dialog
 *
 */
class ClinicalDataGenerationDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Creation of the object
     *
     * @param parent
     */
    explicit ClinicalDataGenerationDialog(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~ClinicalDataGenerationDialog();

    /**
     * @brief Set project information
     *
     * @param data
     */
    void setProjectData(ProjectData data);
    /**
     * @brief Gets project information
     *
     * @return ProjectData
     */
    ProjectData getProjectData();
    /**
     * @brief Returns true if the user accepts the changes made
     *
     * @return bool
     */
    bool hasUserAcceptChanges();
    /**
     * @brief Set patient list
     *
     * @param _list
     */
    void loadPatientList(QList<PatientData> _list);


private slots:
    /**
     * @brief Logic to select the path where are the data of the patients
     *
     */
    void on_dataPatientToolButton_clicked();

    /**
     * @brief Logic to define the rules of syastole/dyastole for each patient in the current study
     *
     */
    void on_defPatientCheckListButton_clicked();

    /**
     * @brief Logic to generate the listClinical.txt file
     *
     */
    void on_generateCheckListButton_clicked();

    /**
     * @brief Logic for OK
     *
     */
    void on_buttonBox_accepted();

    /**
     * @brief Logic for Cancel
     *
     */
    void on_buttonBox_rejected();

    /**
     * @brief Logic to define the rules of inclusion/exclusion of patients in the current study
     *
     */
    void on_loadPatientsButton_clicked();

    /**
     * @brief Logic to add manually a patient to the study
     *
     */
    void on_addManualPatientButton_clicked();

    /**
     * @brief Logic to remove patients
     *
     */
    void on_removePatientButton_clicked();

private:
    Ui::ClinicalDataGenerationDialog *ui; /**< TODO */

    /**
     * @brief
     *
     */
    enum  PatientColumn{
        PATIENT_NUM = 0,
        PATIENT_NAME = 1,
        PATIENT_SYASTOLE = 2,
        PATIENT_DYASTOLE = 3,
        PATIENT_FILE_IM_PATH = 4,
        PATIENT_FILE_FOLDER_PATH = 5
    };

    /**
     * @brief
     *
     */
    enum RulesValues{
        PREFFIX_RULES =0,
        SUFFIX_RULES = 1
    };

    ProjectData _projectData; /**< TODO */
   // QList<PatientData> _patients;
    bool _userAcceptChanges; /**< TODO */


    /**
     * @brief This functions add a patient in the table
     *
     * @param _patient
     */
    void addPatient(PatientData _patient);

    /**
     * @brief This functions add a non editable item in the table
     *
     * @param _value
     * @return QTableWidgetItem
     */
    QTableWidgetItem * addNonEditableText(QString _value);

    /**
     * @brief This functions clears teh table
     *
     */
    void emptyTable();
    /**
     * @brief This function generates the listClinical.txt file
     *
     */
    void createPatientFile();

    /**
     * @brief This function filters teh patients folders according to the different rules
     *
     */
    void foundPatientInformation();
    /**
     * @brief
     *
     * @param _inclusionPrefixRules
     * @param _iclusionSuffixRules
     * @param _exclusionPrefixRules
     * @param _exclusionSuffixRules
     * @return QList<PatientData>
     */
    QList<PatientData> getPatientIds(QStringList _inclusionPrefixRules, QStringList _iclusionSuffixRules,
                                                     QStringList _exclusionPrefixRules, QStringList _exclusionSuffixRules);
    /**
     * @brief This function filters teh patients image files according to the different rules
     *
     * @param _list
     * @param _inclusionPrefixRules
     * @param _iclusionSuffixRules
     * @param _exclusionPrefixRules
     * @param _exclusionSuffixRules
     * @return QList<PatientData>
     */
    QList<PatientData> completePatientData(QList<PatientData> _list, QStringList _inclusionPrefixRules, QStringList _iclusionSuffixRules,
                                                     QStringList _exclusionPrefixRules, QStringList _exclusionSuffixRules);




    /**
     * @brief This function filters the patients
     *
     * @param list
     * @param inclusion
     * @param exclusion
     * @param _type
     * @return QStringList
     */
    QStringList filterPatientList(QStringList list, QStringList inclusion, QStringList exclusion,
                                                                 RulesValues _type);
    /**
     * @brief This function filters the included values according to the values and teh type of the rule
     *
     * @param _list
     * @param _valueTocheck
     * @param _type
     * @return QStringList
     */
    QStringList filterIncludedValues(QStringList _list,QString _valueTocheck, RulesValues _type );
    /**
     * @brief This function filters the excluded values according to the values and teh type of the rule
     *
     * @param _list
     * @param _valueTocheck
     * @param _type
     * @return QStringList
     */
    QStringList filterExcludedValues(QStringList _list,QString _valueTocheck, RulesValues _type );

    //void addRow(PatientData _patient);
    /**
     * @brief This fucntions add an Editable text item to the table
     *
     * @param _value
     * @return QTableWidgetItem
     */
    QTableWidgetItem * addEditableText(QString _value);
    /**
     * @brief This function fills the table with the patient information
     *
     * @param _list
     */
    void fillPatientTable(QList<PatientData> _list);

    /**
     * @brief This function updates the information of the patients
     *
     */
    void updatePatientData();



};

#endif // CLINICALDATAGENERATIONDIALOG_H
