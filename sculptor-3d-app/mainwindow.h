#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sculptor.h"

#include <QActionGroup>

enum{
    sphere, voxel, box
};

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int dimX, dimY, dimZ;
    int r, g, b;
    int currentObject;
    void updateColor();
    Sculptor *e;
    QActionGroup *actionGroup;

public slots:

    void quit();
    void setRed(int _r);


    void setGreen(int _g);


    void setBlue(int _b);


    void draw3d(int, int);


    void updateAxis(int, int);

private slots:

    void save();

    void putVoxel();

    void putSphere();

    void putBox();

    void set_Axis_z(int);

};
#endif // MAINWINDOW_H
