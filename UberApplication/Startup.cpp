#include <iostream>
#include "include/helper/IdFactory.h"
#include "include/helper/List.hpp"
#include "include/services/UserManager.h"
#include "include/services/OrderManager.h"

void mockTest()
{
	//register users
	UserManager::getInstance().registerUser(UserType::Driver, "shisho66", "Shisho", "Bakshisho", "P@rola123", "B7841PH", "0882756317");
	UserManager::getInstance().registerUser(UserType::Driver, "marin208", "Marin", "Slavchev", "P@rola123", "B3051PX", "0892256247");
	UserManager::getInstance().registerUser(UserType::Driver, "kolyo_wee", "Nikola", "Gotsev", "P@rola123", "Y8373HH", "0883750983");
	UserManager::getInstance().registerUser(UserType::Client, "kris_dmt", "Kristian", "Dimitrov", "P@rola123");
	UserManager::getInstance().registerUser(UserType::Client, "lucas_perez", "Lucas", "Perez", "P@rola123");

	//login and change address from <shisho66>
	UserManager::getInstance().loginUser("shisho66", "P@rola123");
	UserManager::getInstance().changeAddress("ul. Bashryan Nakezi 17", { 800, 800 });
	UserManager::getInstance().logoutUser();

	//login and change address from <marin208>
	UserManager::getInstance().loginUser("marin208", "P@rola123");
	UserManager::getInstance().changeAddress("bul. Tsar Boris III 120", { 300, 400 });
	UserManager::getInstance().logoutUser();

	//login and change address from <kolyo_wee>
	UserManager::getInstance().loginUser("kolyo_wee", "P@rola123");
	UserManager::getInstance().changeAddress("National Palace of Culture", { 523, 412 });
	UserManager::getInstance().logoutUser();

	//login and order from <kris_dmt>
	UserManager::getInstance().loginUser("kris_dmt", "P@rola123");

	Address start1("Tsar Boris III 124g", { 322,434 }, "In the local part");
	Address dest1("National Palace of Culture", { 523,412 });
	OrderManager::getInstance().makeOrder(start1, dest1, 1);

	UserManager::getInstance().logoutUser();

	//login and order from <lucas_perez>
	UserManager::getInstance().loginUser("lucas_perez", "P@rola123");

	Address start2("ul. Budapest 27", { 232,937 });
	Address dest2("bul. Vitosha 5", { 32,212 });
	OrderManager::getInstance().makeOrder(start2, dest2, 2);

	UserManager::getInstance().logoutUser();

	//login and check messages from <shisho66>
	UserManager::getInstance().loginUser("marin208", "P@rola123");

	const List<OrderMessageDto>& messages = UserManager::getInstance()
		.getDriverById(UserManager::getInstance().getCurrentUserId())
		.getMessages();

	for (size_t i = 0; i < messages.length(); i++)
	{
		std::cout << messages[i].clientName << " ordered from "
			<< messages[i].start << " to " << messages[i].destination << std::endl;
	}
}

int main()
{
	mockTest();
}