#ifndef MATLABCONFIGURATIONDATA_H
#define MATLABCONFIGURATIONDATA_H

#include <QString>
#include <QStringList>



/**
 * @brief This class is intended to store the information related with the step related to Matlab
 *
 */
class MatlabConfigurationData
{
public:
    /**
     * @brief Creation of the object
     *
     */
    MatlabConfigurationData();

    /**
     * @brief Get the path to the Matlab tool executable
     *
     * @return QString
     */
    QString getMatlabPath();
    /**
     * @brief Set the path to the Matlab tool executable
     *
     * @param path
     */
    void setMatlabPath(QString path);

    /**
     * @brief Get the path to the matlab scripts used in the different steps
     *
     * @return QStringList
     */
    QStringList getScriptsPath();
    /**
     * @brief Set the path to the matlab scripts used in the different steps
     *
     * @param list
     */
    void setScriptsPath(QStringList list);

    /**
     * @brief Returns true  if no desktop option is required
     *
     * @return bool
     */
    bool isNoDesktop();
    /**
     * @brief Returns true if no Splash option is required
     *
     * @return bool
     */
    bool isNoSplash();

    /**
     * @brief Set if no desktop option is required
     *
     * @param val
     */
    void setNoDesktop(bool val);
    /**
     * @brief Set if no Splash option is required
     *
     * @param val
     */
    void setNoSplash(bool val);



    /**
     * @brief clears the information stored in the object
     *
     */
    void clear();

private:
    QString _matlabPath; /**< TODO */
    QStringList _scriptsPath; /**< TODO */

    bool _noDesktop; /**< TODO */
    bool _noSplash; /**< TODO */


};

#endif // MATLABCONFIGURATIONDATA_H
