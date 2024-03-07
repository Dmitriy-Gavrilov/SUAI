#include "form.h"
#include "./ui_form.h"


Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);

    m_window = new MainWindow();

    connect(m_window, &MainWindow::f_window, this, &Form::show);

}

Form::~Form()
{
    delete ui;
}

void Form::on_to_calculate_clicked()
{
    m_window->show();
    this->close();
}

void Form::on_start_clicked()
{
    ui->label->setText(ui->lineEdit->text());
}

