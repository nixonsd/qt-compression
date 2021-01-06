#include <BinaryData.h>

BinaryData::BinaryData(void) : addedBits(0) {};
BinaryData* BinaryData::binaryData_ = nullptr;

void BinaryData::AddNulls(void) 
{
	// Calculate the number of the addition bits //
	addedBits = 0;
	if (buffer.length() % 8 > 0) addedBits = 8 - buffer.length() % 8;
	else return;
	// Adds the additional bits to the buffer //
	QString bits;
	for (int i = 0; i < addedBits; i++) bits += '0';
	this->AddBits(bits);
}

void BinaryData::AddBits(QString binaryNumber)
{
	// Adds the additional data to the buffer //
	this->buffer += binaryNumber;
	// Checks if there sufficient amount of bits //
	if (this->buffer.length() / 8 > 0)
	{
		for (size_t i = 0; i < buffer.length() / 8; i++)
		{
			std::bitset<8> bits(buffer.toStdString().substr(i * 8, 8));
			chars += char(bits.to_ulong());
		}
		// Shortened the buffer //
		buffer.remove(0, (buffer.length() / 8) * 8);
	}
}

BinaryData* BinaryData::GetInstance(void)
{
	/**
	 * This is a safer way to create an instance. instance = new Singleton is
	 * dangeruous in case two instance threads wants to access at the same time
	 */
	if (binaryData_ == nullptr) {
		binaryData_ = new BinaryData();
	}
	return binaryData_;
}

quint32 BinaryData::HiBit(quint64 x)
{
	quint32 log2Val = 0;
	while (x >>= 1) log2Val++;  // eg x=63 (111111), log2Val=5
	return log2Val + 1; // finds 2^5=32
}

QString BinaryData::ToBinary(quint32 n, size_t l)
{
	size_t lg = ((l > 0) ? l : HiBit(n));
	char* c = new char[lg + 1];
	for (uint32_t i = (uint32_t)1 << (lg - 1), j = 0; i > 0; i >>= 1, j++)
		c[j] = (n & i) ? '1' : '0';

	c[lg] = '\0';

	QString BinaryRepresentation = c;
	delete[] c;

	return BinaryRepresentation;
}

BinaryData::~BinaryData(void)
{
	/**
	 * Clear the arrays
	 */
	chars.clear();
	buffer.clear();
	/**
	 * Clear the memory
	 */
	chars.shrink_to_fit();
	buffer.shrink_to_fit();
};

void BinaryData::ClearChars(void)
{
	/**
	 * Clear the array
	 */
	chars.clear();
	/**
	 * Clear the memory
	 */
	chars.shrink_to_fit();
}

QString BinaryData::ToString(void)
{
	return chars;
}

size_t BinaryData::GetSize(void) const
{
	return buffer.length() + chars.length() * 8;
}

size_t BinaryData::GetAddedBits(void) const
{
	return addedBits;
}