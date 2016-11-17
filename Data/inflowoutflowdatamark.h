#ifndef INFLOWOUTFLOWDATAMARK_H
#define INFLOWOUTFLOWDATAMARK_H
#include <QString>
class InflowOutflowDataMark
{
public:
    InflowOutflowDataMark();

    QString getScriptPath();
    void setScriptPath(QString path);

    void clear();

private:
    QString _scriptPath;

};

#endif // INFLOWOUTFLOWDATAMARK_H
