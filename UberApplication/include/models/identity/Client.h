#pragma once
#include "User.h"

class Client : public User
{
public:
	Client() = default;
	Client(
		const String& _username,
		const String& _firstName, 
		const String& _lastName, 
		const String& _passwordHash);
};