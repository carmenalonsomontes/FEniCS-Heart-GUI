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
#include "patientdata.h"

PatientData::PatientData()
{
    _patientName = "";
    _fileImagePath = "";
    _folderPatientPath = "";
    _syastole = 0;
    _dyastole = 0;
}
QString PatientData::getPatientName()
{
    return _patientName;
}

QString PatientData::getFileImagePath()
{
    return _fileImagePath;
}

QString PatientData::getFolderPatientPath()
{
    return _folderPatientPath;
}
int PatientData::getSyastole()
{
    return _syastole;
}
int PatientData::getDyastole()
{
    return _dyastole;
}

void PatientData::setPatientName(QString data)
{
    _patientName = data;
}

void PatientData::setFileImagePath(QString data)
{
    _fileImagePath = data;
}

void PatientData::setFolderPatientPath(QString data)
{
    _folderPatientPath = data;

}
void PatientData::setSyastole(int val)
{
    _syastole = val;
}
void PatientData::setDyastole(int val)
{
    _dyastole = val;
}

void PatientData::clear()
{
    _patientName.clear();
    _fileImagePath.clear();
    _folderPatientPath.clear();
    _syastole = 0;
    _dyastole = 0;

}
