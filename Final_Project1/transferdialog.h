#ifndef TRANSFERDIALOG_H
#define TRANSFERDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Transferdialog; }
QT_END_NAMESPACE

class Transferdialog : public QDialog
{
    Q_OBJECT

public:
    Transferdialog(QWidget *parent = nullptr);
    ~Transferdialog();

private:
    Ui::Transferdialog *ui;
};
#endif // TRANSFERDIALOG_H
