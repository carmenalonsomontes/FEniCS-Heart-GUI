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
#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"

#include <QString>
#include <QFileDialog>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>

#include "Data/vol4dconfigurationdata.h"
#include "Data/matlabconfigurationdata.h"
#include "Data/inflowoutflowdatamark.h"
#include "Data/ansaconfigurationdata.h"
#include "Data/simulationconfigurationdata.h"

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);
    _userAcceptChanges = false;

    //_perlData = new Vol4DConfigurationData();
}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}


void PreferencesDialog::loadUserData()
{
    loadVol4dData();
    loadMatlabData();
    loadIOFlowData();
    loadAnsaData();
    loadSimulationData();
}


void PreferencesDialog::loadVol4dData()
{
   _perlData = _userData->getVol4DData();

    // Updating the info in the tab
    updateVol4DInfo(_perlData);
}

void PreferencesDialog::loadMatlabData()
{
    _matlabData = _userData->getMatlabData();

    // Updating the info in the tab
    updateMatlabInfo(_matlabData);

}
void PreferencesDialog::loadIOFlowData()
{
    _ioFlowData = _userData->getInflowOutflowData();

    // Updating the info in the tab
    updateIOFlowInfo(_ioFlowData);
}
void PreferencesDialog::loadAnsaData()
{
   _ansaData = _userData->getAnsaData();

    // Updating the info in the tab
    updateAnsaInfo(_ansaData);

}

void PreferencesDialog::loadSimulationData()
{
    _simData= _userData->getSimulationData();

    // Updating the info in the tab
    updateSimulationInfo(_simData);
}


void PreferencesDialog::setUserData(GUIConfigData * _data)
{
    _userData = _data;
}



void PreferencesDialog::on_buttonBox_accepted()
{
    _userAcceptChanges = true;
    saveUserData();
    _userData->setVol4DData(_perlData);
    _userData->setMatlabData(_matlabData);
    _userData->setAnsaData(_ansaData);
    _userData->setInflowOutflowData(_ioFlowData);
    _userData->setSimulationData(_simData);
    close();
}

void PreferencesDialog::saveUserData()
{
    // VOL4d
    _perlData.setPerlBinPath(ui->perlBinPathLineEdit->text());
    _perlData.setPerlPath(ui->perlScriptNameLineEdit->text());
    _perlData.setPerlScriptName(ui->perlScriptPathLineEdit->text());

    // Matlab
    _matlabData.setMatlabPath(ui->matlabPathLineEdit->text());
    QStringList _list;
    QString _niiVal = ui->niiOffSTLScriptLineEdit->text();

    if (_niiVal.isEmpty())
        _list.append("");
    else
        _list.append(_niiVal);

    QString _lbl = ui->LBLlineEdit->text();

    if (_lbl.isEmpty())
        _list.append("");
    else
        _list.append(_lbl);

    QString _leuvenPanthom = ui->LeuvenPhantomLineEdit->text();
    if (_leuvenPanthom.isEmpty())
        _list.append("");
    else
        _list.append(_leuvenPanthom);


    _matlabData.setScriptsPath(_list);
    _matlabData.setNoDesktop(ui->noDesktopCheckBox->isChecked());
    _matlabData.setNoSplash(ui->noSplashCheckBox->isChecked());

    // IO FLOW
   _ioFlowData.setScriptPath(ui->inflowOutflowLineEdit->text());

   // ANSA
   _ansaData.setAnsaPath(ui->AnsaLineEdit->text());

   //Simulation+
   _simData.setScriptPath(ui->SimulationLineEdit->text());


}

bool PreferencesDialog::hasUserAcceptChanges()
{
    return _userAcceptChanges;
}

void PreferencesDialog::on_buttonBox_rejected()
{
     _userAcceptChanges = false;
    close();
}


//--------------- PERL --------------------------------------------------

void PreferencesDialog::on_perlBinPathtoolButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Select Perl binary",QCoreApplication::applicationDirPath(),"*");
    //_perlData.setPerlPath(path);

    updatePerlBinLine(path);
}

void PreferencesDialog::on_perlScriptNametoolButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Select Perl Script",QCoreApplication::applicationDirPath(),"*");
    //_perlData.setPerlScriptName(path);

    updatePerlScriptLine(path);


}

