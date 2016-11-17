#ifndef PROJECTPREFERENCESDIALOG_H
#define PROJECTPREFERENCESDIALOG_H

#include <QDialog>

namespace Ui {
class ProjectPreferencesDialog;
}

class ProjectPreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectPreferencesDialog(QWidget *parent = 0);
    ~ProjectPreferencesDialog();

private:
    Ui::ProjectPreferencesDialog *ui;
};

#endif // PROJECTPREFERENCESDIALOG_H
