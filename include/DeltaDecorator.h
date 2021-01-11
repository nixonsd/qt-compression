#ifndef DELTA_DECORATOR_H
#define DELTA_DECORATOR_H

#include <Component.h>

/**
  * The Delta class makes a delta transformation
  * Subtracts one number from another
  * Transformation starts from the end
  */
class DeltaDecorator : public Decorator
{
public:
	DeltaDecorator(Component* component);
	~DeltaDecorator(void);
	/**
	  * Execute the transformation
	  * @param void
	  * @return void
	  */
	void Execute(void) override;
};

#endif