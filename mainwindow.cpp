#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timehandler.h"
#include <QFileDialog>
#include <QDebug>
#include <QStringList>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int count_str=0;


    /*while(count_str!=SourceFiles.size())
    {

        qDebug()<<SourceFiles[count_str];

        count_str++;
    }*/




    //qDebug()<<SourceFiles.size();
    while(count_str!=SourceFiles.size())
    {
        TimeHandler* handl = new TimeHandler(SourceFiles[count_str]);


        handl->HandlerExec();
        delete handl;
        count_str++;
    }


    QMessageBox::information(this, "Результаты обработки", "Обработка завершена. Смотрите протокол(ы) обработки в директориях, где расположены исходные файлы *c.");


}

void MainWindow::on_pushButton_2_clicked()
{
    QWidget::close();
}

void MainWindow::on_toolButton_clicked()
{

    //SourceFile = QFileDialog::getOpenFileName(0, "Открыть", QCoreApplication::applicationDirPath(), "*c");
    //QStringList SourceFiles;

    SourceFiles=QFileDialog::getOpenFileNames(0, "Открыть", QCoreApplication::applicationDirPath(), "*c");

    if(SourceFiles.size()==1)
    {
        ui->lineEdit->setText(SourceFiles[0]);

    }
    else
    {
        ui->lineEdit->setText("Количество выбранных файлов: "+QString::number(SourceFiles.size()));

    }

}
