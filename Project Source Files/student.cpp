#include "student.h"
#include "ui_student.h"
#include "QDir"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

student::student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::student)
{

    ui->setupUi(this);
    this->setFixedSize(1920,1080);
    ui->line_cp_mid1->setReadOnly(true);
    ui->line_cp_mid2->setReadOnly(true);
    ui->line_cp_sessional->setReadOnly(true);
    ui->line_cp_final->setReadOnly(true);
    ui->line_cp_gpa->setReadOnly(true);
    ui->line_cp_total->setReadOnly(true);

    ui->line_dld_mid1->setReadOnly(true);
    ui->line_dld_mid2->setReadOnly(true);
    ui->line_dld_sessional->setReadOnly(true);
    ui->line_dld_final->setReadOnly(true);
    ui->line_dld_gpa->setReadOnly(true);
    ui->line_dld_total->setReadOnly(true);

    ui->line_pst_mid1->setReadOnly(true);
    ui->line_pst_mid2->setReadOnly(true);
    ui->line_pst_sessional->setReadOnly(true);
    ui->line_pst_final->setReadOnly(true);
    ui->line_pst_gpa->setReadOnly(true);
    ui->line_pst_total->setReadOnly(true);

    ui->line_cal_mid1->setReadOnly(true);
    ui->line_cal_mid2->setReadOnly(true);
    ui->line_cal_sessional->setReadOnly(true);
    ui->line_cal_final->setReadOnly(true);
    ui->line_cal_gpa->setReadOnly(true);
    ui->line_cal_total->setReadOnly(true);

    ui->line_eng_mid1->setReadOnly(true);
    ui->line_eng_mid2->setReadOnly(true);
    ui->line_eng_sessional->setReadOnly(true);
    ui->line_eng_mid1_final->setReadOnly(true);
    ui->line_eng_gpa->setReadOnly(true);
    ui->line_eng_total->setReadOnly(true);

    QFile intro_std("C:/Student_Management_System/Students/"+tech_panel_name+".txt");
    intro_std.open(QFile::ReadOnly | QFile::Text);
    QTextStream intro(&intro_std);
    int kg=0;
    while(!intro.atEnd())
    {
        kg++;
        QString intro_read=intro.readLine();

        if(kg==1)
        {
            ui->department->setText(intro_read);
        }
        if(kg==3)
        {
            ui->student_name->setText(intro_read);
        }
        if(kg==5)
        {
            ui->fathers_name->setText(intro_read);
        }
        if(kg==7)
        {
            ui->section->setText(intro_read);
        }

    }
      ui->noofcourses->setText("5");
     intro_std.flush();
     intro_std.close();

    /*************************** cp read marks **********************************/
    int l=0,total=0;
    QFile cp_marks("C:/Student_Management_System/Marks/"+tech_panel_name+"/CP.txt");
    cp_marks.open(QFile::ReadOnly | QFile::Text);
    QTextStream cp(&cp_marks);
    while(!cp.atEnd())
    {
        l++;
        QString storedata=cp.readLine();
        if(l!=6)
        {
                total=storedata.toDouble()+total;

        }

        if(l==1)
        {
            ui->line_cp_mid1->setText(storedata);
        }
        if(l==2)
        {
            ui->line_cp_mid2->setText(storedata);
        }
        if(l==3)
        {
            ui->line_cp_sessional->setText(storedata);
        }
        if(l==4)
        {
            ui->line_cp_final->setText(storedata);
        }
        if(l==7)
        {
            ui->line_cp_gpa->setText(storedata);
        }

    }
    cp_marks.flush();
    cp_marks.close();

      QString tc=QString::number(total);
      ui->line_cp_total->setText(tc);

      /*************************** dld read marks **********************************/

       int l1=0,total1=0;
       QString tc1;
      QFile dld_marks("C:/Student_Management_System/Marks/"+tech_panel_name+"/DLD.txt");
      dld_marks.open(QFile::ReadOnly | QFile::Text);
      QTextStream dld(&dld_marks);
      while(!dld.atEnd())
      {
          l1++;
          QString storedata1=dld.readLine();
          if(l1!=6)
          {
              total1=storedata1.toDouble()+total1;
             // QMessageBox::information(this,"",tc1);

          }

          if(l1==1)
          {
              ui->line_dld_mid1->setText(storedata1);
          }
          if(l1==2)
          {
              ui->line_dld_mid2->setText(storedata1);
          }
          if(l1==3)
          {
              ui->line_dld_sessional->setText(storedata1);
          }
          if(l1==4)
          {
              ui->line_dld_final->setText(storedata1);
          }
          if(l1==7)
          {
              ui->line_dld_gpa->setText(storedata1);
          }

      }
      tc1=QString::number(total1);
      ui->line_dld_total->setText(tc1);

      /*************************** English read marks **********************************/

      int l2=0,total2=0;
      QString tc2;
      QFile english_marks("C:/Student_Management_System/Marks/"+tech_panel_name+"/English.txt");
      english_marks.open(QFile::ReadOnly | QFile::Text);
      QTextStream eng(&english_marks);
      while(!eng.atEnd())
      {
          l2++;
          QString storedata2=eng.readLine();
          if(l2!=6)
          {
              total2=storedata2.toDouble()+total2;
             // QMessageBox::information(this,"",tc1);

          }

          if(l2==1)
          {
              ui->line_eng_mid1->setText(storedata2);
          }
          if(l2==2)
          {
              ui->line_eng_mid2->setText(storedata2);
          }
          if(l2==3)
          {
              ui->line_eng_sessional->setText(storedata2);
          }
          if(l2==4)
          {
              ui->line_eng_mid1_final->setText(storedata2);
          }
          if(l2==7)
          {
              ui->line_eng_gpa->setText(storedata2);
          }

      }
      tc2=QString::number(total2);
      ui->line_eng_total->setText(tc2);

      /*************************** Calculus read marks **********************************/

       int l3=0,total3=0;
       QString tc3;
      QFile calculus_marks("C:/Student_Management_System/Marks/"+tech_panel_name+"/CALCULUS-2.txt");
      calculus_marks.open(QFile::ReadOnly | QFile::Text);
      QTextStream cal(&calculus_marks);
      while(!cal.atEnd())
      {
          l3++;
          QString storedata3=cal.readLine();
          if(l3!=6)
          {
              total3=storedata3.toDouble()+total3;
             // QMessageBox::information(this,"",tc1);

          }

          if(l3==1)
          {
              ui->line_cal_mid1->setText(storedata3);
          }
          if(l3==2)
          {
              ui->line_cal_mid2->setText(storedata3);
          }
          if(l3==3)
          {
              ui->line_cal_sessional->setText(storedata3);
          }
          if(l3==4)
          {
              ui->line_cal_final->setText(storedata3);
          }
          if(l3==7)
          {
              ui->line_cal_gpa->setText(storedata3);
          }

      }
      tc3=QString::number(total3);
      ui->line_cal_total->setText(tc3);
      calculus_marks.flush();
      calculus_marks.close();



      /*************************** PSt read marks **********************************/

       int l5=0,total5=0;
       QString tc5;
      QFile pst_marks("C:/Student_Management_System/Marks/"+tech_panel_name+"/PST.txt");
      pst_marks.open(QFile::ReadOnly | QFile::Text);
      QTextStream pst(&pst_marks);
      while(!pst.atEnd())
      {
          l5++;
          QString storedata5=pst.readLine();
          if(l5!=6)
          {
              total5=storedata5.toDouble()+total5;
             // QMessageBox::information(this,"",tc1);

          }

          if(l5==1)
          {
              ui->line_pst_mid1->setText(storedata5);
          }
          if(l5==2)
          {
              ui->line_pst_mid2->setText(storedata5);
          }
          if(l5==3)
          {
              ui->line_pst_sessional->setText(storedata5);
          }
          if(l5==4)
          {
              ui->line_pst_final->setText(storedata5);
          }
          if(l5==7)
          {
              ui->line_pst_gpa->setText(storedata5);
          }

      }
      tc5=QString::number(total5);
      ui->line_pst_total->setText(tc5);

      /****************************** attendence **********************/



}

