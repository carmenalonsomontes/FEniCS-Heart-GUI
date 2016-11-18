#ifndef GUICONFIGDATAXMLPARSER_H
#define GUICONFIGDATAXMLPARSER_H

#include <QString>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

#include "Data/guiconfigdata.h"

/**
 * @brief This class is intended to read/write the configuration information from the XML files
 * in particular, for the graphical interface configuration
 *
 */
class GuiConfigDataXMLParser
{
public:
    /**
     * @brief Creation of the object
     *
     */
    GuiConfigDataXMLParser();
    /**
     * @brief This function saves the information of the user
     *
     * @param _userData
     * @param _path
     * @return bool
     */
    bool saveUserGUIConfiguration(GUIConfigData * _userData, QString _path);
    /**
     * @brief This function reads the information of the user
     *
     * @param _userData
     * @param _path
     */
    void readUserGUIConfiguration(GUIConfigData * _userData, QString _path);


private:
    /**
     * @brief This function creates a new file to save the information of the user
     *
     * @param _file
     * @param _userData
     * @return bool
     */
    bool createNewConfigFile(QFile * _file,GUIConfigData * _userData);

    /**
     * @brief This function saves the information of the user related with the Vol4D step
     *
     * @param xmlWriter
     * @param _userData
     */
    void writeVol4DConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData);
    /**
     * @brief This function saves the information of the user related with the Matlab step
     *
     * @param xmlWriter
     * @param _userData
     */
    void writeMatlabConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData);
    /**
     * @brief This function saves the information of the user related with the ANSA step
     *
     * @param xmlWriter
     * @param _userData
     */
    void writeAnsaConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData);
    /**
     * @brief This function saves the information of the user related with the Inlfow/Outflow stepv
     *
     * @param xmlWriter
     * @param _userData
     */
    void writeInflowOutflowConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData);
    /**
     * @brief This function saves the information of the user related with the Simulation step
     *
     * @param xmlWriter
     * @param _userData
     */
    void writeSimulationConfiguration(QXmlStreamWriter * xmlWriter, GUIConfigData * _userData);


    /**
     * @brief  This function reads the information of the user related with the Vol4D step
     *
     * @param xmlReader
     * @param _userData
     */
    void readVol4DConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData);
    /**
     * @brief This function reads the information of the user related with the Matlab step
     *
     * @param xmlReader
     * @param _userData
     */
    void readMatlabConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData);
    /**
     * @brief This function reads the information of the user related with the ANSA step
     *
     * @param xmlReader
     * @param _userData
     */
    void readAnsaConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData);
    /**
     * @brief This function reads the information of the user related with the Inflow/outflow step
     *
     * @param xmlReader
     * @param _userData
     */
    void readInflowOutflowConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData);
    /**
     * @brief This function reads the information of the user
     *
     * @param xmlReader
     * @param _userData
     */
    void readSimulationConfiguration( QXmlStreamReader * xmlReader,GUIConfigData * _userData);



};

#endif // GUICONFIGDATAXMLPARSER_H
