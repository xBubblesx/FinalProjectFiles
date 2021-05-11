#include "loginscreen.h"
#include "ui_loginscreen.h"


LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
    connect(&sscr, SIGNAL(showLogine()), this, SLOT(showLogin()));
    connect(&lscr, SIGNAL(showLogine()), this, SLOT(showLogin()));
    connect(&ascr, SIGNAL(showLogine()), this, SLOT(showLogin()));
    connect(&addstud, SIGNAL(showLogine()), this, SLOT(showLogin()));
}

LoginScreen::~LoginScreen()
{
    delete ui;
}


void LoginScreen::on_cancelButton_clicked()
{
    close();
}

void LoginScreen::on_loginButton_clicked()
{
    QString username = ui->usernameLine->text();
    QString password = ui->passwordLine->text();
    QString userType = type;

    QString res= db.verifyLogin(username, password, userType);
    ui->duplicatelabel->setText(res);


    if(res == "student correct")
    {
        hide();
        sscr.show();
        sscr.raise();
        sscr.activateWindow();

    }
    if (res == "student account suspended")
    {
        hide();
        sscr.hideStudFeat();
    }
    if(res == "lecturer correct")
    {
        hide();
        lscr.show();
        lscr.raise();
        lscr.activateWindow();
    }
    if(res == "lecturer account suspended")
    {
        hide();
        lscr.hideLecFeat();
    }
    if(res == "admin correct")
    {
        hide();
        ascr.show();
        ascr.raise();
        ascr.activateWindow();
    }

    ui->usernameLine->clear();
    ui->passwordLine->clear();

}

void LoginScreen::on_userComboBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        type="null";
    }
    if(index == 1)
    {
        type="student";
    }
    if(index == 2)
    {
        type="lecturer";
    }
    if(index == 3)
    {
        type="admin";
    }
}

void LoginScreen::showLogin()
{
    show();
}

void LoginScreen::on_registerStudentButton_clicked()
{
    addstud.show();
    addstud.raise();
    addstud.activateWindow();

    hide();
}

