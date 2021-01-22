#include <FileHandler.h>

void FileHandler::AlgorithmFunc(QVector<int>* _s_vector)
{
    Component* _data = new DataComponent(_s_vector);

    if (_isDelta)
    {
        DeltaDecorator* _delta = new DeltaDecorator(_data);
        _delta->Execute();
        delete _delta;
    }

    SubtractionDecorator* _subtract = new SubtractionDecorator(_data);
    _subtract->Execute();

    ZeroClass* _zeros = new ZeroClass(_data);
    QMap<int, QString>* _zeroDependencies = _zeros->GetBytesMap();

    delete _zeros;
    delete _subtract;
    delete _data;
}

void FileHandler::run()
{
    QFile* _file = new QFile(_fileName);

    if (!_file->open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::runtime_error("Cannot open file " + _fileName.toStdString());

    QVector<int>* _s_vector = new QVector<int>();;
    _bytesToRead = _file->size();

    QTextStream in(_file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        _bytesRead += line.size() + 2;
        emit changeReadBytes(line.size() + 2);

        if (line.size() != 0)
        {
            _s_vector->append(line.toInt());
            if (_s_vector->size() >= _lData)
            {
                AlgorithmFunc(_s_vector);
                _s_vector->clear();
            }
        }
    }

    if (_s_vector->size() > 0)
        AlgorithmFunc(_s_vector);

    emit changeReadBytes(_bytesToRead - _bytesRead);

    _file->close();
    _s_vector->clear();
    _s_vector->shrink_to_fit();

    delete _s_vector;
    delete _file;
}