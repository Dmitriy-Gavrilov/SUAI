#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isInt(QString str){
    for(int i = 0; i < str.size(); i++){
        if (str[i] < '0' || str[i] > '9'){
            return false;
        }
    }
    return true;
}

void MainWindow::on_addition_clicked()
{
    QString a = ui->first_number->text();
    QString b  = ui->second_number->text();
    if (isInt(a) && isInt(b)){
        ui->result_label->setText(QString::number(a.toInt() + b.toInt()));
    }
    else{
        ui->result_label->setText("Калькулятор только для целых чисел");
    }
}


void MainWindow::on_subtraction_clicked()
{
    QString a = ui->first_number->text();
    QString b  = ui->second_number->text();
    if (isInt(a) && isInt(b)){
        ui->result_label->setText(QString::number(a.toInt() - b.toInt()));
    }
    else{
        ui->result_label->setText("Калькулятор только для целых чисел");
    }
}


void MainWindow::on_multiplication_clicked()
{
    QString a = ui->first_number->text();
    QString b  = ui->second_number->text();
    if (isInt(a) && isInt(b)){
        ui->result_label->setText(QString::number(a.toInt() * b.toInt()));
    }
    else{
        ui->result_label->setText("Калькулятор только для целых чисел");
    }
}


void MainWindow::on_division_clicked()
{
    QString a = ui->first_number->text();
    QString b  = ui->second_number->text();
    if (isInt(a) && isInt(b)){
        int a1 = a.toInt();
        int b1 = b.toInt();
        if (b1 != 0){
            ui->result_label->setText(QString::number(a.toInt() + b.toInt()));
        }
        else{
            ui->result_label->setText("Ошибка: деление на 0");

        }
    }
    else{
        ui->result_label->setText("Калькулятор только для целых чисел");
    }
}

void MainWindow::on_to_form_clicked()
{
    this->close();
    emit f_window();
}


