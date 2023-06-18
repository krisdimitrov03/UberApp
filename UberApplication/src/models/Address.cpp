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
	name.writeToBinaryFile(file);
	file.write((const char*)&coordinates.x, sizeof(int));
	file.write((const char*)&coordinates.y, sizeof(int));
	if (!additionalInfo.hasValue())
	{
		String info = "";
		info.writeToBinaryFile(file);
	}
	else {
		additionalInfo.getData().writeToBinaryFile(file);
	}
}

void Address::readFromBinaryFile(std::ifstream& file)
{
	name.readFromBinaryFile(file);
	file.read((char*)&coordinates.x, sizeof(int));
	file.read((char*)&coordinates.y, sizeof(int));

	String info;
	info.readFromBinaryFile(file);
	additionalInfo.setData(info);
}
