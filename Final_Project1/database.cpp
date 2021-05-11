#include "database.h"
#include "lecturerdialog.h"
#include "loginscreen.h"
#include "studentscreen.h"
#include<QDebug>
#include"user.h"
#include <QSqlRecord>
#include "loginscreen.h"
#include "studentscreen.h"
#include <QMessageBox>

Database::Database()
{

}

QString Database::insertStudent(Student s)
{
    QString FirstName = s.getFirstName();
    QString LastName = s.getLastName();
    QString Gender = s.getGender();
    QString Student_id = s.getID();
    QString BirthDate = s.getBirthDate();
    QString EmailAddress = s.getEmailAddress();
    QString Password = s.getPassword();
    QString Phone_No = s.getPhoneNo();
    QString res;

    try{
        if(FirstName.isEmpty() || LastName.isEmpty() || Gender.isEmpty() || Student_id.isEmpty() || BirthDate.isEmpty() || EmailAddress.isEmpty() || Password.isEmpty() || Phone_No.isEmpty())
        {
           throw "A field is empty!! Please fill in all areas";
        }

        qDebug() << "INSERT INTO student (FirstName, LastName, Gender, Student_Id, BirthDate, EmailAddress, Password, Phone_No) VALUES "
                "('" + FirstName + "','" + LastName + "','" + Gender + "','" + Student_id + "','" + BirthDate + "','" + EmailAddress + "','" + Password + "','" + Phone_No + "')";
        QSqlQuery query;
        if (query.exec("INSERT INTO student (FirstName, LastName, Gender, Student_Id, BirthDate, EmailAddress, Password, Phone_No) VALUES "
                       "('" + FirstName + "','" + LastName + "','" + Gender + "','" + Student_id + "','" + BirthDate + "','" + EmailAddress + "','" + Password + "','" + Phone_No + "')"))
        {
            currentID = query.lastInsertId().toString();
            qDebug() << "Insert success.";
            res = "All clear";
        }
        else
        {
            qDebug() << query.lastError().text();
            res = "Failed insertion of data";
        }

        QString State = "Active";
        QSqlQuery qry;
        if(qry.exec("INSERT INTO status (Student_ID, State) VALUES " "('"+ Student_id +"', '"+ State +"')"))
        {
            qDebug()<<"Inserted status.";

        }
    }
    catch(const char *d)
    {
        return d;
    }
    return res;
}

