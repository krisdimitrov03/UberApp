//Copied from Angel Dimitriev and refactored a little bit

#pragma once
#include <iostream>
#include "interfaces/IFileOperatable.h"

class String : IFileOperatable
{
	static const short SSO_MAX_SIZE = sizeof(char*) + sizeof(size_t) - 1;

	union
	{
		struct
		{
			char* _data;
			size_t _size;
		};
		char ssoData[String::SSO_MAX_SIZE + 1]{ '\0' };
	};

	void move(String&& other);
	void copyFrom(const String& other);
	void free();

	explicit String(size_t size);

	void notUsingSso();
public:
	bool isSso() const;

	String();
	String(const char* data);

	String(const String& other);
	String& operator=(const String& other);

	String(String&& other) noexcept;
	String& operator=(String&& other) noexcept;

	String& operator+=(const String& other);

	const char* c_str() const;
	size_t length() const;

	char& operator[](size_t index);
	char operator[](size_t index) const;

	~String();

	friend std::istream& operator>>(std::istream& is, String& str);

	friend String operator+(const String& lhs, const String& rhs);

	void writeToBinaryFile(std::ofstream& file) const override;
	void readFromBinaryFile(std::ifstream& file) override;
};

std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& str);

bool operator<(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);