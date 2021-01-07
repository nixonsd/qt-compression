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
    QVector<int>* _s_vector = new QVector<int>();
    _s_vector->append(113190);
    _s_vector->append(372147);
    _s_vector->append(691427);
    _s_vector->append(1051801);
    _s_vector->append(1313637);
    _s_vector->append(1473026);
    _s_vector->append(1426564);
    _s_vector->append(1291973);
    _s_vector->append(1133543);
    _s_vector->append(927109);
    _s_vector->append(689008);
    _s_vector->append(447120);
    _s_vector->append(213477);

    Component* _data = new DataComponent(_s_vector);
    DeltaDecorator* _delta = new DeltaDecorator(_data);

    QMessageBox msgB;
    msgB.setText(QString::fromWCharArray(L"�����: ") + QString::number(_delta->GetData()->at(2)));
    msgB.exec();

    delete _delta;
    delete _data;
    delete _s_vector;
}

MainWindow::~MainWindow()
{
    delete ui;
}

