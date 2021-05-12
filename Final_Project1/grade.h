#ifndef GRADE_H
#define GRADE_H
#include <QString>

class Grade
{
public:
    Grade(const QString &, const QString &);
    void setCourse(QString);
    void setGrade(QString);

    QString getCourse();
    QString getGrade();

private:
    QString courseId;
    QString grade;

};

#endif // GRADE_H
