#include "../../include/models/Order.h"
#include "../../include/helper/IdFactory.h"

Order::Order(const Address& _start, const Address& _dest, unsigned _passengersCount, const String& _clientId)
	: start(_start), destination(_dest), passengersCount(_passengersCount), clientId(_clientId)
{
	id = IdFactory::getInstance()
		.create();
}

const String& Order::getId() const
{
	return id;
}

const String& Order::getClientId() const
{
	return clientId;
}

const String& Order::getDriverId() const
{
	return driverId;
}

const Address& Order::getStart() const
{
	return start;
}

const Address& Order::getDestination() const
{
	return destination;
}

bool Order::getFinished() const
{
	return finished;
}

unsigned Order::getMinutes() const
{
	return minutes;
}

double Order::getMoney() const
{
	return money;
}

void Order::setDriverId(const String& _id)
{
	if (_id == "")
		throw std::invalid_argument("DriverId cannot be empty.");

	driverId = _id;
}

void Order::setFinished(bool _data)
{
	finished = _data;
}

void Order::setMinutes(unsigned _minutes)
{
	minutes = _minutes;
}

void Order::setMoney(double _amount)
{
	if (_amount <= 0)
		throw std::invalid_argument("Amount cannot be 0 or less.");

	money = _amount;
}

void Order::writeToBinaryFile(std::ofstream& file) const
{
}

void Order::readFromBinaryFile(std::ifstream& file)
{
}
