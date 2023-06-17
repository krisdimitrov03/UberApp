#pragma once
#include <fstream>

struct IFileOperatable 
{
	virtual void writeToBinaryFile(std::ofstream& file) const = 0;
	virtual void readFromBinaryFile(std::ifstream& file) = 0;
};