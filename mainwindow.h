#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qimg.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_PreviewCheckBox_clicked();

    void on_InputPushButton_clicked();
    void closeEvent(QCloseEvent *event);

    void on_OutputPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QCloseEvent *ev;
    QImg myImg;
};

#endif // MAINWINDOW_H
