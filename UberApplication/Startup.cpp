#include <iostream>
#include "include/helper/IdFactory.h"
#include "include/models/identity/Client.h"
#include "include/models/identity/Driver.h"
#include "include/helper/List.hpp"
#include "include/services/UserManager.h"

int main()
{
	Driver driver("shisho66", "Shisho", "Bakshisho", "498bbf29494a32c9721c242806801eabacd8b00b8c10d30885ef87715eb9b5fe", "B7841PH", "0882756317");
	Client client("kris_dmt", "Kristian", "Dimitrov", "242c13ff16a7e32120d1a040fa4569012782d74d5f05a84fdc35b83ede6fd654");

		UserManager::getInstance()
		.registerUser(
			UserType::Driver,
			"shisho66",
			"Shisho",
			"Bakshisho",
			"P@rola123",
			"B7841PH",
			"0882756317"
		);

	UserManager::getInstance()
		.loginUser("shisho66", "P@rola123");

	std::cout << UserManager::getInstance()
		.getCurrentUserIsLoggedIn();

	UserManager::getInstance()
		.logoutUser();

	std::cout << UserManager::getInstance()
		.getCurrentUserIsLoggedIn();
}