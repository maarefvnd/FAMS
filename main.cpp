#include "fams.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FAMS w;
    w.show();
    return a.exec();
}
