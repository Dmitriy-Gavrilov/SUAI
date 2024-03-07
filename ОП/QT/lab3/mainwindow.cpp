 #include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->length_inp->setValidator(new QIntValidator(0, 1000, this));
    ui->width_inp->setValidator(new QIntValidator(0, 1000, this));
    ui->height_inp->setValidator(new QIntValidator(0, 1000, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_material_combobox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->price_one->setText("-");
        break;
    case 1:
         ui->price_one->setText("0.1");
        break;
    case 2:
         ui->price_one->setText("0.08");
        break;
    case 3:
         ui->price_one->setText("0.13");
        break;
    case 4:
         ui->price_one->setText("0.2");
        break;
    case 5:
         ui->price_one->setText("0.15");
        break;
    }

    ui->result_label->setText(QString::fromUtf8("Результат: "));
}


void MainWindow::on_result_button_clicked()
{
    ui->result_label->setText(QString::fromUtf8("Результат: "));
    if (ui->length_inp->text().toInt() == 0 || ui->width_inp->text().toInt() == 0
        || ui->height_inp->text().toInt() == 0 || ui->price_one->text() == "-"){
        ui->result_label->setText(ui->result_label->text() + QString::fromUtf8("Необходимо заполнить все поля"));
    }
    else{
        int l = ui->length_inp->text().toInt();
        int w = ui->width_inp->text().toInt();
        int h = ui->height_inp->text().toInt();
        int res = 2 * (l * w +  l * h + w * h) * ui->price_one->text().toDouble();
        ui->result_label->setText(ui->result_label->text() + QString::number(res));
    }
}


void MainWindow::on_length_inp_textChanged(const QString &arg1)
{
    ui->result_label->setText(QString::fromUtf8("Результат: "));
}


void MainWindow::on_width_inp_textChanged(const QString &arg1)
{
    ui->result_label->setText(QString::fromUtf8("Результат: "));
}


void MainWindow::on_height_inp_textChanged(const QString &arg1)
{
    ui->result_label->setText(QString::fromUtf8("Результат: "));
}

