#include <SubtractionDecorator.h>

void SubtractionDecorator::Execute(void)
{
	// CURRENT DATA //
	QVector<int>* _data = component_->GetData();
	// TEMPORARY DATA //
	_temp = new QVector<int>();

	// FILL THE TEMPORARY DATA ARRAY //
	_temp->append(_data->mid(0, _data->count()));

	// SETS ALL VALUES TO ABSOLUTE //
	for (auto itr = _data->begin(); itr != _data->end(); ++itr)
	{
		if (*itr < 0) *itr = qAbs(*itr);
	}

	// MINIMAL NUMBER //
	int mNum = *std::min_element(_data->begin(), _data->end());

	if (mNum != 0)
	{
		// IS EXECUTED IF MINIMAL NUMBER IS NOT EQUAL TO ZERO //
		// SUBTRACTS MINIMAL NUMBER OUT EACH ELEMENT OF THE DATA ARRAY //
		for (auto itr = _data->begin(); itr != _data->end(); ++itr)
		{
			*itr = *itr - (mNum - 1);
		}
	}
	else
	{
		// IS EXECUTED IF MINIMAL NUMBER IS ZERO //
		// ADDS ONE TO EACH ELEMENT OF THE DATA ARRAY //
		for (auto itr = _data->begin(); itr != _data->end(); ++itr)
		{
			*itr = *itr + 1;
		}
	}
}

QVector<int>* SubtractionDecorator::GetPreviousData(void)
{
	return _temp;
}

SubtractionDecorator::SubtractionDecorator(Component* component) : Decorator(component)
{
	// EXCEPTION //
	if (component == nullptr)
		throw std::invalid_argument("Invalid argument error. The data in the subtraction decorator component consists of a null pointer.");
}

SubtractionDecorator::~SubtractionDecorator(void)
{
	component_ = nullptr;
	if (_temp != nullptr)
		delete _temp;
}