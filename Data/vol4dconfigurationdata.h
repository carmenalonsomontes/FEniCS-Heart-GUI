#ifndef VOL4DCONFIGURATIONDATA_H
#define VOL4DCONFIGURATIONDATA_H

#include <QString>


class Vol4DConfigurationData
{
public:
    Vol4DConfigurationData();


    QString getPerlPath();
    QString getPerlScriptName();

    void setPerlPath(QString data);
    void setPerlScriptName(QString data);

    QString getPerlBinPath();
    void setPerlBinPath(QString path);

    void clear();

private:
    QString _perlBinPath;
    QString _perlPath;
    QString _perlScriptName;

};

#endif // VOL4DCONFIGURATIONDATA_H
