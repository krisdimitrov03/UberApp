#include "../../include/commands/ChangeAddressCommand.h"
#include "../../include/services/UserManager.h"

ChangeAddressCommand::ChangeAddressCommand(const String& _name, const Point& _coordinates)
	: name(_name), coordinates(_coordinates)
{
}

void ChangeAddressCommand::execute() const
{
	UserManager::getInstance()
		.changeAddress(name, coordinates);
}
