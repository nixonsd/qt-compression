#include <SClass.h>

SClass::SClass(void) : _delta(0) {};

void SClass::SetDelta(unsigned short Delta)
{
	if (Delta < 8 && Delta >= 0)
		_delta = Delta;
}

void SClass::SetFirstNumber(int FirstNumber)
{
	_firstNumber = FirstNumber;
}

void SClass::SetHasZeroFlag(bool Flag)
{
	_hasZeroFlag = Flag;
}

void SClass::SetMinNumber(int MinimumNumber)
{
	_minNumber = MinimumNumber;
}

void SClass::SetZeros(QMap<int, QString>* Zeros)
{
	_zerosMap = Zeros;
}

unsigned short SClass::GetDelta(void)
{
	return _delta;
}

int SClass::GetFirstNumber(void)
{
	return _firstNumber;
}

bool SClass::GetHasZeroFlag(void)
{
	return _hasZeroFlag;
}

int SClass::GetMinNumber(void)
{
	return _minNumber;
}

QMap<int, QString>* SClass::GetZeros(void)
{
	return _zerosMap;
}