#include "Dealer.h"
#include "functions.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
// Dealer.cpp
// * use constructors and define implementations for car/dealer

Dealer::Dealer(){
    Dealer::dealerName = "";
    Dealer::dealerNumber = 0;
    Dealer::numberCars = 0;
    Dealer::carArrayPoint = nullptr;
}
Dealer::Dealer(string _dealerName, int _dealerNumber, int _numberCars){
    Dealer::dealerName = _dealerName;
    Dealer::dealerNumber = _dealerNumber;
    Dealer::numberCars = _numberCars;
    Dealer::carArrayPoint = nullptr;
}

string &Dealer::getdealerName() {
    return this->dealerName;
}
int Dealer::getdealerNumber() {
    return this->dealerNumber;
}
int Dealer::getnumberCars() {
    return this->numberCars;
}

void Dealer::setdealerName(string dealerName) {
    Dealer::dealerName = dealerName;
}

void Dealer::setdealerNumber(int dealerNumber) {
    Dealer::dealerNumber = dealerNumber;
}

void Dealer::setnumberCars(int numberCars) {
    Dealer::numberCars = numberCars;
}



Car::Car() {
    Car::carVIN = "";
    Car::carMake = "";
    Car::carModel = "";
    Car::carYear = 0;
    Car::carPrice = 0.0;
}

// Car::Car(string carMake, string carModel, int carYear, string carVIN, double carPrice) {}

string Car::getcarMake() { // get the car make (display)
    return carMake;
}
string Car::getcarModel() { // get the car model (display)
    return carModel;
}
string Car::getcarVIN() { // get the car vin (display)
    return carVIN;
}
int Car::getcarYear() { // get the car year (display)
    return carYear;
}
double Car::getcarPrice() { // get the car price (display)
    return carPrice;
}


void Car::setcarMake(string &carMake) {
    Car::carMake = carMake;
}

void Car::setcarModel(string &carModel) {
    Car::carModel = carModel;
}

void Car::setcarVIN(string &carVIN) {
    Car::carVIN = carVIN;
}

void Car::setcarYear(int carYear) {
    Car::carYear = carYear;
}

void Car::setcarPrice(double carPrice) {
    Car::carPrice = carPrice;
}

void readFileIn(ifstream &fileIn, vector<Dealer> &vecDealers) {
    // Variables & other
    Dealer dealerObj;
    string dealerName;
    string carVin;
    string carMake;
    string carModel;
    int dealerNumber;

    int carYear;
    int numberCars;
    double carPrice;

    cout << "This is before the if and while" << endl;
        while (getline(fileIn, dealerName)) {
            // cout << dealerName << endl;
            fileIn >> dealerNumber;
            // cout << dealerNumber << endl;
            fileIn.ignore();
            fileIn >> numberCars;
            // cout << numberCars << endl;
            fileIn.ignore();
            dealerObj.setdealerName(dealerName);
            dealerObj.setdealerNumber(dealerNumber);
            dealerObj.setnumberCars(numberCars);
            dealerObj.carArrayPoint = new Car[numberCars];
            for (int i = 0; i < numberCars; i++) {
                // take in vin, make, model, year, price from file

                getline(fileIn, carVin);
                // cout << "Car VIN: " << carVin << endl;
                getline(fileIn, carMake);
                // cout << "Car Make: " << carMake << endl;
                getline(fileIn, carModel);
                // cout << "Car Model: " << carModel << endl;
                fileIn >> carYear;
                // cout << "Car Year: " << carYear << endl;
                fileIn.ignore();
                fileIn >> carPrice;
                // cout << "Car Price: " << carPrice << endl;
                fileIn.ignore();

                // Set the vin, make, model, year, price for the car inside of the array
                dealerObj.carArrayPoint[i].setcarVIN(carVin);
                // cout << "VIN: " << dealerObj.carArrayPoint[i].getcarVIN();
                // cout << endl;
                dealerObj.carArrayPoint[i].setcarMake(carMake);
                // cout << "MAKE: " << dealerObj.carArrayPoint[i].getcarMake();
                // cout << endl;
                dealerObj.carArrayPoint[i].setcarModel(carModel);
                // cout << "MODEL: " << dealerObj.carArrayPoint[i].getcarModel();
                // cout << endl;
                dealerObj.carArrayPoint[i].setcarYear(carYear);
                // cout << "YEAR: " << dealerObj.carArrayPoint[i].getcarYear();
                // cout << endl;
                dealerObj.carArrayPoint[i].setcarPrice(carPrice);
                // cout << "PRICE: " << dealerObj.carArrayPoint[i].getcarPrice();
                // cout << endl;
            } // end of for loop
            vecDealers.push_back(dealerObj);
        } // end of while loop
        for (int i = 0; i < vecDealers.size(); i++) {
            cout << "DEALER NAME: " <<  vecDealers[i].getdealerName() << endl;
            cout << "DEALER NUMBER: " << vecDealers[i].getdealerNumber() << endl;
            cout << "NUMBER OF CARS: " << vecDealers[i].getnumberCars() << endl;
            int c = vecDealers[i].getnumberCars();
            for (int j = 0; j < c; j++) {
                cout << "The make of the car is: " << vecDealers[i].carArrayPoint[j].getcarMake() << endl;
            } // end of internal for loop
        } // end of outer for loop
    //} else {
    //    cout << "Error: File not open." << endl;
    //}
    cout << "This is after the if and while" << endl;
} // end of readFileIn

