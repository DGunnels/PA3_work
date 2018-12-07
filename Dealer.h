#ifndef PA3_DEALER_H
#define PA3_DEALER_H
#include <iostream>
#include <fstream>
using namespace std;

// Dealer.h
/*
 * pre-declare
 * class Dealer;
 * class Car;

 * Dealer class itself
 * variable - dealerName;
 * variable - dealerNumber;
 * variable - numberOfCars;
 * functions to SET and GET individually
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

class Dealer
{
private:
    string dealerName;
    int dealerNumber;
    int numberCars;

public:
    Dealer();
    Dealer(string dealerName, int dealerNumber);

    string getdealerName();
    int getdealerNumber();
    int getnumberCars();

    void setdealerName(string dealerName);
    void setdealerNumber(int dealerNumber);
    void setnumberCars(int numberCars);



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
    Car(string carMake, string carModel, int carYear, string carVIN, double carPrice);

    string getcarMake();
    string getcarModel();
    string getcarVIN();
    int getcarYear();
    double getcarPrice();

    void setcarMake(string carMake);
    void setcarModel(string carModel);
    void setcarVIN(string carVIN);
    void setcarYear(int carYear);
    void setcarPrice(double carPrice);


};
#endif //PA3_DEALER_H
