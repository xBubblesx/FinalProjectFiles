#ifndef STUDENTSCREEN_H
#define STUDENTSCREEN_H
#include "studentdialog.h"
#include "ui_studentdialog.h"
#include "suspenddialog.h"
#include "ui_suspenddialog.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class StudentScreen; }
QT_END_NAMESPACE

class StudentScreen : public QDialog
{
    Q_OBJECT

public:
    StudentScreen(QWidget *parent = nullptr);
    ~StudentScreen();
signals:
    void showLogine();

public slots:
    void on_addDataButton_clicked();
    void showStudentScrn();
    void hideStudFeat();

private slots:
    void on_logOutButton_clicked();

private:
    Ui::StudentScreen *ui;
    Studentdialog student;
    Suspenddialog sus;

};
#endif // STUDENTSCREEN_H