void PreferencesDialog::on_perlScriptPathtoolButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Select Perl Script",QCoreApplication::applicationDirPath(),"*");
   // _perlData.setPerlScriptName(path);

    updatePerlScriptLine(path);

}


void PreferencesDialog::updatePerlBinLine(QString path)
{
    ui->perlBinPathLineEdit->setText(path);
}

void PreferencesDialog::updatePerlScriptLine(QString path)
{
   QString _pathScript = QFileInfo(path).absolutePath();
   QString _scriptName = QFileInfo(path).fileName();

   ui->perlScriptNameLineEdit->setText(_scriptName);
   ui->perlScriptPathLineEdit->setText(_pathScript);

}

void PreferencesDialog::updateVol4DInfo(Vol4DConfigurationData _data)
{
    QString _binPerlPath = _data.getPerlBinPath();
    QString _scriptPerlPath = _data.getPerlScriptName();

    updatePerlBinLine(_binPerlPath);
    updatePerlScriptLine(_scriptPerlPath);
}

//_------------------------------------ MATLAB ---------------------------------------
void PreferencesDialog::on_matlabPathToolButton_clicked()
{

    QString path = QFileDialog::getOpenFileName(this, "Select Matlab Executable",QCoreApplication::applicationDirPath(),"*");
   // _matlabData.setMatlabPath(path);
    updateMatlabExecLine(path);

}

void PreferencesDialog::updateMatlabExecLine(QString path)
{
    ui->matlabPathLineEdit->setText(path);
}

void PreferencesDialog::on_niiOffSTLScriptToolButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Select VOL4D2OFF Script",QCoreApplication::applicationDirPath(),"*");
    if (path.isEmpty())
        return;
 /*   QStringList _list;
    _list = _matlabData.getScriptsPath();
    _list = insertList(0,path,_list);
    _matlabData.setScriptsPath(_list);
    */
    updateNiiOffSTLScriptLine(path);
}

QStringList PreferencesDialog::insertList(int position, QString path,QStringList _list)
{
    if (position < _list.size())
        _list.insert(position,path);
    else
    {
        if (position == _list.size())
            _list.append(path);
        else
        {
            for (int i=_list.size(); i < position;i++)
                _list.append("NONE");
            _list.append(path);

        }
    }
    return _list;
}

void PreferencesDialog::updateNiiOffSTLScriptLine(QString path)
{
      if (QString::compare(path,"NONE") != 0)
            ui->niiOffSTLScriptLineEdit->setText(path);
}

void PreferencesDialog::on_LBLtoolButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Select LBL Script",QCoreApplication::applicationDirPath(),"*");
    if (path.isEmpty())
        return;

 /*   QStringList _list;
    _list = _matlabData.getScriptsPath();
    _list = insertList(1,path,_list);
    _matlabData.setScriptsPath(_list);*/
    updateLBLLine(path);

}

void PreferencesDialog::updateLBLLine(QString path)
{
      if (QString::compare(path,"NONE") != 0)
            ui->LBLlineEdit->setText(path);
}

void PreferencesDialog::on_LeuvenPhantomToolButton_clicked()
{
   QString path = QFileDialog::getOpenFileName(this, "Select Leuven Phantom Script",QCoreApplication::applicationDirPath(),"*");
   if (path.isEmpty())
       return;

 /*  QStringList _list;
   _list = _matlabData.getScriptsPath();
   _list = insertList(2,path,_list);
   _matlabData.setScriptsPath(_list);*/
   updateLeuvenPhantomLine(path);

}

void PreferencesDialog::updateLeuvenPhantomLine(QString path)
{
    if (QString::compare(path,"NONE") != 0)
        ui->LeuvenPhantomLineEdit->setText(path);
}


void PreferencesDialog::updateMatlabInfo(MatlabConfigurationData _data)
{
    updateMatlabExecLine(_data.getMatlabPath());
    QStringList _list = _data.getScriptsPath();
    if ((!_list.isEmpty()) && (_list.size() == 3))
    {
        updateLeuvenPhantomLine(_list.at(0));
        updateLBLLine(_list.at(1));
        updateNiiOffSTLScriptLine(_list.at(2));
    }

    ui->noDesktopCheckBox->setChecked(_data.isNoDesktop());
    ui->noSplashCheckBox->setChecked(_data.isNoSplash());
}


