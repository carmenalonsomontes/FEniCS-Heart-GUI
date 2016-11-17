#ifndef SPECIFICLOADINGRULESDIALOG_H
#define SPECIFICLOADINGRULESDIALOG_H

#include <QDialog>

#include <QString>
#include <QStringList>
#include <QList>


namespace Ui {
class SpecificLoadingRulesDialog;
}

class SpecificLoadingRulesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpecificLoadingRulesDialog(QWidget *parent = 0);
    ~SpecificLoadingRulesDialog();

    bool userAcceptsChanges();

    QStringList getFolderPreffixInclusionRules();
    QStringList getFolderSuffixInclusionRules();
    QStringList getFolderPreffixExclusionRules();
    QStringList getFolderSuffixExclusionRules();


 //   QStringList getFileImagePreffixInclusionRules();
    QStringList getFileImageSuffixInclusionRules();
 //   QStringList getFileImagePreffixExclusionRules();
    QStringList getFileImageSuffixExclusionRules();

    void clear();


private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SpecificLoadingRulesDialog *ui;
    bool _userAcceptChanges;

    QStringList _folderInclusionPreffix;
    QStringList _folderInclusionSuffix;
    QStringList _folderExclusionPreffix;
    QStringList _folderExclusionSuffix;

//    QStringList _fileImageInclusionPreffix;
    QStringList _fileImageInclusionSuffix;
//    QStringList _fileImageExclusionPreffix;
    QStringList _fileImageExclusionSuffix;

    void buildFolderRules();
    void buildFileImageRules();

};

#endif // SPECIFICLOADINGRULESDIALOG_H
