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
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QCoreApplication>
#include <QDir>




#include "preferencesdialog.h"
#include "XML/guiconfigdataxmlparser.h"
#include "XML/projectdataxmlparser.h"
#include "clinicaldatagenerationdialog.h"
#include "aboutdialog.h"

#include "Parser/scriptparser.h"

//const QString FILE_CONFIG_GUI_NAME = "gui-config.xml";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadInitialCongiguration();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadInitialCongiguration()
{
    _userSessionData = new GUIConfigData();
    QString _currentAppPath = QCoreApplication::applicationDirPath();

    _cConfigFilename = QDir(_currentAppPath).filePath(USER_SESSION_DATA_FILENAME);
    GuiConfigDataXMLParser _parser;
    _parser.readUserGUIConfiguration(_userSessionData,_cConfigFilename);
}


void MainWindow::on_actionNew_Project_triggered()
{
    QString projectPath = QFileDialog::getSaveFileName(this, "Create New Project",QCoreApplication::applicationDirPath(),
                               "Project (*.*)");

    //Logic -------------------

    if (!projectPath.isEmpty())
    {
        createProject(projectPath);

        // UI enabling/disabling
        enableSaveButton();
        enableCloseButton();
        enableTabs();

        // Update Console
        QString _msg = "NEW PROJECT CREATED: "+ projectPath;
        UpdateConsole(_msg);
    }

}


void MainWindow::saveUserSessionData()
{
    // Save first project structure
    GuiConfigDataXMLParser _parser;
    _parser.saveUserGUIConfiguration(_userSessionData,_cConfigFilename);
}




void MainWindow::createProject(QString projectPath)
{
    if (projectPath.isEmpty())
        return;

    // Create folder name & path
    if (!QDir(projectPath).exists())
        QDir().mkdir(projectPath);


    QString _projectName = QFileInfo(projectPath).fileName();
    _projectName.append(FILE_EXTENSION_PROJECT);

    QString _fileProject = QDir(projectPath).filePath(_projectName);
    _projectData.setProjectPath(_fileProject);

    // TODO

    ProjectDataXMLParser _xmlWriter;
    _xmlWriter.saveProjectData(&_projectData,_fileProject);

}




void MainWindow::on_actionOpen_Project_triggered()
{
    QString projectPath = QFileDialog::getOpenFileName(this, "Create New Project",QCoreApplication::applicationDirPath(),
                               "Project (*.*)");

    if (projectPath.isEmpty())
        return;
    // Load file

    ProjectDataXMLParser _reader;
    _reader.readProjectData(&_projectData,projectPath);

    // Activate UI elements
    enableSaveButton();
    enableCloseButton();
    enableTabs();
    // Update User Information
    updateUserInformation();

    // Update Console
    QString _msg = "OPEN PROJECT: "+ projectPath;
    UpdateConsole(_msg);
}
void MainWindow::updateUserInformation()
{
    updateSimulationTabInformation();
}


void MainWindow::updateSimulationTabInformation()
{
    ui->patientFilePathLineEdit->setText(_projectData.getClinicalPatientFilePath());
    ClusterData _clusterData = _projectData.getClusterData();
    if (_clusterData.isEmpty())
        return;

    // Cluster Data
    ui->clusterIPlineEdit->setText(_clusterData.getClusterIP());
    ui->loginClusterlineEdit->setText(_clusterData.getClusterLoginName());
    ui->remotePatientDataPath->setText(_clusterData.getRemotePatientDataFolder());
    ui->remoteCPPFilePath->setText(_clusterData.getRemoteCPPFolder());
}

void MainWindow::on_actionRecent_Projects_triggered()
{

    enableSaveButton();
    enableCloseButton();
}

void MainWindow::on_actionSave_triggered()
{
    saveProjectData();
    disableSaveButton();
    enableCloseButton();
    // Update Console
    QString _msg = "SAVE PROJECT";
    UpdateConsole(_msg);
}

void MainWindow::on_actionSave_As_triggered()
{
    QString projectPath = QFileDialog::getSaveFileName(this, "Save as",QCoreApplication::applicationDirPath(),
                               "Project (*.*)");

    if (projectPath.isEmpty())
        return;
    _projectData.setProjectPath(projectPath);
    saveProjectData();
    disableSaveButton();
    enableCloseButton();


    // Update Console
    QString _msg = "SAVE PROJECT as: " + projectPath;
    UpdateConsole(_msg);
}

