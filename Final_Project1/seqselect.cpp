#include "seqselect.h"
#include "ui_seqselect.h"

Seqselect::Seqselect(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Seqselect)
{
    ui->setupUi(this);
}

Seqselect::~Seqselect()
{
    delete ui;
}

