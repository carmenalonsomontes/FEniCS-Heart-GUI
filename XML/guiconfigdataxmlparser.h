#ifndef GUICONFIGDATAXMLPARSER_H
#define GUICONFIGDATAXMLPARSER_H

#include <QString>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

#include "Data/guiconfigdata.h"

class GuiConfigDataXMLParser
{
public:
    GuiConfigDataXMLParser();
    bool saveUserGUIConfiguration(GUIConfigData * _userData, QString _path);
    void readUserGUIConfiguration(GUIConfigData * _userData, QString _path);


private:
    bool createNewConfigFile(QFile * _file,GUIConfigData * _userData);

    void writeVol4DConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData);
    void writeMatlabConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData);
    void writeAnsaConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData);
    void writeInflowOutflowConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData);
    void writeSimulationConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData);


    void readVol4DConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData);
    void readMatlabConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData);
    void readAnsaConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData);
    void readInflowOutflowConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData);
    void readSimulationConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData);



};

#endif // GUICONFIGDATAXMLPARSER_H
