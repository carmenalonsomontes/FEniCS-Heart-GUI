#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QStringList>
#include <QString>

#include "Data/projectdata.h"
#include "Data/guiconfigdata.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_Project_triggered();

    void on_actionOpen_Project_triggered();

    void on_actionRecent_Projects_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionClose_Project_triggered();

    void on_actionExit_triggered();

    void on_actionPreferences_triggered();

    void on_actionProject_Preferences_triggered();

    void on_actionCluster_Preferences_triggered();

    void on_editFileButton_clicked();

    void on_createScriptsButton_clicked();

    void on_actionAbout_HeartFEniCs_GUI_triggered();

private:
    Ui::MainWindow *ui;
    GUIConfigData * _userSessionData;
    QString _cConfigFilename;
    ProjectData _projectData;

    const QString FILE_EXTENSION_PROJECT = ".prj";
    const QString USER_SESSION_DATA_FILENAME = "user-session.xml";

    void enableSaveButton();
    void disableSaveButton();
    void disableCloseButton();
    void enableCloseButton();
    void enableTabs();
    void disableTabs();

    void loadInitialCongiguration();

    void createProject(QString projectPath);
    void saveUserSessionData();
    void saveProjectData();

    void updateUserInformation();
    void updateSimulationTabInformation();
    void cleanTabInformation();
};

#endif // MAINWINDOW_H
