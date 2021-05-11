#include "transferdialog.h"
#include "ui_transferdialog.h"

Transferdialog::Transferdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Transferdialog)
{
    ui->setupUi(this);
}

Transferdialog::~Transferdialog()
{
    delete ui;
}

