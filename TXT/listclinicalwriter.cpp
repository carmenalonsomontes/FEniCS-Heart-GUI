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
#include "listclinicalwriter.h"

ListClinicalWriter::ListClinicalWriter()
{
}


bool ListClinicalWriter::saveProjectData(ProjectData * _projectData, QString _path)
{
    QFile _file(_path);
    bool _success = false;

   if (_file.exists())
       _file.remove();
   _success= createListClinicalFile(&_file,_projectData);
   _file.close();
   return _success;
}


bool ListClinicalWriter::createListClinicalFile(QFile * _file,ProjectData * _projectData)
{
    bool _success = false;
    _success = _file->open(QIODevice::ReadWrite);
    if (_success)
    {

          QTextStream stream(_file);

          QList<PatientData> _list = _projectData->getListPatients();
          for (int i = 0; i< _list.size();i++)
          {
              PatientData _patient = _list.at(i);
              stream << _patient.getPatientName() << "\t" << QString::number(_patient.getSyastole()) <<
                         "\t" <<  QString::number(_patient.getDyastole()) << endl;

          }

         _file->close();
    }

   return _success;

}
