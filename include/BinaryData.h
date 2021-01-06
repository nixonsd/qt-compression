#ifndef _BINARY_DATA_H_
#define _BINARY_DATA_H_

#include <QString>
#include <QMessageBox>
#include <BitSet>

class BinaryData
{
public:
	~BinaryData(void);
	/**
	 * Adds additional nulls
	 * @param void
	 * @return void
	 */
	void AddNulls(void);
	/**
	 * Tranforms the string of bits to the array of chars
	 * @param Array of bits
	 * @return void
	 */
	void AddBits(QString);
	/**
	 * Gets the array of chars
	 * @param void
	 * @return Array of chars
	 */
	QString ToString(void);
	/**
	 * Clears the array and memory of chars
	 * @param void
	 * @return void
	 */
	void ClearChars(void);

public:
	BinaryData(BinaryData& other) = delete;
	void operator=(const BinaryData&) = delete;
	/**
	 * Gets the instance of the class
	 * @param void
	 * @return The class instance
	 */
	static BinaryData* GetInstance(void);
	/**
	 * Gets the position of the highest bit of the number
	 * @param Input number
	 * @return Output position of the highest bit
	 */
	static quint32 HiBit(quint64 x);
	/**
	 * Gets the binary representation of the number
	 * @param Input number
	 * @return Output binary representation of the number
	 */
	static QString ToBinary(quint32 n, size_t l = 0);


protected:
	BinaryData(void);

public:
	/**
	 * Returns the current size of internal data
	 * @param void
	 * @return Value of the size of data
	 */
	size_t GetSize(void) const;
	/**
	 * Number of padding zeros
	 * @param void
	 * @return Count of the padding zeros
	 */
	size_t GetAddedBits(void) const;

private:
	QString buffer;
	QString chars;
	size_t addedBits = 0;

protected:
	static BinaryData* binaryData_;
};

#endif // _BINARY_DATA_H_