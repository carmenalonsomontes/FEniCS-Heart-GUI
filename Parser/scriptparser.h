#ifndef SCRIPTPARSER_H
#define SCRIPTPARSER_H

#include <QFile>
#include <QString>
#include <QTextStream>

#include "Data/projectdata.h"
class ScriptParser
{
public:
    ScriptParser();

    void createLauncherScript();
    void createExecuteScript();

    void setProjectData(ProjectData data);
private:
    ProjectData _projectData;
    const QString LAUNCHER_FILE_NAME = "launcher.sh";
    const QString EXECUTE_FILE_NAME = "execute.sh";

    void createContentLauncherFile(QFile * _file,ProjectData  _projectData);
    void createExecuteLauncherFile(QFile * _file,ProjectData  _projectData);

    void createLauncherHeader(QTextStream * stream,ProjectData  _projectData);
    void createLauncherBody(QTextStream * stream,ProjectData  _projectData);
    void createLauncherFooter(QTextStream * stream);

    void createExecuteHeader(QTextStream * stream,ProjectData  _projectData);
    void createExecuteBody(QTextStream * stream,ProjectData  _projectData);
    void createExecuteFooter(QTextStream * stream);


};

#endif // SCRIPTPARSER_H
