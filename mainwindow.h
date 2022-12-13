#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Technosoft.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButtonRetroceso_pressed(); //Retroceso

    void on_pushButtonRetroceso_released();

    void on_pushButtonAvance_pressed();  //Avance

    void on_pushButtonAvance_released();

    void on_number_change_destroyed();

    void on_pushButtonStep_clicked();

private:
    Ui::MainWindow *ui;
    Technosoft *m_technosoft;
};
#endif // MAINWINDOW_H
