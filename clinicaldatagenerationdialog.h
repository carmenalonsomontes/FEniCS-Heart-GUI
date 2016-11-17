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

class ClinicalDataGenerationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClinicalDataGenerationDialog(QWidget *parent = 0);
    ~ClinicalDataGenerationDialog();

    void setProjectData(ProjectData data);
    ProjectData getProjectData();
    bool hasUserAcceptChanges();
    void loadPatientList(QList<PatientData> _list);


private slots:
    void on_dataPatientToolButton_clicked();

    void on_defPatientCheckListButton_clicked();

    void on_generateCheckListButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_loadPatientsButton_clicked();

    void on_addManualPatientButton_clicked();

    void on_removePatientButton_clicked();

private:
    Ui::ClinicalDataGenerationDialog *ui;

    enum  PatientColumn{
        PATIENT_NUM = 0,
        PATIENT_NAME = 1,
        PATIENT_SYASTOLE = 2,
        PATIENT_DYASTOLE = 3,
        PATIENT_FILE_IM_PATH = 4,
        PATIENT_FILE_FOLDER_PATH = 5
    };

    enum RulesValues{
        PREFFIX_RULES =0,
        SUFFIX_RULES = 1
    };

    ProjectData _projectData;
   // QList<PatientData> _patients;
    bool _userAcceptChanges;


    void addPatient(PatientData _patient);

    QTableWidgetItem * addNonEditableText(QString _value);

    void emptyTable();
    void createPatientFile();

    void foundPatientInformation();
    QList<PatientData> getPatientIds(QStringList _inclusionPrefixRules, QStringList _iclusionSuffixRules,
                                                     QStringList _exclusionPrefixRules, QStringList _exclusionSuffixRules);
    QList<PatientData> completePatientData(QList<PatientData> _list, QStringList _inclusionPrefixRules, QStringList _iclusionSuffixRules,
                                                     QStringList _exclusionPrefixRules, QStringList _exclusionSuffixRules);




    QStringList filterPatientList(QStringList list, QStringList inclusion, QStringList exclusion,
                                                                 RulesValues _type);
    QStringList filterIncludedValues(QStringList _list,QString _valueTocheck, RulesValues _type );
    QStringList filterExcludedValues(QStringList _list,QString _valueTocheck, RulesValues _type );

    //void addRow(PatientData _patient);
    QTableWidgetItem * addEditableText(QString _value);
    void fillPatientTable(QList<PatientData> _list);

    void updatePatientData();



};

#endif // CLINICALDATAGENERATIONDIALOG_H
