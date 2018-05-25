#include "teacher_acess_n.h"
#include "ui_teacher_acess_n.h"
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include "QDir"
#include "QPixmap"
#include "QDateTime"

teacher_acess_n::teacher_acess_n(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teacher_acess_n)
{
    ui->setupUi(this);
    this->setFixedSize(1920,1080);

    //ui->combo_teach_depart->addItem("CS Department");
    //ui->combo_teach_depart->addItem("Electrical Department");
    //QPixmap logo(":/setImage/NU_Logo.png");
    //ui->label_nu_logo->setPixmap(logo.scaled(500,500,Qt:: KeepAspectRatio));
    on_button_show_teach_clicked();
    ui->widget_table_attend->hide();
    ui->lineEdit_total->setReadOnly(true);
    ui->line_cgpa_sub->setReadOnly(true);
    ui->label_mo1->hide();
    ui->label_mo2->hide();
    ui->label_mo3->hide();
    ui->label_mo4->hide();
    ui->label_mo5->hide();
    ui->label_subject_teach->clear();
    ui->label_final->hide();
    ui->label_cgpa->hide();
    ui->line_cgpa_sub->hide();
    ui->label_subject_teach->hide();
    ui->label_mid1->hide();
    ui->label_mid2->hide();
    ui->label_sessional->hide();
    ui->plain_teach_marks->hide();
    ui->label_std_name->hide();
    ui->button_edit_mu->hide();
    ui->button_save_mu->hide();
    ui->lineEdit_mid1->setDisabled(true);
    ui->lineEdit_mid2->setDisabled(true);
    ui->lineEdit_finalmarks->setDisabled(true);
    ui->lineEdit_sessional->setDisabled(true);
    ui->lineEdit_mid1->hide();
    ui->lineEdit_mid2->hide();
    ui->lineEdit_finalmarks->hide();
    ui->lineEdit_sessional->hide();
    QFile introteach("C:/Student_Management_System/Teacher/"+tech_panel_name+".txt");
    introteach.open(QFile::ReadOnly | QFile::Text);
    QTextStream itc(&introteach);
    int kop=0;
    while(!itc.atEnd())
    {
        kop++;
        QString storefname=itc.readLine();
        if(kop==7) ui->line_name_teacher->setText(storefname);
        if(kop==9) ui->line_fname_teach->setText(storefname);
        if(kop==1) ui->line_depart_teach->setText(storefname);
        if(kop==3) ui->line_post->setText(storefname);
    }

}

teacher_acess_n::~teacher_acess_n()
{
    delete ui;
}

void teacher_acess_n::on_button_show_teach_clicked()
{
    ui->list_teach_sec->clear();
    ui->listWidget_std_sec_attend->clear();
    QString storeId=tech_panel_name;
    ui->line_id_teach->setText(storeId);
    QFile file_sec("C:/Student_Management_System/Teacher/"+storeId+".txt");
    file_sec.open(QFile::ReadOnly |QFile::Text);
    QTextStream out_sec(&file_sec);
    int k=0;
    while(!out_sec.atEnd())
    {
        QString get=out_sec.readLine();
        if(k==4)
        {
            course1=get;


        }
        //QMessageBox ::information(this,"ss",get);
        if(get=="#")
        {
            get=out_sec.read(1);
            if(get=="\n")
            {

                 while(!out_sec.atEnd())
                {
                   QString get=out_sec.readLine();
                   ui->list_teach_sec->addItem(get);
                   ui->listWidget_std_sec_attend->addItem(get);
                  // ui->listWidget_std_sec_attend->addItem(get);

                }
            break;
            }
       }
        k++;
    }
    file_sec.flush();
    file_sec.close();
    //QTextStream course(&file_sec);

    ui->line_course_teach->setText(course1);

}



void teacher_acess_n::on_list_teach_sec_itemDoubleClicked(QListWidgetItem *item)
{
    QString section= item->text();
    QString section2=section;
    section2.remove(0,8);
    section2.remove(0,2);   // cs or ee
    section=section.remove(0,8);

    section.remove(1,8);
    ui->list_std_view->clear();
    QString store7;
    QDir dir3("C:/Student_Management_System/Students");
//    if(ui->combo_teach_depart->currentText()=="Electrical Department")
//    {

        if(section2=="EE")
        {

            foreach (QFileInfo var, dir3.entryInfoList())
            {

              store7=var.fileName();
              store9=var.fileName();
              store8=store7;
              store7=store7.remove(0,2);
              store7.remove(1,12);
              store8=store8.remove(0,1);
              store8.remove(1,12);
              //store9=store7.remove(1,2);
                if(store8=="E")
                {
                  if(store7==section)
                  {
                      ui->list_std_view->addItem(store9.remove(8,12));


                  }

                }
             }
        }
   // }
    //QMessageBox :: information(this,store8,store7);

//    if(ui->combo_teach_depart->currentText()=="CS Department")
//    {


        if(section2=="CS")
        {

            foreach (QFileInfo var, dir3.entryInfoList())
            {

              store7=var.fileName();
              store9=var.fileName();
              store8=store7;
              store7=store7.remove(0,2);
              store7.remove(1,12);
              store8=store8.remove(0,1);
              store8.remove(1,12);
              //store9=store7.remove(1,2);
                if(store8=="C")
                {
                  if(store7==section)
                  {
                      ui->list_std_view->addItem(store9.remove(8,12));

                  }

                }
            }
        }


}




