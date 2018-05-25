#include "cppstudent.h"

void cppstudent::setSection(QString section){
    this->section = section;
}
void cppstudent::setSemester(int sem){
    semester = sem;
}
void cppstudent::SetWarningCount(int count){
    this->warningCount = count;
}
void cppstudent::setSemFreeze(bool hh){
    semFreeze = hh;
}
void cppstudent::setCGpa(float cgpa){
    this->cgpa=cgpa;
}
void cppstudent::setSGpa(float sgpa){
    this->sgpa=sgpa;
}
void cppstudent::setDept(QString dept){
    this->dept = dept;
}

QString cppstudent::GetSection(){
    return section;
}
int cppstudent::GetSemester(){
    return semester;

}
bool cppstudent::GetSemFreeze(){
    return semFreeze;
}
int cppstudent::GetWaringCount(){
    return warningCount;
}

float cppstudent::getCGpa(){
    return cgpa;
}
float cppstudent::getSGpa(){
    return sgpa;
}
QString cppstudent::getDept(){
    return dept;
}

cppstudent::cppstudent()
{

}


