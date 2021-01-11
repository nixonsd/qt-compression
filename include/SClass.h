#ifndef S_CLASS_H
#define S_CLASS_H

/**
  * The SClass is responsible for storing metadata
  */
class SClass
{
public:
	SClass(void);
	/**
	  * Gets the instance of the class
	  * @param void
	  * @return The class instance
	  */
public: 
	void SetDelta(unsigned short);
	unsigned short GetDelta(void);

private:
	unsigned short _delta = 0;
};

#endif