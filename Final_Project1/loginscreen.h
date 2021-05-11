#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H
#include <QMainWindow>
#include "database.h"
#include "studentscreen.h"
#include "lecturerscreen.h"
#include "admin.h"
#include "studentdialog.h"
#include "ui_studentdialog.h"



QT_BEGIN_NAMESPACE
namespace Ui { class LoginScreen; }
QT_END_NAMESPACE

class LoginScreen : public QMainWindow
{
    Q_OBJECT

public:
    LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();
signals:
    void showStudent();

private slots:
    void on_cancelButton_clicked();
    void on_loginButton_clicked();
    void on_userComboBox_currentIndexChanged(int index);
    void showLogin();

    void on_registerStudentButton_clicked();

private:
    Ui::LoginScreen *ui;
    QString type;
    Database db;
    StudentScreen sscr;
    Lecturerscreen lscr;
    admin ascr;
    Studentdialog addstud;


};
#endif // LOGINSCREEN_H