student::~student()
{
    delete ui;
}

void student::on_button_view_attendence_clicked()
{
    QMessageBox::information(this,"",tech_panel_name);
    int lm=0;

    if(ui->combo_monthstd->currentText()=="January")
    {
        QFile view_attend("C:/Student_Management_System/Attendence/"+tech_panel_name+"/"+"January.txt");
        view_attend.open(QFile::ReadOnly | QFile::Text);
        QTextStream read_attend(&view_attend);

      while(!read_attend.atEnd())
      {

        QString store_attend=read_attend.readLine();
        lm++;
        if(lm==1)
        {
            ui->label_sun1->setText(store_attend);
        }
        if(lm==2)
        {
            ui->label_sun8->setText(store_attend);
        }
        if(lm==3)
        {
            ui->label_sun15->setText(store_attend);
        }
        if(lm==4)
        {
            ui->label_sun22->setText(store_attend);
        }
        if(lm==5)
        {
            ui->label_sun29->setText(store_attend);
        }

        if(lm==6)
        {
            ui->label_mon2->setText(store_attend);
        }
        if(lm==7)
        {
            ui->label_mon9->setText(store_attend);
        }


        if(lm==8)
        {
            ui->label_mon16->setText(store_attend);
        }
        if(lm==9)
        {
            ui->label_mon23->setText(store_attend);
        }
        if(lm==10)
        {
            ui->label_mon30->setText(store_attend);
        }
        if(lm==11)
        {
            ui->label_tues3->setText(store_attend);
        }
        if(lm==12)
        {
            ui->label_tues10->setText(store_attend);
        }
        if(lm==13)
        {
            ui->label_tues17->setText(store_attend);
        }
        if(lm==14)
        {
            ui->label_tues24->setText(store_attend);
        }
        if(lm==15)
        {
            ui->label_tues31->setText(store_attend);
        }
        if(lm==16)
        {
            ui->label_wed4->setText(store_attend);
        }
        if(lm==17)
        {
            ui->label_wed11->setText(store_attend);
        }
        if(lm==18)
        {
            ui->label_wed18->setText(store_attend);
        }
        if(lm==19)
        {
            ui->label_wed25->setText(store_attend);
        }
        if(lm==20)
        {
            ui->label_thurs5->setText(store_attend);
        }
        if(lm==21)
        {
            ui->label_thurs12->setText(store_attend);
        }
        if(lm==22)
        {
            ui->label_thurs19->setText(store_attend);
        }

        if(lm==23)
        {
            ui->label_thurs26->setText(store_attend);
        }
        if(lm==24)
        {
            ui->label_fri6->setText(store_attend);
        }
        if(lm==25)
        {
            ui->label_fri13->setText(store_attend);
        }
        if(lm==26)
        {
            ui->label_fri20->setText(store_attend);
        }
        if(lm==27)
        {
            ui->label_fri27->setText(store_attend);
        }

        if(lm==28)
        {
            ui->label_sat7->setText(store_attend);
        }

        if(lm==29)
        {
            ui->label_sat14->setText(store_attend);
        }
        if(lm==30)
        {
            ui->label_sat21->setText(store_attend);
        }
        if(lm==31)
        {
            ui->label_sat28->setText(store_attend);
        }

     }
   }
}
