#ifndef RATINGDIALOG_H
#define RATINGDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Ratingdialog; }
QT_END_NAMESPACE

class Ratingdialog : public QDialog
{
    Q_OBJECT

public:
    Ratingdialog(QWidget *parent = nullptr);
    ~Ratingdialog();

private:
    Ui::Ratingdialog *ui;
};
#endif // RATINGDIALOG_H