void teacher_acess_n::on_list_std_view_itemDoubleClicked(QListWidgetItem *item)
{
    ui->lineEdit_finalmarks->clear();
    ui->lineEdit_mid1->clear();
    ui->lineEdit_mid2->clear();
    ui->lineEdit_sessional->clear();
    ui->lineEdit_total->clear();
    ui->line_cgpa_sub->clear();
    //ui->list_teach_sec->clear();
    //ui->label_nu_logo->hide();
    ui->label_subject_teach->setText(course1);
    ui->label_cgpa->show();
    ui->label_subject_teach->show();
    ui->line_cgpa_sub->show();
    ui->lineEdit_mid1->show();
    ui->lineEdit_mid2->show();
    ui->lineEdit_finalmarks->show();
    ui->lineEdit_sessional->show();
    ui->plain_teach_marks->show();
    ui->label_mid1->show();
    ui->label_mid2->show();
    ui->label_sessional->show();
    ui->label_final->show();
    ui->label_std_name->show();
    ui->button_edit_mu->show();
    ui->button_save_mu->show();
    ui->label_mo1->show();
    ui->label_mo2->show();
    ui->label_mo3->show();
    ui->label_mo4->show();
    ui->label_mo5->show();
    ui->plain_teach_marks->setReadOnly(true);
    ui->line_cgpa_sub->setText("0.00");
    std_view=item->text();
    QFile std_select("C:/Student_Management_System/Marks/"+std_view+"/"+course1+".txt");
    //QFile std_select2("C:/Student_Management_System/Marks/"+std_view+".txt");

            //QMessageBox :: information(this,"Info","Password or username not correct");
            //QMessageBox::information(this,"call",course1);
    std_select.open(QFile:: ReadOnly | QFile:: Text);
    QTextStream out_marks(&std_select);
    //std_select2.open(QFile:: ReadOnly | QFile:: Text);
   // QTextStream out2(&std_select2);

        int i=0,j=0;
        QString ch;
        while(!out_marks.atEnd())
        {
            QString lne=out_marks.readLine();
            i++;
            //j++;

            if(lne=="0")
            {
                j++;
            }
            if(i==1)
            {
                ui->lineEdit_mid1->setText(lne);
            }

            if(i==2)
            {
                ui->lineEdit_mid2->setText(lne);
            }
            if(i==3)
            {
                ui->lineEdit_sessional->setText(lne);
            }
            if(i==4)
            {
                ui->lineEdit_finalmarks->setText(lne);
            }
            if(i==8)
            {
                ch=lne;
               // QMessageBox::information(this,lne,lne);
            }


        }

           QString m1=ui->lineEdit_mid1->text();
           QString m2=ui->lineEdit_mid2->text();
           QString m3=ui->lineEdit_sessional->text();
           QString m4=ui->lineEdit_finalmarks->text();

           int n=m1.toDouble()+m2.toDouble()+m3.toDouble()+m4.toDouble();
           QString ns=QString::number(n);
           ui->lineEdit_total->setText(ns);
           if(j==0)
          {
               QFile uploadGpa("C:/Student_Management_System/Marks/"+std_view+"/"+course1+".txt");
               uploadGpa.open(QFile::Append | QFile::Text);
               QTextStream ugpa(&uploadGpa);
               if(n>=86)    //4.0
               {

                   ui->line_cgpa_sub->setText("4.0");
                   ugpa<<"\n"<<"4.0";
               }
               if(n>=74 && n<78) //3.0
               {

                   ui->line_cgpa_sub->setText("3.0");
                   ugpa<<"\n"<<"3.0";
               }
               if(n>=78 && n<82)  // 3.33
               {
                   ui->line_cgpa_sub->setText("3.33");
                   ugpa<<"\n"<<"3.33";
               }

               if(n>=82 && n<86) // 3.67
               {
                   ui->line_cgpa_sub->setText("3.67");
                   ugpa<<"\n"<<"3.67";
               }

               if(n>=70 && n<74)    //2.67
               {
                   ui->line_cgpa_sub->setText("2.67");
                   ugpa<<"\n"<<"2.67";
               }

               if(n>=66 && n<70)   // 2.33
               {
                   ui->line_cgpa_sub->setText("2.33");
                   ugpa<<"\n"<<"2.33";
               }
               if(n>=62 && n<66) //2.0
               {
                   ui->line_cgpa_sub->setText("2.0");
                   ugpa<<"\n"<<"2.0";
               }

               if(n>=58 && n<62) // 1.67
               {
                   ui->line_cgpa_sub->setText("1.67");
                   ugpa<<"\n"<<"1.67";
               }
               if(n>=54 && n<58) //1.33
               {
                   ui->line_cgpa_sub->setText("1.33");
                   ugpa<<"\n"<<"1.33";
               }
               if(n>=50 && n<54) // 1.0
               {
                   ui->line_cgpa_sub->setText("1.0");
                   ugpa<<"\n"<<"1.0";
               }

               if(n<50)  // fail;
               {
                   ui->line_cgpa_sub->setText("Fail");
                   ugpa<<"\n"<<"Fail";
               }



           }





        std_select.flush();
        std_select.close();
      //std_select2.flush();
      //std_select2.close();
}

