#pragma once
#include "../models/identity/Client.h"
#include "../models/identity/Driver.h"
#include "../helper/List.hpp"
#include "../models/identity/UserType.h"

class UserManager : public IFileOperatable
{
	static UserManager instance;

	struct {
		String id;
		String name;
		UserType type = UserType::Guest;
		bool isLogged = false;
		bool isInOrder = false;
	} currentUser;

	List<Client> clients;
	List<Driver> drivers;

	UserManager() = default;
public:
	UserManager(const UserManager&) = delete;
	UserManager& operator=(const UserManager&) = delete;

	static UserManager& getInstance();

	bool loginUser(const String& _username, const String& _password);

	int registerUser(
		UserType _type,
		const String& _username,
		const String& _firstName,
		const String& _lastName,
		const String& _password,
		const String& _carNumber = "",
		const String& _phoneNumber = "");

	void logoutUser();

	List<Client>& getClients();
	List<Driver>& getDrivers();

	UserType getCurrentUserType() const;
	const String& getCurrentUserName() const;
	const String& getCurrentUserId() const;
	bool getCurrentUserIsInOrder() const;
	bool getCurrentUserIsLoggedIn() const;

	void writeToBinaryFile(std::ofstream& file) const override;
	void readFromBinaryFile(std::ifstream& file) override;
};

