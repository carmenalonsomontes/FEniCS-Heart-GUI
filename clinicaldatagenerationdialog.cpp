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
#include "clinicaldatagenerationdialog.h"
#include "ui_clinicaldatagenerationdialog.h"


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>

#include <QFileDialog>
#include <QDir>
#include <QFileInfo>

#include "removepatientsdialog.h"
#include "specificloadingrulesdialog.h"
#include "TXT/listclinicalwriter.h"
#include "manualpatientnumberingdialog.h"

ClinicalDataGenerationDialog::ClinicalDataGenerationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClinicalDataGenerationDialog)
{
    ui->setupUi(this);

    _userAcceptChanges = false;
}

ClinicalDataGenerationDialog::~ClinicalDataGenerationDialog()
{
    delete ui;
}

void ClinicalDataGenerationDialog::setProjectData(ProjectData data)
{
    _projectData = data;
    ui->dataPatientPathLine->setText(_projectData.getClinicalDataPath());
    loadPatientList(data.getListPatients());
}

ProjectData ClinicalDataGenerationDialog::getProjectData()
{
    return _projectData;
}

bool  ClinicalDataGenerationDialog::hasUserAcceptChanges()
{
    return _userAcceptChanges;
}



void ClinicalDataGenerationDialog::loadPatientList(QList<PatientData> _list)
{
    if (_list.isEmpty())
        return;
    for (int i = 0;i < _list.size();i++)
    {
        PatientData _cPatient = _list.at(i);
        addPatient(_cPatient);
    }

}

void ClinicalDataGenerationDialog::addPatient(PatientData _patient)
{
    int _lastRow = ui->patientTable->rowCount();
    ui->patientTable->insertRow(_lastRow);

    ui->patientTable->setItem(_lastRow,PATIENT_NUM,addNonEditableText(QString::number(_lastRow)));
    ui->patientTable->setItem(_lastRow,PATIENT_NAME,addNonEditableText(_patient.getPatientName()));
    ui->patientTable->setItem(_lastRow,PATIENT_SYASTOLE,addEditableText(QString::number(_patient.getSyastole())));
    ui->patientTable->setItem(_lastRow,PATIENT_DYASTOLE,addEditableText(QString::number(_patient.getDyastole())));
    ui->patientTable->setItem(_lastRow,PATIENT_FILE_IM_PATH,addNonEditableText(_patient.getFileImagePath()));
    ui->patientTable->setItem(_lastRow,PATIENT_FILE_FOLDER_PATH,addNonEditableText(_patient.getFolderPatientPath()));

    ui->patientTable->resizeColumnsToContents();

}



void ClinicalDataGenerationDialog::on_dataPatientToolButton_clicked()
{
 //  QString path = QFileDialog::getOpenFileName(this, "Select Patients folder",QCoreApplication::applicationDirPath(),"*");

   QString path = QFileDialog::getExistingDirectory(this,
                           tr("Select Patients folder"),
                           QCoreApplication::applicationDirPath(),
                           QFileDialog::DontUseNativeDialog | QFileDialog::ReadOnly| QFileDialog::ShowDirsOnly);
   if (path.isEmpty())
       return;


   _projectData.setClinicalDataPath(path);
   // Update the UI
   ui->dataPatientPathLine->setText(path);

}


void ClinicalDataGenerationDialog::on_defPatientCheckListButton_clicked()
{
    ManualPatientNumberingDialog _dialog;
    _dialog.setPatientList(_projectData.getListPatients());
    _dialog.exec();

    if (_dialog.hasUserAcceptedChanges())
    {
        _projectData.setListPatients(_dialog.getPatientList());
        emptyTable();
        fillPatientTable(_projectData.getListPatients());
    }
}



void ClinicalDataGenerationDialog::on_generateCheckListButton_clicked()
{
    updatePatientData();
    createPatientFile();

}

void ClinicalDataGenerationDialog::on_buttonBox_accepted()
{
    _userAcceptChanges = true;
    updatePatientData();
    close();

}

