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
#include "scriptparser.h"
#include <QFileInfo>
#include <QDir>
ScriptParser::ScriptParser()
{
}


void ScriptParser::createLauncherScript()
{
    QString _basePath = QFileInfo(_projectData.getProjectPath()).path();
    QString _launcherFilePath = QDir(_basePath ).filePath(LAUNCHER_FILE_NAME);

    QFile _file(_launcherFilePath);

    if (_file.exists())
       _file.remove();
    createContentLauncherFile(&_file,_projectData);
    _file.close();

}

void ScriptParser::createContentLauncherFile(QFile * _file,ProjectData  _projectData)
{

    bool _success = false;
    _success = _file->open(QIODevice::ReadWrite);

    if (_success)
    {
        QTextStream stream( _file );
        createLauncherHeader(&stream,_projectData);
        createLauncherBody(&stream,_projectData);
        createLauncherFooter(&stream);
    }
}

void ScriptParser::createLauncherHeader(QTextStream * stream,ProjectData  _projectData)
{
    ClusterData _clusterInfo = _projectData.getClusterData();

    (* stream) << "#!/bin/bash" << endl;
    (* stream) << "##############################################################" << endl;
    (* stream) << "# LAUNCHER FILE " << endl;
    (* stream) << "# Created by: " << _clusterInfo.getClusterLoginName() << endl;
    (* stream) << "# Project path" << _projectData.getProjectPath() << endl;
    (* stream) << "##############################################################" << endl;

}

void ScriptParser::createLauncherBody(QTextStream * stream,ProjectData  _projectData)
{
    ClusterData _clusterInfo = _projectData.getClusterData();
    QString _executePath = QDir(_projectData.getProjectPath()).filePath("execute.sh"); // TBR


    // Create the Variables
    (* stream) << "##############################################################" << endl;
    (* stream) << "# VARIABLES" << endl;
    (* stream) << "loginName="<<_clusterInfo.getClusterLoginName() << endl;
    (* stream) << "patientDataFolder="<< _projectData.getClinicalDataPath()<< endl;
    (* stream) << "listClinicalFile="<<_projectData.getClinicalPatientFilePath() << endl;
    (* stream) << "ExecuteFile="<<_executePath << endl;
    (* stream) << "clusterIP="<<_clusterInfo.getClusterIP() << endl;
    (* stream) << "remoteDataFolder="<<_clusterInfo.getRemotePatientDataFolder() << endl;
    (* stream) << "remoteCPPFolder="<<_clusterInfo.getRemoteCPPFolder() << endl;

    // Copy all the files Data
    (* stream) << "##############################################################" << endl;
    (* stream) << "# Copy all the files Data" << endl;
    (* stream) << "cd $patientDataFolder; scp -r $loginName@$clusterIP:$remoteDataFolder"<< endl;

    // Copy ListClinical file
    (* stream) << "##############################################################" << endl;
    (* stream) << "# Copy ListClinical file" << endl;
    (* stream) << "scp $listClinicalFile $loginName@$clusterIP:$remoteDataFolder"<< endl;

    // Copy Execute file
    (* stream) << "##############################################################" << endl;
    (* stream) << "# Copy Execute file " << endl;
    (* stream) << "scp $ExecuteFile $loginName@$clusterIP:$remoteCPPFolder"<< endl;

    // Ssh cluster
    (* stream) << "##############################################################" << endl;
    (* stream) << "# Ssh cluster " << endl;
    (* stream) << "ssh $loginName@$clusterIP"<< endl;
}
void ScriptParser::createLauncherFooter(QTextStream * stream)
{
    (* stream) << "##############################################################" << endl;
    (* stream) << "# END LAUNCHER FILE" << endl;
    (* stream) << "##############################################################" << endl;
}




//-------------------------------------

void ScriptParser::createExecuteScript()
{
    QString _basePath = QFileInfo(_projectData.getProjectPath()).path();
    QString _executeFilePath = QDir(_basePath ).filePath(EXECUTE_FILE_NAME);

    QFile _file(_executeFilePath);

    if (_file.exists())
       _file.remove();

     createExecuteLauncherFile(&_file,_projectData);
    _file.close();
}

void ScriptParser::createExecuteLauncherFile(QFile * _file,ProjectData  _projectData)
{
    bool _success = false;
    _success = _file->open(QIODevice::ReadWrite);

    if (_success)
    {
        QTextStream stream( _file );
        createExecuteHeader(&stream,_projectData);
        createExecuteBody(&stream,_projectData);
        createExecuteFooter(&stream);
    }
}

void ScriptParser::createExecuteHeader(QTextStream * stream,ProjectData  _projectData)
{
    ClusterData _clusterInfo = _projectData.getClusterData();

    (* stream) << "#!/bin/bash" << endl;
    (* stream) << "##############################################################" << endl;
    (* stream) << "# EXECUTE FILE " << endl;
    (* stream) << "# Created by: " << _clusterInfo.getClusterLoginName() << endl;
    (* stream) << "# Project path" << _projectData.getProjectPath() << endl;
    (* stream) << "##############################################################" << endl;

}

void ScriptParser::createExecuteBody(QTextStream * stream,ProjectData  _projectData)
{
    ClusterData _clusterInfo = _projectData.getClusterData();

    (* stream) << "remoteDatafolder=" << _clusterInfo.getRemotePatientDataFolder()<< endl;
    (* stream) << "remoteCPPfolder=" <<_clusterInfo.getRemoteCPPFolder()<< endl;

    (* stream) << "c=0" << endl;
    (* stream) << "for line in $(cat listclinical.txt)" << endl;
    (* stream) << "do" << endl;
    (* stream) << " myArray[$c]=\"$line\" #store line" << endl;
    (* stream) << " c=$(($c+1)) #increase counter by 1" << endl;
    (* stream) << "done" << endl;

    (* stream) << "j=0" << endl;
    (* stream) << "k=0" << endl;
    (* stream) << "m=0" << endl;
    (* stream) << "for i in {0..2}" << endl;
    (* stream) << "do:" << endl;

        (* stream) << " k=$(($l+1))" << endl;
        (* stream) << " m=$(($l+2))" << endl;
        (* stream) << " aprun -n 1 ./write heartorg.h heart.h $remoteCPPfolder/${myArray[$l]}/ ${myArray[$m]} ${myArray[$l]} submitorg.h submit.h" << endl;
        (* stream) << " make clean all" << endl;
        (* stream) << " mv heart.h $remoteDatafolder ${myArray[$l]}" << endl;
        (* stream) << " mv heart $remoteDatafolder ${myArray[$l]}" << endl;
        (* stream) << " mv sumbit.h $remoteDatafolder ${myArray[$l]}" << endl;
        (* stream) << " l = $(($l+3))" << endl;

    (* stream) << "done" << endl;


}
void ScriptParser::createExecuteFooter(QTextStream * stream)
{
    (* stream) << "##############################################################" << endl;
    (* stream) << "# END LAUNCHER FILE" << endl;
    (* stream) << "##############################################################" << endl;

}



void ScriptParser::setProjectData(ProjectData data)
{
    _projectData = data;
}
