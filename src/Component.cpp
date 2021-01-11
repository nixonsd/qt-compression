#include <Component.h>

DataComponent::DataComponent(QVector<int>* Vector)
{
    // EXCEPTION //
    if (Vector == nullptr)
        throw std::invalid_argument("Invalid argument error. The data reference consists of a null pointer.");

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

QVector<int>* Decorator::GetData(void)
{
    return component_->GetData();
}

void Decorator::SetData(QVector<int>* Vector)
{
    component_->SetData(Vector);
}