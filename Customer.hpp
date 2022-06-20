#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include<stdio.h>
#include<iostream>
#include <iomanip>
#include<vector>
#include <stdio.h>

using namespace std;

class Customer 
{
    string customerName;
    int customerNumber;
    int quantity;
  public:
    Customer(int, string);
    int getCustomerNumber();
    void notify(int, string);
    void updateOrderQuantity(int);
    int getOrderQuantity();
};

#endif
