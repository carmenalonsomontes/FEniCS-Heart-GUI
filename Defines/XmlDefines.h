#ifndef XMLDEFINES_H
#define XMLDEFINES_H
#include <QString>
const int StrEqual = 0;
enum MatlabScripts{
    VOL4DOFF = 0,
    LBL = 1,
    LEUVEN_PHANTOM = 2
};

// XML Defines
const QString USER_GUI_TAG = "user-gui-config";

const QString USER_GUI_VOL4D_CONFIG_TAG = "vol4d-config";
const QString USER_GUI_VOL4D_PERL_CONFIG_TAG = "perl-config";
const QString USER_GUI_VOL4D_PERL_BIN_CONFIG_PATH_ATT = "bin";
const QString USER_GUI_VOL4D_PERL_CONFIG_PATH_ATT = "path";
const QString USER_GUI_VOL4D_PERL_CONFIG_NAME_ATT = "name";


const QString USER_GUI_MATLAB_CONFIG_TAG = "matlab-config";
const QString USER_GUI_MATLAB_CONFIG_PATH_ATT = "path";

const QString USER_GUI_MATLAB_SCRIPT_CONFIG_TAG = "script";
const QString USER_GUI_MATLAB_SCRIPT_CONFIG_PATH_ATT = "path";
const QString USER_GUI_MATLAB_SCRIPT_CONFIG_NAME_ATT = "name";
const QString USER_GUI_MATLAB_NODESKTOP_CONFIG_ATT = "nodesktop";
const QString USER_GUI_MATLAB_NOSPLASH_CONFIG_ATT = "nosplash";


const QString USER_GUI_ANSA_CONFIG_TAG = "ansa-config";
const QString USER_GUI_ANSA_CONFIG_PATH_ATT = "path";

const QString USER_GUI_IOFlow_CONFIG_TAG = "inflowOutflow-config";
const QString USER_GUI_IOFlow_CONFIG_PATH_ATT = "path";

const QString USER_GUI_SIM_CONFIG_TAG = "sim-config";
const QString USER_GUI_SIM_CONFIG_PATH_ATT = "path";



// XML PROJECT DEFINES
const QString PROJECT_DATA_TAG = "project-data";
const QString PROJECT_DATA_PATH_ATT = "path";


const QString SIM_DATA_TAG = "sim-data";
const QString SIM_CLINICAL_DATA_FOLDER_TAG = "clinical-data";
const QString SIM_CLINICAL_DATA_FOLDER_PATH_ATT = "path";

const QString SIM_CLINICAL_FILE_DATA_TAG = "clinical-file-data";
const QString SIM_CLINICAL_FILE_DATA_PATH_ATT = "path";

const QString CLUSTER_DATA_TAG = "cluster-data";
const QString CLUSTER_DATA_LOGIN_NAME_ATT = "login-name";
const QString CLUSTER_DATA_IP_ATT = "ip";
const QString CLUSTER_DATA_REMOTE_DATA_PATH_ATT = "remote-data-path";
const QString CLUSTER_DATA_REMOTE_CPP_PATH_ATT = "remote-cpp-path";


const QString PATIENTS_LIST_TAG = "patients-list";
const QString PATIENT_TAG = "patient";
const QString PATIENT_NAME_ATT = "name";
const QString PATIENT_SYASTOLE_ATT = "syastole";
const QString PATIENT_DYASTOLE_ATT = "dyastole";
const QString PATIENT_IMAGE_FILE_PATH_ATT = "impath";
const QString PATIENT_BASE_PATH_ATT = "basepath";



#endif // XMLDEFINES_H
