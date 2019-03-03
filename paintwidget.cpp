#include "paintwidget.h"
#include <QPainter>

PaintWidget::PaintWidget(QWidget* parent) : QWidget(parent)
{

}

void PaintWidget::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    QPen pen(Qt::blue, 3);
    painter.setPen(pen);
    painter.setBrush(Qt::blue);
    painter.setWindow(0,0,300,300);
    painter.drawEllipse(QPointF(150, 150), 10, 15);
}
