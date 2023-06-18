#pragma once
#include "../../helper/String.h"
#include "../../helper/interfaces/IFileOperatable.h"

class User : public IFileOperatable
{
protected:
	String id;
	String username;
	String firstName;
	String lastName;
	String passwordHash;
	double account = 0.00;
	bool isInOrder = false;

public:
	User() = default;
	User(const String& _username, const String& _firstName, const String& _lastName, const String& _passwordHash);

	const String& getId() const;
	const String& getUsername() const;
	const String& getFirstName() const;
	const String& getLastName() const;
	const String& getPasswordHash() const;
	double getAccount() const;
	bool getIsInOrder() const;

	void setIsInOrder(bool _data);

	virtual void writeToBinaryFile(std::ofstream& file) const override;
	virtual void readFromBinaryFile(std::ifstream& file) override;
};

bool operator==(const User& lhs, const User& rhs);