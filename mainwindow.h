#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QApplication>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionSave_As_triggered();

    void on_actionCopy_triggered();

    void on_actionPast_triggered();

    void on_actionCut_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
public:
    QString fileName;
};

#endif // MAINWINDOW_H
