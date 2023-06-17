#pragma once
#include "../helper/List.hpp"
#include "../models/Order.h"

class OrderManager : public IFileOperatable
{
	static OrderManager instance;

	List<Order> orders;

	OrderManager() = default;
public:
	OrderManager(const OrderManager&) = delete;
	OrderManager& operator=(const OrderManager&) = delete;

	static OrderManager& getInstance();

	List<Order>& getOrders();

	void makeOrder(const Address& _address, const Address& _destination, unsigned _passengersCount);

	void writeToBinaryFile(std::ofstream& file) const override;
	void readFromBinaryFile(std::ifstream& file) override;
};

