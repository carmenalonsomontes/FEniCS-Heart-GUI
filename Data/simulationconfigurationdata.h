#ifndef SIMULATIONCONFIGURATIONDATA_H
#define SIMULATIONCONFIGURATIONDATA_H
#include <QString>

class SimulationConfigurationData
{
public:
    SimulationConfigurationData();
    QString getScriptPath();
    void setScriptPath(QString path);

    void clear();

private:
    QString _scriptPath;
};

#endif // SIMULATIONCONFIGURATIONDATA_H
