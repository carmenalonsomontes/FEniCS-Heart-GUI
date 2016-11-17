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
#include "guiconfigdataxmlparser.h"
#include <QFileInfo>
#include <QDir>


#include "Defines/XmlDefines.h"

#include "Data/ansaconfigurationdata.h"
#include "Data/matlabconfigurationdata.h"
#include "Data/vol4dconfigurationdata.h"
#include "Data/inflowoutflowdatamark.h"
#include "Data/simulationconfigurationdata.h"




GuiConfigDataXMLParser::GuiConfigDataXMLParser()
{
}


bool GuiConfigDataXMLParser::saveUserGUIConfiguration(GUIConfigData * _userData, QString _path)
{
    QFile _file(_path);
    bool _success = false;

   if (_file.exists())
       _file.remove();
   _success= createNewConfigFile(&_file,_userData);
   _file.close();

   return _success;
}


bool GuiConfigDataXMLParser::createNewConfigFile(QFile * _file,GUIConfigData * _userData)
{
    bool _success = false;
    _success = _file->open(QIODevice::ReadWrite);
    if (_success)
    {

          QXmlStreamWriter xmlWriter(_file);
          xmlWriter.setAutoFormatting(true);
          xmlWriter.writeStartDocument();

          xmlWriter.writeStartElement(USER_GUI_TAG);

          writeVol4DConfiguration(&xmlWriter,_userData);
          writeMatlabConfiguration(&xmlWriter,_userData);
          writeAnsaConfiguration(&xmlWriter,_userData);
          writeInflowOutflowConfiguration(&xmlWriter,_userData);
          writeSimulationConfiguration(&xmlWriter,_userData);


          // Closing the root and the document
          xmlWriter.writeEndElement();
          xmlWriter.writeEndDocument();
          _file->close();
    }

   return _success;


}


void GuiConfigDataXMLParser::writeVol4DConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData)
{
    xmlWriter->writeStartElement(USER_GUI_VOL4D_CONFIG_TAG);

    // MESH TOOL PATH
    xmlWriter->writeStartElement(USER_GUI_VOL4D_PERL_CONFIG_TAG);
    Vol4DConfigurationData  _data = _userData->getVol4DData();

    xmlWriter->writeAttribute(USER_GUI_VOL4D_PERL_BIN_CONFIG_PATH_ATT,_data.getPerlBinPath());

    xmlWriter->writeAttribute(USER_GUI_VOL4D_PERL_CONFIG_PATH_ATT,_data.getPerlPath());

    xmlWriter->writeAttribute(USER_GUI_VOL4D_PERL_CONFIG_NAME_ATT,_data.getPerlScriptName());
    xmlWriter->writeEndElement();


    xmlWriter->writeEndElement();


}

void GuiConfigDataXMLParser::writeMatlabConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData)
{
    MatlabConfigurationData  _data = _userData->getMatlabData();
    xmlWriter->writeStartElement(USER_GUI_MATLAB_CONFIG_TAG);
    xmlWriter->writeAttribute(USER_GUI_MATLAB_CONFIG_PATH_ATT,_data.getMatlabPath());

    if (_data.isNoDesktop())
        xmlWriter->writeAttribute(USER_GUI_MATLAB_NODESKTOP_CONFIG_ATT,"TRUE");
    else
        xmlWriter->writeAttribute(USER_GUI_MATLAB_NODESKTOP_CONFIG_ATT,"FALSE");

    if (_data.isNoSplash())
        xmlWriter->writeAttribute(USER_GUI_MATLAB_NOSPLASH_CONFIG_ATT,"TRUE");
    else
        xmlWriter->writeAttribute(USER_GUI_MATLAB_NOSPLASH_CONFIG_ATT,"FALSE");

    QStringList _scriptList =_data.getScriptsPath();
    int _noScripts = _scriptList.size();
    for (int i =0; i< _noScripts; i++)
    {

        QString _script = _scriptList.at(i);

        xmlWriter->writeStartElement(USER_GUI_MATLAB_SCRIPT_CONFIG_TAG);
        xmlWriter->writeAttribute(USER_GUI_MATLAB_SCRIPT_CONFIG_PATH_ATT,_script);
        xmlWriter->writeAttribute(USER_GUI_MATLAB_SCRIPT_CONFIG_NAME_ATT,QFileInfo(_script).baseName());
        xmlWriter->writeEndElement();

     }


    xmlWriter->writeEndElement();


}

void GuiConfigDataXMLParser::writeAnsaConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData)
{

    AnsaConfigurationData  _data = _userData->getAnsaData();
    xmlWriter->writeStartElement(USER_GUI_ANSA_CONFIG_TAG);
    xmlWriter->writeAttribute(USER_GUI_ANSA_CONFIG_PATH_ATT,_data.getAnsaPath());
    xmlWriter->writeEndElement();
}

