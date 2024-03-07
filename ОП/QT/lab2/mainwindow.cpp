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

bool MainWindow::is_all_choosed(){
    for (int i = 0; i < ui->verticalLayout->count(); i++){
        QCheckBox *checkbox = qobject_cast<QCheckBox*>(ui->verticalLayout->itemAt(i)->widget());
        if (!checkbox->isChecked()){
            return false;
        }
    }
    return true;
}

void MainWindow::print_total_price(){
    ui->result_label->setText(QString::fromUtf8("Итого: ") + QString::number(total_price));
}

void MainWindow::print_discount(){
    if (is_all_choosed()){
        ui->result_label->setText(QString::fromUtf8("Итого: ")
                                  + QString::number(total_price - total_price / 10)
                                  + QString::fromUtf8(" (Скидка 10%)"));
        ui->result_label->setStyleSheet("background-color: green");
    }
    else{
        ui->result_label->setText(ui->result_label->text() + QString::fromUtf8(" (Скидка не была применена)"));
    }
}

void MainWindow::on_monitor_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        total_price += ui->monitor_price->text().toInt();
    }
    else{
        total_price -= ui->monitor_price->text().toInt();
    }

    print_total_price();
}



void MainWindow::on_keyboard_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        total_price += ui->keyboard_price->text().toInt();
    }
    else{
        total_price -= ui->keyboard_price->text().toInt();
    }

    print_total_price();
}


void MainWindow::on_mouse_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        total_price += ui->mouse_price->text().toInt();
    }
    else{
        total_price -= ui->mouse_price->text().toInt();
    }

    print_total_price();
}


void MainWindow::on_video_card_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        total_price += ui->video_card_price->text().toInt();
    }
    else{
        total_price -= ui->video_card_price->text().toInt();
    }

    print_total_price();
}


void MainWindow::on_ram_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        total_price += ui->ram_price->text().toInt();
    }
    else{
        total_price -= ui->ram_price->text().toInt();
    }

    print_total_price();
}


void MainWindow::on_headphones_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        total_price += ui->headphones_price->text().toInt();
    }
    else{
        total_price -= ui->headphones_price->text().toInt();
    }

    print_total_price();
}


void MainWindow::on_microphone_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        total_price += ui->microphone_price->text().toInt();
    }
    else{
        total_price -= ui->microphone_price->text().toInt();
    }

    print_total_price();
}


void MainWindow::on_choose_all_clicked()
{
    for (int i = 0; i < ui->verticalLayout->count(); i++){
        QCheckBox *checkbox = qobject_cast<QCheckBox*>(ui->verticalLayout->itemAt(i)->widget());
        checkbox->setChecked(true);
    }
}


void MainWindow::on_clear_all_clicked()
{
    for (int i = 0; i < ui->verticalLayout->count(); i++){
        QCheckBox *checkbox = qobject_cast<QCheckBox*>(ui->verticalLayout->itemAt(i)->widget());
        checkbox->setChecked(false);
    }
}

void MainWindow::on_result_button_clicked()
{
    print_total_price();
    print_discount();
}

