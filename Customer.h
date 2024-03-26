#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class Customer
{
private:
	int orderPrepTime;

public:
	Customer(int prepTime = 0);
	int getOrderPrepTime() const;
	static void simOrder(int numCustomers);
};

#endif