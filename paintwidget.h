#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event);

public slots:
    void moveCircle(int);
private:
    QTransform transform_;
    int centre_x = 150;
    int centre_y = 150;
};

#endif // PAINTWIDGET_H
