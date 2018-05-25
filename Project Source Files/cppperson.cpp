#include "cppperson.h"

cppperson::  cppperson(QString aname,QString aid,QString apost,QString apassword):id(aid){
    name=aname;
    post = apost;
    password = apassword;

}

cppperson::cppperson()
{
    int i;
}

void cppperson::setName(QString aname){
   name=aname;

}

int cppperson::changePassword(QString old_pass,QString  new_pass,QString new_pass1){
    if(password==old_pass){
        if(new_pass==new_pass1){
           password = new_pass;

        }else{
            return -1;

        }
    }else{
        return -2;
    }
}
void cppperson::setFatherName(QString fatherName){
    this->fathername = fatherName;
}

void cppperson::changePassAdmin(QString apass){
    password = apass;
}

//1 means changed
// 0 means an errr accured
//-1 means pass do not match
//-2 means old pass incorrect

void cppperson::setId(QString oi)
{
    oi=id;

}

void cppperson::setPost(QString apost){
    post = apost;

}
QString  cppperson::getId(){
    return id;
}

QString  cppperson::getName(){
    return name;

}

QString  cppperson::getPassword(){
    return password;

}

QString  cppperson::getPost(){
    return post;
}
QString cppperson::getFatherName(){
    return fathername;

}


