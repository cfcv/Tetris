#ifndef VIDEOCRONTROL_H
#define VIDEOCRONTROL_H
#include<QWidget>
#include <QLabel>

class VideoCrontrol : public QObject
{
    Q_OBJECT
public:
    explicit VideoCrontrol(QLabel* i, QObject *parent = nullptr);

private:
    QLabel* image_label;
signals:

public slots:
};

#endif // VIDEOCRONTROL_H
