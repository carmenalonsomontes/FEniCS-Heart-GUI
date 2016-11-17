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
#include "projectdata.h"

ProjectData::ProjectData()
{
    _clinicalDataPath = "";
    _clinicalPatientFilePath = "";
    _projectPath = "";
}

QString ProjectData::getClinicalDataPath()
{
    return _clinicalDataPath;
}

QString ProjectData::getClinicalPatientFilePath()
{
    return _clinicalPatientFilePath;
}

void ProjectData::setClinicalDataPath(QString data)
{
    _clinicalDataPath = data;
}
void ProjectData::setClinicalPatientFilePath(QString data)
{
    _clinicalPatientFilePath = data;
}

QString ProjectData::getProjectPath()
{
    return _projectPath;
}

void ProjectData::setProjectPath(QString data)
{
    _projectPath = data;
}

QList <PatientData> ProjectData::getListPatients()
{
    return _listPatients;
}

void ProjectData::setListPatients(QList <PatientData>  list)
{
    _listPatients = list;
}

ClusterData ProjectData::getClusterData()
{
    return _clusterData;
}

void  ProjectData::setClusterData(ClusterData data)
{
    _clusterData = data;
}

void ProjectData::clear()
{
    _clinicalDataPath.clear();
    _clinicalPatientFilePath.clear();
    _projectPath.clear();
    _listPatients.clear();
    _clusterData.clear();
}
