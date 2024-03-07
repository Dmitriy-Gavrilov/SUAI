#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    bool is_all_choosed();
    void print_total_price();
    void print_discount();

private slots:
    void on_monitor_stateChanged(int arg1);

    void on_choose_all_clicked();

    void on_clear_all_clicked();

    void on_keyboard_stateChanged(int arg1);

    void on_mouse_stateChanged(int arg1);

    void on_video_card_stateChanged(int arg1);

    void on_ram_stateChanged(int arg1);

    void on_headphones_stateChanged(int arg1);

    void on_microphone_stateChanged(int arg1);

    void on_result_button_clicked();

private:
    Ui::MainWindow *ui;
    int total_price = 0;
};
#endif // MAINWINDOW_H
