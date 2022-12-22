#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sculptor.h"

#include <QActionGroup>

enum{
    sphere, voxel, box, ellipsoid, cVoxel, cSphere, cBox, cEllipsoid
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
    int figuraAtual;
    void updateColor();
    Sculptor *escultor;
    QActionGroup *actionGroup;

public slots:

    void quit();
    void setRed(int _r);


    void setGreen(int _g);


    void setBlue(int _b);


    void draw3d(int, int);


    void updateAxis(int, int);

    void apresentaDialogo();

private slots:

    void save();

    void putVoxel();

    void putBox();

    void putSphere();

    void putEllipsoid();

    void cutVoxel();

    void cutBox();

    void cutSphere();

    void cutEllipsoid();

    void set_Axis_z(int);

    void limpar_voxel();

};
#endif // MAINWINDOW_H
