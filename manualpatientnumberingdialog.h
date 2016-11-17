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

class ManualPatientNumberingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManualPatientNumberingDialog(QWidget *parent = 0);
    ~ManualPatientNumberingDialog();

    void setPatientList(QList<PatientData> list);
    QList<PatientData> getPatientList();

    bool hasUserAcceptedChanges();


private slots:
    void on_previousButton_clicked();

    void on_nextButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ManualPatientNumberingDialog *ui;
    QList<PatientData> _patientList;
    QStringList _dyastoleValues;
    QStringList _syastoleValues;

    bool _userAcceptChanges;

    int _MIN_IMAGES;
    int _MAX_IMAGES;
    int _CURRENT_PATIENT_INDEX;


    void loadPatientInfo(int _noPatient);
    void showPatientImage(int _noPatient);
    void updatePatientNumberingLabels(int pos);
    void updateCurrentPatientNumber(int _pos);
    void updatePatientData(int pos);
    void savePatientInfo(int pos);

    void initializeValues();
    void updatePatientListValues();
};

#endif // MANUALPATIENTNUMBERINGDIALOG_H
