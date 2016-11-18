#ifndef SPECIFICLOADINGRULESDIALOG_H
#define SPECIFICLOADINGRULESDIALOG_H

#include <QDialog>

#include <QString>
#include <QStringList>
#include <QList>


namespace Ui {
class SpecificLoadingRulesDialog;
}

/**
 * @brief This class is intended to define the logic for the Specific Loading Rules dialog
 *
 */
class SpecificLoadingRulesDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Creation of the object
     *
     * @param parent
     */
    explicit SpecificLoadingRulesDialog(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~SpecificLoadingRulesDialog();

    /**
     * @brief Returns true if the user has accepted any change made in this dialog (clicking OK)
     *
     * @return bool
     */
    bool userAcceptsChanges();

    /**
     * @brief Returns the preffix for the folder names that are accepted to be included in the study (STARTS WITH)
     *
     * @return QStringList
     */
    QStringList getFolderPreffixInclusionRules();
    /**
     * @brief  Returns the suffix for the folder names that are accepted to be included in the study (ENDS WITH)
     *
     * @return QStringList
     */
    QStringList getFolderSuffixInclusionRules();
    /**
     * @brief Returns the preffix for the folder names that are NOT accepted to be included in the study
     *
     * @return QStringList
     */
    QStringList getFolderPreffixExclusionRules();
    /**
     * @brief Returns the suffix for the folder names that are NOT accepted to be included in the study
     *
     * @return QStringList
     */
    QStringList getFolderSuffixExclusionRules();


 //   QStringList getFileImagePreffixInclusionRules();
    /**
     * @brief Returns the suffix (.extension) for the patient dyastole/syastole image file extension that are
     * accepted to be included in the study
     *
     * @return QStringList
     */
    QStringList getFileImageSuffixInclusionRules();
 //   QStringList getFileImagePreffixExclusionRules();
    /**
     * @brief Returns the suffix (.extension) for the patient dyastole/syastole image file extension that are
     * NOT accepted to be included in the study
     *
     * @return QStringList
     */
    QStringList getFileImageSuffixExclusionRules();

    /**
     * @brief Clear all the information of the dialog variables
     *
     */
    void clear();


private slots:
    /**
     * @brief User click Accept
     *
     */
    void on_buttonBox_accepted();

    /**
     * @brief User click Cancel
     *
     */
    void on_buttonBox_rejected();

private:
    Ui::SpecificLoadingRulesDialog *ui; /**< TODO */
    bool _userAcceptChanges; /**< TODO */

    QStringList _folderInclusionPreffix; /**< TODO */
    QStringList _folderInclusionSuffix; /**< TODO */
    QStringList _folderExclusionPreffix; /**< TODO */
    QStringList _folderExclusionSuffix; /**< TODO */

//    QStringList _fileImageInclusionPreffix;
    QStringList _fileImageInclusionSuffix; /**< TODO */
//    QStringList _fileImageExclusionPreffix;
    QStringList _fileImageExclusionSuffix; /**< TODO */

    /**
     * @brief This function builds the data for the inclusion/exclusion rules applied to the folder names
     *
     */
    void buildFolderRules();
    /**
     * @brief This function builds the data for the inclusion/exclusion rules applied to the patient image dyastole/syasole image
     * file name extensios
     *
     */
    void buildFileImageRules();

};

#endif // SPECIFICLOADINGRULESDIALOG_H