void  GuiConfigDataXMLParser::writeInflowOutflowConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData)
{
    InflowOutflowDataMark  _data = _userData->getInflowOutflowData();
    xmlWriter->writeStartElement(USER_GUI_IOFlow_CONFIG_TAG);
    xmlWriter->writeAttribute(USER_GUI_IOFlow_CONFIG_PATH_ATT,_data.getScriptPath());
    xmlWriter->writeEndElement();

}

void GuiConfigDataXMLParser::writeSimulationConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData)
{
    SimulationConfigurationData  _data = _userData->getSimulationData();
    xmlWriter->writeStartElement(USER_GUI_SIM_CONFIG_TAG);
    xmlWriter->writeAttribute(USER_GUI_SIM_CONFIG_PATH_ATT,_data.getScriptPath());
    xmlWriter->writeEndElement();
}




void GuiConfigDataXMLParser::readUserGUIConfiguration(GUIConfigData * _userData, QString _path)
{
    bool _fileRead = true;
    QFile _file(_path);
    _fileRead = _file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (_fileRead)
    {
        QXmlStreamReader xmlReader(&_file);
        readVol4DConfiguration(&xmlReader,_userData);
        readMatlabConfiguration(&xmlReader,_userData);
        readAnsaConfiguration(&xmlReader,_userData);
        readInflowOutflowConfiguration(&xmlReader,_userData);
        readSimulationConfiguration(&xmlReader,_userData);
    }
    _file.close();
}

void GuiConfigDataXMLParser::readVol4DConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData)
{
   bool _endItem = false;
   Vol4DConfigurationData  _data;
    while ( (!xmlReader->atEnd()) && (!xmlReader->hasError()) && (!_endItem))
    {
        QXmlStreamReader::TokenType token = xmlReader->readNext();
        if (token == QXmlStreamReader::StartDocument) continue;

        // VOL4D
        if ((token == QXmlStreamReader::StartElement) &&
                (QString::compare(xmlReader->name().toString(), USER_GUI_VOL4D_PERL_CONFIG_TAG) == StrEqual) )
        {
                QXmlStreamAttributes _elementAtt = xmlReader->attributes();

                if (_elementAtt.hasAttribute(USER_GUI_VOL4D_PERL_BIN_CONFIG_PATH_ATT))
                    _data.setPerlBinPath(_elementAtt.value(USER_GUI_VOL4D_PERL_BIN_CONFIG_PATH_ATT).toString());

                if (_elementAtt.hasAttribute(USER_GUI_VOL4D_PERL_CONFIG_PATH_ATT))
                    _data.setPerlPath(_elementAtt.value(USER_GUI_VOL4D_PERL_CONFIG_PATH_ATT).toString());

                if (_elementAtt.hasAttribute(USER_GUI_VOL4D_PERL_CONFIG_NAME_ATT))
                    _data.setPerlScriptName(_elementAtt.value(USER_GUI_VOL4D_PERL_CONFIG_NAME_ATT).toString());

                _endItem = true;
        }
    }
    _userData->setVol4DData(_data);

}


