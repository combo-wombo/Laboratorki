#include "lasq_menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lasq_menu w;
    w.show();
    w.setWindowTitle("lasq_menu");

    return a.exec();
}
