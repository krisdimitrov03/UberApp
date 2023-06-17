#include "../../../include/models/identity/User.h"
#include "../../../include/helper/IdFactory.h"
#include "../../../include/models/identity/User.h"

User::User(const String& _username, const String& _firstName, const String& _lastName, const String& _passwordHash)
	: username(_username), firstName(_firstName), lastName(_lastName), passwordHash(_passwordHash)
{
	id = IdFactory::getInstance()
		.create();
}

const String& User::getId() const
{
	return id;
}

const String& User::getUsername() const
{
	return username;
}

const String& User::getFirstName() const
{
	return firstName;
}

const String& User::getLastName() const
{
	return lastName;
}

const String& User::getPasswordHash() const
{
	return passwordHash;
}

double User::getAccount() const
{
	return account;
}

void User::writeToBinaryFile(std::ofstream& file) const
{
}

void User::readFromBinaryFile(std::ifstream& file)
{
}

bool operator==(const User& lhs, const User& rhs)
{
	bool idExpr = lhs.getId() == rhs.getId();
	bool usernameExpr = lhs.getUsername() == rhs.getUsername();
	bool fnExpr = lhs.getFirstName() == rhs.getFirstName();
	bool lnExpr = lhs.getLastName() == rhs.getLastName();
	bool passExpr = lhs.getPasswordHash() == rhs.getPasswordHash();
	bool accountExpr = lhs.getAccount() == rhs.getAccount();

	return idExpr && usernameExpr && fnExpr && lnExpr && passExpr && accountExpr;
}
