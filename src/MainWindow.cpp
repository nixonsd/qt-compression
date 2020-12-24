#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, &QPushButton::clicked,
        this, &MainWindow::onButtonClick);
}

void MainWindow::onButtonClick()
{
    bool checkBoxStatus = ui->checkBox->checkState();

    QMessageBox msgB;
    msgB.information(this, "CheckBox Status", (checkBoxStatus) ? "True" : "False", QMessageBox::Ok);

    ui->progressBar->setValue(80);
}

MainWindow::~MainWindow()
{
    delete ui;
}

