#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <SClass.h>
#include <BinaryData.h>
#include <DeltaDecorator.h>
#include <ctime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onExecuteButtonClick();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
