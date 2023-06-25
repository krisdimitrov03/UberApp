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

Order& OrderManager::getById(const String& id)
{
	for (size_t i = 0; i < orders.length(); i++)
		if (orders[i].getId() == id)
			return orders[i];

	Order res;
	return res;
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

CheckOrderDto OrderManager::checkOrder() const
{
	const String& clientId = UserManager::getInstance()
		.getCurrentUserId();

	Optional<Order> order = orders.find(
		[&](const Order& el)
		{
			return el.getClientId() == clientId;
		}
	);

	const String& driverId = order.getData().getDriverId();

	if (driverId == "")
		return { order.getData().getId(), "", "", 0};

	const Driver& driver = UserManager::getInstance()
		.getDriverById(order.getData().getDriverId());

	return {
		order.getData().getId(),
		driver.getFirstName() + " " + driver.getLastName(),
		driver.getCarNumber(),
		order.getData().getMinutes()
	};
}

void OrderManager::acceptOrder(const String& id, unsigned minutes)
{
	const String& driverId = UserManager::getInstance()
		.getCurrentUserId();

	for (size_t i = 0; i < orders.length(); i++)
	{
		if (orders[i].getId() == id)
		{
			orders[i].setDriverId(driverId);
			orders[i].setMinutes(minutes);

			UserManager::getInstance()
				.setCurrentUserIsInOrder(true);

			UserManager::getInstance()
				.getDriverById(driverId)
				.setIsInOrder(true);

			List<Driver> drivers = UserManager::getInstance()
				.getDrivers();

			for (size_t i = 0; i < drivers.length(); i++)
			{
				if (drivers[i].getId() != driverId)
					drivers[i].deleteMessage(id);
				else
					drivers[i].setIsInOrder(true);
			}

			break;
		}
	}
}

void OrderManager::declineOrder(const String& id)
{
	const String& driverId = UserManager::getInstance()
		.getCurrentUserId();

	UserManager::getInstance()
		.getDriverById(driverId)
		.deleteMessage(id);
}

void OrderManager::cancelOrder(const String& id)
{
	size_t idx;
	String driverId;
	for (idx = 0; idx < orders.length(); idx++) {
		if (orders[idx].getId() == id) {
			driverId = orders[idx].getDriverId();
			break;
		}
	}

	List<Driver> drivers = UserManager::getInstance()
		.getDrivers();

	for (size_t i = 0; i < drivers.length(); i++)
	{
		drivers[i].deleteMessage(id);

		if (drivers[i].getId() == driverId)
			drivers[i].setIsInOrder(false);
	}

	orders.remove(idx);
}

void OrderManager::finishOrder(const String& id)
{
	for (size_t i = 0; i < orders.length(); i++)
	{
		if (orders[i].getId() == id)
			orders[i].setFinished(true);
	}
}

bool OrderManager::pay(const String& orderId, double amount)
{
	size_t i;
	for (i = 0; i < orders.length(); i++)
		if (orders[i].getId() == orderId)
			break;

	if (!orders[i].getFinished())
		throw std::exception("Order is not finished.");

	orders[i].setMoney(amount);
	const String& clientId = UserManager::getInstance()
		.getCurrentUserId();

	try
	{
		UserManager::getInstance()
			.getClientById(clientId)
			.removeMoney(amount);

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

void OrderManager::acceptPayment(const String& orderId)
{
	size_t i;
	for (i = 0; i < orders.length(); i++)
		if (orders[i].getId() == orderId)
			break;

	const String& driverId = UserManager::getInstance()
		.getCurrentUserId();

	UserManager::getInstance()
		.getDriverById(driverId)
		.addMoney(orders[i].getMoney());
}

void OrderManager::finishAll()
{
	for (size_t i = 0; i < orders.length(); i++)
		orders[i].setFinished(true);
}

void OrderManager::writeToBinaryFile(std::ofstream& file) const
{
	size_t ordersLen = orders.length();
	file.write((const char*)&ordersLen, sizeof(size_t));

	for (size_t i = 0; i < ordersLen; i++)
		orders[i].writeToBinaryFile(file);
}

void OrderManager::readFromBinaryFile(std::ifstream& file)
{
	size_t ordersCount = 0;
	file.read((char*)&ordersCount, sizeof(size_t));

	for (size_t i = 0; i < ordersCount; i++)
	{
		Order current;
		current.readFromBinaryFile(file);
		orders.add(current);
	}
}
