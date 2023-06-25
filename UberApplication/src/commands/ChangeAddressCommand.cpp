#include "../../include/commands/ChangeAddressCommand.h"
#include "../../include/services/UserManager.h"
#include "../../include/services/UIManager.h"
#include "../../include/ui/Messages.h"

ChangeAddressCommand::ChangeAddressCommand(const String& _name, const Point& _coordinates)
	: name(_name), coordinates(_coordinates)
{
}

void ChangeAddressCommand::execute() const
{
	try
	{
		UserManager::getInstance()
			.changeAddress(name, coordinates);

		UIManager::printSuccessMessage(success::ADDRESS_CHANGED);
	}
	catch (const std::exception&)
	{
		UIManager::printErrorMessage(error::ADDRESS_CHANGE_FAIL);
	}
}
