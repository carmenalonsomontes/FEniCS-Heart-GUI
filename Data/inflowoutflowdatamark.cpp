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
#include "inflowoutflowdatamark.h"

InflowOutflowDataMark::InflowOutflowDataMark()
{
    _scriptPath = "";
}
QString InflowOutflowDataMark::getScriptPath()
{
    return _scriptPath;
}

void InflowOutflowDataMark::setScriptPath(QString path)
{
    _scriptPath = path;

}

void InflowOutflowDataMark::clear()
{
    _scriptPath.clear();
}
