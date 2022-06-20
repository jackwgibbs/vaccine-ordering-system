# vaccine-ordering-system
C++ Vaccine Ordering System


## Description
Tasked with writing a well-structured, C++11 standard C++ program to process customer orders of COVID-19 vaccines. This was a coursework for my C module of my undergraduate degree at The University of Exeter and I achieved 95% in the project.

## How to run
Step 1:
The first step is to ensure you have permission to run the compile and link script. Enter the following command to ensure you do:

chmod u+x compileOP

Step 2:
Now we definitely have permission, we can run the compileOP script to compile and link the code. In order to do this, run the following command:

./compileOP

Step 3:
To run the program, run the following command 

./ordering orderFile.txt

This command will execute the ordering system with input file orderFile.txt. You can change this parameter providing you have a text file in the same directory. 

Alternatively, without using the dedicated compileOP script, you can compile, link and run the program with the following commands.

g++ -std=c++11 -I./ -c ordering.cpp -o ordering.o
g++ -std=c++11 -I./ -c Customer.cpp -o Customer.o
g++ -std=c++11 -I./ -c Observer.cpp -o Observer.o
g++ -std=c++11 -I./ -c Broker.cpp -o Broker.o

g++ ordering.o  Customer.o Observer.o Broker.o -o ordering
