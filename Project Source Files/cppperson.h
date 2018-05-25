#ifndef cppperson_H
#define cppperson_H
#include <QString>


class cppperson
{
    QString id;
    QString name;
    QString password;
    QString post;//0)  For student 1) For teacher 2) for Admin ....
    QString  fathername;




public:
   cppperson(QString aname,QString aid,QString apost,QString apassword);
   cppperson();

// //////////////////////////////////SETTERS/////////////////////////////////////////////////////
void setName(QString aname);
int changePassword(QString old_pass,QString new_pass,QString new_pass1);
void setPost(QString apost);
void changePassAdmin(QString aPass);
void setId(QString oi);
void setFatherName(QString fatherName);



// ///////////////////////////////////GETTERS/////////////////////////////////////////////////////
QString  getId();
QString  getName();
QString  getPassword();
QString  getPost();
QString  getFatherName();

};

#endif // cppperson_H
