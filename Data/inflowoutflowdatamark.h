#ifndef INFLOWOUTFLOWDATAMARK_H
#define INFLOWOUTFLOWDATAMARK_H
#include <QString>
/**
 * @brief This class manage the informatino stored in the Inflow/Outflow step
 *
 */
class InflowOutflowDataMark
{
public:
    /**
     * @brief Creation of the object
     *
     */
    InflowOutflowDataMark();

    /**
     * @brief get the path to the scripts
     *
     * @return QString
     */
    QString getScriptPath();
    /**
     * @brief SEt the path to the scripts
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

#endif // INFLOWOUTFLOWDATAMARK_H
