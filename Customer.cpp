#include<Customer.hpp>

#include<stdio.h>
#include <fstream>
#include <iomanip>
#include<string>
#include<iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

Customer::Customer(int customerNumber, string customerName)
{
    this->customerName = customerName;
    this->customerNumber = customerNumber;
    this->quantity = 0;
}

int Customer::getCustomerNumber()
{
    return this->customerNumber;
}

void Customer::notify(int invoiceNum, string currentDate)
{
    //Output invoice to the user - notify them
    cout << "SC: customer " << setfill('0') << setw(4) << customerNumber << ": Invoice "<< invoiceNum << ": date " << currentDate << ": quantity: " << quantity  <<endl;
    quantity = 0;
}

void Customer::updateOrderQuantity(int quantity)
{
    //Add new order to the customers current order quantity
    this->quantity = this->quantity + quantity;
}

int Customer::getOrderQuantity()
{
    return quantity;
}


