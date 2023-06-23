#pragma once
#include "../helper/String.h"
#include "../models/identity/UserType.h"
#include "../app/Theme.h"
#include "../models/dto/CheckOrderDto.h"
#include "../models/dto/OrderMessageDto.h"

class UIManager
{
	static UIManager instance;

	Theme theme = Theme(ThemeOption::Dark);

	static void printMessage(const String& ch, const String& message);

	UIManager() = default;
public:
	static UIManager& getInstance();

	void changeTheme();

	Theme& getTheme();

	static void printLogo();

	static void printLandingPage(UserType type, const String& name = "", bool isInOrder = false);

	static void printLoginPage();

	static void printOrderPage();

	static void printAddMoneyPage();

	static void printOrderDetailsPage(const CheckOrderDto& details);

	static void printTypePartial();

	static void printGreetingPartial(const String& name, UserType type);

	static void printExitMessage();

	static void printRegisterPage(UserType type);

	static void printErrorMessage(const String& message);

	static void printSuccessMessage(const String& message);

	static void printOrderMessage(const OrderMessageDto& data, size_t idx);
};
