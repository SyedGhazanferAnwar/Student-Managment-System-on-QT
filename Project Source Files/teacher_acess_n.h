#ifndef TEACHER_ACESS_N_H
#define TEACHER_ACESS_N_H

#include <QMainWindow>
#include "global.h"
#include<QListWidgetItem>

namespace Ui {
class teacher_acess_n;
}

class teacher_acess_n : public QMainWindow
{
    Q_OBJECT

public:
    explicit teacher_acess_n(QWidget *parent = 0);
    ~teacher_acess_n();

public slots:


private slots:


    void on_button_show_teach_clicked();

    void on_list_teach_sec_itemDoubleClicked(QListWidgetItem *item);

    void on_list_std_view_itemDoubleClicked(QListWidgetItem *item);

    void on_button_edit_mu_clicked();

    void on_button_save_mu_clicked();





    void on_listWidget_std_sec_attend_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_std_list_attend_itemDoubleClicked(QListWidgetItem *item);

    void on_button_upload_clicked();

private:
    Ui::teacher_acess_n *ui;
    QString store7,store8,store9,std_view,store_rm;
    QString course1,storeid;
    int push;

};

#endif // TEACHER_ACESS_N_H
