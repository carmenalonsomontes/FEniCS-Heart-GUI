/*
 * Copyright (c) 2016 Carmen Alonso Montes. calonso@bcamath.org
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#include "removepatientsdialog.h"
#include "ui_removepatientsdialog.h"

RemovePatientsDialog::RemovePatientsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemovePatientsDialog)
{
    ui->setupUi(this);
    _userAcceptChanges = false;
}




RemovePatientsDialog::~RemovePatientsDialog()
{
    delete ui;
}

#include <QCheckBox>
void RemovePatientsDialog::on_removeButton_clicked()
{
     removePatients(_removePatientIndexList);
}

void RemovePatientsDialog::removePatients(QList<int> indexToRemove)
{
    if (indexToRemove.isEmpty())
        return;
    for (int i = indexToRemove.size()-1; i >= 0; i--)
    {
        _patientList.removeAt(indexToRemove.at(i));
        ui->patientsTable->removeRow(indexToRemove.at(i));
    }

}




void RemovePatientsDialog::on_acceptButtonBox_accepted()
{
    _userAcceptChanges = true;

    close();
}

void RemovePatientsDialog::on_acceptButtonBox_rejected()
{
    _userAcceptChanges = false;

    close();
}
bool RemovePatientsDialog::hasUserAcceptChanges()
{
    return _userAcceptChanges;
}

void RemovePatientsDialog::loadPatientList(QList<PatientData> _list)
{
    _patientList = _list;
    fillTable();
}

QList<PatientData> RemovePatientsDialog::getPatientList()
{
    return _patientList;
}

void RemovePatientsDialog::fillTable()
{
    if (_patientList.isEmpty())
        return;

    for (int i = 0; i< _patientList.size();i++)
    {
        PatientData _patient = _patientList.at(i);
        addRow(_patient);
    }

}

void RemovePatientsDialog::addRow(PatientData patient)
{
    int _lastRow = ui->patientsTable->rowCount();

    ui->patientsTable->insertRow(_lastRow);
    ui->patientsTable->setItem(_lastRow,PATIENT_COLUMN_SELECTED,addChangedColumn());
    ui->patientsTable->setItem(_lastRow,PATIENT_COLUMN_PATIENT_NAME,addNonEditableText(patient.getPatientName()));
    ui->patientsTable->setItem(_lastRow,PATIENT_COLUMN_SYASTOLE,addNonEditableText(QString::number(patient.getSyastole())));
    ui->patientsTable->setItem(_lastRow,PATIENT_COLUMN_DYASTOLE,addNonEditableText(QString::number(patient.getDyastole())));
}


QTableWidgetItem * RemovePatientsDialog::addChangedColumn()
{
    QTableWidgetItem * _checkStatusItem = new QTableWidgetItem("");
    _checkStatusItem->setCheckState(Qt::Unchecked);
    _checkStatusItem->setSelected(false);
    return _checkStatusItem;
}

QTableWidgetItem * RemovePatientsDialog::addNonEditableText(QString _value)
{
    QTableWidgetItem * _defaultTxt = new QTableWidgetItem(_value);
    _defaultTxt->setFlags(_defaultTxt->flags() &= ~Qt::ItemIsEditable);    

    return _defaultTxt;

}



void RemovePatientsDialog::on_patientsTable_cellClicked(int row, int column)
{
    if (column == PATIENT_COLUMN_SELECTED)
    {
        Qt::CheckState _status = ui->patientsTable->itemAt(row,column)->checkState();

       if (_status == Qt::Checked)
            _removePatientIndexList.append(row);
        else
         {
            int _posToRemove =    _removePatientIndexList.indexOf(row);
            _removePatientIndexList.removeAt(_posToRemove);
        }
    }
}
