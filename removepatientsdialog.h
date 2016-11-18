#ifndef REMOVEPATIENTSDIALOG_H
#define REMOVEPATIENTSDIALOG_H

#include <QDialog>
#include <QList>
#include <QTableWidgetItem>

#include "Data/patientdata.h"

namespace Ui {
class RemovePatientsDialog;
}

/**
 * @brief This class is intended to define the logic for the REMOVE PATIENT dialog
 *
 */
class RemovePatientsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Creation of the object
     *
     * @param parent
     */
    explicit RemovePatientsDialog(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~RemovePatientsDialog();

    /**
     * @brief Returns true if the user has clicked OK, and accept the changes made
     *
     * @return bool
     */
    bool hasUserAcceptChanges();
    /**
     * @brief This function loads the list of patients in the dialog table
     *
     * @param _list
     */
    void loadPatientList(QList<PatientData> _list);
    /**
     * @brief Returns the stored patient list
     *
     * @return QList<PatientData>
     */
    QList<PatientData> getPatientList();

private slots:
    /**
     * @brief Logic for remove button
     *
     */
    void on_removeButton_clicked();

    /**
     * @brief Logic for accept button
     *
     */
    void on_acceptButtonBox_accepted();

    /**
     * @brief Logic for cancel button
     *
     */
    void on_acceptButtonBox_rejected();

    /**
     * @brief Add the selected patient to the removal list
     *
     * @param row
     * @param column
     */
    void on_patientsTable_cellClicked(int row, int column);

private:
    Ui::RemovePatientsDialog *ui; /**< TODO */

    bool _userAcceptChanges; /**< TODO */
    QList<PatientData> _patientList; /**< TODO */
    QList<int> _removePatientIndexList; /**< TODO */

    /**
     * @brief
     *
     */
    enum PatientsColumnsName{
        PATIENT_COLUMN_SELECTED = 0,
        PATIENT_COLUMN_PATIENT_NAME = 1,
        PATIENT_COLUMN_SYASTOLE = 2,
        PATIENT_COLUMN_DYASTOLE = 3
    };

    /**
     * @brief Fills the table with teh patient list information
     *
     */
    void fillTable();
    /**
     * @brief Add the patient to the table (each row --> 1 Patient)
     *
     * @param patient
     */
    void addRow(PatientData patient);
    /**
     * @brief Add the Item for the Column of seleection
     *
     * @return QTableWidgetItem
     */
    QTableWidgetItem * addChangedColumn();
    /**
     * @brief Add non editable item
     *
     * @param _value
     * @return QTableWidgetItem
     */
    QTableWidgetItem * addNonEditableText(QString _value);
    /**
     * @brief This function removes those patients listed
     *
     * @param indexToRemove
     */
    void removePatients(QList<int> indexToRemove);


};

#endif // REMOVEPATIENTSDIALOG_H
