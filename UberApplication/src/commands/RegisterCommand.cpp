#include "../../include/commands/RegisterCommand.h"
#include "../../include/services/UserManager.h"

RegisterCommand::RegisterCommand(
	UserType _type,
	const String& _username,
	const String& _firstName,
	const String& _lastName,
	const String& _password,
	const String& _carNumber,
	const String& _phoneNumber)
	: type(_type),
	username(_username),
	firstName(_firstName),
	lastName(_lastName),
	password(_password),
	carNumber(_carNumber),
	phoneNumber(_phoneNumber)
{
}

void RegisterCommand::execute() const
{
	UserManager::getInstance()
		.registerUser(
			type,
			username,
			firstName,
			lastName,
			password,
			carNumber,
			phoneNumber);
}