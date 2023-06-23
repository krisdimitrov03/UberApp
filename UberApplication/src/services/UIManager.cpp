#include "../../include/Services/UIManager.h"
#include "../../include/Services/Parser.h"
#include "../../include/UI/Landings.h"
#include "../../include/UI/Logo.h"
#include "../../include/UI/Pages.h"
#include "../../include/Helper/Console.h"

UIManager UIManager::instance;

void UIManager::printMessage(const String& ch, const String& message)
{
	for (size_t i = 0; i < message.length() + 8; i++)
		Console::write("*");
	Console::writeLine();

	Console::write("* " + ch);
	Console::write(" " + message);
	Console::write(" " + ch);
	Console::writeLine(" *");

	for (size_t i = 0; i < message.length() + 8; i++)
		Console::write("*");
	Console::writeLine();
}


void UIManager::changeTheme()
{
	theme = Theme(theme == ThemeOption::Dark
		? ThemeOption::Light
		: ThemeOption::Dark);

	Console::changeColors(theme);
}

void UIManager::printLogo()
{
	Console::writeLine(LOGO);
}

UIManager& UIManager::getInstance()
{
	return instance;
}

void UIManager::printLandingPage(UserType type, const String& name, bool isInOrder)
{
	switch (type) {
	case UserType::Guest:
		Console::write(GUEST_LANDING);
		break;
	case UserType::Client:
		printGreetingPartial(name, type);
		if (!isInOrder)
			Console::write(CLIENT_LANDING);
		else
			Console::write(ORDERED_CLIENT_LANDING);
		break;
	case UserType::Driver:
		printGreetingPartial(name, type);
		if (!isInOrder)
			Console::write(DRIVER_LANDING);
		else
			Console::write(DRIVER_IN_ORDER_LANDING);
		break;
	}
}

void UIManager::printLoginPage()
{
	Console::write(LOGIN_PAGE);
}

Theme& UIManager::getTheme()
{
	return theme;
}

void UIManager::printOrderPage()
{
	Console::write(ORDER_PAGE);
}

void UIManager::printAddMoneyPage()
{
	Console::write(ADD_MONEY_PAGE);
}

void UIManager::printOrderDetailsPage(const CheckOrderDto& details) {
	if (details.driverName == "")
		printMessage("*", "We are still searching a driver.");
	else
		printMessage("*",
			"Driver " +
			details.driverName +
			" will be with you in " +
			Parser::intToString(details.minutes) +
			" minutes.");
}

void UIManager::printTypePartial()
{
	Console::write(TYPE_PARTIAL);
}

void UIManager::printGreetingPartial(const String& name, UserType type)
{
	Console::write("\n Hello, ");
	Console::write(name);
	Console::write("! Welcome to Vega Taxi App! [");
	Console::write(type == UserType::Client ? "Client]" : "Driver]");
}

void UIManager::printExitMessage()
{
	Console::writeLine(EXIT_VIEW);
}

void UIManager::printRegisterPage(UserType type)
{
	Console::writeLine(REGISTER_LOGO_PARTIAL);
	switch (type) {
	case UserType::Client:
		Console::write(REGISTER_CLIENT_PARTIAL);
		break;
	case UserType::Driver:
		Console::write(REGISTER_DRIVER_PARTIAL);
		break;
	}
}

void UIManager::printErrorMessage(const String& message)
{
	Console::writeLine();
	printMessage("X", message);
	Console::writeLine("Press <Enter> to continue...");
	Console::readKey();
}

void UIManager::printSuccessMessage(const String& message)
{
	Console::writeLine();
	printMessage("V", message);
	Console::writeLine("Press <Enter> to continue...");
	Console::readKey();
}

void UIManager::printOrderMessage(const OrderMessageDto& data, size_t idx)
{
	Console::write("   [" + Parser::intToString(idx) + "] ");
	Console::write(data.clientName);
	Console::write(" ordered from ");
	Console::write(data.start + " ");
	Console::write(
		"(" +
		Parser::intToString(data.startCoordinates.x) +
		", " +
		Parser::intToString(data.startCoordinates.y) +
		")"
	);
	Console::write(" to ");
	Console::write(data.destination + " ");
	Console::writeLine(
		"(" +
		Parser::intToString(data.destCoordinates.x) +
		", " +
		Parser::intToString(data.destCoordinates.y) +
		")"
	);
}
