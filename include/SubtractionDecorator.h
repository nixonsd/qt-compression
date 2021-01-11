#ifndef SUBTRACTION_DECORATOR_H
#define SUBTRACTION_DECORATOR_H

#include <Component.h>

/**
  * The Delta class makes a delta transformation
  * Subtracts one number from another
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
};

#endif