//_------------------------------------IO FLOW ---------------------------------------

void PreferencesDialog::on_infflowOutflowToolbutton_clicked()
{
     QString path = QFileDialog::getOpenFileName(this, "Select ANSA Script",QCoreApplication::applicationDirPath(),"*");
     if (path.isEmpty())
         return;

     //_ioFlowData.setScriptPath(path);

     updateIOFlowLine(path);
}

void PreferencesDialog::updateIOFlowLine(QString path)
{
     ui->inflowOutflowLineEdit->setText(path);
}

void PreferencesDialog::updateIOFlowInfo(InflowOutflowDataMark _data)
{
   updateIOFlowLine(_data.getScriptPath());
}
//_------------------------------------ ANSA ---------------------------------------


void PreferencesDialog::on_AnsaToolButton_clicked()
{
       QString path = QFileDialog::getOpenFileName(this, "Select ANSA Script",QCoreApplication::applicationDirPath(),"*");
       if (path.isEmpty())
           return;

      // _ansaData.setAnsaPath(path);

       updateAnsaLine(path);
}
void PreferencesDialog::updateAnsaLine(QString path)
{
      ui->AnsaLineEdit->setText(path);
}

void PreferencesDialog::updateAnsaInfo(AnsaConfigurationData _data)
{
     updateAnsaLine(_data.getAnsaPath());
}
//---------------------- SIMULATION -----------------------------------------------
void PreferencesDialog::on_SimulationToolButton_clicked()
{
       QString path = QFileDialog::getOpenFileName(this, "Select Simulation Script",QCoreApplication::applicationDirPath(),"*");
       if (path.isEmpty())
           return;

      // _simData.setScriptPath(path);

       updateSimulationLine(path);
}
void PreferencesDialog::updateSimulationLine(QString path)
{
      ui->SimulationLineEdit->setText(path);
}
void PreferencesDialog::updateSimulationInfo(SimulationConfigurationData _data)
{
   updateSimulationLine(_data.getScriptPath());
}



void PreferencesDialog::on_deletePerlbinButton_clicked()
{
    ui->perlBinPathLineEdit->clear();
}

void PreferencesDialog::on_deletePerlScriptButton_clicked()
{
   ui->perlScriptNameLineEdit->clear();
}

void PreferencesDialog::on_deleteScripthPathButton_clicked()
{
     ui->perlScriptPathLineEdit->clear();
}

void PreferencesDialog::on_deleteMatlabPathButton_clicked()
{
    ui->matlabPathLineEdit->clear();
}

void PreferencesDialog::on_deleteNiiButton_clicked()
{
    ui->niiOffSTLScriptLineEdit->clear();
}

void PreferencesDialog::on_deleteLBLButton_clicked()
{
    ui->LBLlineEdit->clear();
}

void PreferencesDialog::on_deleteLeuvenPhantomButton_clicked()
{
    ui->LeuvenPhantomLineEdit->clear();
}

void PreferencesDialog::on_deleteIOFlowButton_clicked()
{
    ui->inflowOutflowLineEdit->clear();
}

void PreferencesDialog::on_deleteAnsaButton_clicked()
{
    ui->AnsaLineEdit->clear();
}

void PreferencesDialog::on_deleteSimButton_clicked()
{
    ui->SimulationLineEdit->clear();
}

void PreferencesDialog::on_resetAllButton_clicked()
{
    emit on_deletePerlbinButton_clicked();
    emit on_deletePerlScriptButton_clicked();
    emit on_deleteScripthPathButton_clicked();
    emit on_deleteMatlabPathButton_clicked();
    emit on_deleteNiiButton_clicked();
    emit on_deleteLBLButton_clicked();
    emit on_deleteLeuvenPhantomButton_clicked();
    emit on_deleteIOFlowButton_clicked();
    emit on_deleteAnsaButton_clicked();
    emit on_deleteSimButton_clicked();

    ui->noDesktopCheckBox->setChecked(true);
    ui->noSplashCheckBox->setChecked(true);
}
