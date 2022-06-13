#include "renderarea.h"
#include "aboutdialog.h"
#include "ui_renderarea.h"

#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent}
{

}

void RenderArea::paintEvent(QPaintEvent*  event)
{
    QPainter painter;

    painter.begin(this);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);

    QBrush brush;
    brush.setColor(Qt::green);
    brush.setStyle(Qt::Dense5Pattern);


    painter.setPen(pen);
    painter.setBrush(brush);
    QPolygon pol;
    pol << QPoint(20,20) << QPoint(100,200) << QPoint(80,180);
    pol << QPoint(300,185);
    painter.drawPolygon(pol);

    painter.end();

}
