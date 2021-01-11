#ifndef S_CLASS_H
#define S_CLASS_H

/**
  * The SClass is responsible for storing metadata
  */
class SClass
{
public:
	SClass(SClass& other) = delete;
	void operator=(const SClass&) = delete;
	/**
	  * Gets the instance of the class
	  * @param void
	  * @return The class instance
	  */
	static SClass* GetInstance(void);

public: 
	void SetDelta(unsigned short);
	unsigned short GetDelta(void);

protected:
	SClass(void);

private:
	unsigned short _delta = 0;
	static SClass* sClass_;
};

#endif