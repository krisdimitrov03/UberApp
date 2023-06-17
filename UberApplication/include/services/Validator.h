#pragma once
#include "../helper/String.h"

class Validator
{
private:
	static bool isDigit(char value);
	static bool isLetter(char value);
	static bool isUpper(char value);
public:
	static bool validateUsername(const String& data);
	static bool validateName(const String& data);
	static bool validatePassword(const String& data);

	static bool validatePassengersCount(int data);
};