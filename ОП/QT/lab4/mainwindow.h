#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map>

using namespace std;

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

    QString coffee_choosed();
    int size_choosed();

private slots:
    void calc_result();
private:
    Ui::MainWindow *ui;

    map<QString, map<int, int>> price{
        {"Каппучино", {
                        {150, 120},
                        {250, 200},
                        {350, 250},
                        {500, 330},
                      }
        },
        {"Латте", {
                          {150, 130},
                          {250, 210},
                          {350, 270},
                          {500, 380},
                          }
        },
        {"Эспрессо", {
                      {150, 90},
                      {250, 160},
                      {350, 200},
                      {500, 300},
                      }
        },
        {"Американо", {
                      {150, 110},
                      {250, 190},
                      {350, 250},
                      {500, 330},
                      }
        },

};
};
#endif // MAINWINDOW_H
