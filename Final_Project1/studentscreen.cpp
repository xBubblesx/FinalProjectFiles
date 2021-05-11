#include "studentscreen.h"
#include "ui_studentscreen.h"
#include <QMessageBox>

StudentScreen::StudentScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentScreen)
{
    ui->setupUi(this);
    connect(&sus, SIGNAL(hideSFeat()), this, SLOT(hideStudFeat()));
}

StudentScreen::~StudentScreen()
{
    delete ui;
}

void StudentScreen::on_addDataButton_clicked()
{
    student.show();
    student.raise();
    student.activateWindow();
}

void StudentScreen::showStudentScrn()
{
    show();

}

void StudentScreen::hideStudFeat()
{
    show();
    ui->addDataButton->hide();
    ui->viewCSButton->hide();
    QMessageBox msg;
    msg.setWindowTitle("Account Suspended");
    msg.setText("This account is Suspended. Contact Administrator for further assistance.");
    msg.exec();
}

void StudentScreen::on_logOutButton_clicked()
{
    close();
    emit showLogine();
}
