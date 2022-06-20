#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include<Observer.hpp>

#include<stdio.h>
#include <iomanip>
#include<string>
#include<iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//Set static variables
int Observer::invoiceNumber = 1000;
string Observer::currentDate = "";

void Observer::setCurrentDate(string currentDateIn)
{
    //Check if the date has already been set
    //If not, set the current date
    //If already set, check it is the same
    if (currentDate == "")
    {
        currentDate = currentDateIn;
    }
    else
    {
        if (currentDate!=currentDateIn)
        {
            cerr << "Inconsistant date issue" << endl;
            exit(-1);
        }
    }
}

void Observer::publishInvoice()
{ 
    //Publish invoice with invoice and the current date of the system
    invoiceNumber = publish(invoiceNumber, currentDate);
}

void Observer::orderShipped(string type, Customer* customer)
{
    //Check the type of shipment
    if (type=="E")
    { 
        //If end of the day, notify all users, ship all orders and send invoices
        publishInvoice();
        currentDate = "";
    }
    else
    {
        //If its an express order for one customer, notify that one customer and send their invoice 
        cout << "OP: customer " << setfill('0') << setw(4) << customer->getCustomerNumber() << ": shipped quantity " << customer->getOrderQuantity() << endl;
        customer->notify(invoiceNumber++, currentDate);
    }
}

#endif
