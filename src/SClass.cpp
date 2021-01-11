#include <SClass.h>

SClass::SClass(void) : _delta(0) {};

void SClass::SetDelta(unsigned short Delta)
{
	if (Delta < 8 && Delta >= 0)
		_delta = Delta;
}

unsigned short SClass::GetDelta(void)
{
	return _delta;
}