#ifndef CPPSTUDENT_H
#define CPPSTUDENT_H
#include "cppperson.h"
#include <QString>


class cppstudent:public cppperson
{
private:
    QString section;
    int semester;
    int warningCount;
    bool semFreeze;
    float cgpa;
    float sgpa;
    QString dept;




public:
    cppstudent();
    void setSection(QString);
    void setSemester(int);
    void SetWarningCount(int);
    void setSemFreeze(bool);
    void setCGpa(float);
    void setSGpa(float);
    void setDept(QString dept);


    QString GetSection();
    int GetSemester();
    int GetWaringCount();
    bool GetSemFreeze();
    float getCGpa();
    float getSGpa();
    QString getDept();



};

#endif // CPPSTUDENT_H
