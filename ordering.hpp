#include<Customer.hpp>
#include<Observer.hpp>
#include<Broker.hpp>
#include<ObserverBroker.hpp>

#include<stdio.h>
#include <fstream>
#include <iomanip>
#include<string>
#include<iostream>
#include <stdio.h>
#include <string.h>

//Function prototypes
void processNewCustomer(ObserverBroker*, string);
void processNewOrder(ObserverBroker*, string);
void processEndOfDay(ObserverBroker*, string);

