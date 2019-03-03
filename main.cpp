#include "tetrismainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TetrisMainWindow w;
    w.show();

    return a.exec();
}
