#ifndef DIALOGNEWPROJECT_H
#define DIALOGNEWPROJECT_H

#include <QDialog>
#include <QString>

namespace Ui {
class DialogNewProject;
}

class DialogNewProject : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewProject(QWidget *parent = nullptr);
    ~DialogNewProject();

    QString get_x_dialog();

    QString get_y_dialog();

    QString get_z_dialog();

private:
    Ui::DialogNewProject *ui;
};

#endif // DIALOGNEWPROJECT_H
