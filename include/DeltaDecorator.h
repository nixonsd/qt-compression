#ifndef DELTA_DECORATOR_H
#define DELTA_DECORATOR_H

#include <Component.h>

class DeltaDecorator : public Decorator
{
public:
	DeltaDecorator(Component * component) : Decorator(component) { }
	~DeltaDecorator(void);

	/**
	  * Return the data array
	  * @param void
	  * @return Vector of the data
	  */
	QVector<int>* GetData(void) override;
	/**
	  * Set the data array
	  * @param Vector of the data
	  * @return void
	  */
	void SetData(QVector<int>* Vector) override;
	/**
	  * Execute the transformation
	  * @param void
	  * @return void
	  */
	void Execute(void) override;
};

#endif