#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "timehandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = NULL);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_toolButton_clicked();

private:
    //class TimeHandler;
    //TimeHandler handl;

    QStringList SourceFiles;


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
