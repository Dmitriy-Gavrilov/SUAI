#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QStringList>
#include <QIntValidator>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->index_lineEdit->setValidator(new QIntValidator(-100, 100));
    ui->value_lineEdit->setValidator(new QIntValidator(-1000, 1000));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isDuplicate(QString fname){
    int count = ui->choose_file->count();

    for (int i =0; i < count; i++){
        if (ui->choose_file->itemText(i) == fname){
            return true;
        }
    }

    return false;
}

bool MainWindow::check_index()
{
    QString text = ui->index_lineEdit->text();
    if(text.isEmpty() || text == "-"){
        QMessageBox::critical(nullptr, "Ошибка", "Поле 'Индекс' не должно быть пустым");
        return false;
    }
    return true;
}

bool MainWindow::check_value()
{
    QString text = ui->value_lineEdit->text();
    if(text.isEmpty() || text == "-"){
        QMessageBox::critical(nullptr, "Ошибка", "Поле 'Значение' не должно быть пустым");
        return false;
    }
    return true;
}

void MainWindow::clear_widgets(int count)
{
    if (count > 1){
        ui->index_lineEdit->clear();
        ui->value_lineEdit->clear();
    }

    if (count > 2){
        ui->sum_lineEdit->clear();
    }

    if (count > 3){
        ui->converted_collection->clear();
    }
}

void MainWindow::show_collection()
{
    QString text;
    for (int element : collection.getArray()) {
        text += QString::number(element) + " ";
    }

    ui->orig_collection->setText(text);
}

void MainWindow::on_choose_file_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Добавить новый"){
         QString fileName =QFileDialog::getOpenFileName(this,"Открыть файл",
                                                        "C:/QtCreator Files/Lab5",QString::fromUtf8("Текстовые файлы(*.txt)"));
        if (!isDuplicate(fileName)){
            ui->choose_file->addItem(fileName);
        }
        ui->choose_file->setCurrentText(fileName);
    }
}

void MainWindow::on_load_clicked()
{
    ui->orig_collection->clear();

    QString fileName = ui->choose_file->currentText();

    QFile file(fileName);

    bool isSuccessfully = true;

    if (file.open(QIODevice::ReadOnly)){
        QString dataString(file.readAll());

        QStringList data = dataString.split(" ");

        for (QChar character : dataString) {
            if (!character.isDigit() && !character.isSpace() && character != '-') {
                isSuccessfully = false;
                break;
            }
        }

        if (isSuccessfully){

            QList<int> dataArray;
            for (const QString& n : data) {
                dataArray.append(n.toInt());
            }


            if (collection.fillArray(dataArray)){
                show_collection();
            }
            else{
                isSuccessfully = false;
            }

            file.close();
        }
    }
    else{
        isSuccessfully = false;
    }

    if (!isSuccessfully){
        QMessageBox::critical(nullptr, "Ошибка", "Невозможно считать данные из файла");
        collection.clear();
        clear_widgets(4);
    }


}


void MainWindow::on_clear_clicked()
{
    collection.clear();
    ui->orig_collection->clear();
    clear_widgets(4);
}


void MainWindow::on_save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Сохранить файл", "C:/QtCreator Files/Lab5", "Текстовые файлы (*.txt)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            for (int n: collection.getArray()){
                out << QString::number(n) << " ";
            }

            file.close();
        }
    }
}


void MainWindow::on_add_element_clicked()
{
    if (check_index() && check_value()){
        if (!collection.add_element(ui->index_lineEdit->text().toInt(), ui->value_lineEdit->text().toInt())){
            QMessageBox::critical(nullptr, "Ошибка", "Введены некорректные данные");
        }
        else{
            show_collection();
        }
    }

    clear_widgets(3);
}

void MainWindow::on_sum_all_clicked()
{
    ui->sum_lineEdit->setText(QString::number(collection.sum_array()));

    clear_widgets(2);
}


void MainWindow::on_sum_even_clicked()
{
    ui->sum_lineEdit->setText(QString::number(collection.sum_even()));

    clear_widgets(2);
}


void MainWindow::on_show_element_clicked()
{
    if (check_index()){
        QString res = collection.find_element(ui->index_lineEdit->text().toInt());
        if (res == "Неверный индекс"){
            QMessageBox::critical(nullptr, "Ошибка", "Неверный индекс");
            clear_widgets(2);
        }
        else{
            ui->value_lineEdit->setText(res);
        }
    }

    ui->sum_lineEdit->clear();
}

void MainWindow::on_delete_by_index_clicked()
{
    if (check_index()){
        if (collection.delete_by_index(ui->index_lineEdit->text().toInt()) == "Неверный индекс"){
            QMessageBox::critical(nullptr, "Ошибка", "Неверный индекс");
        }
        else{
            show_collection();
        }
    }

    clear_widgets(3);
}

void MainWindow::on_delete_by_value_clicked()
{
    if (check_value()){
        if (collection.delete_by_value(ui->value_lineEdit->text().toInt()) == "Неверное значение"){
            QMessageBox::critical(nullptr, "Ошибка", "Неверное значение");
        }
        else{
            show_collection();
        }
    }

    clear_widgets(3);
}

void MainWindow::on_task1_clicked()
{
    if (collection.getArray().empty()){
        QMessageBox::critical(nullptr, "Ошибка", "В коллекции нет значений");
    }
    else{
        QString text;
        for (int element : collection.task1()) {
            text += QString::number(element) + " ";
        }

        ui->converted_collection->setText(text);
    }

   clear_widgets(3);
}


void MainWindow::on_task2_clicked()
{
    if (collection.getArray().empty()){
        QMessageBox::critical(nullptr, "Ошибка", "В коллекции нет значений");
    }
    else{
        clear_widgets(4);

        ui->sum_lineEdit->setText(QString::number(collection.task2()));

    }
}
