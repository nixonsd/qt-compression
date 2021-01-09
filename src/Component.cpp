#include <Component.h>

DataComponent::DataComponent(QVector<int>* Vector)
{
    _data = Vector;
    _binaryData = BinaryData::GetInstance();
}

QVector<int>* DataComponent::GetData(void)
{
    return _data;
}

void DataComponent::SetData(QVector<int>* Vector)
{
    _data = Vector;
}