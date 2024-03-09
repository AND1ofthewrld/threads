#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include<exampleobject.h>


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
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_start_clicked();

    void on_stop_clicked();

private:
    Ui::MainWindow *ui;
    QThread thread_1;
    QThread thread_2;
    ExampleObject object_1;
    ExampleObject object_2;
};
#endif // MAINWINDOW_H
