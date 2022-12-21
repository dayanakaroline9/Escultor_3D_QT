#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sculptor.h"
#include <QString>
#include <QFileDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dimX = 20;
    dimY = 20;
    dimZ = 20;
    r=0;
    g=0;
    b=0;

    e = new Sculptor(dimX,dimY,dimZ);
    e->limparVoxel();

    ui->horizontalSlider_z->setMaximum(dimZ-1);
    ui->widget->imprimirFigura(e->getPlano(ui->horizontalSlider_z->value()));

    actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actionputVoxel);
    actionGroup->addAction(ui->actionputSphere);
    actionGroup->addAction(ui->actionputBox);
    ui->actionputVoxel->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quit()
{
    exit(0);
}

void MainWindow::setRed(int _r)
{
    r = _r;
    updateColor();
}

void MainWindow::setGreen(int _g)
{
    g = _g;
    updateColor();
}

void MainWindow::setBlue(int _b)
{
    b = _b;
    updateColor();
}

void MainWindow::draw3d(int hClick, int vClick)
{
    switch(currentObject){
    case(sphere):

        e->putSphere(vClick,hClick,ui->horizontalSlider_z->value(),ui->sliderRadiusSphere->value());
        ui->widget->imprimirFigura(e->getPlano(ui->horizontalSlider_z->value()));
        break;
    case(voxel):
        e->putVoxel(vClick,hClick,ui->horizontalSlider_z->value());
        ui->widget->imprimirFigura(e->getPlano(ui->horizontalSlider_z->value()));
        break;

    case(box):
        e->putBox(vClick,ui->horizontalSlider_BX->value(),hClick,ui->horizontalSlider_BY->value(),ui->horizontalSlider_z->value(),ui->horizontalSlider_BZ->value());
        ui->widget->imprimirFigura(e->getPlano(ui->horizontalSlider_z->value()));
        break;

    }
}

void MainWindow::updateAxis(int hClick, int vClick)
{
        ui->lcdNumber_x->display(vClick);
        ui->lcdNumber_y->display(hClick);
}

void MainWindow::save()
{
    QFileDialog dialog;
    QString selectedFilter;
    QString filename = dialog.getSaveFileName(this,tr("Salvar"),
                                              QDir::currentPath(),
                                              tr("Arquivo OFF(*.off);;Arquivo VECT(*.vect)"),
                                              &selectedFilter);
    if(filename.isNull()){
        return;
    }

    e->writeOFF(filename.toStdString().c_str());
}



void MainWindow::putVoxel()
{
    currentObject = voxel;
}

void MainWindow::putSphere()
{
    currentObject = sphere;
}

void MainWindow::putBox()
{
    currentObject = box;

}



void MainWindow::set_Axis_z(int value)
{
    ui->widget->imprimirFigura(e->getPlano(value));
}

void MainWindow::updateColor()
{
    QString color;

    color = "QPushButton { background-color: rgb(" +
            QString().setNum(r) + "," +
            QString().setNum(g) + "," +
            QString().setNum(b) + ");}";
    ui->pushButton_color_preview->setStyleSheet(color);
    e->setColor(r,g,b,1);
}


