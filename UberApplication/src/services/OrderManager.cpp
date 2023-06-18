#include "../../include/services/OrderManager.h"
#include "../../include/services/UserManager.h"

OrderManager OrderManager::instance;

OrderManager& OrderManager::getInstance()
{
	return instance;
}

List<Order>& OrderManager::getOrders()
{
	return orders;
}

void OrderManager::makeOrder(const Address& _address, const Address& _destination, unsigned _passengersCount)
{
	if (UserManager::getInstance().getCurrentUserIsInOrder())
		throw std::runtime_error("User already ordered!");

	const String& clientId = UserManager::getInstance()
		.getCurrentUserId();

	Order current(
		_address,
		_destination,
		_passengersCount,
		clientId
	);

	orders.add(current);
	UserManager::getInstance()
		.setCurrentUserIsInOrder(true);

	UserManager::getInstance()
		.getClientById(clientId)
		.setIsInOrder(true);

	//send messageToSortedDrivers
	List<size_t> indexes = UserManager::getInstance()
		.getSortedDriversIndexes(_address.getCoordinates());

	for (size_t i = 0; i < indexes.length(); i++)
	{
		UserManager::getInstance()
			.getDrivers()[indexes[i]]
			.addMessage(
				std::move(current),
				UserManager::getInstance()
				.getCurrentUserName());
	}
}

void OrderManager::writeToBinaryFile(std::ofstream& file) const
{
}

void OrderManager::readFromBinaryFile(std::ifstream& file)
{
}
