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
#include "projectdataxmlparser.h"

#include "Defines/XmlDefines.h"

ProjectDataXMLParser::ProjectDataXMLParser()
{
}
bool ProjectDataXMLParser::saveProjectData(ProjectData * _projectData, QString _path)
{
    QFile _file(_path);
    bool _success = false;

   if (_file.exists())
       _file.remove();
   _success= createNewProjectFile(&_file,_projectData);
   _file.close();

   return _success;
}


// TODO

bool ProjectDataXMLParser::createNewProjectFile(QFile * _file,ProjectData * _projectData)
{
    bool _success = false;
    _success = _file->open(QIODevice::ReadWrite);
    if (_success)
    {

          QXmlStreamWriter xmlWriter(_file);
          xmlWriter.setAutoFormatting(true);
          xmlWriter.writeStartDocument();

          xmlWriter.writeStartElement(PROJECT_DATA_TAG);
          xmlWriter.writeAttribute(PROJECT_DATA_PATH_ATT,_projectData->getProjectPath());

          writeSimulationConfiguration(&xmlWriter,_projectData);
          writeClusterData(&xmlWriter,_projectData);
          writePatientsData(&xmlWriter,_projectData);

          // Closing the root and the document
          xmlWriter.writeEndElement();
          xmlWriter.writeEndDocument();
          _file->close();
    }

   return _success;

}

void ProjectDataXMLParser::writeSimulationConfiguration(QXmlStreamWriter * xmlWriter, ProjectData * _projectData)
{

    xmlWriter->writeStartElement(SIM_DATA_TAG);

    xmlWriter->writeStartElement(SIM_CLINICAL_DATA_FOLDER_TAG);
    xmlWriter->writeAttribute(SIM_CLINICAL_DATA_FOLDER_PATH_ATT,_projectData->getClinicalDataPath());
    xmlWriter->writeEndElement();

    xmlWriter->writeStartElement(SIM_CLINICAL_FILE_DATA_TAG);
    xmlWriter->writeAttribute(SIM_CLINICAL_FILE_DATA_PATH_ATT,_projectData->getClinicalPatientFilePath());
    xmlWriter->writeEndElement();

    xmlWriter->writeEndElement();


}


void ProjectDataXMLParser::writePatientsData(QXmlStreamWriter * xmlWriter, ProjectData * _projectData)
{
    QList<PatientData> _list = _projectData->getListPatients();
    if (_list.isEmpty())
        return;
    xmlWriter->writeStartElement(PATIENTS_LIST_TAG);
    for (int i=0;i<_list.size();i++)
    {
        PatientData _patient = _list.at(i);
        xmlWriter->writeStartElement(PATIENT_TAG);
        xmlWriter->writeAttribute(PATIENT_NAME_ATT,_patient.getPatientName());
        xmlWriter->writeAttribute(PATIENT_SYASTOLE_ATT,QString::number(_patient.getSyastole()));
        xmlWriter->writeAttribute(PATIENT_DYASTOLE_ATT,QString::number(_patient.getDyastole()));
        xmlWriter->writeAttribute(PATIENT_IMAGE_FILE_PATH_ATT,_patient.getFileImagePath());
        xmlWriter->writeAttribute(PATIENT_BASE_PATH_ATT,_patient.getFolderPatientPath());
        xmlWriter->writeEndElement();
    }
    xmlWriter->writeEndElement();

}
void ProjectDataXMLParser::writeClusterData(QXmlStreamWriter * xmlWriter, ProjectData * _projectData)
{
    ClusterData _clusterData = _projectData->getClusterData();
    xmlWriter->writeStartElement(CLUSTER_DATA_TAG);


    xmlWriter->writeAttribute(CLUSTER_DATA_LOGIN_NAME_ATT,_clusterData.getClusterLoginName());
    xmlWriter->writeAttribute(CLUSTER_DATA_IP_ATT,_clusterData.getClusterIP());
    xmlWriter->writeAttribute(CLUSTER_DATA_REMOTE_DATA_PATH_ATT,_clusterData.getRemotePatientDataFolder());
    xmlWriter->writeAttribute(CLUSTER_DATA_REMOTE_CPP_PATH_ATT,_clusterData.getRemoteCPPFolder());


    xmlWriter->writeEndElement();
}



void ProjectDataXMLParser::readProjectData(ProjectData * _projectData, QString _path)
{
    bool _fileRead = true;
    QFile _file(_path);
    _fileRead = _file.open(QIODevice::ReadOnly | QIODevice::Text);
    int _val;
    if (_fileRead)
    {
        QXmlStreamReader xmlReader(&_file);

        readSimulationConfiguration(&xmlReader,_projectData);
        readPatientsData(&xmlReader,_projectData);

    }
    _file.close();

}

