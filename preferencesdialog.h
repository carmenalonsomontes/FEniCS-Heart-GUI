#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <QString>
#include "Data/vol4dconfigurationdata.h"
#include "Data/guiconfigdata.h"

namespace Ui {
class PreferencesDialog;
}

/**
 * @brief This class is intended to define the logic for the Preferences dialog
 *
 */
class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Creation of the object
     *
     * @param parent
     */
    explicit PreferencesDialog(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~PreferencesDialog();

    /**
     * @brief Saves the user data and its preferences
     *
     * @param _data
     */
    void setUserData(GUIConfigData * _data);

    /**
     * @brief  Loads the user data and its preferences
     *
     */
    void loadUserData();
    /**
     * @brief Returs true if the user has accepted the changes made
     *
     * @return bool
     */
    bool hasUserAcceptChanges();

private slots:
    /**
     * @brief Logic for OK
     *
     */
    void on_buttonBox_accepted();

    /**
     * @brief Set up the path for the Perl binary
     *
     */
    void on_perlBinPathtoolButton_clicked();

    /**
     * @brief Set up the path for the Perl scripts
     *
     */
    void on_perlScriptNametoolButton_clicked();

    /**
     * @brief Set up the path for the Perl scripts
     *
     */
    void on_perlScriptPathtoolButton_clicked();

    /**
     * @brief Logic for CAncel
     *
     */
    void on_buttonBox_rejected();

    /**
     * @brief  Set up the path for the Matlab tool
     *
     */
    void on_matlabPathToolButton_clicked();

    /**
     * @brief  Set up the path for the Matlab scripts
     *
     */
    void on_niiOffSTLScriptToolButton_clicked();

    /**
     * @brief  Set up the path for the Matlab scripts
     *
     */
    void on_LBLtoolButton_clicked();

    /**
     * @brief  Set up the path for the Matlab scripts
     *
     */
    void on_LeuvenPhantomToolButton_clicked();

    /**
     * @brief  Set up the path for the ANSA tool
     *
     */
    void on_AnsaToolButton_clicked();

    /**
     * @brief  Set up the path for the Simulation scripts
     *
     */
    void on_SimulationToolButton_clicked();

    /**
     * @brief  Set up the path for the Inflow/outflow scripts
     *
     */
    void on_infflowOutflowToolbutton_clicked();

    /**
     * @brief Delete Perl binary path
     *
     */
    void on_deletePerlbinButton_clicked();

    /**
     * @brief Delete Perl scripts path
     *
     */
    void on_deletePerlScriptButton_clicked();

    /**
     * @brief Delete Perl scripts path
     *
     */
    void on_deleteScripthPathButton_clicked();

    /**
     * @brief Delete Matlab binary path
     *
     */
    void on_deleteMatlabPathButton_clicked();

    /**
     * @brief Delete Matlab script path
     *
     */
    void on_deleteNiiButton_clicked();

    /**
     * @brief Delete Matlab script path
     *
     */
    void on_deleteLBLButton_clicked();

    /**
     * @brief Delete Matlab script path
     *
     */
    void on_deleteLeuvenPhantomButton_clicked();

    /**
     * @brief Delete inflow/outflow script path
     *
     */
    void on_deleteIOFlowButton_clicked();

    /**
     * @brief Delete ANSA tool path
     *
     */
    void on_deleteAnsaButton_clicked();

    /**
     * @brief Delete simulation script path
     *
     */
    void on_deleteSimButton_clicked();

    /**
     * @brief Reset all values in all fields
     *
     */
    void on_resetAllButton_clicked();

private:
    Ui::PreferencesDialog *ui; /**< TODO */
    Vol4DConfigurationData  _perlData; /**< TODO */
    MatlabConfigurationData _matlabData; /**< TODO */
    InflowOutflowDataMark _ioFlowData; /**< TODO */
    AnsaConfigurationData _ansaData; /**< TODO */
    SimulationConfigurationData _simData; /**< TODO */

    GUIConfigData * _userData; /**< TODO */

    QString _perlScriptPath; /**< TODO */
    bool _userAcceptChanges; /**< TODO */

    /**
     * @brief Updates the perl bin path
     *
     * @param path
     */
    void updatePerlBinLine(QString path);
    /**
     * @brief Updates the perl script path
     *
     * @param path
     */
    void updatePerlScriptLine(QString path);

    /**
     * @brief Updates the matlab bin path
     *
     * @param path
     */
    void updateMatlabExecLine(QString path);
    /**
     * @brief Updates the matlab script path
     *
     * @param path
     */
    void updateNiiOffSTLScriptLine(QString path);
    /**
     * @brief Updates the matlab script path
     *
     * @param path
     */
    void updateLBLLine(QString path);
    /**
     * @brief Updates the matlab script path
     *
     * @param path
     */
    void updateLeuvenPhantomLine(QString path);

    /**
     * @brief Updates the matlab script path
     *
     * @param path
     */
    void updateIOFlowLine(QString path);
    /**
     * @brief Updates the ANSA bin path
     *
     * @param path
     */
    void updateAnsaLine(QString path);
    /**
     * @brief Updates the simulation script path
     *
     * @param path
     */
    void updateSimulationLine(QString path);

    /**
     * @brief Loads Vol 4D information
     *
     */
    void loadVol4dData();
    /**
     * @brief Loads Matlab information
     *
     */
    void loadMatlabData();
    /**
     * @brief Loads Inflow/Outflow information
     *
     */
    void loadIOFlowData();
    /**
     * @brief Loads ANSA information
     *
     */
    void loadAnsaData();
    /**
     * @brief Loads Simulation information
     *
     */
    void loadSimulationData();


    /**
     * @brief Updates Vol 4D information
     *
     * @param _data
     */
    void updateVol4DInfo(Vol4DConfigurationData _data);
    /**
     * @brief Updates Matlab information
     *
     * @param _data
     */
    void updateMatlabInfo(MatlabConfigurationData _data);
    /**
     * @brief Updates Inflow/Outflow information
     *
     * @param _data
     */
    void updateIOFlowInfo(InflowOutflowDataMark _data);
    /**
     * @brief Updates ANSA information
     *
     * @param _data
     */
    void updateAnsaInfo(AnsaConfigurationData _data);
    /**
     * @brief Updates Simulation information
     *
     * @param _data
     */
    void updateSimulationInfo(SimulationConfigurationData _data);

    /**
     * @brief Insert the correspondent path in a specific position of hte list
     *
     * @param position
     * @param path
     * @param _list
     * @return QStringList
     */
    QStringList insertList(int position, QString path,QStringList _list);
    /**
     * @brief Save User preferences
     *
     */
    void saveUserData();

};

#endif // PREFERENCESDIALOG_H
