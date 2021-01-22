#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <QFile>
#include <QTextStream>
#include <QProgressBar>
#include <QMessageBox>
#include <QThread>
#include <SClass.h>
#include <ZeroClass.h>
#include <BinaryData.h>
#include <DeltaDecorator.h>
#include <SubtractionDecorator.h>

class FileHandler : public QThread
{
    Q_OBJECT
public:
    FileHandler(QString fileName, int LData, bool IsDelta) :
        _fileName(fileName), _lData(LData), _isDelta(IsDelta) { }

    ~FileHandler(void) {  }

signals:
    void changeReadBytes(int);

private:
    void run();

private:
    void AlgorithmFunc(QVector<int>* _s_vector);

private:
    QString _fileName = nullptr;
    quint64 _bytesRead = 0;
    quint64 _bytesToRead = 0;
    int _lData = 0;
    bool _isDelta = false;

};

#endif