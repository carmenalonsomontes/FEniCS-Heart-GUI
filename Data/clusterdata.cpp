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
#include "clusterdata.h"

ClusterData::ClusterData()
{
}


QString ClusterData::getClusterLoginName()
{
    return _clusterLoginName;
}

QString ClusterData::getClusterIP()
{
    return _clusterIP;
}

QString ClusterData::getRemotePatientDataFolder()
{
    return _remotePatientDataFolder;
}

QString ClusterData::getRemoteCPPFolder()
{
    return _remoteCPPFolder;
}


void ClusterData::setClusterLoginName(QString name)
{
    _clusterLoginName = name;
}

void ClusterData::setClusterIP(QString ip)
{
    _clusterIP = ip;
}

void ClusterData::setRemotePatientDataFolder(QString folder)
{
    _remotePatientDataFolder = folder;
}

void ClusterData::setRemoteCPPFolder(QString folder)
{
    _remoteCPPFolder = folder;
}

void ClusterData::clear()
{
    _clusterLoginName.clear();
    _clusterIP.clear();
    _remotePatientDataFolder.clear();
    _remoteCPPFolder.clear();
}

bool ClusterData::isEmpty()
{
    if ((_clusterIP.isEmpty()) || (_clusterLoginName.isEmpty())
            || (_remotePatientDataFolder.isEmpty()) || (_remoteCPPFolder.isEmpty()))
        return true;
    return false;

}
