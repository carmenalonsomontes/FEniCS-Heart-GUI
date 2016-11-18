#ifndef SIMULATIONCONFIGURATIONDATA_H
#define SIMULATIONCONFIGURATIONDATA_H
#include <QString>

/**
 * @brief This class is intended to store the information relative to the simulaton pathss
 *
 */
class SimulationConfigurationData
{
public:
    /**
     * @brief Creation of the object
     *
     */
    SimulationConfigurationData();
    /**
     * @brief Get the path to the scripts
     *
     * @return QString
     */
    QString getScriptPath();
    /**
     * @brief Set the path to the scripts
     *
     * @param path
     */
    void setScriptPath(QString path);

    /**
     * @brief clears the information stored in the object
     *
     */
    void clear();

private:
    QString _scriptPath; /**< TODO */
};

#endif // SIMULATIONCONFIGURATIONDATA_H
