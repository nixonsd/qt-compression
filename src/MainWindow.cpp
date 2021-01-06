#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->executeButton, &QPushButton::clicked,
        this, &MainWindow::onExecuteButtonClick);
}

void MainWindow::onExecuteButtonClick()
{
    bool statisticsBoxStatus = ui->statisticsBox->checkState();

    QString bits = "0100001001";
    BinaryData* binaryData_ = BinaryData::GetInstance();
    binaryData_->AddBits(bits);
    binaryData_->AddBits("00001");
    binaryData_->AddNulls();

    QMessageBox msgB;
    msgB.information(this, "CheckBox Status", binaryData_->ToString(), QMessageBox::Ok);
    ui->progressBar->setValue((statisticsBoxStatus) ? 100 : 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

