#include "teacher_access.h"
#include "ui_teacher_access.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"


teacher_access::teacher_access(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teacher_access)
{
    ui->setupUi(this);
    this->setFixedSize(1920,1080);
}

teacher_access::~teacher_access()
{
    delete ui;
}



void teacher_access::on_button_Show_teach_clicked()
{
    QString storeId=tech_panel_name;
    QFile file_sec("C:/Student_Management_System/Teacher/"+storeId+".txt");
    QMessageBox ::information(this,"ss",tech_panel_name);

    file_sec.open(QFile :: ReadOnly | QFile :: Text);

    QTextStream sec_out(&file_sec);
//    while(!sec_out.atEnd())
//    {
//        QString store_sec=sec_out.read(1);


//        //if(sec_out)
//    }


}
