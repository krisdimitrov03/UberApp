#include "../../../include/models/identity/Driver.h"

Driver::Driver(const String& _username,
	const String& _firstName,
	const String& _lastName,
	const String& _passwordHash,
	const String& _carNumber,
	const String& _phoneNumber)
	: User(_username, _firstName, _lastName, _passwordHash),
	carNumber(_carNumber),
	phoneNumber(_phoneNumber)
{
}

const String& Driver::getCarNumber() const
{
	return carNumber;
}

const String& Driver::getPhoneNumber() const
{
	return phoneNumber;
}

const Point& Driver::getCoordinates() const
{
	return address.getCoordinates();
}

double Driver::getRating() const
{
	return rating;
}

const Address& Driver::getAddress() const
{
	return address;
}

void Driver::setAddress(Address&& newAddress)
{
	address = std::move(newAddress);
}

void Driver::addMessage(Order&& data, const String& clientName)
{
	OrderMessageDto message = {
		data.getId(),
		clientName,
		data.getStart().getName(),
		data.getStart().getCoordinates(),
		data.getDestination().getName(),
		data.getDestination().getCoordinates()
	};

	messages.add(std::move(message));
}

void Driver::deleteMessage(const String& orderId)
{
	for (size_t i = 0; i < messages.length(); i++)
		if (messages[i].orderId == orderId)
			messages.remove(i);
}

void Driver::rate(double _rating)
{
	if (_rating < 0)
		throw std::invalid_argument("Rating cannot be less than 0.");

	if (rating == 0.00)
		rating += _rating;
	else
		rating = (rating + _rating) / 2;
}

double Driver::getDistanceTo(const Point& point)
{
	return point.getDistanceTo(address.getCoordinates());
}

const List<OrderMessageDto>& Driver::getMessages() const
{
	return messages;
}

void Driver::writeToBinaryFile(std::ofstream& file) const
{
	User::writeToBinaryFile(file);
	carNumber.writeToBinaryFile(file);
	phoneNumber.writeToBinaryFile(file);
	address.writeToBinaryFile(file);
	file.write((const char*)&rating, sizeof(double));
}

void Driver::readFromBinaryFile(std::ifstream& file)
{
	User::readFromBinaryFile(file);
	carNumber.readFromBinaryFile(file);
	phoneNumber.readFromBinaryFile(file);
	address.readFromBinaryFile(file);
	file.read((char*)&rating, sizeof(double));
}