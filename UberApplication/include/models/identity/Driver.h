#pragma once
#include "User.h"
#include "../../helper/List.hpp"
#include "../dto/OrderMessageDto.h"
#include "../Order.h"

class Driver : public User
{
	String carNumber;
	String phoneNumber;
	Address address;
	List<OrderMessageDto> messages;

public:
	Driver() = default;
	Driver(const String& _username,
		const String& _firstName,
		const String& _lastName,
		const String& _passwordHash,
		const String& _carNumber,
		const String& _phoneNumber);

	const String& getCarNumber() const;
	const String& getPhoneNumber() const;
	const Point& getCoordinates() const;
	const Address& getAddress() const;

	void setAddress(Address&& newAddress);

	void addMessage(Order&& data, const String& clientName);
	void deleteMessage(const String& orderId);

	double getDistanceTo(const Point& point);

	const List<OrderMessageDto>& getMessages() const;

	void writeToBinaryFile(std::ofstream& file) const override;
	void readFromBinaryFile(std::ifstream& file) override;
};