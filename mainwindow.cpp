#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Technosoft.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_technosoft = new Technosoft();

    m_technosoft->openMotorControl();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonRetroceso_pressed()  //Boton retroceso
{
       m_technosoft->moveMotor(1000);
}


void MainWindow::on_pushButtonRetroceso_released()
{
    m_technosoft->stopMotor();
}


void MainWindow::on_pushButtonAvance_pressed()  //Boton avance
{

    m_technosoft->moveMotor(-1000);
}


void MainWindow::on_pushButtonAvance_released()
{
    m_technosoft->stopMotor();
}


void MainWindow::on_number_change_destroyed()  //Boton cambio preciso
{

}

void MainWindow::on_pushButtonStep_clicked()
{
    double factor = this->ui->number_change->toPlainText().toDouble();

    m_technosoft->moveMotor(factor *(2000));
}
