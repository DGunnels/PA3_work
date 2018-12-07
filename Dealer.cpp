#include "Dealer.h"
#include "functions.h"
#include <vector>
#include <iostream>
using namespace std;
// Dealer.cpp
// * use constructors and define implementations for car/dealer

Dealer::Dealer(){}
Dealer::Dealer(string dealerName, int dealerNumber){}

string Dealer::getdealerName() {
    return dealerName;
}
int Dealer::getdealerNumber() {
    return dealerNumber;
}
int Dealer::getnumberCars() {
    return numberCars;
}

void Dealer::setdealerName(string dealerName) {

}

void Dealer::setdealerNumber(int dealerNumber) {

}

void Dealer::setnumberCars(int numberCars) {

}



Car::Car() {}
Car::Car(string carMake, string carModel, int carYear, string carVIN, double carPrice) {}

string Car::getcarMake() {
    return carMake;
}
string Car::getcarModel() {
    return carModel;
}
string Car::getcarVIN() {
    return carVIN;
}
int Car::getcarYear() {
    return carYear;
}
double Car::getcarPrice() {
    return carPrice;
}


void Car::setcarMake(string carMake) {

}

void Car::setcarModel(string carModel) {

}

void Car::setcarVIN(string carVIN) {

}

void Car::setcarYear(int carYear) {

}

void Car::setcarPrice(double carPrice) {

}
