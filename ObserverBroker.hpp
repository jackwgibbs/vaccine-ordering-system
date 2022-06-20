#ifndef OBSERVERBROKER_H
#define OBSERVERBROKER_H

#include<Observer.hpp>
#include<Customer.hpp>


using namespace std;

class ObserverBroker: public Broker, public Observer
{
    public:
    int publish(int alert, string currentDate)
    {
        invoiceNumber = Broker::publish(alert, currentDate);
        return invoiceNumber;
    }
};

#endif

