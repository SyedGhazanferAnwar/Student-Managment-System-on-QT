#include "admin.h"
#include "ui_admin.h"
#include <QTabWidget>
#include "QFile"
#include "QDir"
#include "QTextStream"
#include "QMessageBox"
#include<QDir>
#include "marks.h"


QFile num_students("C:/Student_Management_System/Num.txt");//global to this class
QFile teacher_num("C:/Student_Management_System/num_teach.txt");//global to this class

admin::admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    ui->centralwidget->adjustSize();
    this->setFixedSize(1920,1080);

   // ui->combo_teacher_course->clear();
    ui->combo_std_depart->addItem("<Select Depart>");
    ui->combo_std_depart->addItem("Electrical Depart");
    ui->combo_std_depart->addItem("CS depart");

    ui->comboBox_teach_post->addItem("Lecturer");
    ui->comboBox_teach_post->addItem("Professor");
    ui->comboBox_teach_post->addItem("Assistant professor");

//    ui->combo_teacher_course->addItem("CS");
//    ui->combo_teacher_course->addItem("Electrical");


    if(!num_students.exists())
    {
               num_students.open(QFile::WriteOnly | QFile:: Text);
               QTextStream ini(&num_students);//initialisin roll no || student odf number with 1000 and also reading

               ini<<a_id;
               //a_id.toInt(10);
               roll_file=a_id.toInt();
              // QMessageBox::information(this,Id,"jkh");
               num_students.flush();
               num_students.close();
    }
    else
    {
                QString num;
                num_students.open(QFile::ReadOnly | QFile:: Text);
                QTextStream getin(&num_students);
                num=getin.readAll();
                roll_file=num.toInt();
                num_students.flush();
                num_students.close();
    }


    if(!teacher_num.exists())
    {
               teacher_num.open(QFile::WriteOnly | QFile:: Text);
               QTextStream ini(&teacher_num);//initialisin roll no || student odf number with 1000 and also reading

               ini<<a_id2;
               //a_id.toInt(10);
               roll_file2=a_id2.toInt();
               //QMessageBox::information(this,Id,"jkh");
               teacher_num.flush();
               teacher_num.close();
    }
    else
    {
                QString num2;
                teacher_num.open(QFile::ReadOnly | QFile:: Text);
                QTextStream getin(&teacher_num);
                num2=getin.readAll();
                roll_file2=num2.toInt();
                teacher_num.flush();
                teacher_num.close();
    }


}


admin::~admin()
{
    delete ui;
}



void admin::on_show_button_clicked()
{
    ui->list_show_teacher->clear();
    QString store=ui->combo_std_depart->currentText();

    if(store =="CS depart")
    {
        QDir teach_file("C:/Student_Management_System/Students/");



        foreach (QFileInfo var, teach_file.entryInfoList())
        {
            if(var.isFile())
            {
                QString store2=var.fileName();
                QFile std_cs("C:/Student_Management_System/Students/"+store2);
                QTextStream cs_read(&std_cs);
                std_cs.open(QFile:: ReadOnly | QFile::Text);
                QString read=cs_read.readLine();
                if(read=="Computer Science")
                {
                   // QMessageBox::information(this,store2,"call");
                    store2=store2.remove(".txt");
                    ui->list_show_teacher->addItem(store2);
                   // ui->listWidget_2->addItem(store2);
                }

            }
        }
    }

    if(store =="Electrical Depart")
    {
        QDir teach_file("C:/Student_Management_System/Students/");



        foreach (QFileInfo var, teach_file.entryInfoList())
        {
            if(var.isFile())
            {
                QString store2=var.fileName();
                QFile std_cs("C:/Student_Management_System/Students/"+store2);
                QTextStream cs_read(&std_cs);
                std_cs.open(QFile:: ReadOnly | QFile::Text);
                QString read=cs_read.readLine();
                if(read=="Electrical")
                {
                    store2=store2.remove(".txt");
                    ui->list_show_teacher->addItem(store2);
                }

            }
        }
    }

}

