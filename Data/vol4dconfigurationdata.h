#ifndef VOL4DCONFIGURATIONDATA_H
#define VOL4DCONFIGURATIONDATA_H

#include <QString>


/**
 * @brief This class is intended to store the information (paths) of the tools used for the Vol 4d generation
 *
 */
class Vol4DConfigurationData
{
public:
    /**
     * @brief Creation of the object
     *
     */
    Vol4DConfigurationData();


    /**
     * @brief Get the Perl path where the files are stored
     *
     * @return QString
     */
    QString getPerlPath();
    /**
     * @brief Get the perl script name
     *
     * @return QString
     */
    QString getPerlScriptName();

    /**
     * @brief Set the Perl path where the files are stored
     *
     * @param data
     */
    void setPerlPath(QString data);
    /**
     * @brief Set the perl script name
     *
     * @param data
     */
    void setPerlScriptName(QString data);

    /**
     * @brief Get the path of the Perl binary
     *
     * @return QString
     */
    QString getPerlBinPath();

    /**
     * @brief Set the path of the Perl binary
     *
     * @param path
     */
    void setPerlBinPath(QString path);

    /**
     * @brief clears the information stored in the object
     *
     */
    void clear();

private:
    QString _perlBinPath; /**< TODO */
    QString _perlPath; /**< TODO */
    QString _perlScriptName; /**< TODO */

};

#endif // VOL4DCONFIGURATIONDATA_H
