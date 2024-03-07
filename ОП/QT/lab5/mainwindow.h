#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "collection.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool isDuplicate(QString fname);

    bool check_index();
    bool check_value();

    void show_collection();

    void clear_widgets(int count);

private slots:
    void on_choose_file_currentTextChanged(const QString &arg1);

    void on_load_clicked();

    void on_clear_clicked();

    void on_save_clicked();

    void on_add_element_clicked();

    void on_sum_all_clicked();

    void on_sum_even_clicked();

    void on_show_element_clicked();

    void on_delete_by_index_clicked();

    void on_delete_by_value_clicked();

    void on_task1_clicked();

    void on_task2_clicked();

private:
    Ui::MainWindow *ui;

    Collection collection;

};
#endif // MAINWINDOW_H
