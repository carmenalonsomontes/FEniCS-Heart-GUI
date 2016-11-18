#ifndef ANSACONFIGURATIONDATA_H
#define ANSACONFIGURATIONDATA_H

#include <QString>
/**
 * @brief This class is intended to store the configuration information needed for the ANSA step
 * In this case, the path to the official ANSA tool is needed
 *
 */
class AnsaConfigurationData
{
public:
    /**
     * @brief Creation of the object
     *
     */
    AnsaConfigurationData();

    /**
     * @brief Returns the ANSA tool path
     *
     * @return QString
     */
    QString getAnsaPath();
    /**
     * @brief Sets the ANSA tool path
     *
     * @param path
     */
    void setAnsaPath(QString path);
    /**
     * @brief clears the information stored in the object
     *
     */
    void clear();

private:
    QString _ansaPath; /**< TODO */

};

#endif // ANSACONFIGURATIONDATA_H