void teacher_acess_n::on_button_edit_mu_clicked()
{
    ui->lineEdit_finalmarks->setEnabled(true);
    ui->lineEdit_mid1->setEnabled(true);
    ui->lineEdit_mid2->setEnabled(true);
    ui->lineEdit_sessional->setEnabled(true);
}


void teacher_acess_n::on_button_save_mu_clicked()
{

    QFile marks_upload("C:/Student_Management_System/Marks/"+std_view+"/"+course1+".txt");

    marks_upload.open(QFile:: WriteOnly | QFile :: Text);
    QTextStream marks(&marks_upload);
    ui->plain_teach_marks->setReadOnly(true);

    marks<<ui->lineEdit_mid1->text()<<"\n"<<ui->lineEdit_mid2->text()<<"\n"<<ui->lineEdit_sessional->text()<<"\n"<<ui->lineEdit_finalmarks->text()<<"\n"<<"#\n3";
//    if(course1=="CP")
//    {
//        marks<<"3";
//    }
//    if(course1=="English")
//    {
//        marks<<"3";
//    }
//    if(course1=="DLD")
//    {
//        marks<<"3";
//    }
//    if(course1=="Calculus-2")
//    {
//        marks<<"3";
//    }
//    if(course1=="PST")
//    {
//        marks<<"3";
//    }


    QMessageBox::information(this,"Info","Marks has Uploaded");




}



void teacher_acess_n::on_listWidget_std_sec_attend_itemDoubleClicked(QListWidgetItem *item)
{
    QString name=item->text();
    ui->listWidget_std_list_attend->clear();

    QString section= item->text();
    QString section2=section;
    section2.remove(0,8);
    section2.remove(0,2);   // cs or ee
    section=section.remove(0,8);

    section.remove(1,8);
    //ui->list_std_view->clear();
    QString store7;
    QDir dir3("C:/Student_Management_System/Students");
//    if(ui->combo_teach_depart->currentText()=="Electrical Department")
//    {

        if(section2=="EE")
        {

            foreach (QFileInfo var, dir3.entryInfoList())
            {

              store7=var.fileName();
              store9=var.fileName();
              store8=store7;
              store7=store7.remove(0,2);
              store7.remove(1,12);
              store8=store8.remove(0,1);
              store8.remove(1,12);
              //store9=store7.remove(1,2);
                if(store8=="E")
                {
                  if(store7==section)
                  {
                       ui->listWidget_std_list_attend->addItem(store9.remove(8,12));


                  }

                }
             }
        }
   // }
    //QMessageBox :: information(this,store8,store7);

//    if(ui->combo_teach_depart->currentText()=="CS Department")
//    {


        if(section2=="CS")
        {

            foreach (QFileInfo var, dir3.entryInfoList())
            {

              store7=var.fileName();
              store9=var.fileName();
              store8=store7;
              store7=store7.remove(0,2);
              store7.remove(1,12);
              store8=store8.remove(0,1);
              store8.remove(1,12);
              //store9=store7.remove(1,2);
                if(store8=="C")
                {
                  if(store7==section)
                  {
                      ui->listWidget_std_list_attend->addItem(store9.remove(8,12));

                  }

                }
            }
        }


}

