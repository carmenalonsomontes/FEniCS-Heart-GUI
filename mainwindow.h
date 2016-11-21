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

/**
 * @brief This class is intended to define the logic for the Main window dialog
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Creation of the object
     *
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~MainWindow();

private slots:
    /**
     * @brief Logic for New project
     *
     */
    void on_actionNew_Project_triggered();

    /**
     * @brief Logic for Open project
     *
     */
    void on_actionOpen_Project_triggered();

    /**
     * @brief Logic for REcent projects // TODO
     *
     */
    void on_actionRecent_Projects_triggered();

    /**
     * @brief Logic for Save project
     *
     */
    void on_actionSave_triggered();

    /**
     * @brief Logic for Save as project
     *
     */
    void on_actionSave_As_triggered();

    /**
     * @brief Logic for Close project
     *
     */
    void on_actionClose_Project_triggered();

    /**
     * @brief Logic for Exit
     *
     */
    void on_actionExit_triggered();

    /**
     * @brief Logic for Preference3s
     *
     */
    void on_actionPreferences_triggered();

    /**
     * @brief Logic for project Preferences
     *
     */
    void on_actionProject_Preferences_triggered();

    /**
     * @brief Logic for cluster preferences
     *
     */
    void on_actionCluster_Preferences_triggered();

    /**
     * @brief Logic for edit file for the creation of the listClinical.txt
     *
     */
    void on_editFileButton_clicked();

    /**
     * @brief Logic for create scripts in the simulation
     *
     */
    void on_createScriptsButton_clicked();

    /**
     * @brief Logic for About
     *
     */
    void on_actionAbout_HeartFEniCs_GUI_triggered();

    void UpdateConsole(const QString text);
private:
    Ui::MainWindow *ui; /**< TODO */
    GUIConfigData * _userSessionData; /**< TODO */
    QString _cConfigFilename; /**< TODO */
    ProjectData _projectData; /**< TODO */

    const QString FILE_EXTENSION_PROJECT = ".prj"; /**< TODO */
    const QString USER_SESSION_DATA_FILENAME = "user-session.xml"; /**< TODO */

    /**
     * @brief Enables Save Button
     *
     */
    void enableSaveButton();
    /**
     * @brief Disables Save Button
     *
     */
    void disableSaveButton();
    /**
     * @brief Disables Close Button
     *
     */
    void disableCloseButton();
    /**
     * @brief Enable Close Button
     *
     */
    void enableCloseButton();
    /**
     * @brief Enable the Tab widget
     *
     */
    void enableTabs();
    /**
     * @brief Disables the Tab widget
     *
     */
    void disableTabs();

    /**
     * @brief Load Initial User configuration data
     *
     */
    void loadInitialCongiguration();

    /**
     * @brief Create Project
     *
     * @param projectPath
     */
    void createProject(QString projectPath);
    /**
     * @brief Save user configuration
     *
     */
    void saveUserSessionData();
    /**
     * @brief Save project data
     *
     */
    void saveProjectData();

    /**
     * @brief update user configuration
     *
     */
    void updateUserInformation();
    /**
     * @brief Update project simulation information in the tab
     *
     */
    void updateSimulationTabInformation();
    /**
     * @brief Clear Tab information
     *
     */
    void cleanTabInformation();
};

#endif // MAINWINDOW_H
