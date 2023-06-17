#include "../../include/helper/String.h"
#include <cstring>

#pragma warning (disable : 4996)

String::String() : String("") { }

String::String(size_t size)
{
	_data = new char[size + 1];
	this->_size = size;
}
String::String(const char* data)
{
	size_t currentSize = strlen(data);

	if (currentSize <= String::SSO_MAX_SIZE)
	{
		ssoData[String::SSO_MAX_SIZE] = String::SSO_MAX_SIZE - currentSize;
		strcpy(ssoData, data);
	}
	else
	{
		_size = currentSize;
		_data = new char[_size + 1];
		strcpy(_data, data);
		notUsingSso();
	}
}
void String::notUsingSso()
{
	ssoData[String::SSO_MAX_SIZE] |= (1 << 7);
}

String::String(String&& other) noexcept
{
	move(std::move(other));
}

String& String::operator=(String&& other) noexcept
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

String::String(const String& other)
{
	copyFrom(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void String::move(String&& other) {
	_data = other._data;
	_size = other._size;

	if (!other.isSso())
	{
		other._data = nullptr;
		notUsingSso();
	}
}

void String::free()
{
	if (!isSso())
		delete[] _data;
	_data = nullptr;
}
String::~String()
{
	free();
}

void String::writeToBinaryFile(std::ofstream& file) const
{
}

void String::readFromBinaryFile(std::ifstream& file)
{
}

bool String::isSso() const
{
	return (ssoData[String::SSO_MAX_SIZE] & (1 << 7)) == 0;
}

const char* String::c_str() const
{
	return isSso() ? ssoData : _data;
}

size_t String::length() const
{
	if (isSso())
	{
		return String::SSO_MAX_SIZE - ssoData[String::SSO_MAX_SIZE];
	}
	else
	{
		size_t realSize = _size;
		size_t mask = 1;
		mask = ~(mask << (sizeof(_size) * 8 - 1));
		return realSize & mask;
	}
}

void String::copyFrom(const String& other)
{
	if (!other.isSso())
	{
		_data = new char[other.length() + 1];
		strcpy(_data, other._data);
		_size = other._size;
	}
	else
	{
		strcpy(ssoData, other.ssoData);
		ssoData[String::SSO_MAX_SIZE] = other.ssoData[String::SSO_MAX_SIZE];
	}
}

String& String::operator+=(const String& other)
{
	size_t newStrSize = length() + other.length();

	if (newStrSize <= String::SSO_MAX_SIZE)
	{
		strcat(ssoData, other.ssoData);
		ssoData[String::SSO_MAX_SIZE] = String::SSO_MAX_SIZE - newStrSize;
	}
	else
	{
		char* newData = new char[newStrSize + 1] {'\0'};

		strcpy(newData, c_str());
		strcat(newData, other.c_str());

		if (!isSso())
			delete[] _data;
		_data = newData;
		_size = newStrSize;
		notUsingSso();
	}

	return *this;
}


char& String::operator[](size_t index)
{
	return isSso() ? ssoData[index] : _data[index];
}

char String::operator[](size_t index) const
{
	return isSso() ? ssoData[index] : _data[index];
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.c_str();
}

String operator+(const String& lhs, const String& rhs)
{
	size_t newStrSize = lhs.length() + rhs.length();

	if (newStrSize <= String::SSO_MAX_SIZE)
	{
		String res(lhs);
		res += rhs;
		return res;
	}
	else
	{
		String res(newStrSize + 1);
		strcpy(res._data, lhs.c_str());
		strcat(res._data, rhs.c_str());
		res.notUsingSso();
		return res;
	}
}
bool operator<(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}