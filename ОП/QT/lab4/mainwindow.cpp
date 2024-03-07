#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->cappuccino, &QRadioButton::toggled, this, &MainWindow::calc_result);
    connect(ui->amerikano, &QRadioButton::toggled, this, &MainWindow::calc_result);
    connect(ui->latte, &QRadioButton::toggled, this, &MainWindow::calc_result);
    connect(ui->espresso, &QRadioButton::toggled, this, &MainWindow::calc_result);
    connect(ui->ml150, &QRadioButton::toggled, this, &MainWindow::calc_result);
    connect(ui->ml250, &QRadioButton::toggled, this, &MainWindow::calc_result);
    connect(ui->ml350, &QRadioButton::toggled, this, &MainWindow::calc_result);
    connect(ui->ml500, &QRadioButton::toggled, this, &MainWindow::calc_result);
    connect(ui->count_spinBox, &QSpinBox::valueChanged, this, &MainWindow::calc_result);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::coffee_choosed()
{
    QList<QRadioButton*> radioButtons = ui->groupBox_2->findChildren<QRadioButton*>();

    for (QRadioButton* radioButton : radioButtons) {
        if (radioButton->isChecked()) {
            return radioButton->text();
        }
    }

    return "";
}

int MainWindow::size_choosed()
{
    QList<QRadioButton*> radioButtons = ui->groupBox->findChildren<QRadioButton*>();

    for (QRadioButton* radioButton : radioButtons) {
        if (radioButton->isChecked()) {
            return radioButton->text().toInt();
        }
        else{
        }
    }
    return 0;
}

void MainWindow:: calc_result()
{
    QString coffee = coffee_choosed();
    int size = size_choosed();
    int count = ui->count_spinBox->value();

    if (coffee != "" && size){
        if (count < 3){
            ui->result_lineEdit->setText(QString::number(this->price[coffee][size] * count));
        }
        else if (count >= 3 && count < 5){
            ui->result_lineEdit->setText(QString::number(this->price[coffee][size] * count * 0.9) + QString::fromUtf8("Скидка ") + QString::number(this->price[coffee][size] * count * 0.1));
        }
        else if (count >= 5 && count < 8){
            ui->result_lineEdit->setText(QString::number(this->price[coffee][size] * count * 0.8) + QString::fromUtf8("Скидка ") + QString::number(this->price[coffee][size] * count * 0.2));
        }
        else if (count >= 8){
            ui->result_lineEdit->setText(QString::number(this->price[coffee][size] * count * 0.6) + QString::fromUtf8("Скидка ") + QString::number(this->price[coffee][size] * count * 0.4));
        }
        else{
            ui->result_lineEdit->setText("0");
        }

    }
}


