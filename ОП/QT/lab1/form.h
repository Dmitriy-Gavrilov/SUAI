#ifndef FORM_H
#define FORM_H


#include <QWidget>

#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Form;
}
QT_END_NAMESPACE

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_to_calculate_clicked();

    void on_start_clicked();

private:
    Ui::Form *ui;
    MainWindow *m_window;
};

#endif // FORM_H
