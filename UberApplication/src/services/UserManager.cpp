#include "../../include/services/UserManager.h"
#include "../../include/services/Validator.h"
#include "../../include/helper/Sha256.h"

UserManager UserManager::instance;

UserManager& UserManager::getInstance()
{
	return instance;
}

bool UserManager::loginUser(const String& _username, const String& _password)
{
	if (currentUser.isLogged)
		return false;

	bool success = false;

	auto findCondition = [&](const User& element) {
		return element.getUsername() == _username &&
			element.getPasswordHash() == Sha256::createHash(_password);
	};

	Optional<Client> client = clients.find(findCondition);
	Optional<Driver> driver = drivers.find(findCondition);

	if (client.hasValue()) {
		currentUser.isLogged = true;
		currentUser.id = client.getData().getId();
		currentUser.name = client.getData().getFirstName() +
			" " + client.getData().getLastName();
		currentUser.type = UserType::Client;
		return true;
	}
	else if (driver.hasValue()) {
		currentUser.isLogged = true;
		currentUser.id = driver.getData().getId();
		currentUser.name = driver.getData().getFirstName() +
			" " + driver.getData().getLastName();
		currentUser.type = UserType::Driver;
		return true;
	}

	return false;
}

int UserManager::registerUser(
	UserType _type,
	const String& _username,
	const String& _firstName,
	const String& _lastName,
	const String& _password,
	const String& _carNumber,
	const String& _phoneNumber)
{
	if (!Validator::validateUsername(_username)) {
		return -1;
	}
	if (!Validator::validateName(_firstName)) {
		return -2;
	}
	if (!Validator::validateName(_lastName)) {
		return -3;
	}
	if (!Validator::validatePassword(_password)) {
		return -4;
	}

	switch (_type) {
	case UserType::Client: {
		Client client(
			_username,
			_firstName,
			_lastName,
			Sha256::createHash(_password)
		);

		clients.add(std::move(client));
		break;
	}
	case UserType::Driver: {
		Driver driver(
			_username,
			_firstName,
			_lastName,
			Sha256::createHash(_password),
			_carNumber,
			_phoneNumber
		);

		drivers.add(std::move(driver));
		break;
	}
	}

	return 0;
}

void UserManager::logoutUser()
{
	currentUser.id = "";
	currentUser.type = UserType::Guest;
	currentUser.isLogged = false;
	currentUser.isInOrder = false;
}

void UserManager::changeAddress(const String& name, const Point& coordinates)
{
	const String& driverId = UserManager::getInstance()
		.getCurrentUserId();

	Address address(name, coordinates);

	UserManager::getInstance()
		.getDriverById(driverId)
		.setAddress(std::move(address));
}

void UserManager::addMoney(double amount)
{
	getClientById(currentUser.id).
}

void UserManager::rateDriver(const String& driverName, double rating)
{
	for (size_t i = 0; i < drivers.length(); i++)
	{
		String name = drivers[i].getFirstName() + " " + drivers[i].getLastName();
		if (name == driverName)
			drivers[i].rate(rating);
	}
}

List<Client>& UserManager::getClients()
{
	return clients;
}

Client& UserManager::getClientById(const String& id)
{
	for (size_t i = 0; i < clients.length(); i++)
		if (clients[i].getId() == id)
			return clients[i];

	Client res;
	return res;
}

List<Driver>& UserManager::getDrivers()
{
	return drivers;
}

Driver& UserManager::getDriverById(const String& id)
{
	for (size_t i = 0; i < drivers.length(); i++)
		if (drivers[i].getId() == id)
			return drivers[i];

	Driver res;
	return res;
}

List<size_t> UserManager::getSortedDriversIndexes(const Point& coordinates)
{
	List<size_t> result;

	bool isAdded = true;
	while (result.length() < drivers.length()) {
		size_t minIndex = 0;

		for (size_t i = 0; i < drivers.length(); i++)
		{
			if (result.contains(i))
				continue;

			if (drivers.length() - result.length() == 1)
				result.add(i);

			double lhs = drivers[i].getDistanceTo(coordinates);
			double rhs = drivers[minIndex].getDistanceTo(coordinates);

			if (lhs < rhs)
				minIndex = i;
		}

		if (!result.contains(minIndex))
			result.add(minIndex);
	}

	return result;
}

UserType UserManager::getCurrentUserType() const
{
	return currentUser.type;
}

const String& UserManager::getCurrentUserName() const
{
	return currentUser.name;
}

const String& UserManager::getCurrentUserId() const
{
	return currentUser.id;
}

bool UserManager::getCurrentUserIsInOrder() const
{
	return currentUser.isInOrder;
}

bool UserManager::getCurrentUserIsLoggedIn() const
{
	return currentUser.isLogged;
}

void UserManager::setCurrentUserIsInOrder(bool _data)
{
	currentUser.isInOrder = _data;
}

void UserManager::writeToBinaryFile(std::ofstream& file) const
{
}

void UserManager::readFromBinaryFile(std::ifstream& file)
{
}
