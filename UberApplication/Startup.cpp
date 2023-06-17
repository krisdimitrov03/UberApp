#include <iostream>
#include "include/helper/IdFactory.h"
#include "include/models/identity/Client.h"
#include "include/models/identity/Driver.h"
#include "include/helper/List.hpp"
#include "include/services/UserManager.h"
#include "include/services/OrderManager.h"

int main()
{
	UserManager::getInstance().registerUser(UserType::Driver, "shisho66", "Shisho", "Bakshisho", "P@rola123", "B7841PH", "0882756317");
	UserManager::getInstance().registerUser(UserType::Client, "kris_dmt", "Kristian",  "Dimitrov", "P@rola123");

	UserManager::getInstance().loginUser("kris_dmt", "P@rola123");

	Address start("Tsar Boris III 124g", { 322,434 }, "In the local part");
	Address dest("National Palace of Culture", { 523,412 });
	OrderManager::getInstance().makeOrder(start, dest, 1);

	auto orders = OrderManager::getInstance().getOrders();
	for (size_t i = 0; i < orders.length(); i++)
	{
		std::cout << orders[i].getStart().getName() + " to ";
		std::cout << orders[i].getDestination().getName() + " (Client ID: ";
		std::cout << orders[i].getClientId() + ")";
	}
}