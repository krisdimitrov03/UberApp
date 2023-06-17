#include "../../../include/models/identity/Driver.h"

Driver::Driver(const String& _username,
	const String& _firstName,
	const String& _lastName,
	const String& _passwordHash,
	const String& _carNumber,
	const String& _phoneNumber)
	: User(_username, _firstName, _lastName, _passwordHash),
	carNumber(_carNumber),
	phoneNumber(_phoneNumber)
{
}

const String& Driver::getCarNumber() const
{
	return carNumber;
}

const String& Driver::getPhoneNumber() const
{
	return phoneNumber;
}

void Driver::writeToBinaryFile(std::ofstream& file) const
{
}

void Driver::readFromBinaryFile(std::ifstream& file)
{
}
