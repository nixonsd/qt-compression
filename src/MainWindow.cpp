#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->executeButton, &QPushButton::clicked,
        this, &MainWindow::onButtonClick);
}

void MainWindow::onButtonClick()
{
    bool statisticsBoxStatus = ui->statisticsBox->checkState();

    QMessageBox msgB;
    msgB.information(this, "CheckBox Status", (statisticsBoxStatus) ? "True" : "False", QMessageBox::Ok);
    ui->progressBar->setValue((statisticsBoxStatus) ? 100 : 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

