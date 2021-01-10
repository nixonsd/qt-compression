#include <SClass.h>

SClass::SClass(void) : _delta(0) {};
SClass* SClass::sClass_ = nullptr;

void SClass::SetDelta(unsigned short Delta)
{
	if (Delta < 8 && Delta >= 0)
		_delta = Delta;
}

unsigned short SClass::GetDelta(void)
{
	return _delta;
}

SClass* SClass::GetInstance(void)
{
	/**
	 * This is a safer way to create an instance. instance = new Singleton is
	 * dangeruous in case two instance threads wants to access at the same time
	 */
	if (sClass_ == nullptr) {
		sClass_ = new SClass();
	}
	return sClass_;
}