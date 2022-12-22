#ifndef CANVA_H
#define CANVA_H

#include <QWidget>
#include <vector>
#include <QVector>
#include "sculptor.h"

using namespace std;

class Canva : public QWidget
{
    Q_OBJECT

private:
    int nl, nc;
    vector <vector<Voxel>> v;
    int gridV, gridH;
    int tamCel;
    int widthScreen, heightScreen;
    int widthCel, heightCel;
    bool pressed;

public:
    explicit Canva(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *e);

    void setTamanho(int _nl, int _nc);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void imprimirFigura(vector <vector <Voxel> > m);

signals:
    void enviaPosicao(int,int);


};

#endif // CANVA_H
