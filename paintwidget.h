#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>

class PaintWidget : public QWidget
{
public:
    PaintWidget(QWidget* parent);

protected:
    void paintEvent(QPaintEvent* event);
private:
    QTransform transform_;
};

#endif // PAINTWIDGET_H
