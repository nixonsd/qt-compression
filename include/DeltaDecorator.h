#ifndef DELTA_DECORATOR_H
#define DELTA_DECORATOR_H

#include <Component.h>

class DeltaDecorator : public Decorator
{
public:
	DeltaDecorator(Component * component) : Decorator(component)
	{

	}

	QVector<int>* GetData(void) override
	{
		return component_->GetData();
	}

	void SetData(QVector<int>* l) override
	{
		return;
	}
};

#endif