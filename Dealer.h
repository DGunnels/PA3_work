#ifndef PA3_DEALER_H
#define PA3_DEALER_H
#include <iostream>
#include <fstream>
using namespace std;

// Dealer.h
/*
 * -   Add a new car pointer when you use the Dealer default
 * ie. void Dealer(string _name, int _number);

 * Car class itself
 * variable - carName
 * variable - carModel
 * variable - carYear
 * variable - carVIN
 * variable - carPrice
 * functions to SET and GET individuals
 */

// Pre-declare
class Car;
class Dealer;


// Defined Dealer
// - private
// + public
class Dealer
{
private:
    string dealerName;
    int dealerNumber;
    int numberCars;

public:
    Car *carArrayPoint;

    Dealer();
    Dealer(string _dealerName, int _dealerNumber, int _numberCars);

    string &getdealerName();
    int getdealerNumber();
    int getnumberCars();

    void setdealerName(string dealerName);
    void setdealerNumber(int dealerNumber);
    void setnumberCars(int numberCars);

    friend ostream & operator<< (ostream & out, Dealer & _dealer){
        return out;
        // overload operator<< function
    }

};


class Car
{
private:
    string carMake;
    string carModel;
    int carYear;
    string carVIN;
    double carPrice;
public:
    Car();

    string getcarMake();
    string getcarModel();
    string getcarVIN();
    int getcarYear();
    double getcarPrice();

    void setcarMake(string &carMake);
    void setcarModel(string &carModel);
    void setcarVIN(string &carVIN);
    void setcarYear(int carYear);
    void setcarPrice(double carPrice);

    friend ostream & operator<< (ostream & out, Car _car){
        return out;
        // overload operator for Car class
    }


};
#endif //PA3_DEALER_H
