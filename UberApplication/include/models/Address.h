#pragma once
#include "../helper/String.h"
#include "../helper/Point.h"
#include "../helper/Optional.hpp"

class Address : public IFileOperatable
{
	String name;
	Point coordinates = { 0,0 };
	Optional<String> additionalInfo;

public:
	Address() = default;
	Address(const String& _name, const Point& _coordinates, const String& _additionalInfo);
	Address(const String& _name, const Point& _coordinates);

	const String& getName() const;
	const Point& getCoordinates() const;

	void writeToBinaryFile(std::ofstream& file) const override;
	void readFromBinaryFile(std::ifstream& file) override;
};

