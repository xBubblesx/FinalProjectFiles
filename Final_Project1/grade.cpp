#include "grade.h"

Grade::Grade(const QString &cId, const QString &grd)
{
    courseId = cId;
    grade = grd;
}

void Grade::setCourse(QString Courseid)
{
    courseId = Courseid;
}

void Grade::setGrade(QString Grd)
{
    grade = Grd;
}

QString Grade::getCourse()
{
    return courseId;
}

QString Grade::getGrade()
{
    return grade;
}
