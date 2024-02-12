#include "networkinformation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    networkinformation w;
    w.show();
    return a.exec();
}
