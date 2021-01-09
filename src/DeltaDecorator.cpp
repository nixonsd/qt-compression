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
			// delta_times = i + 1;
		}
	}
	// END OF DELTA //

	delete _temp;
}

DeltaDecorator::~DeltaDecorator(void)
{
	component_ = nullptr;
}

QVector<int>* DeltaDecorator::GetData(void)
{
	return component_->GetData();
}

void DeltaDecorator::SetData(QVector<int>* Vector)
{
	component_->SetData(Vector);
}