void ClinicalDataGenerationDialog::updatePatientData()
{
    QList<PatientData> _list = _projectData.getListPatients();
    QList<PatientData> _newList;


    for (int i = 0; i < _list.size();i++)
    {
        PatientData _patient = _list.at(i);
        int _syastole = ui->patientTable->item(i,PATIENT_SYASTOLE)->text().toInt();
        int _dyastole = ui->patientTable->item(i,PATIENT_DYASTOLE)->text().toInt();


        if (_syastole != _patient.getSyastole())
            _patient.setSyastole(_syastole);
        if (_dyastole != _patient.getDyastole())
            _patient.setDyastole(_dyastole);
        _newList.append(_patient);
    }

    _projectData.setListPatients(_newList);

}



void ClinicalDataGenerationDialog::on_buttonBox_rejected()
{
    _userAcceptChanges = false;
    close();
}

void ClinicalDataGenerationDialog::on_loadPatientsButton_clicked()
{
    if (ui->dataPatientPathLine->text().isEmpty())
        return;
    if (ui->patientTable->rowCount()>0)
        emptyTable();

    foundPatientInformation();
    fillPatientTable(_projectData.getListPatients());

}

void ClinicalDataGenerationDialog::emptyTable()
{
    int _totalRows = ui->patientTable->rowCount();

    for (int i = _totalRows; i >= 0; i--)
        ui->patientTable->removeRow(i);
}


//=====================================================================================
void ClinicalDataGenerationDialog::foundPatientInformation()
{
    // TODO -- Se le pasa el folder y tiene que ir encontrando todos los valores de la tabla
    // y rellenando el project data

    SpecificLoadingRulesDialog _rulesDialog;
    _rulesDialog.exec();

    QStringList _folderInclusionPrefixRules;
    QStringList _folderIclusionSuffixRules;

    QStringList _folderExclusionPrefixRules;
    QStringList _folderExclusionSuffixRules;

    QStringList _fileImageInclusionPrefixRules;
    QStringList _fileImageIclusionSuffixRules;

    QStringList _fileImageExclusionPrefixRules;
    QStringList _fileImageExclusionSuffixRules;

    if (_rulesDialog.userAcceptsChanges())
    {

         _folderInclusionPrefixRules = _rulesDialog.getFolderPreffixInclusionRules();
         _folderIclusionSuffixRules = _rulesDialog.getFolderSuffixInclusionRules();

         _folderExclusionPrefixRules = _rulesDialog.getFolderPreffixExclusionRules();
         _folderExclusionSuffixRules = _rulesDialog.getFolderSuffixExclusionRules();

         //_fileImageInclusionPrefixRules =  _rulesDialog.getFileImagePreffixInclusionRules();
         _fileImageIclusionSuffixRules= _rulesDialog.getFileImageSuffixInclusionRules();

         //_fileImageExclusionPrefixRules = _rulesDialog.getFileImagePreffixExclusionRules();
         _fileImageExclusionSuffixRules = _rulesDialog.getFileImageSuffixExclusionRules();
    }

    QList<PatientData> _listPatients = getPatientIds(_folderInclusionPrefixRules,_folderIclusionSuffixRules,
                                                   _folderExclusionPrefixRules,_folderExclusionSuffixRules);
    QList<PatientData> _finalListPatients = completePatientData(_listPatients,_fileImageInclusionPrefixRules,
                                                               _fileImageIclusionSuffixRules, _fileImageExclusionPrefixRules,
                                                                _fileImageExclusionSuffixRules);

    // Update Data
    _projectData.setListPatients(_finalListPatients);

}

void ClinicalDataGenerationDialog::fillPatientTable(QList<PatientData> _list)
{
    if (_list.isEmpty())
        return;
    for (int i = 0;i < _list.size();i++)
    {
        PatientData _patient = _list.at(i);
        addPatient(_patient);
    }
    ui->patientTable->resizeColumnsToContents();
}

QTableWidgetItem * ClinicalDataGenerationDialog::addNonEditableText(QString _value)
{
    QTableWidgetItem * _defaultTxt = new QTableWidgetItem(_value);
    _defaultTxt->setFlags(_defaultTxt->flags() &= ~Qt::ItemIsEditable);
    return _defaultTxt;

}
QTableWidgetItem * ClinicalDataGenerationDialog::addEditableText(QString _value)
{
    QTableWidgetItem * _defaultTxt = new QTableWidgetItem(_value);
   // _defaultTxt->setFlags(_defaultTxt->flags() &= Qt::ItemIsEditable);
    return _defaultTxt;

}

