#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<admin.h>
#include<teacher_access.h>
#include<teacher_acess_n.h>
#include<student.h>
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_login_button_clicked();

private:
    Ui::login *ui;
    login *loginn;
    admin *hod_win;
    QString id;
    //teacher_access teach;
    teacher_acess_n *teach;
    //student *std_wind;
    student *std;

};

#endif // LOGIN_H