void teacher_acess_n::on_listWidget_std_list_attend_itemDoubleClicked(QListWidgetItem *item)
{
    storeid=item->text();
    ui->widget_table_attend->show();
}

void teacher_acess_n::on_button_upload_clicked()
{
      if(ui->combo_month->currentText()=="January")
      {
          QMessageBox::information(this,"storeid",storeid);
          QFile load_jan("C:/Student_Management_System/Attendence/"+storeid+"/January.txt");
          load_jan.open(QFile::WriteOnly | QFile::Text);
          QTextStream jantext(&load_jan);
          jantext<<ui->comboBox_sun1->currentText()<<"\n"<<ui->comboBox_sun8->currentText()<<"\n"<<ui->comboBox_sun15->currentText()<<"\n"
                <<ui->comboBox_sun22->currentText()<<"\n"<<ui->comboBox_sun29->currentText()<<"\n"<<ui->comboBox_mon2->currentText()<<"\n"
                <<ui->comboBox_mon9->currentText()<<"\n"<<ui->comboBox_mon16->currentText()<<"\n"<<ui->comboBox_mon23->currentText()<<"\n"
                <<ui->comboBox_mon30->currentText()<<"\n"<<ui->comboBox_tues3->currentText()<<"\n"<<ui->comboBox_tues10->currentText()<<"\n"
                <<ui->comboBox_tues17->currentText()<<"\n"<<ui->comboBox_tues24->currentText()<<"\n"<<ui->comboBox_tues31->currentText()<<"\n"
                <<ui->comboBox_wed4->currentText()<<"\n"<<ui->comboBox_wed11->currentText()<<"\n"<<ui->comboBox_wed18->currentText()<<"\n"
                <<ui->comboBox_wed25->currentText()<<"\n"<<ui->comboBox_thurs5->currentText()<<"\n"<<ui->comboBox_thurs12->currentText()<<"\n"
                <<ui->comboBox_thurs19->currentText()<<"\n"<<ui->comboBox_thurs26->currentText()<<"\n"<<ui->comboBox_fri6->currentText()<<"\n"
                <<ui->comboBox_fri13->currentText()<<"\n"<<ui->comboBox_fri20->currentText()
                <<"\n"<<ui->comboBox_fri27->currentText()<<"\n"<<ui->comboBox_sat7->currentText()<<"\n"<<ui->comboBox_sat14->currentText()<<"\n"
               <<ui->comboBox_sat21->currentText()<<"\n"<<ui->comboBox_sat28->currentText();
          load_jan.close();
      }
      if(ui->combo_month->currentText()=="Feburary")
      {
         // QMessageBox::information(this,"storeid",storeid);
          QFile load_feb("C:/Student_Management_System/Attendence/"+storeid+"/Feburary.txt");
          load_feb.open(QFile::WriteOnly | QFile::Text);
          QTextStream febtext(&load_feb);
          febtext<<ui->comboBox_sun1->currentText()<<"\n"<<ui->comboBox_sun8->currentText()<<"\n"<<ui->comboBox_sun15->currentText()<<"\n"
                <<ui->comboBox_sun22->currentText()<<"\n"<<ui->comboBox_sun29->currentText()<<"\n"<<ui->comboBox_mon2->currentText()<<"\n"
                <<ui->comboBox_mon9->currentText()<<"\n"<<ui->comboBox_mon16->currentText()<<"\n"<<ui->comboBox_mon23->currentText()<<"\n"
                <<ui->comboBox_mon30->currentText()<<"\n"<<ui->comboBox_tues3->currentText()<<"\n"<<ui->comboBox_tues10->currentText()<<"\n"
                <<ui->comboBox_tues17->currentText()<<"\n"<<ui->comboBox_tues24->currentText()<<"\n"<<ui->comboBox_tues31->currentText()<<"\n"
                <<ui->comboBox_wed4->currentText()<<"\n"<<ui->comboBox_wed11->currentText()<<"\n"<<ui->comboBox_wed18->currentText()<<"\n"
                <<ui->comboBox_wed25->currentText()<<"\n"<<ui->comboBox_thurs5->currentText()<<"\n"<<ui->comboBox_thurs12->currentText()<<"\n"
                <<ui->comboBox_thurs19->currentText()<<"\n"<<ui->comboBox_thurs26->currentText()<<"\n"<<ui->comboBox_fri6->currentText()<<"\n"
                <<ui->comboBox_fri13->currentText()<<"\n"<<ui->comboBox_fri20->currentText()
                <<"\n"<<ui->comboBox_fri27->currentText()<<"\n"<<ui->comboBox_sat7->currentText()<<"\n"<<ui->comboBox_sat14->currentText()<<"\n"
               <<ui->comboBox_sat21->currentText()<<"\n"<<ui->comboBox_sat28->currentText();
      }
      if(ui->combo_month->currentText()=="March")
      {
          //QMessageBox::information(this,"storeid",storeid);
          QFile load_mar("C:/Student_Management_System/Attendence/"+storeid+"/March.txt");
          load_mar.open(QFile::WriteOnly | QFile::Text);
          QTextStream martext(&load_mar);
          martext<<ui->comboBox_sun1->currentText()<<"\n"<<ui->comboBox_sun8->currentText()<<"\n"<<ui->comboBox_sun15->currentText()<<"\n"
                <<ui->comboBox_sun22->currentText()<<"\n"<<ui->comboBox_sun29->currentText()<<"\n"<<ui->comboBox_mon2->currentText()<<"\n"
                <<ui->comboBox_mon9->currentText()<<"\n"<<ui->comboBox_mon16->currentText()<<"\n"<<ui->comboBox_mon23->currentText()<<"\n"
                <<ui->comboBox_mon30->currentText()<<"\n"<<ui->comboBox_tues3->currentText()<<"\n"<<ui->comboBox_tues10->currentText()<<"\n"
                <<ui->comboBox_tues17->currentText()<<"\n"<<ui->comboBox_tues24->currentText()<<"\n"<<ui->comboBox_tues31->currentText()<<"\n"
                <<ui->comboBox_wed4->currentText()<<"\n"<<ui->comboBox_wed11->currentText()<<"\n"<<ui->comboBox_wed18->currentText()<<"\n"
                <<ui->comboBox_wed25->currentText()<<"\n"<<ui->comboBox_thurs5->currentText()<<"\n"<<ui->comboBox_thurs12->currentText()<<"\n"
                <<ui->comboBox_thurs19->currentText()<<"\n"<<ui->comboBox_thurs26->currentText()<<"\n"<<ui->comboBox_fri6->currentText()<<"\n"
                <<ui->comboBox_fri13->currentText()<<"\n"<<ui->comboBox_fri20->currentText()
                <<"\n"<<ui->comboBox_fri27->currentText()<<"\n"<<ui->comboBox_sat7->currentText()<<"\n"<<ui->comboBox_sat14->currentText()<<"\n"
               <<ui->comboBox_sat21->currentText()<<"\n"<<ui->comboBox_sat28->currentText();
      }

      if(ui->combo_month->currentText()=="April")
      {
          //QMessageBox::information(this,"storeid",storeid);
          QFile load_apr("C:/Student_Management_System/Attendence/"+storeid+"/April.txt");
          load_apr.open(QFile::WriteOnly | QFile::Text);
          QTextStream aprtext(&load_apr);
          aprtext<<ui->comboBox_sun1->currentText()<<"\n"<<ui->comboBox_sun8->currentText()<<"\n"<<ui->comboBox_sun15->currentText()<<"\n"
                <<ui->comboBox_sun22->currentText()<<"\n"<<ui->comboBox_sun29->currentText()<<"\n"<<ui->comboBox_mon2->currentText()<<"\n"
                <<ui->comboBox_mon9->currentText()<<"\n"<<ui->comboBox_mon16->currentText()<<"\n"<<ui->comboBox_mon23->currentText()<<"\n"
                <<ui->comboBox_mon30->currentText()<<"\n"<<ui->comboBox_tues3->currentText()<<"\n"<<ui->comboBox_tues10->currentText()<<"\n"
                <<ui->comboBox_tues17->currentText()<<"\n"<<ui->comboBox_tues24->currentText()<<"\n"<<ui->comboBox_tues31->currentText()<<"\n"
                <<ui->comboBox_wed4->currentText()<<"\n"<<ui->comboBox_wed11->currentText()<<"\n"<<ui->comboBox_wed18->currentText()<<"\n"
                <<ui->comboBox_wed25->currentText()<<"\n"<<ui->comboBox_thurs5->currentText()<<"\n"<<ui->comboBox_thurs12->currentText()<<"\n"
                <<ui->comboBox_thurs19->currentText()<<"\n"<<ui->comboBox_thurs26->currentText()<<"\n"<<ui->comboBox_fri6->currentText()<<"\n"
                <<ui->comboBox_fri13->currentText()<<"\n"<<ui->comboBox_fri20->currentText()
                <<"\n"<<ui->comboBox_fri27->currentText()<<"\n"<<ui->comboBox_sat7->currentText()<<"\n"<<ui->comboBox_sat14->currentText()<<"\n"
               <<ui->comboBox_sat21->currentText()<<"\n"<<ui->comboBox_sat28->currentText();
      }

      if(ui->combo_month->currentText()=="May")
      {
          //QMessageBox::information(this,"storeid",storeid);
          QFile load_may("C:/Student_Management_System/Attendence/"+storeid+"/May.txt");
          load_may.open(QFile::WriteOnly | QFile::Text);
          QTextStream maytext(&load_may);
          maytext<<ui->comboBox_sun1->currentText()<<"\n"<<ui->comboBox_sun8->currentText()<<"\n"<<ui->comboBox_sun15->currentText()<<"\n"
                <<ui->comboBox_sun22->currentText()<<"\n"<<ui->comboBox_sun29->currentText()<<"\n"<<ui->comboBox_mon2->currentText()<<"\n"
                <<ui->comboBox_mon9->currentText()<<"\n"<<ui->comboBox_mon16->currentText()<<"\n"<<ui->comboBox_mon23->currentText()<<"\n"
                <<ui->comboBox_mon30->currentText()<<"\n"<<ui->comboBox_tues3->currentText()<<"\n"<<ui->comboBox_tues10->currentText()<<"\n"
                <<ui->comboBox_tues17->currentText()<<"\n"<<ui->comboBox_tues24->currentText()<<"\n"<<ui->comboBox_tues31->currentText()<<"\n"
                <<ui->comboBox_wed4->currentText()<<"\n"<<ui->comboBox_wed11->currentText()<<"\n"<<ui->comboBox_wed18->currentText()<<"\n"
                <<ui->comboBox_wed25->currentText()<<"\n"<<ui->comboBox_thurs5->currentText()<<"\n"<<ui->comboBox_thurs12->currentText()<<"\n"
                <<ui->comboBox_thurs19->currentText()<<"\n"<<ui->comboBox_thurs26->currentText()<<"\n"<<ui->comboBox_fri6->currentText()<<"\n"
                <<ui->comboBox_fri13->currentText()<<"\n"<<ui->comboBox_fri20->currentText()
                <<"\n"<<ui->comboBox_fri27->currentText()<<"\n"<<ui->comboBox_sat7->currentText()<<"\n"<<ui->comboBox_sat14->currentText()<<"\n"
               <<ui->comboBox_sat21->currentText()<<"\n"<<ui->comboBox_sat28->currentText();
      }

      if(ui->combo_month->currentText()=="August")
      {
          //QMessageBox::information(this,"storeid",storeid);
          QFile load_aug("C:/Student_Management_System/Attendence/"+storeid+"/August.txt");
          load_aug.open(QFile::WriteOnly | QFile::Text);
          QTextStream augtext(&load_aug);
          augtext<<ui->comboBox_sun1->currentText()<<"\n"<<ui->comboBox_sun8->currentText()<<"\n"<<ui->comboBox_sun15->currentText()<<"\n"
                <<ui->comboBox_sun22->currentText()<<"\n"<<ui->comboBox_sun29->currentText()<<"\n"<<ui->comboBox_mon2->currentText()<<"\n"
                <<ui->comboBox_mon9->currentText()<<"\n"<<ui->comboBox_mon16->currentText()<<"\n"<<ui->comboBox_mon23->currentText()<<"\n"
                <<ui->comboBox_mon30->currentText()<<"\n"<<ui->comboBox_tues3->currentText()<<"\n"<<ui->comboBox_tues10->currentText()<<"\n"
                <<ui->comboBox_tues17->currentText()<<"\n"<<ui->comboBox_tues24->currentText()<<"\n"<<ui->comboBox_tues31->currentText()<<"\n"
                <<ui->comboBox_wed4->currentText()<<"\n"<<ui->comboBox_wed11->currentText()<<"\n"<<ui->comboBox_wed18->currentText()<<"\n"
                <<ui->comboBox_wed25->currentText()<<"\n"<<ui->comboBox_thurs5->currentText()<<"\n"<<ui->comboBox_thurs12->currentText()<<"\n"
                <<ui->comboBox_thurs19->currentText()<<"\n"<<ui->comboBox_thurs26->currentText()<<"\n"<<ui->comboBox_fri6->currentText()<<"\n"
                <<ui->comboBox_fri13->currentText()<<"\n"<<ui->comboBox_fri20->currentText()
                <<"\n"<<ui->comboBox_fri27->currentText()<<"\n"<<ui->comboBox_sat7->currentText()<<"\n"<<ui->comboBox_sat14->currentText()<<"\n"
               <<ui->comboBox_sat21->currentText()<<"\n"<<ui->comboBox_sat28->currentText();
      }

      if(ui->combo_month->currentText()=="September")
      {
          //QMessageBox::information(this,"storeid",storeid);
          QFile load_sep("C:/Student_Management_System/Attendence/"+storeid+"/September.txt");
          load_sep.open(QFile::WriteOnly | QFile::Text);
          QTextStream septext(&load_sep);
          septext<<ui->comboBox_sun1->currentText()<<"\n"<<ui->comboBox_sun8->currentText()<<"\n"<<ui->comboBox_sun15->currentText()<<"\n"
                <<ui->comboBox_sun22->currentText()<<"\n"<<ui->comboBox_sun29->currentText()<<"\n"<<ui->comboBox_mon2->currentText()<<"\n"
                <<ui->comboBox_mon9->currentText()<<"\n"<<ui->comboBox_mon16->currentText()<<"\n"<<ui->comboBox_mon23->currentText()<<"\n"
                <<ui->comboBox_mon30->currentText()<<"\n"<<ui->comboBox_tues3->currentText()<<"\n"<<ui->comboBox_tues10->currentText()<<"\n"
                <<ui->comboBox_tues17->currentText()<<"\n"<<ui->comboBox_tues24->currentText()<<"\n"<<ui->comboBox_tues31->currentText()<<"\n"
                <<ui->comboBox_wed4->currentText()<<"\n"<<ui->comboBox_wed11->currentText()<<"\n"<<ui->comboBox_wed18->currentText()<<"\n"
                <<ui->comboBox_wed25->currentText()<<"\n"<<ui->comboBox_thurs5->currentText()<<"\n"<<ui->comboBox_thurs12->currentText()<<"\n"
                <<ui->comboBox_thurs19->currentText()<<"\n"<<ui->comboBox_thurs26->currentText()<<"\n"<<ui->comboBox_fri6->currentText()<<"\n"
                <<ui->comboBox_fri13->currentText()<<"\n"<<ui->comboBox_fri20->currentText()
                <<"\n"<<ui->comboBox_fri27->currentText()<<"\n"<<ui->comboBox_sat7->currentText()<<"\n"<<ui->comboBox_sat14->currentText()<<"\n"
               <<ui->comboBox_sat21->currentText()<<"\n"<<ui->comboBox_sat28->currentText();
      }


      if(ui->combo_month->currentText()=="October")
      {
          //QMessageBox::information(this,"storeid",storeid);
          QFile load_oct("C:/Student_Management_System/Attendence/"+storeid+"/October.txt");
          load_oct.open(QFile::WriteOnly | QFile::Text);
          QTextStream octtext(&load_oct);
          octtext<<ui->comboBox_sun1->currentText()<<"\n"<<ui->comboBox_sun8->currentText()<<"\n"<<ui->comboBox_sun15->currentText()<<"\n"
                <<ui->comboBox_sun22->currentText()<<"\n"<<ui->comboBox_sun29->currentText()<<"\n"<<ui->comboBox_mon2->currentText()<<"\n"
                <<ui->comboBox_mon9->currentText()<<"\n"<<ui->comboBox_mon16->currentText()<<"\n"<<ui->comboBox_mon23->currentText()<<"\n"
                <<ui->comboBox_mon30->currentText()<<"\n"<<ui->comboBox_tues3->currentText()<<"\n"<<ui->comboBox_tues10->currentText()<<"\n"
                <<ui->comboBox_tues17->currentText()<<"\n"<<ui->comboBox_tues24->currentText()<<"\n"<<ui->comboBox_tues31->currentText()<<"\n"
                <<ui->comboBox_wed4->currentText()<<"\n"<<ui->comboBox_wed11->currentText()<<"\n"<<ui->comboBox_wed18->currentText()<<"\n"
                <<ui->comboBox_wed25->currentText()<<"\n"<<ui->comboBox_thurs5->currentText()<<"\n"<<ui->comboBox_thurs12->currentText()<<"\n"
                <<ui->comboBox_thurs19->currentText()<<"\n"<<ui->comboBox_thurs26->currentText()<<"\n"<<ui->comboBox_fri6->currentText()<<"\n"
                <<ui->comboBox_fri13->currentText()<<"\n"<<ui->comboBox_fri20->currentText()
                <<"\n"<<ui->comboBox_fri27->currentText()<<"\n"<<ui->comboBox_sat7->currentText()<<"\n"<<ui->comboBox_sat14->currentText()<<"\n"
               <<ui->comboBox_sat21->currentText()<<"\n"<<ui->comboBox_sat28->currentText();    }

      if(ui->combo_month->currentText()=="November")
      {
          //QMessageBox::information(this,"storeid",storeid);
          QFile load_nov("C:/Student_Management_System/Attendence/"+storeid+"/November.txt");
          load_nov.open(QFile::WriteOnly | QFile::Text);
          QTextStream novtext(&load_nov);
          novtext<<ui->comboBox_sun1->currentText()<<"\n"<<ui->comboBox_sun8->currentText()<<"\n"<<ui->comboBox_sun15->currentText()<<"\n"
                <<ui->comboBox_sun22->currentText()<<"\n"<<ui->comboBox_sun29->currentText()<<"\n"<<ui->comboBox_mon2->currentText()<<"\n"
                <<ui->comboBox_mon9->currentText()<<"\n"<<ui->comboBox_mon16->currentText()<<"\n"<<ui->comboBox_mon23->currentText()<<"\n"
                <<ui->comboBox_mon30->currentText()<<"\n"<<ui->comboBox_tues3->currentText()<<"\n"<<ui->comboBox_tues10->currentText()<<"\n"
                <<ui->comboBox_tues17->currentText()<<"\n"<<ui->comboBox_tues24->currentText()<<"\n"<<ui->comboBox_tues31->currentText()<<"\n"
                <<ui->comboBox_wed4->currentText()<<"\n"<<ui->comboBox_wed11->currentText()<<"\n"<<ui->comboBox_wed18->currentText()<<"\n"
                <<ui->comboBox_wed25->currentText()<<"\n"<<ui->comboBox_thurs5->currentText()<<"\n"<<ui->comboBox_thurs12->currentText()<<"\n"
                <<ui->comboBox_thurs19->currentText()<<"\n"<<ui->comboBox_thurs26->currentText()<<"\n"<<ui->comboBox_fri6->currentText()<<"\n"
                <<ui->comboBox_fri6->currentText()<<"\n"<<ui->comboBox_fri13->currentText()<<"\n"<<ui->comboBox_fri20->currentText()
                <<"\n"<<ui->comboBox_fri27->currentText()<<"\n"<<ui->comboBox_sat7->currentText()<<"\n"<<ui->comboBox_sat14->currentText()<<"\n"
               <<ui->comboBox_sat21->currentText()<<"\n"<<ui->comboBox_sat28->currentText();
      }

      if(ui->combo_month->currentText()=="December")
      {
          //QMessageBox::information(this,"storeid",storeid);
          QFile load_dec("C:/Student_Management_System/Attendence/"+storeid+"/December.txt");
          load_dec.open(QFile::WriteOnly | QFile::Text);
          QTextStream dectext(&load_dec);
          dectext<<ui->comboBox_sun1->currentText()<<"\n"<<ui->comboBox_sun8->currentText()<<"\n"<<ui->comboBox_sun15->currentText()<<"\n"
                <<ui->comboBox_sun22->currentText()<<"\n"<<ui->comboBox_sun29->currentText()<<"\n"<<ui->comboBox_mon2->currentText()<<"\n"
                <<ui->comboBox_mon9->currentText()<<"\n"<<ui->comboBox_mon16->currentText()<<"\n"<<ui->comboBox_mon23->currentText()<<"\n"
                <<ui->comboBox_mon30->currentText()<<"\n"<<ui->comboBox_tues3->currentText()<<"\n"<<ui->comboBox_tues10->currentText()<<"\n"
                <<ui->comboBox_tues17->currentText()<<"\n"<<ui->comboBox_tues24->currentText()<<"\n"<<ui->comboBox_tues31->currentText()<<"\n"
                <<ui->comboBox_wed4->currentText()<<"\n"<<ui->comboBox_wed11->currentText()<<"\n"<<ui->comboBox_wed18->currentText()<<"\n"
                <<ui->comboBox_wed25->currentText()<<"\n"<<ui->comboBox_thurs5->currentText()<<"\n"<<ui->comboBox_thurs12->currentText()<<"\n"
                <<ui->comboBox_thurs19->currentText()<<"\n"<<ui->comboBox_thurs26->currentText()<<"\n"<<ui->comboBox_fri6->currentText()<<"\n"
                <<ui->comboBox_fri13->currentText()<<"\n"<<ui->comboBox_fri20->currentText()
                <<"\n"<<ui->comboBox_fri27->currentText()<<"\n"<<ui->comboBox_sat7->currentText()<<"\n"<<ui->comboBox_sat14->currentText()<<"\n"
               <<ui->comboBox_sat21->currentText()<<"\n"<<ui->comboBox_sat28->currentText();
      }

       QMessageBox::information(this,"Info","Attendence has Uploaded");
}
