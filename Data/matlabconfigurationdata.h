#ifndef MATLABCONFIGURATIONDATA_H
#define MATLABCONFIGURATIONDATA_H

#include <QString>
#include <QStringList>



class MatlabConfigurationData
{
public:
    MatlabConfigurationData();

    QString getMatlabPath();
    void setMatlabPath(QString path);

    QStringList getScriptsPath();
    void setScriptsPath(QStringList list);

    bool isNoDesktop();
    bool isNoSplash();

    void setNoDesktop(bool val);
    void setNoSplash(bool val);



    void clear();

private:
    QString _matlabPath;
    QStringList _scriptsPath;

    bool _noDesktop;
    bool _noSplash;


};

#endif // MATLABCONFIGURATIONDATA_H
