#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setStyleSheet("background-color:#444444;color:#ffffff;line-height:22pt;");
    setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    fileName = "";
    QString nowString = ui->plainTextEdit->toPlainText();
    if(nowString.isEmpty()){
        ui->plainTextEdit->setPlainText("");
    }else{
        on_actionSave_As_triggered();
    }
}

void MainWindow::on_actionOpen_triggered()
{
    fileName = QFileDialog::getOpenFileName(this,"打开文件");
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream out(&file);
            QString content = file.readAll();
            ui->plainTextEdit->setPlainText("");
            ui->plainTextEdit->setPlainText(content);
            file.close();
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(fileName.isEmpty()){
        fileName = QFileDialog::getSaveFileName(this,"保存文件");
    }
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out<<ui->plainTextEdit->toPlainText();
        out.flush();
        file.close();
    }

}

void MainWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void MainWindow::on_actionSave_As_triggered()
{
    fileName = QFileDialog::getSaveFileName(this,"另存为");
    on_actionSave_triggered();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionPast_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"easyPad","easyPad是余征开发的一个用于替代记事本的简单程序，祝您使用愉快。");
}
