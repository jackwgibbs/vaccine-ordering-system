#ifndef OBSERVER_H
#define OBSERVER_H

#include<stdio.h>
#include <fstream>
#include <iomanip>
#include<string>
#include<iostream>
#include<vector>
#include <stdio.h>
#include <string.h>
#include<Customer.hpp>

using namespace std;

class Observer
{   
    public:
    static int invoiceNumber; 
    static string currentDate;
    void setCurrentDate(string);
    virtual int publish(int, string) {cout << "d"<<endl;};
    void publishInvoice();
    void orderShipped(string, Customer*);
};

#endif
