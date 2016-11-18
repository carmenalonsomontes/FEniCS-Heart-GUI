#ifndef XMLDEFINES_H
#define XMLDEFINES_H
#include <QString>
const int StrEqual = 0; /**< TODO */
/**
 * @brief This class is intended to store all the information related with the definition of the tags for the XML files
 *
 */
enum MatlabScripts{
    VOL4DOFF = 0,
    LBL = 1,
    LEUVEN_PHANTOM = 2
};

// XML Defines
const QString USER_GUI_TAG = "user-gui-config"; /**< TODO */

const QString USER_GUI_VOL4D_CONFIG_TAG = "vol4d-config"; /**< TODO */
const QString USER_GUI_VOL4D_PERL_CONFIG_TAG = "perl-config"; /**< TODO */
const QString USER_GUI_VOL4D_PERL_BIN_CONFIG_PATH_ATT = "bin"; /**< TODO */
const QString USER_GUI_VOL4D_PERL_CONFIG_PATH_ATT = "path"; /**< TODO */
const QString USER_GUI_VOL4D_PERL_CONFIG_NAME_ATT = "name"; /**< TODO */


const QString USER_GUI_MATLAB_CONFIG_TAG = "matlab-config"; /**< TODO */
const QString USER_GUI_MATLAB_CONFIG_PATH_ATT = "path"; /**< TODO */

const QString USER_GUI_MATLAB_SCRIPT_CONFIG_TAG = "script"; /**< TODO */
const QString USER_GUI_MATLAB_SCRIPT_CONFIG_PATH_ATT = "path"; /**< TODO */
const QString USER_GUI_MATLAB_SCRIPT_CONFIG_NAME_ATT = "name"; /**< TODO */
const QString USER_GUI_MATLAB_NODESKTOP_CONFIG_ATT = "nodesktop"; /**< TODO */
const QString USER_GUI_MATLAB_NOSPLASH_CONFIG_ATT = "nosplash"; /**< TODO */


const QString USER_GUI_ANSA_CONFIG_TAG = "ansa-config"; /**< TODO */
const QString USER_GUI_ANSA_CONFIG_PATH_ATT = "path"; /**< TODO */

const QString USER_GUI_IOFlow_CONFIG_TAG = "inflowOutflow-config"; /**< TODO */
const QString USER_GUI_IOFlow_CONFIG_PATH_ATT = "path"; /**< TODO */

const QString USER_GUI_SIM_CONFIG_TAG = "sim-config"; /**< TODO */
const QString USER_GUI_SIM_CONFIG_PATH_ATT = "path"; /**< TODO */



// XML PROJECT DEFINES
const QString PROJECT_DATA_TAG = "project-data"; /**< TODO */
const QString PROJECT_DATA_PATH_ATT = "path"; /**< TODO */


const QString SIM_DATA_TAG = "sim-data"; /**< TODO */
const QString SIM_CLINICAL_DATA_FOLDER_TAG = "clinical-data"; /**< TODO */
const QString SIM_CLINICAL_DATA_FOLDER_PATH_ATT = "path"; /**< TODO */

const QString SIM_CLINICAL_FILE_DATA_TAG = "clinical-file-data"; /**< TODO */
const QString SIM_CLINICAL_FILE_DATA_PATH_ATT = "path"; /**< TODO */

const QString CLUSTER_DATA_TAG = "cluster-data"; /**< TODO */
const QString CLUSTER_DATA_LOGIN_NAME_ATT = "login-name"; /**< TODO */
const QString CLUSTER_DATA_IP_ATT = "ip"; /**< TODO */
const QString CLUSTER_DATA_REMOTE_DATA_PATH_ATT = "remote-data-path"; /**< TODO */
const QString CLUSTER_DATA_REMOTE_CPP_PATH_ATT = "remote-cpp-path"; /**< TODO */


const QString PATIENTS_LIST_TAG = "patients-list"; /**< TODO */
const QString PATIENT_TAG = "patient"; /**< TODO */
const QString PATIENT_NAME_ATT = "name"; /**< TODO */
const QString PATIENT_SYASTOLE_ATT = "syastole"; /**< TODO */
const QString PATIENT_DYASTOLE_ATT = "dyastole"; /**< TODO */
const QString PATIENT_IMAGE_FILE_PATH_ATT = "impath"; /**< TODO */
const QString PATIENT_BASE_PATH_ATT = "basepath"; /**< TODO */



#endif // XMLDEFINES_H
