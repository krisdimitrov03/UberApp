#pragma once
#include "CommandBase.h"
#include "../models/identity/UserType.h"
#include "../helper/String.h"

class RegisterCommand : public CommandBase
{
	UserType type;
	const String& username;
	const String& firstName;
	const String& lastName;
	const String& password;
	const String& carNumber;
	const String& phoneNumber;

public:
	RegisterCommand(
		UserType _type,
		const String& _username,
		const String& _firstName,
		const String& _lastName,
		const String& _password,
		const String& _carNumber = "",
		const String& _phoneNumber = "");

	void execute() const override;
};

