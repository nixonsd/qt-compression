#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <FileHandler.h>

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
    void onDataFolderButtonClick();
    void onChangeBytes(int i);

private:
    Ui::MainWindow *ui;
    quint64 _bytesToRead = 0;
    quint64 _bytesRead = 0;
};


#endif // MAINWINDOW_H
