#include "../../../include/models/identity/Client.h"

Client::Client(const String& _username, const String& _firstName, const String& _lastName, const String& _passwordHash)
	: User(_username, _firstName, _lastName, _passwordHash)
{
}
