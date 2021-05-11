#include <QApplication>
#include "database.h"
#include "admin.h"
#include "loginscreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    admin m;
//    m.show();
//    m.activateWindow();
    LoginScreen ls;
    ls.show();
    ls.activateWindow();

    Database Dconnect;
    Dconnect.connect();
    return a.exec();
}

