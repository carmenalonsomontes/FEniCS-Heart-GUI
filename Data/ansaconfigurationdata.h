#ifndef ANSACONFIGURATIONDATA_H
#define ANSACONFIGURATIONDATA_H

#include <QString>
class AnsaConfigurationData
{
public:
    AnsaConfigurationData();

    QString getAnsaPath();
    void setAnsaPath(QString path);
    void clear();

private:
    QString _ansaPath;

};

#endif // ANSACONFIGURATIONDATA_H
