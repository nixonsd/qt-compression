#ifndef S_CLASS_H
#define S_CLASS_H

#include <QMap>

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
	/**
	  * Set Delta Data
	  * @param Delta
	  * @return void
	  */
	void SetDelta(unsigned short);
	/**
	  * Set First Number Data
	  * @param First Number
	  * @return void
	  */
	void SetFirstNumber(int);
	/**
	  * Set Zero Flag Data
	  * @param Boolean status set to true if there existing zero
	  * @return void
	  */
	void SetHasZeroFlag(bool);
	/**
	  * Set Minimum Number Data
	  * @param Minimum Number
	  * @return void
	  */
	void SetMinNumber(int);
	/**
	  * Set zeros delimeters Data
	  * @param Map of the delimeters
	  * @return void
	  */
	void SetZeros(QMap<int, QString>*);

	unsigned short GetDelta(void);
	int GetFirstNumber(void);
	bool GetHasZeroFlag(void);
	int GetMinNumber(void);
	QMap<int, QString>* GetZeros(void);

private:
	unsigned short _delta = 0;
	int _firstNumber = 0;
	bool _hasZeroFlag = false;
	int _minNumber = 0;
	QMap<int, QString>* _zerosMap = nullptr;
};

#endif