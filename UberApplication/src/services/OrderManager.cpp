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

	Order current(
		_address,
		_destination,
		_passengersCount,
		UserManager::getInstance()
		.getCurrentUserId()
	);

	orders.add(std::move(current));
	UserManager::getInstance()
		.setCurrentUserIsInOrder(true);

	//send messageToSortedDrivers
	List<size_t> indexes = UserManager::getInstance()
		.getSortedDriversIndexes(_address.getCoordinates());

	//OrderMessageDTO message = ...;
	//
	//for (size_t i = 0; i < indexes.length(); i++)
	//{
	//	UserManager::getInstance()
	//		.getDrivers()[indexes[i]].addMessage(message);
	//}
}

void OrderManager::writeToBinaryFile(std::ofstream& file) const
{
}

void OrderManager::readFromBinaryFile(std::ifstream& file)
{
}
