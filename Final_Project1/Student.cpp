#include <iostream>
using namespace std;
#include <QString>
#include"Student.h"

//Initializes the student constructor
Student::Student(const QString &id, const QString &fName, const QString &lName, const QString &pw, const QString &email, const QString &pNo, const QString &gender, const QString &birthDate)
    :User(id, fName, lName, pw, email, pNo, gender, birthDate)
{

}
