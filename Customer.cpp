#include <iostream>
#include <random>
#include <cstdlib>
#include "Customer.h"
#include "LinkedQueue.h"

Customer::Customer(int prepTime)
{
	orderPrepTime = prepTime;
}

int Customer::getOrderPrepTime() const
{
	return orderPrepTime;
}

void Customer::simOrder(int numCustomers)
{
	LinkedQueue<Customer> queue;
	int total = 0;

	srand(static_cast<unsigned>(time(0)));

	for (int i = 0; i < numCustomers; ++i)
	{
		int prepTime = 1 + rand() % 15;
		queue.enqueue(Customer(prepTime));
	}

	while (!queue.isEmpty())
	{
		Customer currentCustomer = queue.peekFront();
		total += currentCustomer.getOrderPrepTime();
		queue.dequeue();
	}

	std::cout << "Total time to process " << numCustomers << ": " << total << " minutes";
}

int main()
{
	Customer::simOrder(10);
	std::cin.get();
	return 0;
}