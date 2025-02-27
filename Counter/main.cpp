#include "win.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Win w(nullptr);
    w.show();
    return a.exec();
}
