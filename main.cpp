#include "doteditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DotEditor w;
    w.show();

    return a.exec();
}
