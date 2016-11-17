#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <QString>
#include "Data/vol4dconfigurationdata.h"
#include "Data/guiconfigdata.h"

namespace Ui {
class PreferencesDialog;
}

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreferencesDialog(QWidget *parent = 0);
    ~PreferencesDialog();

    void setUserData(GUIConfigData * _data);

    void loadUserData();
    bool hasUserAcceptChanges();

private slots:
    void on_buttonBox_accepted();

    void on_perlBinPathtoolButton_clicked();

    void on_perlScriptNametoolButton_clicked();

    void on_perlScriptPathtoolButton_clicked();

    void on_buttonBox_rejected();

    void on_matlabPathToolButton_clicked();

    void on_niiOffSTLScriptToolButton_clicked();

    void on_LBLtoolButton_clicked();

    void on_LeuvenPhantomToolButton_clicked();

    void on_AnsaToolButton_clicked();

    void on_SimulationToolButton_clicked();

    void on_infflowOutflowToolbutton_clicked();

    void on_deletePerlbinButton_clicked();

    void on_deletePerlScriptButton_clicked();

    void on_deleteScripthPathButton_clicked();

    void on_deleteMatlabPathButton_clicked();

    void on_deleteNiiButton_clicked();

    void on_deleteLBLButton_clicked();

    void on_deleteLeuvenPhantomButton_clicked();

    void on_deleteIOFlowButton_clicked();

    void on_deleteAnsaButton_clicked();

    void on_deleteSimButton_clicked();

    void on_resetAllButton_clicked();

private:
    Ui::PreferencesDialog *ui;
    Vol4DConfigurationData  _perlData;
    MatlabConfigurationData _matlabData;
    InflowOutflowDataMark _ioFlowData;
    AnsaConfigurationData _ansaData;
    SimulationConfigurationData _simData;

    GUIConfigData * _userData;

    QString _perlScriptPath;
    bool _userAcceptChanges;

    void updatePerlBinLine(QString path);
    void updatePerlScriptLine(QString path);

    void updateMatlabExecLine(QString path);
    void updateNiiOffSTLScriptLine(QString path);
    void updateLBLLine(QString path);
    void updateLeuvenPhantomLine(QString path);

    void updateIOFlowLine(QString path);
    void updateAnsaLine(QString path);
    void updateSimulationLine(QString path);

    void loadVol4dData();
    void loadMatlabData();
    void loadIOFlowData();
    void loadAnsaData();
    void loadSimulationData();


    void updateVol4DInfo(Vol4DConfigurationData _data);
    void updateMatlabInfo(MatlabConfigurationData _data);
    void updateIOFlowInfo(InflowOutflowDataMark _data);
    void updateAnsaInfo(AnsaConfigurationData _data);
    void updateSimulationInfo(SimulationConfigurationData _data);

    QStringList insertList(int position, QString path,QStringList _list);
    void saveUserData();

};

#endif // PREFERENCESDIALOG_H
