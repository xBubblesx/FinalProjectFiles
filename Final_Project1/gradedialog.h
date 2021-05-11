#ifndef GRADEDIALOG_H
#define GRADEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Gradedialog; }
QT_END_NAMESPACE

class Gradedialog : public QDialog
{
    Q_OBJECT

public:
    Gradedialog(QWidget *parent = nullptr);
    ~Gradedialog();

private:
    Ui::Gradedialog *ui;
};
#endif // GRADEDIALOG_H
