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
		double amount = 0.00;
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

	void changeAddress(const String& name, const Point& coordinates);

	const List<OrderMessageDto>& getMessages() const;

	void addMoney(double amount);

	void rateDriver(const String& driverName, double rating);

	List<Client>& getClients();
	Client& getClientById(const String& id);

	List<Driver>& getDrivers();
	Driver& getDriverById(const String& id);

	List<size_t> getSortedDriversIndexes(const Point& coordinates);

	UserType getCurrentUserType() const;
	const String& getCurrentUserName() const;
	const String& getCurrentUserId() const;
	bool getCurrentUserIsInOrder() const;
	bool getCurrentUserIsLoggedIn() const;
	double getCurrentUserAmount() const;

	void setCurrentUserIsInOrder(bool _data);
	void addToCurrentUserAmount(double data);
	void removeFromCurrentUserAmount(double data);

	void writeToBinaryFile(std::ofstream& file) const override;
	void readFromBinaryFile(std::ifstream& file) override;
};

