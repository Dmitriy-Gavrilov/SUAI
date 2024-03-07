#include "form.h"

#include <QApplication>
#include <QLabel>
#include <QLineEdit>
//#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    Form f;
    f.show();

    return a.exec();
}