void displayDealers(vector<Dealer> &vecDealers){
    for(int i = 0; i < vecDealers.size(); i++){
        cout << "This is Dealer #" << i+1 << ": " << vecDealers[i].getdealerName() << endl;
    }
}

void displayDealerCars(vector<Dealer> &vecDealers){
    int carDisplaySelect = 0;
    int dealerSelection = 0;
    while (carDisplaySelect != 2) {
        cout << "Would you like to select a dealer to display?" << endl << "Enter 1 to display Dealers. Enter 2 to return to the main menu." << endl;
        cin >> carDisplaySelect;
        switch (carDisplaySelect) {
            case 1: { // Yes

                for (int i = 0; i < vecDealers.size(); i++) {
                    cout << "This is Dealer #" << i + 1 << ": " << vecDealers[i].getdealerName() << endl;
                }
                cout << "Select a dealer to display cars: " << endl;
                cin >> dealerSelection;

                for (int i = 0; i < vecDealers[dealerSelection - 1].getnumberCars(); i++){
                    cout << "Car Maker: " << vecDealers[dealerSelection - 1].carArrayPoint[i].getcarMake()
                         << endl;
                    cout << "Car Model: " << vecDealers[dealerSelection - 1].carArrayPoint[i].getcarModel()
                         << endl;
                    cout << "Car VIN: " << vecDealers[dealerSelection - 1].carArrayPoint[i].getcarVIN()
                         << endl;
                    cout << "Car Year: " << vecDealers[dealerSelection - 1].carArrayPoint[i].getcarYear()
                         << endl;
                    cout << "Car Price: " << vecDealers[dealerSelection - 1].carArrayPoint[i].getcarPrice()
                         << endl;
                }

                break;
            }
            case 2: // No
                cout << "Returning to main menu." << endl;
                break;
            default: // catch-all
                break;
        }
    }
}
void addDealerCar (vector<Dealer> &vecDealers){
    int carDisplaySelect = 0;
    int dealerSelection = 0;
    while (carDisplaySelect != 2) {
        cout << "Would you like to select a dealer to add a car to?" << endl << "Enter 1 to display Dealers. Enter 2 to return to the main menu." << endl;
        cin >> carDisplaySelect;
                for (int a = 0; a < vecDealers.size(); a++) {
                    cout << "This is Dealer #" << a + 1 << ": " << vecDealers[a].getdealerName() << endl;
                }
                cout << "Select a dealer to add a car: " << endl;
                cin >> dealerSelection;

                int numberCars = vecDealers[dealerSelection-1].getnumberCars() +1;
                Car *tempArray = new Car[numberCars];
                for (int i = 0; i < vecDealers[dealerSelection - 1].getnumberCars(); i++) {
                    tempArray[i] = vecDealers[dealerSelection-1].carArrayPoint[i];
                    cout << tempArray[i].getcarMake() << endl;
                    cout << tempArray[i].getcarModel() << endl;
                    cout << tempArray[i].getcarVIN() << endl;
                    cout << tempArray[i].getcarPrice() << endl;
                    cout << tempArray[i].getcarYear() << endl;
                }
                delete[] vecDealers[dealerSelection-1].carArrayPoint;
                Car *carArrayPoint = new Car[numberCars];
                vecDealers[dealerSelection-1].carArrayPoint = carArrayPoint;
                vecDealers[dealerSelection-1].setnumberCars(numberCars);
                for (int j = 0; j < vecDealers[dealerSelection - 1].getnumberCars()-1; j++) {
                    vecDealers[dealerSelection-1].carArrayPoint[j] = tempArray[j];
                    cout << vecDealers[dealerSelection-1].carArrayPoint[j].getcarMake() << endl;
                    cout << vecDealers[dealerSelection-1].carArrayPoint[j].getcarModel() << endl;
                    cout << vecDealers[dealerSelection-1].carArrayPoint[j].getcarVIN() << endl;
                    cout << vecDealers[dealerSelection-1].carArrayPoint[j].getcarPrice() << endl;
                    cout << vecDealers[dealerSelection-1].carArrayPoint[j].getcarYear() << endl;

        }
        string carMake;
                cin >> carMake;
        vecDealers[dealerSelection-1].carArrayPoint[numberCars].setcarMake(carMake);
        
    }
}
