#pragma once
#include "User.h"

class Driver : public User
{
	String carNumber;
	String phoneNumber;

public:
	Driver() = default;
	Driver(const String& _username,
		const String& _firstName,
		const String& _lastName,
		const String& _passwordHash,
		const String& _carNumber,
		const String& _phoneNumber);

	const String& getCarNumber() const;
	const String& getPhoneNumber() const;

	void writeToBinaryFile(std::ofstream& file) const override;
	void readFromBinaryFile(std::ifstream& file) override;
};