/*
void ClinicalDataGenerationDialog::addRow(PatientData _patient)
{
    int _lastRow = ui->patientTable->rowCount();

    ui->patientTable->insertRow(_lastRow);

    ui->patientTable->setItem(_lastRow,PATIENT_NUM,addNonEditableText(QString::number(_lastRow)));
    ui->patientTable->setItem(_lastRow,PATIENT_NAME,addNonEditableText(_patient.getPatientName()));
    ui->patientTable->setItem(_lastRow,PATIENT_SYASTOLE,addEditableText(QString::number(_patient.getSyastole())));
    ui->patientTable->setItem(_lastRow,PATIENT_DYASTOLE,addEditableText(QString::number(_patient.getDyastole())));
    ui->patientTable->setItem(_lastRow,PATIENT_FILE_IM_PATH,addNonEditableText(_patient.getFileImagePath()));
    ui->patientTable->setItem(_lastRow,PATIENT_FILE_FOLDER_PATH,addNonEditableText(_patient.getFolderPatientPath()));
}

*/

QList<PatientData> ClinicalDataGenerationDialog::getPatientIds(QStringList _inclusionPrefixRules, QStringList _iclusionSuffixRules,
                                                 QStringList _exclusionPrefixRules, QStringList _exclusionSuffixRules)
{
    QDir _cDirectory;
    QList<PatientData> _list;
    QString _cPath = ui->dataPatientPathLine->text();
    if (_cPath.isEmpty())
        return _list;

    _cDirectory.setCurrent(_cPath);
    _cDirectory.setFilter(QDir::AllDirs|QDir::NoDotAndDotDot);//,QDir::Name);

    QStringList _listAllPatients = _cDirectory.entryList();
    QStringList _listPreffix = _listAllPatients;
    QStringList _listSuffix;

    // If inclusion is empty means to take all
    if (!_inclusionPrefixRules.isEmpty())
        _listPreffix = filterPatientList(_listAllPatients,_inclusionPrefixRules,_exclusionPrefixRules,PREFFIX_RULES);
    _listSuffix = _listPreffix;
    if (!_iclusionSuffixRules.isEmpty())
        _listSuffix = filterPatientList(_listPreffix,_iclusionSuffixRules,_exclusionSuffixRules,SUFFIX_RULES);

    for (int i = 0; i < _listSuffix.size();i++)
    {
        PatientData _cPatient;
        QString _patientName = _listSuffix.at(i);
        _cPatient.setPatientName(_patientName);
        _list.append(_cPatient);
    }

    return _list;
}

QStringList  ClinicalDataGenerationDialog::filterPatientList(QStringList list, QStringList inclusion, QStringList exclusion,
                                                             RulesValues _type)
{
    // Note: 1st select all those the user want to be included, and then from the included one, I remove those in the exclusion list.
    // If no inclusion criteria is written, the user is including all teh files, except those with exclusion criteria
    QStringList _folderList;
    if (list.isEmpty())
        return _folderList;


    QStringList _tmpIncludeList = list;
    for (int j= 0; j < inclusion.size();j++)
    {
        QString _inclVal = inclusion.at(j);

        if (_inclVal.isEmpty())
            continue;
        _tmpIncludeList = filterIncludedValues(_tmpIncludeList,_inclVal,_type);
    }


    QStringList _tmpExclList = _tmpIncludeList;
    for (int i= 0; i < exclusion.size();i++)
    {
        QString _exclVal = exclusion.at(i);

        if (_exclVal.isEmpty())
            continue;
        _tmpExclList = filterExcludedValues(_tmpExclList,_exclVal,_type);
    }

    _folderList = _tmpExclList;
    return _folderList;

}


QStringList ClinicalDataGenerationDialog::filterIncludedValues(QStringList _list,QString _valueTocheck, RulesValues _type )
{
    QStringList _result;

    for (int i = 0; i < _list.size();i++)
    {
        QString _cValue= _list.at(i);
        if (_cValue.isEmpty())
            continue;
        if( ((_type == PREFFIX_RULES) && (_cValue.startsWith(_valueTocheck)))
            || ((_type == SUFFIX_RULES) && (_cValue.endsWith(_valueTocheck))))
                _result.append(_cValue);
    }

    return _result;

 }




