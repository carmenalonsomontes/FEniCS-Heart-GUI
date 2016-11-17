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
#include "specificloadingrulesdialog.h"
#include "ui_specificloadingrulesdialog.h"

SpecificLoadingRulesDialog::SpecificLoadingRulesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpecificLoadingRulesDialog)
{
    ui->setupUi(this);
    _userAcceptChanges = false;
}

SpecificLoadingRulesDialog::~SpecificLoadingRulesDialog()
{
    delete ui;
}

void SpecificLoadingRulesDialog::on_buttonBox_accepted()
{
    buildFolderRules();
    buildFileImageRules();
    _userAcceptChanges = true;

    close();
}


void SpecificLoadingRulesDialog::buildFolderRules()
{
    // cleaning all the lists
     if (!_folderInclusionPreffix.isEmpty())
         _folderInclusionPreffix.clear();
     if (!_folderInclusionSuffix.isEmpty())
         _folderInclusionSuffix.clear();
     if (!_folderExclusionSuffix.isEmpty())
         _folderExclusionSuffix.clear();
     if (!_folderExclusionPreffix.isEmpty())
         _folderExclusionPreffix.clear();

    // Taking the data from the GUI

    QString _inclusionPreffix = ui->patientFolderIncludePrefixlineEdit->text();
    QString _inclusionSuffix = ui->patientFolderIncludeSuffixlineEdit->text();

    QString _exclusionPreffix = ui->patientFolderExcludePrefixlineEdit->text();
    QString _exclusionSuffix = ui->patientFolderExcludeSuffixlineEdit->text();

    if (!_inclusionPreffix.isEmpty())
        _folderInclusionPreffix = _inclusionPreffix.split(",");

    if (!_inclusionSuffix.isEmpty())
        _folderInclusionSuffix = _inclusionSuffix.split(",");

    if (!_exclusionPreffix.isEmpty())
        _folderExclusionPreffix = _exclusionPreffix.split(",");

    if (!_exclusionSuffix.isEmpty())
        _folderExclusionSuffix = _exclusionSuffix.split(",");

}

void SpecificLoadingRulesDialog::buildFileImageRules()
{

    // cleaning all the lists
//     if (!_fileImageExclusionPreffix.isEmpty())
//         _fileImageExclusionPreffix.clear();
     if (!_fileImageExclusionSuffix.isEmpty())
         _fileImageExclusionSuffix.clear();
//     if (!_fileImageInclusionPreffix.isEmpty())
//         _fileImageInclusionPreffix.clear();
     if (!_fileImageInclusionSuffix.isEmpty())
         _fileImageInclusionSuffix.clear();

    // Taking the data from the GUI

    //QString _inclusionPreffix = ui->patientFileExtensionIncludePrefixlineEdit->text();
    QString _inclusionSuffix = ui->patientFileExtensionIncludeSuffixlineEdit->text();

    //QString _exclusionPreffix = ui->patientFileExtensionExcludePrefixlineEdit->text();
    QString _exclusionSuffix = ui->patientFileExtensionExcludeSuffixlineEdit->text();

    //_fileImageExclusionPreffix = _exclusionPreffix.split(",");
    _fileImageExclusionSuffix = _exclusionSuffix.split(",");

    //_fileImageInclusionPreffix = _inclusionPreffix.split(",");
    _fileImageInclusionSuffix = _inclusionSuffix.split(",");
}


void SpecificLoadingRulesDialog::on_buttonBox_rejected()
{
    _userAcceptChanges = false;
    close();
}

bool SpecificLoadingRulesDialog::userAcceptsChanges()
{
    return _userAcceptChanges;
}

QStringList SpecificLoadingRulesDialog::getFolderPreffixInclusionRules()
{
    return _folderInclusionPreffix;
}
QStringList SpecificLoadingRulesDialog::getFolderSuffixInclusionRules()
{
    return _folderInclusionSuffix;
}
QStringList SpecificLoadingRulesDialog::getFolderPreffixExclusionRules()
{
    return _folderExclusionPreffix;
}
QStringList SpecificLoadingRulesDialog::getFolderSuffixExclusionRules()
{
    return _folderExclusionSuffix;
}


/*QStringList SpecificLoadingRulesDialog::getFileImagePreffixInclusionRules()
{
    return _fileImageInclusionPreffix;
}*/
QStringList SpecificLoadingRulesDialog::getFileImageSuffixInclusionRules()
{
    return _fileImageInclusionSuffix;
}
/*
QStringList SpecificLoadingRulesDialog::getFileImagePreffixExclusionRules()
{
    return _fileImageExclusionPreffix;
}*/
QStringList SpecificLoadingRulesDialog::getFileImageSuffixExclusionRules()
{
    return _fileImageExclusionSuffix;
}

void SpecificLoadingRulesDialog::clear()
{
    _userAcceptChanges = false;

    _folderInclusionPreffix.clear();
    _folderInclusionSuffix.clear();
    _folderExclusionPreffix.clear();
    _folderExclusionSuffix.clear();

   // _fileImageInclusionPreffix.clear();
    _fileImageInclusionSuffix.clear();
   // _fileImageExclusionPreffix.clear();
    _fileImageExclusionSuffix.clear();


}
