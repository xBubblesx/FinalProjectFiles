#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include "Student.h"
#include "lecturer.h"
#include "course.h"
#include "searchdialog.h"
#include "ui_searchdialog.h"
#include "ui_loginscreen.h"
#include "sequence.h"
#include "reset.h"
#include "suspend.h"

namespace Ui {
class Database;

}
class Database
{
public:
    Database();
    QString insertStudent(Student );
    void insertLecturer(Lecturer);
    void insertCourse(Course);
    void findStudent(QString );
    void resetUserPwd(Reset);
    void suspendAccount(Suspend);
    QString insertSequence(Sequence);
    QString verifyLogin(QString, QString, QString);

signals:
    void showStudentScrn();
    void showLecturerScrn();
    void showAdminScrn();

public slots:
    void connect();

private:
    QSqlDatabase db;
    Ui::Searchdialog *sd;
    Ui::LoginScreen *lg;
    bool connected;
    QString currentID;
    QString status;
};

#endif // DATABASE_H
