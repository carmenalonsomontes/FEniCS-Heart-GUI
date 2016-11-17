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
#include "manualpatientnumberingdialog.h"
#include "ui_manualpatientnumberingdialog.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QDir>


ManualPatientNumberingDialog::ManualPatientNumberingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManualPatientNumberingDialog)
{
    ui->setupUi(this);

    _userAcceptChanges = false;
    _MIN_IMAGES = 0;
    _CURRENT_PATIENT_INDEX = 0;
}

ManualPatientNumberingDialog::~ManualPatientNumberingDialog()
{
    delete ui;
}

void ManualPatientNumberingDialog::setPatientList(QList<PatientData> list)
{
    _patientList = list;
    if (_patientList.isEmpty())
    {
        ui->nextButton->setEnabled(false);
        ui->previousButton->setEnabled(false);
        ui->noImlineEdit->setEnabled(false);
        ui->dyastoleLineEdit->setEnabled(false);
        ui->timeStepLineEdit->setEnabled(false);

        return;
    }

    initializeValues();

    if (_patientList.size() >= 1)
        loadPatientInfo(0);

    _MAX_IMAGES = _patientList.size()-1;
    _CURRENT_PATIENT_INDEX = 0;

     updatePatientNumberingLabels(_CURRENT_PATIENT_INDEX);
     updatePatientData(_CURRENT_PATIENT_INDEX);

}

void ManualPatientNumberingDialog::initializeValues()
{
    for (int i = 0; i < _patientList.size();i++)
    {
        PatientData _patient = _patientList.at(i);
        _dyastoleValues.append(QString::number(_patient.getDyastole()));
        _syastoleValues.append(QString::number(_patient.getSyastole()));
    }
}

void ManualPatientNumberingDialog::updatePatientData(int pos)
{
    if (pos > _MAX_IMAGES)
        return;
    ui->dyastoleLineEdit->setText(_dyastoleValues.at(pos));
    ui->timeStepLineEdit->setText(_syastoleValues.at(pos));
    PatientData _cPatient = _patientList.at(pos);
    ui->patientNameLabel->setText(_cPatient.getPatientName());
}

void ManualPatientNumberingDialog::updatePatientNumberingLabels(int pos)
{
    ui->noImlineEdit->setText(QString::number(pos));
    ui->maxNoImLabel->setText(QString::number(_MAX_IMAGES));

    if (pos == _MIN_IMAGES)
        ui->previousButton->setEnabled(false);
    if (pos > _MIN_IMAGES)
        ui->previousButton->setEnabled(true);

    if (pos == _MAX_IMAGES)
        ui->nextButton->setEnabled(false);
    if (pos < _MAX_IMAGES)
        ui->nextButton->setEnabled(true);

}



void ManualPatientNumberingDialog::loadPatientInfo(int _noPatient)
{   
    if (_noPatient < _patientList.size())
       showPatientImage(_noPatient);
   // _CURRENT_PATIENT_INDEX = _noPatient;
    updateCurrentPatientNumber(_noPatient);
    updatePatientNumberingLabels(_noPatient);
    updatePatientData(_noPatient);
}

void ManualPatientNumberingDialog::updateCurrentPatientNumber(int _pos)
{
    ui->noImlineEdit->setText(QString::number(_pos));
    _CURRENT_PATIENT_INDEX = _pos;
}

void ManualPatientNumberingDialog::showPatientImage(int _noPatient)
{
    PatientData _cPatient = _patientList.at(_noPatient);

    QString _fileName = QDir(_cPatient.getFolderPatientPath()).filePath(_cPatient.getFileImagePath());
    if (_fileName.isEmpty())
        return;
    QImage image(_fileName);
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

}


QList<PatientData> ManualPatientNumberingDialog::getPatientList()
{
    return _patientList;
}

bool ManualPatientNumberingDialog::hasUserAcceptedChanges()
{
    return _userAcceptChanges;
}


void ManualPatientNumberingDialog::on_previousButton_clicked()
{
    savePatientInfo(_CURRENT_PATIENT_INDEX);
    loadPatientInfo(_CURRENT_PATIENT_INDEX - 1);


}

void ManualPatientNumberingDialog::on_nextButton_clicked()
{
    savePatientInfo(_CURRENT_PATIENT_INDEX);
    loadPatientInfo(_CURRENT_PATIENT_INDEX +1);

}

void ManualPatientNumberingDialog::savePatientInfo(int pos)
{
    _dyastoleValues[pos]= ui->dyastoleLineEdit->text();
    _syastoleValues[pos]= ui->timeStepLineEdit->text();
}

void ManualPatientNumberingDialog::on_buttonBox_accepted()
{
    _userAcceptChanges = true;
    savePatientInfo(_CURRENT_PATIENT_INDEX);
    updatePatientListValues();
    close();

}

void ManualPatientNumberingDialog::updatePatientListValues()
{
    QList<PatientData> _updatedList;
    for (int i = 0; i<_patientList.size();i++)
    {
        PatientData _patient = _patientList.at(i);
        _patient.setDyastole(_dyastoleValues.at(i).toInt());
        _patient.setSyastole(_syastoleValues.at(i).toInt());
        _updatedList.append(_patient);
    }

    _patientList = _updatedList;
}

void ManualPatientNumberingDialog::on_buttonBox_rejected()
{
    _userAcceptChanges = false;
    close();

}
