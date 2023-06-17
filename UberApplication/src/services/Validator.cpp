#include "../../include/services/Validator.h"

bool Validator::isDigit(char value)
{
	return value >= '0' && value <= '9';
}

bool Validator::isLetter(char value)
{
	return (value >= 'A' && value <= 'Z') ||
		(value >= 'a' && value <= 'z');
}

bool Validator::isUpper(char value)
{
	return value >= 'A' && value <= 'Z';
}

bool Validator::validateUsername(const String& data)
{
	for (size_t i = 0; i < data.length(); i++)
		if (!isLetter(data[i]) &&
			!isDigit(data[i]) &&
			data[i] != '.' &&
			data[i] != '_')
			return false;

	return true;
}

bool Validator::validateName(const String& data)
{
	for (size_t i = 0; i < data.length(); i++)
		if (!isLetter(data[i]) && data[i] != '-')
			return false;

	return true;
}

bool Validator::validatePassword(const String& data)
{
	if (data.length() < 8)
		return false;

	int digits = 0, upper = 0, special = 0;

	for (size_t i = 0; i < data.length(); i++)
	{
		if (isDigit(data[i]))
			digits++;
		else if (isUpper(data[i]))
			upper++;
		else if (!isLetter(data[i]))
			special++;
	}

	if (digits < 1 || upper < 1 || special < 1)
		return false;

	return true;
}

bool Validator::validatePassengersCount(int data)
{
	return data > 0 && data < 5;
}
