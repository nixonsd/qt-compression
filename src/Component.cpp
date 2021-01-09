#include <Component.h>

DataComponent::DataComponent(QVector<int>* Vector)
{
    _data = Vector;
    _binaryData = BinaryData::GetInstance();
    _sInfo = SClass::GetInstance();
}

DataComponent::~DataComponent(void)
{
    _binaryData = nullptr;
    _sInfo = nullptr;
}

QVector<int>* DataComponent::GetData(void)
{
    return _data;
}

void DataComponent::SetData(QVector<int>* Vector)
{
    _data = Vector;
}