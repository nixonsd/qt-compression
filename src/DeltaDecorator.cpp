#include <DeltaDecorator.h>

void DeltaDecorator::Execute(void)
{
	// CURRENT DATA //
	QVector<int>* _data = component_->GetData();
	// TEMPORARY DATA //
	QVector<int>* _temp = new QVector<int>();
	// PREVIOUS BITS //
	quint32 pBits = 0;

	// FILL THE TEMPORARY DATA ARRAY //
	_temp->append(_data->mid(0, _data->count()));

	// COUNT THE BITS //
	for (auto itr = _temp->rbegin(); itr != _temp->rend(); ++itr) 
	{
		pBits += BinaryData::HiBit(qAbs(*itr));
	}

	// SET DELTA TO ZERO //
	SClass::GetInstance()->SetDelta(0);

	// DELTA //
	for (int i = 0; i < 7; i++)
	{
		// CURRENT BITS //
		quint32 qBits = 0;
		// PERFORM THE DELTA //
		for (auto itr = _temp->rbegin(); itr != _temp->rend(); ++itr)
		{
			if (itr < _temp->rend() - i - 1) *itr -= *(itr + 1);
			qBits += BinaryData::HiBit(qAbs(*itr));
		}

		if (pBits > qBits)
		{
			pBits = qBits;
			_data->clear();
			_data->append(_temp->mid(0, _temp->count()));
			SClass::GetInstance()->SetDelta(i + 1);
		}
	}
	// END OF DELTA //

	delete _temp;
}

DeltaDecorator::DeltaDecorator(Component* component) : Decorator(component)
{
	// EXCEPTION //
	if (component == nullptr)
		throw std::invalid_argument("Invalid argument error. The data in the delta decorator component consists of a null pointer.");

}

DeltaDecorator::~DeltaDecorator(void)
{
	component_ = nullptr;
}