#include "../../include/app/Theme.h"
#include "../../include/helper/Console.h"

void Theme::setColors(ThemeOption data)
{
	switch (data) {
	case ThemeOption::Dark:
		bColor = "0";
		fColor = "f";
		break;
	default:
	case ThemeOption::Light:
		bColor = "f";
		fColor = "0";
		break;
	}
}

Theme::Theme()
{
	setColors(ThemeOption::Dark);
}

Theme::Theme(ThemeOption data)
{
	setColors(data);
}

const String& Theme::getFColor() const
{
	return fColor;
}

const String& Theme::getBColor() const
{
	return bColor;
}

bool Theme::operator==(ThemeOption option) const
{
	switch (option) {
	case ThemeOption::Light:
		return getBColor() == "f" && getFColor() == "0";
		break;
	default:
		return getBColor() == "0" && getFColor() == "f";
	}
}

void Theme::writeToBinaryFile(std::ofstream& file) const
{
	bool isLight = *this == ThemeOption::Light;
	file.write((const char*)&isLight, sizeof(bool));
}

void Theme::readFromBinaryFile(std::ifstream& file)
{
	bool isLight = false;
	file.read((char*)&isLight, sizeof(bool));

	setColors((ThemeOption)isLight);
}
