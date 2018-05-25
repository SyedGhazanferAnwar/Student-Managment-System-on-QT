#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include "QListWidgetItem"
#include "cppstudent.h"
#include<QFile>
#include "cppteacher.h"
namespace Ui {
class admin;
}

class admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();

private slots:


    void on_show_button_clicked();

    void on_list_show_teacher_itemDoubleClicked(QListWidgetItem *item);


    void on_edit_clicked();

    void on_pushButton_2_clicked();

    void on_save_admin_clicked();



    void on_delete_std_clicked();

    void on_Add_teacher_clicked();

private:
    QString store4;
   // Ui::admin *ui;
    Ui::admin *ui;
    cppstudent student[1000];
    QString Id;//To be loaded from the file Num.txt
    QString a_id="1000";
    QString store3;
    int roll_file;
    int roll_file2;
    int k=0;
    QString a_id2="5000";
   cppteacher teacher[1000];
     //QString store_detail[100]={"Department","Name\t","Father's Name","Section\t","Password"};


};

#endif // ADMIN_H
