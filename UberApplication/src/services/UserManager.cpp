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
		currentUser.isInOrder = client.getData().getIsInOrder();
		currentUser.amount = client.getData().getAccount();
		return true;
	}
	else if (driver.hasValue()) {
		currentUser.isLogged = true;
		currentUser.id = driver.getData().getId();
		currentUser.name = driver.getData().getFirstName() +
			" " + driver.getData().getLastName();
		currentUser.type = UserType::Driver;
		currentUser.isInOrder = driver.getData().getIsInOrder();
		currentUser.amount = driver.getData().getAccount();
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

const List<OrderMessageDto>& UserManager::getMessages() const
{
	size_t i;
	for (i = 0; i < drivers.length(); i++)
		if (drivers[i].getId() == currentUser.id)
			break;

	return drivers[i].getMessages();
}

void UserManager::addMoney(double amount)
{
	getClientById(currentUser.id).addMoney(amount);
	addToCurrentUserAmount(amount);
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

double UserManager::getCurrentUserAmount() const
{
	return currentUser.amount;
}

void UserManager::setCurrentUserIsInOrder(bool _data)
{
	currentUser.isInOrder = _data;
}

void UserManager::addToCurrentUserAmount(double data)
{
	if (data < 0)
		throw std::exception("Amount cannot be less than 0.");

	currentUser.amount += data;
}

void UserManager::removeFromCurrentUserAmount(double data)
{
	if (data > getCurrentUserAmount())
		currentUser.amount = 0.00;

	currentUser.amount -= data;
}

void UserManager::writeToBinaryFile(std::ofstream& file) const
{
	size_t clientsLen = clients.length();
	size_t driversLen = drivers.length();

	file.write((const char*)&clientsLen, sizeof(size_t));
	for (size_t i = 0; i < clientsLen; i++)
		clients[i].writeToBinaryFile(file);

	file.write((const char*)&driversLen, sizeof(size_t));
	for (size_t i = 0; i < driversLen; i++)
		drivers[i].writeToBinaryFile(file);
}

void UserManager::readFromBinaryFile(std::ifstream& file)
{
	size_t clientsCount = 0;
	file.read((char*)&clientsCount, sizeof(size_t));

	for (size_t i = 0; i < clientsCount; i++)
	{
		Client current;
		current.readFromBinaryFile(file);
		clients.add(std::move(current));
	}

	size_t driversCount = 0;
	file.read((char*)&driversCount, sizeof(size_t));

	for (size_t i = 0; i < driversCount; i++)
	{
		Driver current;
		current.readFromBinaryFile(file);
		drivers.add(std::move(current));
	}
}
