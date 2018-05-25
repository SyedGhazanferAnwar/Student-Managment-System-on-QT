#ifndef CPPTEACHER_H
#define CPPTEACHER_H
#include "cppperson.h"
#include <QString>
#include <QStringList>



class cppteacher:public cppperson
{
  private:
    int noOfcourses;
    QStringList courses; // name of courses
    QString depart;
    QString dob;
    QString course;
     // helper function



public:

    void addcourses(QString course);
    void setDepat(QString dept);
    int getNumberOfcourses();
    QString getDepart();
    QString getCourse();
    void setCourse(QString);
    //void delcourses(QString course);
    void setDob(QString);
    QString getDob();




};

#endif // CPPTEACHER_H
