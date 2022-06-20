#include<ordering.hpp>

using namespace std;

int main(int argc, char **argv){
    
    //Check that the program is provided with 1 input parameter 
    if (argc!=2)
    {
        //If incorrect number of parameters provided, exit with error code -3
        cerr << "Incorrect number of input parameters provided" << endl;
        exit(-3);
    }

    //Get the file name provided as a program input parameter
    string inputFileName = argv[1];

    //Create the observer broker
    ObserverBroker obs;
  
    ifstream file(inputFileName);
    string line;

    //Open the input file and read each line in turn
    if (file.is_open())
    {
        while (getline(file,line))
        {
            if (line[0]=='C')
            { 
		  processNewCustomer(&obs, line);
            } 
            else if(line[0]=='S')
            {
                 processNewOrder(&obs, line);
	    }
            else if (line[0]=='E')
            {
                 processEndOfDay(&obs, line);
            }
            else
            {
                cerr << "Invalid operation. Line must start with either a C, S or E" << endl;
                exit(-2);
            }
        
	}
        //return 0;
    }
    else
    {
        //If the file could not be opened, write to the standard error stream
        //and exit with error code -4
        cerr << "Could not open file" << endl;
        exit(-4);
    }
}

void processNewCustomer(ObserverBroker *obs, string line)
{
    // Get the customer number and name from the line from the file
     int customerNumber = std::stoi( line.substr(1,4) );
     string customerName = line.substr(5);

    //Ensure that the new customer number follows on from the previous    
    int numberOfCustomers = (*obs).getNumberOfCustomers();
    if (numberOfCustomers+1 != customerNumber)
    {
        cerr << "Inconsistant customer number incrementation" << endl;
        exit(-5);
    }

    //Create a new customer using information form the line in the file 
     Customer customer(customerNumber, customerName);

    //Subscribe the user to the ordering system so that they get notified when their orders get shipped
     (*obs).subscribe(customer);

    //Output to standard output stream that customer has been added to the system
     cout << "OP: customer: " << setfill('0') << setw(4)  <<customerNumber<< " added" << endl;
}

void processNewOrder(ObserverBroker *obs, string line)
{
    //Get the order type and date from the line from the file
    string orderType = line.substr(9,1);
    string orderDate = line.substr(1,8);

    //Set the 'current date' of the system to the date of the order
    (*obs).setCurrentDate(orderDate);
 
    //Get the customer number and the order quantity from the line form the line
    int customerNumber = std::stoi(line.substr(10,4));
    int orderQuantityNum = std::stoi(line.substr(14,3));
    
    //Retrieve the customer object who is making the order
    Customer* customer = (*obs).getCustomer(customerNumber-1);

    //Update the customers order with the new order quantity
    customer->updateOrderQuantity(orderQuantityNum);

    //Check whether the order is an express order
    if (orderType=="X")
    {
        //Output to the standard output stream that the order has been processed
        cout << "OP: customer " << setfill('0') << setw(4) << customerNumber << ": EXPRESS order: quantity " << orderQuantityNum << endl;
       
        //Ship the express order and notify the customer by sending them an invoice of their order
        (*obs).orderShipped("S", customer);
    }
    else
    {
        //Output to the standard output stream that the order has been processed
        cout << "OP: customer " << setfill('0') << setw(4) << customerNumber << ": normal order: quantity " << orderQuantityNum << endl;
    }
}

void processEndOfDay(ObserverBroker *obs, string line)
{
    //Get the end of the day date from the line from the file
    string endOfDayDate = line.substr(1,8);

    //Check the end of day date is valid
    (*obs).setCurrentDate(endOfDayDate);

    //Output to the standard output stream that the day has ended and display the date
    cout << "OP: end of day " << endOfDayDate << endl;

    //Ship all orders and notify all customers by sending them each an invoice if they have orders for that day
    (*obs).orderShipped("E", 0);
}

