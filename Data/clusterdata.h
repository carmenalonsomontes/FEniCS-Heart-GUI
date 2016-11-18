#ifndef CLUSTERDATA_H
#define CLUSTERDATA_H
#include <QString>

/**
 * @brief This class stores the information rellated with the cluster (cluster name, username in the cluster, etc)
 * For the last step (simulation in the cluster)
 *
 */
class ClusterData
{
public:
    /**
     * @brief  Creation of the object
     *
     */
    ClusterData();

    /**
     * @brief Get the login name in the cluster
     *
     * @return QString
     */
    QString getClusterLoginName();
    /**
     * @brief Get the cluster IP
     *
     * @return QString
     */
    QString getClusterIP();
    /**
     * @brief Get the patient data folder path in the remote cluster
     *
     * @return QString
     */
    QString getRemotePatientDataFolder();
    /**
     * @brief Get the CPP folder  path in the remote cluster
     *
     * @return QString
     */
    QString getRemoteCPPFolder();


    /**
     * @brief Set the login name in the cluster
     *
     * @param name
     */
    void setClusterLoginName(QString name);
    /**
     * @brief Set the cluster IP
     *
     * @param ip
     */
    void setClusterIP(QString ip);
    /**
     * @brief Set the patient data folder path in the remote cluster
     *
     * @param folder
     */
    void setRemotePatientDataFolder(QString folder);
    /**
     * @brief Set the CPP folder  path in the remote cluster
     *
     * @param folder
     */
    void setRemoteCPPFolder(QString folder);

    /**
     * @brief clears the information stored in the object
     *
     */
    void clear();
    /**
     * @brief Check if the object is empty (all the fields are empty)
     *
     * @return bool
     */
    bool isEmpty();

private:
    QString _clusterLoginName; /**< TODO */
    QString _clusterIP;     /**< TODO */
    QString _remotePatientDataFolder; /**< TODO */
    QString _remoteCPPFolder; /**< TODO */
};

#endif // CLUSTERDATA_H
