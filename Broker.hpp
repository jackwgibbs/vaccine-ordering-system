#ifndef BROKER_H
#define BROKER_H

#include<Customer.hpp>

using namespace std;

class Broker
{
    vector<Customer> customers;
  public:
    int publish(int, string);
    void subscribe(Customer);
    Customer* getCustomer(int);
    int getNumberOfCustomers();    
};

#endif
