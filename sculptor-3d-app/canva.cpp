#include "canva.h"
#include <QPainter>
#include <QSize>
#include <QPen>
#include <QBrush>
#include <QPoint>
#include <QMouseEvent>
#include <QGradient>
#include <cmath>
#include <iostream>
#include <sculptor.h>
#include <qdebug.h>

Canva::Canva(QWidget *parent)
    : QWidget{parent}
{
    nl = 10;
    nc = 10;

    pressed = false;
    widthScreen = rect().width();
    heightScreen = rect().height();
    widthCel = widthScreen/nc;
    heightCel = heightScreen/nl;
    if (heightCel > widthCel){
        tamCel = widthCel;
    }else{
        tamCel = heightCel;
    }
    setTamanho(nl,nc);
}

void Canva::paintEvent(QPaintEvent *e)
{

    QPen pen;
    QPainter p(this);
    QBrush brush;

    pen.setWidth(2);

    widthScreen = width();
    heightScreen = height();

    widthCel = widthScreen/nc;
    heightCel = heightScreen/nl;

    if (heightCel > widthCel){
        tamCel = widthCel;
    }else{
        tamCel = heightCel;
    }
    borderh = (widthScreen - nc*tamCel)/2;
    borderv = (heightScreen - nl*tamCel)/2;

    p.setPen(pen);
    p.drawRect(rect());

    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            if(v[i][j].isOn == true){
                p.save();
                p.translate(j*tamCel+borderh+tamCel/2,
                            i*tamCel+borderv+tamCel/2);
                p.setPen(Qt::NoPen);
                brush.setColor(QColor::fromRgb(v[i][j].r, v[i][j].g, v[i][j].b));
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
                p.drawRect(-tamCel/2+1, -tamCel/2+1, tamCel-1, tamCel-1);
                p.restore();
            }else{
                brush.setColor(QColor(255,255,255,0));
                p.setBrush(brush);
                p.drawRect(j*tamCel+borderh,i*tamCel+borderv,tamCel, tamCel);
            }
        }
    }

}

void Canva::setTamanho(int _nl, int _nc)
{
    nl = _nl;
    nc = _nc;
    repaint();
}

void Canva::mousePressEvent(QMouseEvent *event)
{
    int posh, posv;
    QRect ret;
    ret = rect();
    pressed = true;
    ret.adjust(borderh, borderv, -borderh, -borderv);
    if(ret.contains(event->pos())){
        posh = (event->pos().x()-borderh)*nc/ret.width();
        posv = (event->pos().y()-borderv)*nl/ret.height();
        emit enviaPosicao(posh, posv);
    }
}

void Canva::mouseMoveEvent(QMouseEvent *event)
{
    int posh, posv;
    QRect ret;
    ret = rect();
    ret.adjust(borderh, borderv, -borderh, -borderv);
    if(ret.contains(event->pos())&& pressed == true){
        posh = (event->pos().x()-borderh)*nc/ret.width();
        posv = (event->pos().y()-borderv)*nl/ret.height();
        emit enviaPosicao(posh, posv);
    }

}

void Canva::mouseReleaseEvent(QMouseEvent *event)
{
    pressed = false;
}

void Canva::imprimirFigura(vector<vector<Voxel> > m)
{
    nl = m.size();
    nc = m[0].size();
    v = m;
    repaint();
}

