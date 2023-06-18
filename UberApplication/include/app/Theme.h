#pragma once
#include "../helper/interfaces/IFileOperatable.h"
#include "../helper/String.h"
#include "ThemeOption.h"

class Theme : public IFileOperatable
{
	String bColor = "";
	String fColor = "";

public:
	Theme();
	explicit Theme(ThemeOption data);

	const String& getFColor() const;
	const String& getBColor() const;

	void setColors(ThemeOption data);

	bool operator==(ThemeOption option) const;

	void writeToBinaryFile(std::ofstream& file) const override;
	void readFromBinaryFile(std::ifstream& file) override;
};