void Database::insertLecturer(Lecturer l)
{
    // try{
    QString FirstName = l.getFirstName();
    QString LastName = l.getLastName();
    QString Gender = l.getGender();
    QString Lecturer_Id = l.getID();
    QString BirthDate = l.getBirthDate();
    QString EmailAddress = l.getEmailAddress();
    QString Password = l.getPassword();
    QString Phone_No = l.getPhoneNo();

    qDebug() << "INSERT INTO lecturer (FirstName, LastName, Gender, Lecturer_Id, BirthDate, EmailAddress, Password, Phone_No) VALUES "
                "('" + FirstName + "','" + LastName + "','" + Gender + "','" + Lecturer_Id + "','" + BirthDate + "','" + EmailAddress + "','" + Password + "','" + Phone_No + "')";
    QSqlQuery query;
    if (query.exec("INSERT INTO lecturer (FirstName, LastName, Gender, Lecturer_Id, BirthDate, EmailAddress, Password, Phone_No) VALUES "
                   "('" + FirstName + "','" + LastName + "','" + Gender + "','" + Lecturer_Id + "','" + BirthDate + "','" + EmailAddress + "','" + Password + "','" + Phone_No + "')"))
    {
        currentID = query.lastInsertId().toString();
        qDebug() << "Insert success.";
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    QString State = "Active";
    QSqlQuery qry;
    if(qry.exec("INSERT INTO lecturerstatus (Lecturer_Id, State) VALUES " "('"+ Lecturer_Id +"', '"+ State +"')"))
    {
        qDebug()<<currentID;
    }


}

void Database::insertCourse(Course c)
{
    QString Course_Code = c.getcourseId();
    QString Course_Name = c.getcourseName();
    QString Description = c.getcourseDescrip();
    QString Credits = c.getnoOfCredits();

    try
    {
        if(Credits == 0)
        {
            throw "Courses must have atleast 1 credit";
        }
    }
    catch(const char *c)
    {

    }


    qDebug() << "INSERT INTO Course (Course_Code, Course_Name, Credits, Description) "
                "VALUES ('"+ Course_Code +"', '"+ Course_Name +"', '"+ Credits +"', '"+ Description +"')";
    QSqlQuery query;
    if(query.exec("INSERT INTO Course (Course_Code, Course_Name, Credits, Description) "
                  "VALUES ('"+ Course_Code +"', '"+ Course_Name +"', '"+ Credits +"', '"+ Description +"')"))
    {
        currentID = query.lastInsertId().toInt();
        qDebug() << "Insert success";
    }
    else
    {
        qDebug() << "failed to connect to database";
    }
}

QString Database::insertSequence(Sequence d)
{
    QString Syllabus_Id= d.getsyllabusId();
    QString Program= d.getProgram();
    QString Program_Year= d.getprogramYear();
    QString Semester= d.getSemester();
    QString Course_Id= d.getcourseId();
    QString s;

    try
    {
        if(Syllabus_Id.isEmpty() || Program.isEmpty() || Program_Year.isEmpty() || Semester.isEmpty() || Course_Id.isEmpty())
        {
            throw "A field is empty. Fill in all areas.";
        }

        qDebug() << "Creating Course Sequence(SyllabusId, Program, Program Year, Semester, Course) "
                    "WITH VALUES ('"+ Syllabus_Id +"', '"+ Program +"', '"+ Program_Year +"', '"+ Semester +"', '"+ Course_Id +"')";
        QSqlQuery query;

        qDebug()<<"SELECT Program_Id FROM program WHERE Program_Code = '"+ Program +"' ";
        if(query.exec("SELECT Program_Id FROM program WHERE Program_Code = '"+ Program +"' "))
        {
            query.first();
            Program =query.value(0).toString();
            qDebug()<<Program;
        }

        qDebug()<<"SELECT Program_Year_Id FROM program_year WHERE Year = '"+ Program_Year +"'";
        if(query.exec("SELECT Program_Year_Id FROM program_year WHERE Year = '"+ Program_Year +"' "))
        {
            query.first();
            Program_Year=query.value(0).toString();
            qDebug()<<Program_Year;
        }

        qDebug()<<"SELECT Course_ID FROM course WHERE Course_Code = '"+ Course_Id +"'";
        if(query.exec("SELECT Course_ID FROM course WHERE Course_Code = '"+ Course_Id +"' "))
        {
            query.first();
            Course_Id=query.value(0).toString();
            qDebug()<<Course_Id;
        }
        //        if(query.exec("INSERT INTO Course (Course_Code, Course_Name, Credits, Description) "
        //                      "VALUES ('"+ Course_Code +"', '"+ Course_Name +"', '"+ Credits +"', '"+ Description +"')"))

        qDebug() << "INSERT INTO syllabus (Syllabus_Id, Program, Program_Year, Semester, Course_Id) "
                    "VALUES ('"+ Syllabus_Id +"', '"+ Program +"', '"+ Program_Year +"', '"+ Semester +"', '"+ Course_Id +"')";

        if(query.exec("INSERT INTO syllabus (Syllabus_Id, Program, Program_Year, Semester, Course_Id) "
                      "VALUES ('"+ Syllabus_Id +"','"+ Program +"','"+ Program_Year +"','"+ Semester +"','"+ Course_Id +"')" ))
        {
            currentID = query.lastInsertId().toInt();
            qDebug()<<"Insert success";
            s="Insert Sucess";
        }


        else
        {
            qDebug()<<"Insert failed!! Denver";
        }

    }
    catch(const char *d)
    {
        return d;
    }
    return s;
}

void Database::connect()
{
    try{
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("");
        db.setDatabaseName("final_project");
        connected = db.open();
        if(connected)
        {
            throw 1;
        }
        else{
            throw "bad Database Connection";
        }
    }
    catch(const int d)
    {
        qDebug() << "connected to database.";
    }
    catch(const char * str)
    {
        qDebug() << "Failed to connect to database."<<str;
    }
}

void Database::findStudent(QString id)
{
    //    Searchdialog sd;
    qDebug() << "SEARCHING STUDENT (ID) IS: "
                "('" + id + "')";
    QString id1, fn, ln,ad, pn, g, bd, pswd;

    QSqlQuery query;
    QString sql= "SELECT Student_Id, FirstName, LastName, EmailAddress, Phone_No, Gender, "
                 "BirthDate, Password FROM student WHERE Student_Id = "+ id +" ";
    query.prepare(sql);
    if(query.exec(sql))
    {
        qDebug()<<"Record Found!";
        query.first();
        id1=query.value(0).toString();
        fn=query.value(1).toString();
        ln=query.value(2).toString();
        ad=query.value(3).toString();
        pn=query.value(4).toString();
        g=query.value(5).toString();
        bd=query.value(6).toString();
        pswd=query.value(7).toString();

        qDebug()<<id1<<fn<<ln<<ad<<pn<<g<<bd<<pswd;
    }
    else if(!query.exec())
    {
        qDebug()<<"yuh code nuh work bass";
    }

    QMessageBox msg;
    msg.setWindowTitle("Results:");
    msg.setText("Id: " + id1 + "\nFirst Name: " + fn + "\nLast Name: "
                + ln + "\nEmail: " + ad + "\nContact: " + pn +
                "\nGender: " + g + "\nBirth Date: " + bd +
                "\nPassword: " + pswd);
    msg.exec();
}

void Database::resetUserPwd(Reset r)
{
    QString UserId = r.getuserId();
    QString Password = r.getnewPwd();
    QString UserType = r.getType();
    QString Student_id;
    QString Lecturer_Id;

    QSqlQuery query;

    if(UserType == "student")
    {
        Student_id = UserId;

        query.prepare("UPDATE student SET Password='"+Password+"' WHERE Student_id='"+Student_id+"'");

        if(query.exec())
        {
            qDebug() << "Update success.";
        }
        else
        {
            qDebug() << "Update failed.";
        }
    }
    else if(UserType == "lecturer")
    {
        Lecturer_Id = UserId;

        query.prepare("UPDATE lecturer SET Password='"+Password+"' WHERE Lecturer_Id='"+Lecturer_Id+"'");

        if(query.exec())
        {
            qDebug() << "Update success.";
        }
        else
        {
            qDebug() << "Update failed.";
        }
    }

}

void Database::suspendAccount(Suspend s)
{
    QString UserId = s.getuserId();
    QString State = s.getuserStatus();
    QString UserType = s.getType();
    QString Student_id;
    QString Lecturer_Id;

    QSqlQuery query;

    if(UserType == "student")
    {
        Student_id = UserId;

        query.prepare("UPDATE status SET State='"+State+"' WHERE Student_id='"+Student_id+"'");
        if(query.exec())
        {
            qDebug() << "Update success.";
        }
        else
        {
            qDebug() << "Update failed.";
        }
    }
    else if(UserType == "lecturer")
    {
        Lecturer_Id = UserId;

        query.prepare("UPDATE lecturerstatus SET State='"+State+"' WHERE Lecturer_Id='"+Lecturer_Id+"'");
        if(query.exec())
        {
            qDebug() << "Update success.";
        }
        else
        {
            qDebug() << "Update failed.";
        }
    }
}

QString Database::verifyLogin(QString user, QString pswd, QString type)
{
    try
    {
        if(user.isEmpty() || pswd.isEmpty() || type.isEmpty())
        {
            throw "A field is empty. Fill in all areas.";
        }

    }
    catch(const char *d)
    {
        return d;
    }

    QSqlQuery query;
    int count=0;
    QString q;
    LoginScreen login;
    StudentScreen s;

    QSqlQuery statquery;

    try {
        if(type=="student")
        {
            if(query.exec("SELECT * FROM student WHERE Student_Id= '"+ user +"' AND Password= '"+ pswd +"' "))
            {
                while(query.next())
                {
                    count++;
                }
                if(count < 1)
                {
                    throw "Incorrect credentials";
                }
                else if(count == 1)
                {
                    QString stsql= "SELECT State FROM status WHERE Student_Id = "+ user +" ";
                    statquery.prepare(stsql);
                    if(statquery.exec(stsql))
                    {
                        qDebug()<<"Status Found!";
                        statquery.first();
                        status=statquery.value(0).toString();
                        qDebug()<<status;
                        if (status == "Active")
                        {
                            q= "student correct";
                        }
                        else if(status == "Inactive")
                        {
                            q = "student account suspended";
                        }
                    }
                    else if(!statquery.exec())
                    {
                        qDebug()<<"Status not found!";
                    }

                }
            }

            return q;
        }

        if(type=="lecturer")
        {
            if(query.exec("SELECT * FROM lecturer WHERE Lecturer_Id= '"+ user +"' AND Password= '"+ pswd +"' "))
            {
                while(query.next())
                {
                    count++;
                }
                if(count < 1)
                {
                    throw "Incorrect credentials";
                }
                else if(count == 1)
                {
                    QString stsql= "SELECT State FROM lecturerstatus WHERE Lecturer_Id = '"+ user +"' ";
                    statquery.prepare(stsql);
                    if(statquery.exec(stsql))
                    {
                        qDebug()<<"Status Found!";
                        statquery.first();
                        status=statquery.value(0).toString();
                        qDebug()<<status;
                        if (status == "Active")
                        {
                            q= "lecturer correct";
                        }
                        else if(status == "Inactive")
                        {
                            q = "lecturer account suspended";
                        }
                    }
                    else if(!statquery.exec())
                    {
                        qDebug()<<"Status not found!";
                    }
                }
            }
            return q;
        }

        if(type=="admin")
        {
            if(query.exec("SELECT * FROM admin WHERE Username= '"+ user +"' AND Password= '"+ pswd +"' "))
            {
                while(query.next())
                {
                    count++;
                }
                if(count < 1)
                {
                    throw "Incorrect credentials";
                }
                else if(count == 1)
                {
                    q = "admin correct";
                }
            }
            return q;
        }
    }
    catch(const char *d)
    {
        return d;
    }

}