void GuiConfigDataXMLParser::readMatlabConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData)
{
    bool _endItem = false;
    MatlabConfigurationData  _data;
    QStringList _scriptList;
     while ( (!xmlReader->atEnd()) && (!xmlReader->hasError()) && (!_endItem))
     {
         QXmlStreamReader::TokenType token = xmlReader->readNext();
         if (token == QXmlStreamReader::StartDocument) continue;

         // MAtlab
         if ((token == QXmlStreamReader::StartElement) &&
                 (QString::compare(xmlReader->name().toString(), USER_GUI_MATLAB_CONFIG_TAG) == StrEqual) )
         {
                 QXmlStreamAttributes _elementAtt = xmlReader->attributes();
                 if (_elementAtt.hasAttribute(USER_GUI_MATLAB_CONFIG_PATH_ATT))
                     _data.setMatlabPath(_elementAtt.value(USER_GUI_MATLAB_CONFIG_PATH_ATT).toString());
                 if (_elementAtt.hasAttribute(USER_GUI_MATLAB_NODESKTOP_CONFIG_ATT))
                 {
                     if (QString::compare(_elementAtt.value(USER_GUI_MATLAB_NODESKTOP_CONFIG_ATT).toString(),"TRUE") == 0)
                        _data.setNoDesktop(true);
                    else
                        _data.setNoDesktop(false);
                 }
                 if (_elementAtt.hasAttribute(USER_GUI_MATLAB_NOSPLASH_CONFIG_ATT))
                     if (QString::compare(_elementAtt.value(USER_GUI_MATLAB_NOSPLASH_CONFIG_ATT).toString(),"TRUE") == 0)
                        _data.setNoSplash(true);
                    else
                        _data.setNoSplash(false);

         }

         // Scripts
         if ((token == QXmlStreamReader::StartElement) &&
                 (QString::compare(xmlReader->name().toString(), USER_GUI_MATLAB_SCRIPT_CONFIG_TAG) == StrEqual) )
         {
                 QXmlStreamAttributes _elementAtt = xmlReader->attributes();
                 QString _path = "";
                 QString _nameScript = "";
                 if (_elementAtt.hasAttribute(USER_GUI_MATLAB_SCRIPT_CONFIG_PATH_ATT))
                    _path = _elementAtt.value(USER_GUI_MATLAB_SCRIPT_CONFIG_PATH_ATT).toString();

                 if (_elementAtt.hasAttribute(USER_GUI_MATLAB_SCRIPT_CONFIG_NAME_ATT))
                    _nameScript = _elementAtt.value(USER_GUI_MATLAB_SCRIPT_CONFIG_NAME_ATT).toString();

                 QString _scriptFilePath = QDir(_path).filePath(_nameScript);
                 _scriptList.append(_scriptFilePath);
         }
         if ((token == QXmlStreamReader::EndElement) &&
                 (QString::compare(xmlReader->name().toString(), USER_GUI_MATLAB_CONFIG_TAG) == StrEqual) )
             _endItem = true;
     }

     _data.setScriptsPath(_scriptList);
    _userData->setMatlabData(_data);

}

void GuiConfigDataXMLParser::readAnsaConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData)
{
    bool _endItem = false;
    AnsaConfigurationData _data;

    while ( (!xmlReader->atEnd()) && (!xmlReader->hasError()) && (!_endItem))
     {
         QXmlStreamReader::TokenType token = xmlReader->readNext();
         if (token == QXmlStreamReader::StartDocument) continue;

         // Ansa
         if ((token == QXmlStreamReader::StartElement) &&
                 (QString::compare(xmlReader->name().toString(), USER_GUI_ANSA_CONFIG_TAG) == StrEqual) )
         {
             QXmlStreamAttributes _elementAtt = xmlReader->attributes();
             if (_elementAtt.hasAttribute(USER_GUI_ANSA_CONFIG_PATH_ATT))
                 _data.setAnsaPath(_elementAtt.value(USER_GUI_ANSA_CONFIG_PATH_ATT).toString());

             _endItem = true;
         }
     }
     _userData->setAnsaData(_data);

}



void  GuiConfigDataXMLParser::readInflowOutflowConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData)
{
    bool _endItem = false;
    InflowOutflowDataMark _data;

    while ( (!xmlReader->atEnd()) && (!xmlReader->hasError()) && (!_endItem))
     {
         QXmlStreamReader::TokenType token = xmlReader->readNext();
         if (token == QXmlStreamReader::StartDocument) continue;

         // Ansa
         if ((token == QXmlStreamReader::StartElement) &&
                 (QString::compare(xmlReader->name().toString(), USER_GUI_IOFlow_CONFIG_TAG) == StrEqual) )
         {
             QXmlStreamAttributes _elementAtt = xmlReader->attributes();
             if (_elementAtt.hasAttribute(USER_GUI_IOFlow_CONFIG_PATH_ATT))
                 _data.setScriptPath(_elementAtt.value(USER_GUI_IOFlow_CONFIG_PATH_ATT).toString());

             _endItem = true;
         }
     }
     _userData->setInflowOutflowData(_data);

}


void GuiConfigDataXMLParser::readSimulationConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData)
{
    bool _endItem = false;
    SimulationConfigurationData _data;

    while ( (!xmlReader->atEnd()) && (!xmlReader->hasError()) && (!_endItem))
     {
         QXmlStreamReader::TokenType token = xmlReader->readNext();
         if (token == QXmlStreamReader::StartDocument) continue;

         // Sim
         if ((token == QXmlStreamReader::StartElement) &&
                 (QString::compare(xmlReader->name().toString(), USER_GUI_SIM_CONFIG_TAG) == StrEqual) )
         {
             QXmlStreamAttributes _elementAtt = xmlReader->attributes();
             if (_elementAtt.hasAttribute(USER_GUI_SIM_CONFIG_PATH_ATT))
                 _data.setScriptPath(_elementAtt.value(USER_GUI_SIM_CONFIG_PATH_ATT).toString());

             _endItem = true;
         }
     }
     _userData->setSimulationData(_data);
}



