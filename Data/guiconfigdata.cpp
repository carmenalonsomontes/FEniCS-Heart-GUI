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
#include "guiconfigdata.h"

GUIConfigData::GUIConfigData()
{

}

GUIConfigData::~GUIConfigData()
{

}

Vol4DConfigurationData  GUIConfigData::getVol4DData()
{
    return _vol4DData;
}

MatlabConfigurationData   GUIConfigData::getMatlabData()
{
    return _matlabData;
}

AnsaConfigurationData  GUIConfigData::getAnsaData()
{
    return _ansaData;
}

InflowOutflowDataMark GUIConfigData::getInflowOutflowData()
{
    return _inflowOutflowData;
}

SimulationConfigurationData GUIConfigData::getSimulationData()
{
    return _simulationData;
}



void GUIConfigData::setVol4DData(Vol4DConfigurationData  data)
{
    _vol4DData = data;
}

void GUIConfigData::setMatlabData( MatlabConfigurationData data)
{
    _matlabData = data;
}

void GUIConfigData::setAnsaData(AnsaConfigurationData data)
{
    _ansaData = data;
}
void GUIConfigData::setInflowOutflowData(InflowOutflowDataMark data)
{
    _inflowOutflowData = data;
}
void GUIConfigData::setSimulationData(SimulationConfigurationData data)
{
    _simulationData = data;
}

void GUIConfigData::clear()
{
    _vol4DData.clear();
    _matlabData.clear();
    _ansaData.clear();
    _inflowOutflowData.clear();
    _simulationData.clear();

}
