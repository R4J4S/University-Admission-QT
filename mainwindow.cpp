#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sqlhandle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_status->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_fname_editingFinished()
{
    if(ui->lineEdit_fname->text().isEmpty())
    {
        ui->label_status->setText("Please fill in your First Name.");
        ui->lineEdit_fname->setStyleSheet("border:1px solid red");
        ui->label_status->show();
    }
    else
    {
        ui->label_status->hide();
        ui->lineEdit_fname->setStyleSheet("border:none");
    }
}

void MainWindow::on_lineEdit_lname_editingFinished()
{
    if(ui->lineEdit_lname->text().isEmpty())
    {
        ui->label_status->setText("Please fill in your Last Name.");
        ui->lineEdit_lname->setStyleSheet("border:1px solid red");
        ui->label_status->show();
    }
    else
    {
        ui->label_status->hide();
        ui->lineEdit_lname->setStyleSheet("border:none");
    }
}

void MainWindow::on_lineEdit_state_editingFinished()
{
    if(ui->lineEdit_state->text().isEmpty())
    {
        ui->label_status->setText("Please fill in your state.");
        ui->lineEdit_state->setStyleSheet("border:1px solid red");
        ui->label_status->show();
    }
    else
    {
        ui->label_status->hide();
        ui->lineEdit_state->setStyleSheet("border:none");
    }
}

void MainWindow::on_lineEdit_city_editingFinished()
{
    if(ui->lineEdit_city->text().isEmpty())
    {
        ui->label_status->setText("Please fill in your city.");
        ui->lineEdit_city->setStyleSheet("border:1px solid red");
        ui->label_status->show();
    }
    else
    {
        ui->label_status->hide();
        ui->lineEdit_city->setStyleSheet("border:none");
    }
}

void MainWindow::on_lineEdit_hsc_editingFinished()
{
    if(ui->lineEdit_hsc->text().isEmpty())
    {
        ui->label_status->setText("Please fill in your HSc marks.");
        ui->lineEdit_hsc->setStyleSheet("border:1px solid red");
        ui->label_status->show();
    }
    else
    {
        ui->label_status->hide();
        ui->lineEdit_hsc->setStyleSheet("border:none");
    }
}

void MainWindow::on_lineEdit_ssc_editingFinished()
{
    if(ui->lineEdit_ssc->text().isEmpty())
    {
        ui->label_status->setText("Please fill in your SSc marks.");
        ui->lineEdit_ssc->setStyleSheet("border:1px solid red");
        ui->label_status->show();
    }
    else
    {
        ui->label_status->hide();
        ui->lineEdit_ssc->setStyleSheet("border:none");
    }
}

void MainWindow::on_pushButton_cancel_clicked()
{
    sqlHandle dbmanager;
    dbmanager.disconnectDB();
    QCoreApplication::quit();
}

void MainWindow::on_pushButton_test_clicked()
{
    sqlHandle dbmanager;
    dbmanager.connectDB();
    //dbmanager.insertStudent("Rajas","Mahadule","Maharashtra","Nagpur","1","2","3","4","5","6","7","8");
}
