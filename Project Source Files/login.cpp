#include "login.h"
#include "ui_login.h"
#include <QGraphicsDropShadowEffect>
//#include "customshadoweffect.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include<QDir>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
//    this->setFixedSize(960,608);
    ui->widget->setFixedSize(970,620);
    ui->username->setPlaceholderText("    k16-3898");
    ui->password->setPlaceholderText("    PASSWORD");
//    ui->login_postselect->addItem("Student");
//    ui->login_postselect->addItem("Teacher");

//    CustomShadowEffect *bodyShadow = new CustomShadowEffect();
//    bodyShadow->setBlurRadius(200.0);
//    bodyShadow->setDistance(6.0);
//    bodyShadow->setColor(QColor(100, 50, 0, 80));
//    ui->widget_2->setAutoFillBackground(true);
//    ui->widget_2->setGraphicsEffect(bodyShadow);
    // ...

    QString path("C:/Student_Management_System/");
    QDir dir = QDir::root();
    dir.mkdir(path);

}

login::~login()
{
    delete ui;
}

void login::on_login_button_clicked()
{

    id=ui->username->text();
    tech_panel_name=id;
    QString pass_store=ui->password->text();
    //hardcoding for hod
    hod_win=new admin;
    teach=new teacher_acess_n;
    std=new student;

    if(id=="HOD")
    {
        if(pass_store=="123")
        {
            hod_win->show();
           //teach->show();
           //std->show();
            this->setVisible(false);
            //this->deleteLater();
            return;
        }
    }


        QString address1="C:/Student_Management_System/Students/";
        QString address2="C:/Student_Management_System/Teacher/";
        QString join_st=address1+id+".txt";
        QString join_tech=address2+id+".txt";
        QFile check_std(join_st);
        QFile check_tech(join_tech);
        int flag1=0,flag2=0;
        int op=0;

        try{
        if(check_std.exists())
        {
          //  QMessageBox :: information(this,"Info",join);

           if(check_std.open(QFile::ReadOnly | QFile::Text))
           {
                QTextStream readfile(&check_std);

                while(!readfile.atEnd())
                {


                    QString readline=readfile.readLine();
                     if(op==8){
                        // QMessageBox :: information(this,"pepe",readline);
                     if(readline==pass_store)//maybe mistake pass_store==readline
                     {
                        flag2=1;
                        break;
                     }
                     }
                      op++;
                 }


           }
           if(flag2==1)
           {
                 std->show();
                 this->setVisible(false);

           }


          //  QMessageBox :: information(this,"Info","This user doesnot Exist");


       }
       else if(check_tech.exists())
       {
            op=0;
//             QMessageBox :: information(this,"Info",join_tech);

             if(check_tech.open(QFile::ReadOnly | QFile::Text))
             {
//                 QMessageBox :: information(this,"Info","FdsFSSFD");
                  QTextStream readfile2(&check_tech);

                  while(!readfile2.atEnd())
                  {


                      QString readline2=readfile2.readLine();
                       if(op==12){
//                           QMessageBox :: information(this,"pepe",readline2);
                       if(readline2==pass_store)//maybe mistake pass_store==readline
                       {
                          flag2=1;
                          break;
                       }
                       }
                        op++;
                   }


             }
             if(flag2==1)
             {
                   teach->show();
                   this->setVisible(false);

             }
             else
             {
                 throw "ERROR";
             }

            //  QMessageBox :: information(this,"Info","This user doesnot Exist");

        }
        else
        {
            throw "ERROR";
        }
    }
        catch(...)
        {
            QMessageBox :: warning(this,"Info","Password or username not correct");
        }
}