void MainWindow::saveProjectData()
{
    // Save Project DAta

    ProjectDataXMLParser _saveProject;
    _saveProject.saveProjectData(&_projectData,_projectData.getProjectPath());

    // Clearing the values
    _projectData.clear();

}

void MainWindow::on_actionClose_Project_triggered()
{
     saveProjectData();

    // Update UI values
    disableSaveButton();
    disableCloseButton();
    disableTabs();

    // Clean Tabs

    cleanTabInformation();

    // Update Console
    QString _msg = "CLOSE PROJECT";
    UpdateConsole(_msg);
}

void MainWindow::cleanTabInformation()
{
    ui->clusterIPlineEdit->clear();
    ui->loginClusterlineEdit->clear();
    ui->remoteCPPFilePath->clear();
    ui->remotePatientDataPath->clear();
    ui->patientFilePathLineEdit->clear();
}

//---------------------------------------------------------------------------------------------------------------------

void MainWindow::on_actionExit_triggered()
{
    saveUserSessionData();
    close();
}


void MainWindow::on_actionPreferences_triggered()
{
    PreferencesDialog _preferDialog;

    _preferDialog.setUserData(_userSessionData);
    _preferDialog.loadUserData();
    _preferDialog.exec();

    if(_preferDialog.hasUserAcceptChanges())
        saveUserSessionData();
   /* if (_preferDialog.hasUserAcceptChanges())
        _userSessionData = _preferDialog.*/

}

void MainWindow::on_actionProject_Preferences_triggered()
{
    // TODO
}

void MainWindow::on_actionCluster_Preferences_triggered()
{
    // TODO

}



//------------------------------------------------------------------------------------------------------------------
void MainWindow::enableSaveButton()
{
    ui->actionSave->setEnabled(true);
    ui->actionSave_As->setEnabled(true);
}

void MainWindow::disableSaveButton()
{
    ui->actionSave->setEnabled(false);
    ui->actionSave_As->setEnabled(false);
}
void MainWindow::disableCloseButton()
{
    ui->actionClose_Project->setEnabled(false);
}
void MainWindow::enableCloseButton()
{
    ui->actionClose_Project->setEnabled(true);

}
void MainWindow::enableTabs()
{   
    ui->mainTabWidget->setEnabled(true);
    ui->patientFilePathLineEdit->setEnabled(true);

}

void MainWindow::disableTabs()
{
    ui->mainTabWidget->setEnabled(false);
}


void MainWindow::on_editFileButton_clicked()
{
    ClinicalDataGenerationDialog _dialog;
    _dialog.setProjectData(_projectData);
    _dialog.exec();

    if (_dialog.hasUserAcceptChanges())
    {
        _projectData = _dialog.getProjectData();
        QString _clinicalPath = _projectData.getClinicalPatientFilePath();
        ui->patientFilePathLineEdit->setText(_clinicalPath);

        // Update Console
        QString _msg = "CREATED FILE" + _clinicalPath;
        UpdateConsole(_msg);
    }


}


void MainWindow::on_createScriptsButton_clicked()
{

    ClusterData _clusterData;
    _clusterData.setClusterLoginName(ui->loginClusterlineEdit->text());
    _clusterData.setClusterIP(ui->clusterIPlineEdit->text());
    _clusterData.setRemotePatientDataFolder(ui->remotePatientDataPath->text());
    _clusterData.setRemoteCPPFolder(ui->remoteCPPFilePath->text());

    if (_clusterData.isEmpty())
        return;

    _projectData.setClusterData(_clusterData);

    ScriptParser _parser;
    _parser.setProjectData(_projectData);
    _parser.createLauncherScript();
    _parser.createExecuteScript();

    // Update Console
    QString _msg = "CREATED SCRIPTS in " + _projectData.getProjectPath();
    UpdateConsole(_msg);
}


void MainWindow::on_actionAbout_HeartFEniCs_GUI_triggered()
{
    AboutDialog _dialog;
    _dialog.exec();

}
void  MainWindow::UpdateConsole(const QString text)
{
    // Adding the text to the console
    ui->consoleTextEdit->append(text);
}
