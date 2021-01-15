#include <ZeroClass.h>

QMap<int, QString>* ZeroClass::GetBytesMap(void)
{
	// CURRENT DATA //
	QVector<int>* _data = component_->GetData();
	// TEMPORARY DATA //
	_temp = new QMap<int, QString>();
	// MAP OF BITS //
	QMap<quint32, quint32>* _bitsMap = new QMap<quint32, quint32>();

	// COUNTS THE NUMBER OF OCCURRENCES OF BITS //
	for (auto itr = _data->begin(); itr != _data->end(); ++itr)
	{
		// CURRENT BITS //
		quint32 _bits = BinaryData::HiBit(*itr);
		if (_bitsMap->contains(_bits))
		{
			// ADDS ONE TO AN EXISTING OCCASION //
			_bitsMap[0][_bits]++;
		}
		else
		{
			// ADDS NEW NUMBER OF OCCURRENCE OF BITS //
			_bitsMap->insert(_bits, 1);
		}
	}

	// STRING OF ZEROS //
	QString _zeros = "";
	// SORTED MAP BY VALUE //
	std::multimap<quint32, quint32>* _sorted = in_sort(_bitsMap);

	// GENERATES ZEROS FOR CHAINS OF THE BITS //
	for (auto itr = _sorted->rbegin(); itr != _sorted->rend(); ++itr)
	{
		_temp->insert(itr->second, _zeros);
		_zeros += "0";
	}

	delete _sorted;
	return _temp;
}

std::multimap<quint32, quint32>* ZeroClass::in_sort(QMap<quint32, quint32>* M)
{

	// Declare a multimap 
	std::multimap<quint32, quint32>* MM = new std::multimap<quint32, quint32>();

	// Insert every (key-value) pairs from 
	// map M to multimap MM as (value-key) 
	// pairs 
	for (auto itr = M->begin(); itr != M->end(); ++itr) {
		MM->insert({ itr.value(), itr.key() });
	}

	return MM;
}

void ZeroClass::Execute(void)
{
	// DO NOTHING //
	return;
}

ZeroClass::ZeroClass(Component* component) : Decorator(component)
{
	// EXCEPTION //
	if (component == nullptr)
		throw std::invalid_argument("Invalid argument error. The data in the zero class component consists of a null pointer.");
}

ZeroClass::~ZeroClass(void)
{
	component_ = nullptr;
}