#ifndef GUICONFIGDATA_H
#define GUICONFIGDATA_H
#include <QString>

#include "vol4dconfigurationdata.h"
#include "matlabconfigurationdata.h"
#include "ansaconfigurationdata.h"
#include "inflowoutflowdatamark.h"
#include "simulationconfigurationdata.h"

/**
 * @brief This class is intended to store the information relative to the paths
 * of the main tools used by the user.
 *
 */
class GUIConfigData
{
public:
    /**
     * @brief  Creation of the object
     *
     */
    GUIConfigData();
    /**
     * @brief
     *
     */
    ~GUIConfigData();

    /**
     * @brief Get the object data containing the information to set up the Vol4D Configuration Data
     *
     * @return Vol4DConfigurationData
     */
    Vol4DConfigurationData  getVol4DData();
    /**
     * @brief Get the object data containing the information to set up the Matlab configuration
     *
     * @return MatlabConfigurationData
     */
    MatlabConfigurationData   getMatlabData();
    /**
     * @brief Get the object data containing the information to set up the ANSA configuration
     *
     * @return AnsaConfigurationData
     */
    AnsaConfigurationData  getAnsaData();
    /**
     * @brief Get the object data containing the information to set up the Inflow/Outflow configuration
     *
     * @return InflowOutflowDataMark
     */
    InflowOutflowDataMark getInflowOutflowData();
    /**
     * @brief Get the object data containing the information to set up the Simulatioon configuration
     *
     * @return SimulationConfigurationData
     */
    SimulationConfigurationData getSimulationData();



    /**
     * @brief Set the object data containing the information to set up the Vol4D Configuration Data
     *
     * @param data
     */
    void setVol4DData(Vol4DConfigurationData  data);
    /**
     * @brief Set the object data containing the information to set up the Matlab configuration
     *
     * @param data
     */
    void setMatlabData( MatlabConfigurationData  data);
    /**
     * @brief Set the object data containing the information to set up the ANSA configuration
     *
     * @param data
     */
    void setAnsaData(AnsaConfigurationData  data);
    /**
     * @brief Set the object data containing the information to set up the Inflow/Outflow configuration
     *
     * @param data
     */
    void setInflowOutflowData(InflowOutflowDataMark data);
    /**
     * @brief Set the object data containing the information to set up the Simulatioon configuration
     *
     * @param data
     */
    void setSimulationData(SimulationConfigurationData data);

    /**
     * @brief clears the information stored in the object
     *
     */
    void clear();

private:
    Vol4DConfigurationData  _vol4DData; /**< TODO */
    MatlabConfigurationData   _matlabData; /**< TODO */
    AnsaConfigurationData  _ansaData; /**< TODO */
    InflowOutflowDataMark _inflowOutflowData; /**< TODO */
    SimulationConfigurationData _simulationData; /**< TODO */


};

#endif // GUICONFIGDATA_H
