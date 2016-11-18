#ifndef SCRIPTPARSER_H
#define SCRIPTPARSER_H

#include <QFile>
#include <QString>
#include <QTextStream>

#include "Data/projectdata.h"
/**
 * @brief This class is intended to develop the logic associated with the generation of two scripts,
 * needed for the simulation process: (1) launcher.sh and (2) execute.sh
 * (1) launcher.sh --> Is intended to define a basic bash script to copy and create the structures needed at the cluster, from the
 * local client computer
 * (2) execute.sh --> this is the script that will be launched in the cluster, to start the simulation.
 *
 */
class ScriptParser
{
public:
    /**
     * @brief Creation of the object
     *
     */
    ScriptParser();

    /**
     * @brief This function creates the launcher.sh file
     *
     */
    void createLauncherScript();
    /**
     * @brief This function creates the execute.sh file
     *
     */
    void createExecuteScript();

    /**
     * @brief This function stores the object ProjectData, that contains all the project information
     *
     * @param data
     */
    void setProjectData(ProjectData data);
private:
    ProjectData _projectData; /**< TODO */
    const QString LAUNCHER_FILE_NAME = "launcher.sh"; /**< TODO */
    const QString EXECUTE_FILE_NAME = "execute.sh"; /**< TODO */

    /**
     * @brief This function creates the content of  the launcher file
     *
     * @param _file
     * @param _projectData
     */
    void createContentLauncherFile(QFile * _file,ProjectData  _projectData);
    /**
     * @brief This function creates the content of  the execute file
     *
     * @param _file
     * @param _projectData
     */
    void createExecuteLauncherFile(QFile * _file,ProjectData  _projectData);

    /**
     * @brief This function creates the header of  the launcher file
     *
     * @param stream
     * @param _projectData
     */
    void createLauncherHeader(QTextStream * stream,ProjectData  _projectData);
    /**
     * @brief This function creates the body of  the launcher file
     *
     * @param stream
     * @param _projectData
     */
    void createLauncherBody(QTextStream * stream,ProjectData  _projectData);
    /**
     * @brief This function creates the footer of  the launcher file
     *
     * @param stream
     */
    void createLauncherFooter(QTextStream * stream);

    /**
     * @brief This function creates the header of  the execute file
     *
     * @param stream
     * @param _projectData
     */
    void createExecuteHeader(QTextStream * stream,ProjectData  _projectData);
    /**
     * @brief This function creates the body of  the execute file
     *
     * @param stream
     * @param _projectData
     */
    void createExecuteBody(QTextStream * stream,ProjectData  _projectData);
    /**
     * @brief This function creates the footer of  the execute file
     *
     * @param stream
     */
    void createExecuteFooter(QTextStream * stream);


};

#endif // SCRIPTPARSER_H
