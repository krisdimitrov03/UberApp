#pragma once
#include "../helper/List.hpp"
#include "../models/Order.h"
#include "../models/dto/CheckOrderDto.h"

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
	CheckOrderDto checkOrder() const;
	void acceptOrder(const String& id, unsigned minutes);
	void declineOrder(const String& id);
	void cancelOrder(const String& id);
	void finishOrder(const String& id);

	bool pay(const String& orderId, double amount);
	void acceptPayment(const String& orderId);

	void finishAll();

	void writeToBinaryFile(std::ofstream& file) const override;
	void readFromBinaryFile(std::ifstream& file) override;
};

