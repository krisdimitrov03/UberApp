#include "../../include/models/Address.h"

Address::Address(const String& _name, const Point& _coordinates, const String& _additionalInfo)
	: name(_name), coordinates(_coordinates), additionalInfo(_additionalInfo)
{
}

Address::Address(const String& _name, const Point& _coordinates)
	: name(_name), coordinates(_coordinates)
{
}

const String& Address::getName() const
{
	return name;
}

const Point& Address::getCoordinates() const
{
	return coordinates;
}

void Address::writeToBinaryFile(std::ofstream& file) const
{
}

void Address::readFromBinaryFile(std::ifstream& file)
{
}
