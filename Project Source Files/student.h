#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>
#include "global.h"

namespace Ui {
class student;
}

class student : public QMainWindow
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = 0);
    ~student();

private slots:
    void on_button_view_attendence_clicked();

private:
    Ui::student *ui;
};

#endif // STUDENT_H
