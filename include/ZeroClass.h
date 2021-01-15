#ifndef ZERO_CLASS_H
#define ZERO_CLASS_H

#include <Component.h>

class ZeroClass : public Decorator
{
public:
	ZeroClass(Component* component);
	~ZeroClass(void);
	/**
	  * Do nothing (Reserve)
	  * @param void
	  * @return void
	  */
	void Execute(void) override;
	/**
	  * Returns the map of the bytes and delimiter
	  * @param void
	  * @return Map of the bytes and delimiter
	  */
	QMap<int, QString>* GetBytesMap(void);

private:
	/**
	  * A static function that sorts the map and returns the sorted multimap
	  * @param The map
	  * @return The sorted multimap
	  */
	static std::multimap<quint32, quint32>* in_sort(QMap<quint32, quint32>* M);

private:
	QMap<int, QString>* _temp = nullptr;
};

#endif