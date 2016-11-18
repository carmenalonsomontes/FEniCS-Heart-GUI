#ifndef PROJECTPREFERENCESDIALOG_H
#define PROJECTPREFERENCESDIALOG_H

#include <QDialog>

namespace Ui {
class ProjectPreferencesDialog;
}

/**
 * @brief This class is intended to define the logic for the Project PReferences dialog
 * TODO
 *
 */
class ProjectPreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Creation of the object
     *
     * @param parent
     */
    explicit ProjectPreferencesDialog(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~ProjectPreferencesDialog();

private:
    Ui::ProjectPreferencesDialog *ui; /**< TODO */
};

#endif // PROJECTPREFERENCESDIALOG_H
