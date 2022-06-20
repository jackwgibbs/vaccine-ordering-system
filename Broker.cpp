#include<Broker.hpp>

using namespace std;

int Broker::publish(int invoiceNumber, string currentDate)
{
    //Generate iterator to iterate over the vector collection of customers to ship each of their orders
    vector<Customer>::iterator currentCustomer = customers.begin();

    //Iterate over every customer
    while(currentCustomer!=customers.end())
    {
        //Check whether the customer has any orders
        if ((*currentCustomer).getOrderQuantity() > 0){

           //get the customer number and the quantity of their order
           int currentCustomerNumber = (*currentCustomer).getCustomerNumber(); 
           int currentCustomerQuantity = (*currentCustomer).getOrderQuantity();
            
           //Output to standard output stream that the customers order has been shipped
            cout << "OP: customer " << setfill('0') << setw(4) << currentCustomerNumber << ": shipped quantity " << currentCustomerQuantity << endl;  
             
           //Customer is altered that their order has been shipped by receiving an invoice
           (*currentCustomer).notify(invoiceNumber++, currentDate);
              
            currentCustomer++;
        }
        else
        {
            currentCustomer++;
        }
    }

    // Return the updated invoice number
    return invoiceNumber;
}

void Broker::subscribe(Customer customer)
{
    //Add the new customer to the list of subscribers, i.e. customers in the system
    customers.push_back(customer);
  
}

Customer* Broker::getCustomer(int customerNumber)
{
   //Return the customer object from the customer collection  
    return &customers[customerNumber];
}

int Broker::getNumberOfCustomers()
{
    return customers.size();
}

