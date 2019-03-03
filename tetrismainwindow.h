#ifndef TETRISMAINWINDOW_H
#define TETRISMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class TetrisMainWindow;
}

class TetrisMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TetrisMainWindow(QWidget *parent = nullptr);
    ~TetrisMainWindow();

private:
    Ui::TetrisMainWindow *ui;
};

#endif // TETRISMAINWINDOW_H
