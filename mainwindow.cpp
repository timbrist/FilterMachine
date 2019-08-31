#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QMessageBox"
#include "QFileDialog"
#include "QCloseEvent"

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
void MainWindow::on_PreviewCheckBox_clicked()
{
    if(ui->PreviewCheckBox->isChecked())
    {
        QString img_path = ui->InputComboBox->currentText();

        if(!img_path.isEmpty())
        {
            QImage view_img ;
            if( ui->GaussianRadioButton->isChecked())
                view_img = this->myImg.FilterMachine(img_path,0);
            else if(ui->MedianRadioButton->isChecked())
                view_img = this->myImg.FilterMachine(img_path,1);

            QPixmap px = (QPixmap::fromImage(view_img));
            px = px.scaled(ui->ImageLabel->width(),
                           ui->ImageLabel->height(),
                           Qt::IgnoreAspectRatio,
                           Qt::SmoothTransformation);
            ui->ImageLabel->setPixmap(px);
            ui->ImageLabel->show();

        }
        else {
            QMessageBox::information(this,"Info","Can not play Image file");
            ui->PreviewCheckBox->setCheckState(Qt::Unchecked);
        }
    }
    else {
        ui->ImageLabel->clear();
    }
}

void MainWindow::on_InputPushButton_clicked()
{

    QString aFile = QDir::currentPath();
    QString img_path = QFileDialog::getOpenFileName(
                this,
                tr("Select a img"),
                aFile,
                tr("img type(*.jpg *.bmp *.png)"));
    if(!img_path.isEmpty())
    {
        ui->InputComboBox->addItem(img_path);
    }
    else {
        QMessageBox::information(this,"Warning","image file hasn's been selected");
    }
}

void MainWindow::on_OutputPushButton_clicked()
{
   QString aFile = QDir::currentPath();
   QString img_path = QFileDialog::getSaveFileName(
                        this, "Select a img",
                        aFile,
                        "img type(*.jpg *.bmp *.png)");
   if(!img_path.isEmpty() && this->myImg.SaveImage(img_path))
   {
       ui->OutputComboBox->addItem(img_path);
       QMessageBox::information(this, "Info", "Save image succeed");
   }
   else {
       QMessageBox::information(this, "Error", "Save image failed");
   }


}
void MainWindow::closeEvent(QCloseEvent *event)
{
    int result =QMessageBox::warning(this,
                                   "Exit",
                                   "Are you sure you want to close thisprogram?",
                                   QMessageBox::Yes, QMessageBox::No);
   if(result ==QMessageBox::Yes)
   {
       event->accept();
   }
   else {
       event->ignore();
   }
}
