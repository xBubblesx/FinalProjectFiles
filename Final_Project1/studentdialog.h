#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H
#include"database.h"
#include<QSqlDatabase>
#include <QDialog>

namespace Ui {
class Studentdialog;
}

class Studentdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Studentdialog(QWidget *parent = nullptr);
    ~Studentdialog();

signals:
    void showLogine();
//    void showadmine();

private slots:
    void on_cancelButton_clicked();
    void on_okButton_clicked();

private:
    Ui::Studentdialog *ui;
    QString SID;
    QString Fname;
    QString Lname;
    QString Pwd;
    QString Email;
    QString Pno;
    QString DOB;
    QString Gender;

    Database db;
};

#endif // STUDENTDIALOG_H