QStringList ClinicalDataGenerationDialog::filterExcludedValues(QStringList _list,QString _valueTocheck, RulesValues _type )
{
    QStringList _result;

    for (int i = 0; i < _list.size();i++)
    {
        QString _cValue= _list.at(i);
        if (_cValue.isEmpty())
            continue;
        if( ((_type == PREFFIX_RULES) && (!_cValue.startsWith(_valueTocheck)))
            || ((_type == SUFFIX_RULES) && (!_cValue.endsWith(_valueTocheck))))
                _result.append(_cValue);
    }

    return _result;

 }

QList<PatientData> ClinicalDataGenerationDialog::completePatientData(QList<PatientData> _list, QStringList _inclusionPrefixRules,
                                                                     QStringList _iclusionSuffixRules,
                                                 QStringList _exclusionPrefixRules, QStringList _exclusionSuffixRules)
{
    QDir _cDirectory;
    QList<PatientData> _newList;
    QString _cPath = ui->dataPatientPathLine->text();
    if (_cPath.isEmpty())
        return _newList;

    for (int i= 0;i < _list.size();i++)
    {
        PatientData _cPatient = _list.at(i);
        QString _patientPath = QDir(_cPath).filePath(_cPatient.getPatientName());
        // Saving the Patient Folder Path
        _cPatient.setFolderPatientPath(_patientPath);

        _cDirectory.setCurrent(_patientPath);
        QStringList _allFiles = _cDirectory.entryList(QDir::Files);
        QStringList _listPreffix = _allFiles;
        QStringList _listSuffix;

        // Filter files
        if (!_inclusionPrefixRules.isEmpty())
            _listPreffix = filterPatientList(_allFiles,_inclusionPrefixRules,_exclusionPrefixRules,PREFFIX_RULES);
        _listSuffix = _listPreffix;
        if (!_iclusionSuffixRules.isEmpty())
            _listSuffix = filterPatientList(_listSuffix,_iclusionSuffixRules,_exclusionSuffixRules,SUFFIX_RULES);

        QString _fileToShow;
        if ((!_listSuffix.isEmpty()) && (_listSuffix.size()>=1))
            _fileToShow = _listSuffix.at(0);
        // Saving the Image File Path
        _cPatient.setFileImagePath(_fileToShow);

        _newList.append(_cPatient);

    }
    return _newList;

}



void ClinicalDataGenerationDialog::createPatientFile()
{
    // Crear el fichero con los valores ... PReguntar a jeannette como es ese fichero
    ListClinicalWriter _fileWriter;
    QString _txtPath = QDir(_projectData.getClinicalDataPath()).filePath("listClinical.txt");

    _fileWriter.saveProjectData(&_projectData,_txtPath);
    _projectData.setClinicalPatientFilePath(_txtPath);


}


void ClinicalDataGenerationDialog::on_addManualPatientButton_clicked()
{
    // In case there is a patient(s) you want to add manually

      QList<PatientData> _list = _projectData.getListPatients();
      QString _currentPath = _projectData.getClinicalDataPath();
      QString _imageFile = QFileDialog::getOpenFileName(this, "Select Patient Image Filer",_currentPath,"*");

      if (_imageFile.isEmpty())
          return;


      QString path = QFileInfo(_imageFile).absolutePath();
      QString _fileName = QFileInfo(_imageFile).baseName();


      PatientData _newPatient;
      _newPatient.setFolderPatientPath(path);
      _newPatient.setPatientName(_fileName);

      _newPatient.setFileImagePath(QFileInfo(_imageFile).fileName());

      addPatient(_newPatient);

      _list.append(_newPatient);

      _projectData.setListPatients(_list);
}


void ClinicalDataGenerationDialog::on_removePatientButton_clicked()
{

    RemovePatientsDialog _removePatients;
    _removePatients.loadPatientList(_projectData.getListPatients());
    _removePatients.exec();

    if (_removePatients.hasUserAcceptChanges())
    {
        _projectData.setListPatients(_removePatients.getPatientList());
        emptyTable();
        fillPatientTable(_projectData.getListPatients());

    }


}
