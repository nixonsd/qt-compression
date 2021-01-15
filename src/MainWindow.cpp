#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->DeltaBox->setChecked(true);
    QObject::connect(ui->executeButton, &QPushButton::clicked,
        this, &MainWindow::onExecuteButtonClick);
}

void MainWindow::onExecuteButtonClick()
{
    // TODO:
    // SubtractionDecorator:
    // Add Statistics to the execute function
    // Return previous array by special function (for defining the sign)
    // OR Make the function of the return previous array as common

    srand(time(nullptr));
    QVector<int>* _s_vector = new QVector<int>();

    /*
    for (int i = 0; i < 1000000; i++)
    {
        _s_vector->append(rand() % 250);
    }
    */

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

    try {
        Component* _data = new DataComponent(_s_vector);

        if (ui->DeltaBox->checkState())
        {
            DeltaDecorator* _delta = new DeltaDecorator(_data);
            _delta->Execute();
            delete _delta;
        }

        SubtractionDecorator* _subtract = new SubtractionDecorator(_data);
        _subtract->Execute();

        ZeroClass* _zeros = new ZeroClass(_data);
        QMap<int, QString>* _zeroDependencies = _zeros->GetBytesMap();

        QMessageBox messageBox;
        messageBox.information(0, "Delta", "Delta is equal to " + QString::number(_data->_sInfo->GetDelta())
        + ".\n" + "The number is: " + QString::number(_data->GetData()->at(5)));

        delete _subtract;
        delete _data;
    }
    catch (std::exception e)
    {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", e.what());
    }

    delete _s_vector;
}

MainWindow::~MainWindow()
{
    delete ui;
}

