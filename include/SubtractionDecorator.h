#ifndef SUBTRACTION_DECORATOR_H
#define SUBTRACTION_DECORATOR_H

#include <Component.h>

/**
  * The SubtractionDecorator class makes a subtraction transformation
  * Subtracts the minimum number from another
  * Transformation starts from the end
  */
class SubtractionDecorator : public Decorator
{
public:
	SubtractionDecorator(Component* component);
	~SubtractionDecorator(void);
	/**
	  * Execute the transformation
	  * @param void
	  * @return void
	  */
	void Execute(void) override;
	/**
	  * Returns the previous data array
	  * @param void
	  * @return Previous data array
	  */
	QVector<int>* GetPreviousData(void);
private:
	QVector<int>* _temp = nullptr;
};

#endif