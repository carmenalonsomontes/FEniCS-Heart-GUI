#ifndef REMOVEPATIENTSDIALOG_H
#define REMOVEPATIENTSDIALOG_H

#include <QDialog>
#include <QList>
#include <QTableWidgetItem>

#include "Data/patientdata.h"

namespace Ui {
class RemovePatientsDialog;
}

class RemovePatientsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemovePatientsDialog(QWidget *parent = 0);
    ~RemovePatientsDialog();

    bool hasUserAcceptChanges();
    void loadPatientList(QList<PatientData> _list);
    QList<PatientData> getPatientList();

private slots:
    void on_removeButton_clicked();

    void on_acceptButtonBox_accepted();

    void on_acceptButtonBox_rejected();

    void on_patientsTable_cellClicked(int row, int column);

private:
    Ui::RemovePatientsDialog *ui;

    bool _userAcceptChanges;
    QList<PatientData> _patientList;
    QList<int> _removePatientIndexList;

    enum PatientsColumnsName{
        PATIENT_COLUMN_SELECTED = 0,
        PATIENT_COLUMN_PATIENT_NAME = 1,
        PATIENT_COLUMN_SYASTOLE = 2,
        PATIENT_COLUMN_DYASTOLE = 3
    };

    void fillTable();
    void addRow(PatientData patient);
    QTableWidgetItem * addChangedColumn();
    QTableWidgetItem * addNonEditableText(QString _value);
    void removePatients(QList<int> indexToRemove);


};

#endif // REMOVEPATIENTSDIALOG_H
