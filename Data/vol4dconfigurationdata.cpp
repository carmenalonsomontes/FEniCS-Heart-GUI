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
#include "vol4dconfigurationdata.h"

Vol4DConfigurationData::Vol4DConfigurationData()
{
    _perlPath = "";
    _perlScriptName = "";
    _perlBinPath = "";
}


QString Vol4DConfigurationData::getPerlPath()
{
    return _perlPath;
}

QString Vol4DConfigurationData::getPerlScriptName()
{
    return _perlScriptName;
}

void Vol4DConfigurationData::setPerlPath(QString data)
{
    _perlPath = data;
}
void Vol4DConfigurationData::setPerlScriptName(QString data)
{
    _perlScriptName = data;
}


QString Vol4DConfigurationData::getPerlBinPath()
{
    return _perlBinPath;
}

void Vol4DConfigurationData::setPerlBinPath(QString path)
{
    _perlBinPath = path;
}


void Vol4DConfigurationData::clear()
{
    _perlPath.clear();
    _perlScriptName.clear();
    _perlBinPath.clear();
}


