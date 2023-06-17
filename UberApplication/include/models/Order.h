#pragma once
#include "../helper/String.h"
#include "Address.h"

class Order : public IFileOperatable
{
	String id;
	Address start;
	Address destination;
	unsigned passengersCount = 0;
	bool finished = false;
	String clientId;
	String driverId;
	unsigned minutes = 0;

public:
	Order() = default;

	Order(
		const Address& _start,
		const Address& _dest,
		unsigned _passengersCount,
		const String& _clientId);

	const String& getId() const;
	const String& getClientId() const;
	const String& getDriverId() const;
	const Address& getStart() const;
	const Address& getDestination() const;
	bool getFinished() const;
	unsigned getMinutes() const;

	void setDriverId(const String& _id);
	void setFinished(bool _data);
	void setMinutes(unsigned _minutes);

	void writeToBinaryFile(std::ofstream& file) const override;
	void readFromBinaryFile(std::ifstream& file) override;
};

