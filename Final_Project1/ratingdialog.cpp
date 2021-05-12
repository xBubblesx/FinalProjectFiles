#include "ratingdialog.h"
#include "ui_ratingdialog.h"

Ratingdialog::Ratingdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Ratingdialog)
{
    ui->setupUi(this);
}

Ratingdialog::~Ratingdialog()
{
    delete ui;
}

