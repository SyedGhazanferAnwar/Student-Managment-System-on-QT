#ifndef TEACHER_ACCESS_H
#define TEACHER_ACCESS_H

#include <QMainWindow>
#include "global.h"

namespace Ui {
class teacher_access;
}

class teacher_access : public QMainWindow
{
    Q_OBJECT

public:
    explicit teacher_access(QWidget *parent = 0);
    ~teacher_access();

private slots:
//    void on_pushButton_clicked();

    void on_button_Show_teach_clicked();

private:
    Ui::teacher_access *ui;
    //login *login_panel;
};

#endif // TEACHER_ACCESS_H
