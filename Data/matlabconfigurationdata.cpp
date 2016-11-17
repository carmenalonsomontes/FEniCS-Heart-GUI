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
#include "matlabconfigurationdata.h"

MatlabConfigurationData::MatlabConfigurationData()
{
     _matlabPath = "";
     _noDesktop = true;
     _noSplash = true;

}

QString MatlabConfigurationData::getMatlabPath()
{
    return _matlabPath;
}


void MatlabConfigurationData::setMatlabPath(QString path)
{
    _matlabPath = path;
}

QStringList MatlabConfigurationData::getScriptsPath()
{
    return _scriptsPath;
}

void MatlabConfigurationData::setScriptsPath(QStringList list)
{
    _scriptsPath = list;
}

bool MatlabConfigurationData::isNoDesktop()
{
    return _noDesktop;
}

bool MatlabConfigurationData::isNoSplash()
{
    return _noSplash;
}
void MatlabConfigurationData::setNoDesktop(bool val)
{
    _noDesktop = val;
}

void MatlabConfigurationData::setNoSplash(bool val)
{
    _noSplash = val;
}

void MatlabConfigurationData::clear()
{
    _matlabPath.clear();
    _scriptsPath.clear();
    _noDesktop = true;
    _noSplash = true;

}
