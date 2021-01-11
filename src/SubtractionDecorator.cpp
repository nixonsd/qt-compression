#include <SubtractionDecorator.h>

void SubtractionDecorator::Execute(void)
{
	return;
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
}