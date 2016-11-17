#ifndef GUICONFIGDATA_H
#define GUICONFIGDATA_H
#include <QString>

#include "vol4dconfigurationdata.h"
#include "matlabconfigurationdata.h"
#include "ansaconfigurationdata.h"
#include "inflowoutflowdatamark.h"
#include "simulationconfigurationdata.h"

class GUIConfigData
{
public:
    GUIConfigData();
    ~GUIConfigData();

    Vol4DConfigurationData  getVol4DData();
    MatlabConfigurationData   getMatlabData();
    AnsaConfigurationData  getAnsaData();
    InflowOutflowDataMark getInflowOutflowData();
    SimulationConfigurationData getSimulationData();



    void setVol4DData(Vol4DConfigurationData  data);
    void setMatlabData( MatlabConfigurationData  data);
    void setAnsaData(AnsaConfigurationData  data);
    void setInflowOutflowData(InflowOutflowDataMark data);
    void setSimulationData(SimulationConfigurationData data);

    void clear();

private:
    Vol4DConfigurationData  _vol4DData;
    MatlabConfigurationData   _matlabData;
    AnsaConfigurationData  _ansaData;
    InflowOutflowDataMark _inflowOutflowData;
    SimulationConfigurationData _simulationData;


};

#endif // GUICONFIGDATA_H
