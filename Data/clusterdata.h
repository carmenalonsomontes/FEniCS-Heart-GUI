#ifndef CLUSTERDATA_H
#define CLUSTERDATA_H
#include <QString>

class ClusterData
{
public:
    ClusterData();

    QString getClusterLoginName();
    QString getClusterIP();
    QString getRemotePatientDataFolder();
    QString getRemoteCPPFolder();


    void setClusterLoginName(QString name);
    void setClusterIP(QString ip);
    void setRemotePatientDataFolder(QString folder);
    void setRemoteCPPFolder(QString folder);

    void clear();
    bool isEmpty();

private:
    QString _clusterLoginName;
    QString _clusterIP;    
    QString _remotePatientDataFolder;
    QString _remoteCPPFolder;
};

#endif // CLUSTERDATA_H
