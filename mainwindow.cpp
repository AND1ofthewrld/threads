#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&thread_1, &QThread::started, &object_1, &ExampleObject::run);
    connect(&thread_2, &QThread::started, &object_2, &ExampleObject::run);
    connect(&object_1, &ExampleObject::finished, &thread_1, &QThread::terminate);
    connect(&object_2, &ExampleObject::finished, &thread_2, &QThread::terminate);
    connect(&object_1, &ExampleObject::sendMessage, &object_2, &ExampleObject::setMessage2, Qt::DirectConnection);
    object_1.moveToThread(&thread_1);
    object_2.moveToThread(&thread_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_1_clicked()
{
    object_1.setMessage(ui->lineEdit_1->text());
}


void MainWindow::on_pushButton_2_clicked()
{
    object_2.setMessage(ui->lineEdit_2->text());
}


void MainWindow::on_start_clicked()
{
    object_1.setRunning(true);
    object_2.setRunning(true);
    thread_1.start();
    thread_2.start();
}


void MainWindow::on_stop_clicked()
{
    object_1.setRunning(false);
    object_2.setRunning(false);

}










