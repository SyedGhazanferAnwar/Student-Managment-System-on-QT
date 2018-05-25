#include <QString>
#include <QStringList>
#include "cppteacher.h"
int cppteacher::getNumberOfcourses(){
    return noOfcourses;
}
void cppteacher::setDepat(QString  dept ){
    depart=dept;
}
QString cppteacher::getDepart(){
    return depart;
}
void cppteacher::addcourses(QString course){
    courses.append(course);
}

void cppteacher::setDob(QString dob){
    this->dob= dob;
}
QString cppteacher::getDob(){
    return dob;
}
QString cppteacher::getCourse(){
    return course;
}
void cppteacher::setCourse(QString a){

    this->course = a;

}


