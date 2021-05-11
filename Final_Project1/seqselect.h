#ifndef SEQSELECT_H
#define SEQSELECT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Seqselect; }
QT_END_NAMESPACE

class Seqselect : public QDialog
{
    Q_OBJECT

public:
    Seqselect(QWidget *parent = nullptr);
    ~Seqselect();

private:
    Ui::Seqselect *ui;
};
#endif // SEQSELECT_H
