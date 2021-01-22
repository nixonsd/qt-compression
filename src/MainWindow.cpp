#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->DeltaBox->setChecked(true);

    ui->firstReplace->setDisabled(true);
    ui->secondReplace->setDisabled(true);

    QObject::connect(ui->executeButton, &QPushButton::clicked,
        this, &MainWindow::onExecuteButtonClick);

    QObject::connect(ui->DataFolder, &QPushButton::clicked,
        this, &MainWindow::onDataFolderButtonClick);
}

void MainWindow::onChangeBytes(int i)
{
    _bytesRead += i;
    int progress = (float)_bytesRead / _bytesToRead * 100;
    ui->progressBar->setValue(progress);

    if (i != 0 && _bytesRead == _bytesToRead)
    {
        ui->executeButton->setDisabled(false);
    
        if (ui->statisticsBox->checkState()) {
            QMessageBox messageBox;
            messageBox.information(0, "Info", QString::fromStdWString(L"Завершено"));
        }
    }
    
    
}

void MainWindow::onDataFolderButtonClick()
{
    QFileDialog* dialog = new QFileDialog(this);
    QStringList* filesNames = new QStringList();

    if ((*filesNames = dialog->getOpenFileNames(this, 
        tr("Select Files"), QDir::homePath(), tr("Text Files (*.txt)")))
        .size() != 0) {
        ui->DataFolderPath->setText(filesNames->join(";"));
    }

    delete dialog;
    delete filesNames;
}

void MainWindow::onExecuteButtonClick()
{
    FileHandler* _file = nullptr;
    QStringList* _filesNames = new QStringList();

    ui->progressBar->setValue(0);
    ui->executeButton->setDisabled(true);
    
    _bytesToRead = 0;
    _bytesRead = 0;

    try 
    {
        QStringList* _temp = new QStringList(ui->DataFolderPath->text().split(";"));
        for (auto itr = _temp->begin(); itr != _temp->end(); ++itr)
        {
            QFile* _file = new QFile(*itr);
            if (_file->exists())
            {
                QFileInfo* _fileInfo = new QFileInfo(*itr);
                _bytesToRead += _fileInfo->size();
                _filesNames->append(*itr);
                delete _fileInfo;
            }
            delete _file;
        }

        if (_filesNames->isEmpty()) 
            throw std::runtime_error("The path to the files is empty or incorrect");

        for (auto itr = _filesNames->begin(); itr != _filesNames->end(); ++itr)
        {
            _file = new FileHandler(*itr, ui->LData->text().toInt(),
                ui->DeltaBox->checkState());
            QObject::connect(_file, &FileHandler::changeReadBytes, this, &MainWindow::onChangeBytes);
            QObject::connect(_file, &FileHandler::finished, _file, &FileHandler::deleteLater);
            _file->start();
        }

        delete _temp;
    }
    catch (std::exception e)
    {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", e.what());
        ui->executeButton->setDisabled(false);
    }

    delete _filesNames;
}

MainWindow::~MainWindow()
{
    delete ui;
}

