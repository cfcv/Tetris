#include "paintwidget.h"
#include <QPainter>
#include <QDebug>

PaintWidget::PaintWidget(QWidget* parent) : QWidget(parent)
{

}

void PaintWidget::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    QPen pen(Qt::blue, 3);
    painter.setPen(pen);
    painter.setBrush(Qt::blue);
    painter.setWindow(0,0,300,300);
    painter.drawEllipse(QPointF(centre_x, centre_y), 10, 15);
}

void PaintWidget::moveCircle(int direction){
    switch (direction) {
    case 1:
        centre_x+=2;
        break;
    case -1:
        centre_x-=2;
        break;
    default:
        break;

    }
    update();
    qDebug() << direction;
}