void ProjectDataXMLParser::readSimulationConfiguration( QXmlStreamReader * xmlReader,ProjectData * _projectData)
{
    bool _endItem = false;
    //SimulationConfigurationData _data;

    while ( (!xmlReader->atEnd()) && (!xmlReader->hasError()) && (!_endItem))
     {
         QXmlStreamReader::TokenType token = xmlReader->readNext();
         if (token == QXmlStreamReader::StartDocument) continue;

         // Project Pathj
         if ((token == QXmlStreamReader::StartElement) &&
                 (QString::compare(xmlReader->name().toString(), PROJECT_DATA_TAG) == StrEqual) )
         {
             QXmlStreamAttributes _elementAtt = xmlReader->attributes();
             if (_elementAtt.hasAttribute(PROJECT_DATA_PATH_ATT))
                 _projectData->setProjectPath(_elementAtt.value(PROJECT_DATA_PATH_ATT).toString());

         }
         // Project Pathj
         if ((token == QXmlStreamReader::StartElement) &&
                 (QString::compare(xmlReader->name().toString(), SIM_CLINICAL_DATA_FOLDER_TAG) == StrEqual) )
         {
             QXmlStreamAttributes _elementAtt = xmlReader->attributes();
             if (_elementAtt.hasAttribute(SIM_CLINICAL_DATA_FOLDER_PATH_ATT))
                 _projectData->setClinicalDataPath(_elementAtt.value(SIM_CLINICAL_DATA_FOLDER_PATH_ATT).toString());

         }

         if ((token == QXmlStreamReader::StartElement) &&
                 (QString::compare(xmlReader->name().toString(), SIM_CLINICAL_FILE_DATA_TAG) == StrEqual) )
         {
             QXmlStreamAttributes _elementAtt = xmlReader->attributes();
             if (_elementAtt.hasAttribute(SIM_CLINICAL_FILE_DATA_PATH_ATT))
                 _projectData->setClinicalPatientFilePath(_elementAtt.value(SIM_CLINICAL_FILE_DATA_PATH_ATT).toString());

         }

         if ((token == QXmlStreamReader::StartElement) &&
                  (QString::compare(xmlReader->name().toString(), CLUSTER_DATA_TAG) == StrEqual) )
            readClusterData(xmlReader,  _projectData);

         if ((token == QXmlStreamReader::StartElement) &&
                 (QString::compare(xmlReader->name().toString(), PATIENTS_LIST_TAG) == StrEqual) )
         {
             _endItem = true;
         }
     }

}


void ProjectDataXMLParser::readPatientsData(QXmlStreamReader * xmlReader, ProjectData * _projectData)
{
    bool _endList = false;
    QList<PatientData> _list;

    while ( (!xmlReader->atEnd()) && (!xmlReader->hasError()) && (!_endList))
    {
        QXmlStreamReader::TokenType token = xmlReader->readNext();
        if (token == QXmlStreamReader::StartDocument) continue;

        // Project Pathj
        if ((token == QXmlStreamReader::StartElement) &&
                (QString::compare(xmlReader->name().toString(), PATIENT_TAG) == StrEqual) )
        {
            PatientData _cPatient;

            QXmlStreamAttributes _elementAtt = xmlReader->attributes();
            if (_elementAtt.hasAttribute(PATIENT_NAME_ATT))
               _cPatient.setPatientName(_elementAtt.value(PATIENT_NAME_ATT).toString());

            if (_elementAtt.hasAttribute(PATIENT_SYASTOLE_ATT))
               _cPatient.setSyastole(_elementAtt.value(PATIENT_SYASTOLE_ATT).toInt());

            if (_elementAtt.hasAttribute(PATIENT_DYASTOLE_ATT))
                _cPatient.setDyastole(_elementAtt.value(PATIENT_DYASTOLE_ATT).toInt());

            if (_elementAtt.hasAttribute(PATIENT_IMAGE_FILE_PATH_ATT))
                _cPatient.setFileImagePath(_elementAtt.value(PATIENT_IMAGE_FILE_PATH_ATT).toString());

            if (_elementAtt.hasAttribute(PATIENT_BASE_PATH_ATT))
                _cPatient.setFolderPatientPath(_elementAtt.value(PATIENT_BASE_PATH_ATT).toString());

            _list.append(_cPatient);

        }
        if ((token == QXmlStreamReader::EndElement) &&
                (QString::compare(xmlReader->name().toString(), PATIENTS_LIST_TAG) == StrEqual) )
            _endList = true;

    }
    _projectData->setListPatients(_list);


}



void ProjectDataXMLParser::readClusterData(QXmlStreamReader * xmlReader, ProjectData * _projectData)
{

         QXmlStreamAttributes _elementAtt = xmlReader->attributes();
         ClusterData _cluster;

         if (_elementAtt.hasAttribute(CLUSTER_DATA_LOGIN_NAME_ATT))
             _cluster.setClusterLoginName(_elementAtt.value(CLUSTER_DATA_LOGIN_NAME_ATT).toString());

         if (_elementAtt.hasAttribute(CLUSTER_DATA_IP_ATT))
             _cluster.setClusterIP(_elementAtt.value(CLUSTER_DATA_IP_ATT).toString());

         if (_elementAtt.hasAttribute(CLUSTER_DATA_REMOTE_DATA_PATH_ATT))
             _cluster.setRemotePatientDataFolder(_elementAtt.value(CLUSTER_DATA_REMOTE_DATA_PATH_ATT).toString());

         if (_elementAtt.hasAttribute(CLUSTER_DATA_REMOTE_CPP_PATH_ATT))
             _cluster.setRemoteCPPFolder(_elementAtt.value(CLUSTER_DATA_REMOTE_CPP_PATH_ATT).toString());

         _projectData->setClusterData(_cluster);

}