void admin::on_list_show_teacher_itemDoubleClicked(QListWidgetItem *item)
{
      ui->label_hint1->clear();
      ui->plain_teach_detail->clear();


       store3=item->text();
      store4="C:/Student_Management_System/Students/"+store3+".txt";
      QFile file_teacher(store4);
     // QMessageBox ::information(this,"check",store4);

      file_teacher.open(QFile:: ReadOnly | QFile:: Text);

      QTextStream out_teacher(&file_teacher);

      while(!out_teacher.atEnd())
      {


              ui->plain_teach_detail->appendPlainText(out_teacher.readLine());




             // ui->plain_teach_detail->appendPlainText(out_teacher.readLine());




     }
      file_teacher.close();
      file_teacher.flush();

}


void admin::on_edit_clicked()
{
    ui->plain_teach_detail->setReadOnly(false);

}

void admin::on_pushButton_2_clicked()//Add for student and teacher
{

    if((ui->lineEdit->text()).isEmpty()|| (ui->lineEdit_2->text()).isEmpty()||(ui->lineEdit_3->text()).isEmpty()||
            (ui->lineEdit_4->text()).isEmpty())
    {

        QMessageBox:: warning(this,"Warning","Please fill all fields first");
    }
    else {
    //making directory for all data
    QString path("C:/Student_Management_System/Students/");
    QDir dir = QDir::root();
    dir.mkdir(path);

    QString path3("C:/Student_Management_System/Marks/");
    QDir dir33 = QDir::root();
    dir33.mkdir(path3);

    QString path35("C:/Student_Management_System/Attendence/");
    QDir dir35 = QDir::root();
    dir35.mkdir(path35);




   QString Student_ID="K";
   QString int_id;
   int_id=QString::number(roll_file);
   student[roll_file-1000].setName(ui->lineEdit->text());
   student[roll_file-1000].setId(Student_ID);
   student[roll_file-1000].setFatherName(ui->lineEdit_2->text());
   student[roll_file-1000].setSection(ui->lineEdit_3->text());
   student[roll_file-1000].changePassAdmin(ui->lineEdit_4->text());
   student[roll_file-1000].setPost("Student");
   student[roll_file-1000].setDept(ui->comboBox->currentText());


   if(ui->comboBox->currentText()=="Electrical")
   {
       Student_ID.append("E");
   }
   else
   {
       Student_ID.append("C");
   }
   Student_ID.append(ui->lineEdit_3->text());
   Student_ID.append("-");
   QString path_studentfile=path;
   path_studentfile.append(Student_ID);
   path_studentfile.append(int_id);
   path_studentfile.append(".txt");
   QMessageBox:: information(this,"Student Added",path_studentfile);

   /*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

   QString path40("C:/Student_Management_System/Attendence/"+Student_ID+int_id+"/");
   QDir dir40= QDir::root();
   dir40.mkdir(path40);

   QFile jan_att(path40+"January"+".txt");
   jan_att.open(QFile:: WriteOnly | QFile::Text);
   QTextStream jan(&jan_att);
   //QMessageBox::information(this,"","creat");

   QFile feb_att(path40+"Feb"+".txt");
   feb_att.open(QFile:: WriteOnly | QFile::Text);
   QTextStream feb(&feb_att);

   QFile march_att(path40+"March"+".txt");
   march_att.open(QFile:: WriteOnly | QFile::Text);
   QTextStream mar(&march_att);

   QFile apr_att(path40+"April"+".txt");
   apr_att.open(QFile:: WriteOnly | QFile::Text);
   QTextStream apr(&apr_att);

   QFile may_att(path40+"May"+".txt");
   may_att.open(QFile:: WriteOnly | QFile::Text);
   QTextStream may(&may_att);

   QFile aug_att(path40+"August"+".txt");
   aug_att.open(QFile:: WriteOnly | QFile::Text);
   QTextStream aug(&aug_att);

   QFile sep_att(path40+"September"+".txt");
   sep_att.open(QFile:: WriteOnly | QFile::Text);
   QTextStream sep(&sep_att);

   QFile oct_att(path40+"Oct"+".txt");
   oct_att.open(QFile:: WriteOnly | QFile::Text);
   QTextStream oct(&oct_att);

   QFile nov_att(path40+"November"+".txt");
   nov_att.open(QFile:: WriteOnly | QFile::Text);
   QTextStream nov(&nov_att);

   QFile dec_att(path40+"December"+".txt");
   dec_att.open(QFile:: WriteOnly | QFile::Text);
   QTextStream dec(&dec_att);





/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
   QString path4("C:/Student_Management_System/Marks/"+Student_ID+int_id+"/");
   QDir dir34= QDir::root();
   dir34.mkdir(path4);

   QString path_markfile=path4+"CP"+".txt";

   QFile marks_file1(path4+"CALCULUS-2"+".txt");
   marks_file1.open(QFile:: WriteOnly | QFile::Text);
   QTextStream setzero1(&marks_file1);
   setzero1<<"0"<<"\n"<<"0"<<"\n"<<"0\n"<<"0\n"<<"#\n3";

   QFile marks_file2(path4+"English"+".txt");
   marks_file2.open(QFile:: WriteOnly | QFile::Text);
   QTextStream setzero2(&marks_file2);
   setzero2<<"0"<<"\n"<<"0"<<"\n"<<"0\n"<<"0\n"<<"#\n3";

    QFile marks_file4(path4+"DLD"+".txt");
    marks_file4.open(QFile:: WriteOnly | QFile::Text);
    QTextStream setzero4(&marks_file4);
    setzero4<<"0"<<"\n"<<"0"<<"\n"<<"0\n"<<"0\n"<<"#\n3";;

    QFile marks_file5(path4+"CP"+".txt");
    marks_file5.open(QFile:: WriteOnly | QFile::Text);
    QTextStream setzero5(&marks_file5);
    setzero5<<"0"<<"\n"<<"0"<<"\n"<<"0\n"<<"0\n"<<"#\n3";;

    QFile marks_file6(path4+"PST"+".txt");
    marks_file6.open(QFile:: WriteOnly | QFile::Text);
    QTextStream setzero6(&marks_file6);
    setzero6<<"0"<<"\n"<<"0"<<"\n"<<"0\n"<<"0\n"<<"#\n3";;


 /*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
    QFile student_file(path_studentfile);
    student_file.open(QFile:: WriteOnly | QFile:: Text);
     QTextStream stu_fil_stream(&student_file);
    stu_fil_stream<<ui->comboBox->currentText()<<"\n\n";
    stu_fil_stream<<ui->lineEdit->text()<<"\n\n";
    stu_fil_stream<<ui->lineEdit_2->text()<<"\n\n";
    if(ui->comboBox->currentText()=="Electrical")
    {
        stu_fil_stream<<ui->lineEdit_3->text()<<"-EE\n\n";
    }
    else
    {
        stu_fil_stream<<ui->lineEdit_3->text()<<"-CS\n\n";
    }

    stu_fil_stream<<ui->lineEdit_4->text()<<"\n\n";


    //AT The End INCRMENTING IN THE UNIQUE ID
            QString a;
            num_students.open(QFile:: WriteOnly | QFile:: Text);
            QTextStream ini(&num_students);//initialisin roll no || student odf number with 1000 and also reading
            roll_file=roll_file+1;
            num_students.seek(0);
            ini<<roll_file;
            //marks_file.close();

}


}

void admin::on_save_admin_clicked()
{

    //QMessageBox ::information(this,"check",store4);
    QFile save_file_open(store4);
    save_file_open.open(QFile:: WriteOnly | QFile:: Text);
    QTextStream out(&save_file_open);

    QString save_plain=ui->plain_teach_detail->toPlainText();

    // ::information(this,"check",copy);
    //num_students.seek(0);

    out<<save_plain;

    k++;

    save_file_open.flush();
    save_file_open.close();
}



void admin::on_delete_std_clicked()
{
    QFile student_dlt(store4);

    student_dlt.remove();
    ui->plain_teach_detail->clear();
    on_show_button_clicked();


}

void admin::on_Add_teacher_clicked()
{
    try
    {


         if(((ui->dob_edit->text()).isEmpty()|| (ui->line_fname_teach->text()).isEmpty()||
              (ui->line_pass_teach->text()).isEmpty() ))
         {
             throw "Error";
         }

    }

    catch(...)
    {
        QMessageBox:: warning(this,"Warning","Please fill all fields first");
        return;
    }

    try
    {

        if(((ui->check_A->isChecked()==false )&& (ui->check_B->isChecked() == false) && (ui->check_C->isChecked()==false)
                && (ui->check_D->isChecked()==false) && (ui->check_F->isChecked()==false) && (ui->check_G->isChecked()==false)))
        {
              throw "Error";
        }
    }
    catch(...)
    {
        QMessageBox:: warning(this,"Warning","Please Select a Section");
        return;
    }




      teacher[roll_file2-5000].setName(ui->line_name_teach->text());
      teacher[roll_file2-5000].setFatherName(ui->line_fname_teach->text());
      teacher[roll_file2-5000].setDepat(ui->dob_edit->text());
      teacher[roll_file2-5000].changePassAdmin(ui->line_pass_teach->text());
      teacher[roll_file2-5000].setDob(ui->dob_edit->text());

      QString path2("C:/Student_Management_System/Teacher/");
      QDir dir2 = QDir::root();
      dir2.mkdir(path2);
      QString Teacher_ID="TK-";
      QString int_id2;
      int_id2=QString::number(roll_file2);
      QString section[10];

      QString path_teacherfile=path2;
      path_teacherfile.append(Teacher_ID);
      path_teacherfile.append(int_id2);
      path_teacherfile.append(".txt");
      QMessageBox:: information(this,"nn",path_teacherfile);

      QFile teacher_file(path_teacherfile);
      teacher_file.open(QFile:: WriteOnly | QFile:: Text);
      QTextStream teach_fil_stream(&teacher_file);
      teach_fil_stream<<ui->combo_teacher_course->currentText()<<"\n\n";
      teach_fil_stream<<ui->comboBox_teach_post->currentText()<<"\n\n";
      teach_fil_stream<<ui->combo_teacher->currentText()<<"\n\n";
      teach_fil_stream<<ui->line_name_teach->text()<<"\n\n";
      teach_fil_stream<<ui->line_fname_teach->text()<<"\n\n";
      teach_fil_stream<<ui->dob_edit->text()<<"\n\n";
      teach_fil_stream<<ui->line_pass_teach->text()<<"\n\n";
      teach_fil_stream<<"#\n\n";



          if(ui->check_A->isChecked())
        {
            teach_fil_stream<<ui->check_A->text()<<"\n";
         }
         if(ui->check_B->isChecked())
         {
            teach_fil_stream<<ui->check_B->text()<<"\n";
         }
           if(ui->check_C->isChecked())
        {
             teach_fil_stream<<ui->check_C->text()<<"\n";
        }
         if(ui->check_D->isChecked())
        {
             teach_fil_stream<<ui->check_D->text()<<"\n";
        }
        if(ui->check_F->isChecked())
        {
           teach_fil_stream<<ui->check_F->text()<<"\n";
        }
        if(ui->check_G->isChecked())
        {
              teach_fil_stream<<ui->check_G->text()<<"\n";
        }


         if(ui->check_A_EE->isChecked())
       {
           teach_fil_stream<<ui->check_A_EE->text()<<"\n";
        }
        if(ui->check_B_EE->isChecked())
        {
           teach_fil_stream<<ui->check_B_EE->text()<<"\n";
        }
          if(ui->check_C_EE->isChecked())
       {
            teach_fil_stream<<ui->check_C_EE->text()<<"\n";
       }
        if(ui->check_D_EE->isChecked())
       {
            teach_fil_stream<<ui->check_D_EE->text()<<"\n";
       }
       if(ui->check_F_EE->isChecked())
       {
          teach_fil_stream<<ui->check_F_EE->text()<<"\n";
       }
       if(ui->check_G_EE->isChecked())
       {
             teach_fil_stream<<ui->check_G_EE->text()<<"\n";
       }






      QString a;
      teacher_num.open(QFile:: WriteOnly | QFile:: Text);
      QTextStream ini(&teacher_num);//initialisin roll no || student odf number with 1000 and also reading
      roll_file2=roll_file2+1;
      teacher_num.seek(0);
      ini<<roll_file2;


}
