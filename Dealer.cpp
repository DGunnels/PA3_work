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
} // end of readFileIn

void displayDealers(vector<Dealer> &vecDealers){
    for(int i = 0; i < vecDealers.size(); i++){
        cout << "This is Dealer #" << vecDealers[i].getdealerNumber() << ": " << vecDealers[i].getdealerName() << endl << endl;
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
                    cout << "This is Dealer #" << vecDealers[i].getdealerNumber() << ": " << vecDealers[i].getdealerName() << endl << endl;
                }
                cout << "Select a dealer to display cars: " << endl;
                cin >> dealerSelection;
                int dealerIndex = -1;

                for(int a = 0; a < vecDealers.size(); a++){
                    if(dealerSelection == vecDealers[a].getdealerNumber()){
                        dealerIndex = a;
                    }
                }
                if(dealerIndex == -1){
                    cout << "That is not a valid selection." << endl;
                    break;
                }

                for (int i = 0; i < vecDealers[dealerIndex].getnumberCars(); i++){
                    cout << "Car Maker: " << vecDealers[dealerIndex].carArrayPoint[i].getcarMake()
                         << endl;
                    cout << "Car Model: " << vecDealers[dealerIndex].carArrayPoint[i].getcarModel()
                         << endl;
                    cout << "Car VIN: " << vecDealers[dealerIndex].carArrayPoint[i].getcarVIN()
                         << endl;
                    cout << "Car Year: " << vecDealers[dealerIndex].carArrayPoint[i].getcarYear()
                         << endl;
                    cout << "Car Price: " << vecDealers[dealerIndex].carArrayPoint[i].getcarPrice()
                         << endl << endl;

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
        switch(carDisplaySelect) {
            case 1: {
                string carMake;
                string carVIN;
                string carModel;
                int carYear;
                double carPrice;

                for (int a = 0; a < vecDealers.size(); a++) {
                    cout << "This is Dealer #" << vecDealers[a].getdealerNumber() << ": " << vecDealers[a].getdealerName() << endl << endl;
                }
                cout << "Select a dealer to add a car: " << endl;
                cin >> dealerSelection;
                int dealerIndex = -1;

                for(int a = 0; a < vecDealers.size(); a++){
                    if(dealerSelection == vecDealers[a].getdealerNumber()){
                        dealerIndex = a;
                    }
                }
                if(dealerIndex == -1){
                    cout << "That is not a valid selection." << endl;
                    break;
                }


                int numberCars = vecDealers[dealerIndex].getnumberCars() + 1;
                Car *tempArray = new Car[numberCars];

                 for (int i = 0; i < vecDealers[dealerIndex].getnumberCars(); i++) {
                    tempArray[i] = vecDealers[dealerIndex].carArrayPoint[i];
                    //cout << tempArray[i].getcarMake() << endl;
                    //cout << tempArray[i].getcarModel() << endl;
                    //cout << tempArray[i].getcarVIN() << endl;
                    //cout << tempArray[i].getcarPrice() << endl;
                    //cout << tempArray[i].getcarYear() << endl;
                }

                delete[] vecDealers[dealerIndex].carArrayPoint;
                vecDealers[dealerIndex].carArrayPoint = tempArray;
                vecDealers[dealerIndex].setnumberCars(numberCars);
                cin.ignore();
                cout << "Please enter the VIN: " << endl;
                getline(cin, carVIN);
                vecDealers[dealerIndex].carArrayPoint[numberCars - 1].setcarVIN(carVIN);
                cout << "Please enter the Maker: " << endl;
                getline(cin, carMake);
                vecDealers[dealerIndex].carArrayPoint[numberCars - 1].setcarMake(carMake);
                cout << "Please enter the Model: " << endl;
                getline(cin, carModel);
                vecDealers[dealerIndex].carArrayPoint[numberCars - 1].setcarModel(carModel);
                cout << "Please enter the Year: " << endl;
                cin >> carYear;
                vecDealers[dealerIndex].carArrayPoint[numberCars - 1].setcarYear(carYear);
                cout << "Please enter the Price: " << endl;
                cin >> carPrice;
                //cin.ignore();
                vecDealers[dealerIndex].carArrayPoint[numberCars - 1].setcarPrice(carPrice);
            }
            break;
            case 2:
                cout << "Exiting to Menu." << endl;
                break;
            default:
                break;
        }



    }
}

void modDealerCar (vector<Dealer> &vecDealers) {
    int carDisplaySelect = 0;
    int dealerSelection = 0;
    while (carDisplaySelect != 2) {
        cout << "Would you like to select a dealer to modify a car of?" << endl
             << "Enter 1 to display Dealers. Enter 2 to return to the main menu." << endl;
        cin >> carDisplaySelect;
        switch (carDisplaySelect) {
            case 1: {
                string carMake;
                string carModel;
                string carVIN;
                int carYear;
                double carPrice;
                for (int a = 0; a < vecDealers.size(); a++) {
                    cout << "This is Dealer #" << vecDealers[a].getdealerNumber() << ": " << vecDealers[a].getdealerName() << endl << endl;
                }
                cout << "Select a dealer to modify a car: " << endl;
                cin >> dealerSelection;
                int dealerIndex = -1;

                for(int a = 0; a < vecDealers.size(); a++){
                    if(dealerSelection == vecDealers[a].getdealerNumber()){
                        dealerIndex = a;
                    }
                }
                if(dealerIndex == -1){
                    cout << "That is not a valid selection." << endl;
                    break;
                }


                cout << "There are " << vecDealers[dealerIndex].getnumberCars() << " cars to choose from."
                     << endl;
                //for (int j = 0; j < vecDealers[dealerSelection - 1].getnumberCars(); j++) {
                    for (int i = 0; i < vecDealers[dealerIndex].getnumberCars(); i++) {
                        cout << "This is car #" << i + 1 << endl;
                        cout << "Car Maker: " << vecDealers[dealerIndex].carArrayPoint[i].getcarMake()
                             << endl;
                        cout << "Car Model: " << vecDealers[dealerIndex].carArrayPoint[i].getcarModel()
                             << endl;
                        cout << "Car VIN: " << vecDealers[dealerIndex].carArrayPoint[i].getcarVIN()
                             << endl;
                        cout << "Car Year: " << vecDealers[dealerIndex].carArrayPoint[i].getcarYear()
                             << endl;
                        cout << "Car Price: " << vecDealers[dealerIndex].carArrayPoint[i].getcarPrice()
                             << endl << endl;
                    //}
                }
                cout << "Which car would you like to modify?" << endl;
                int carModSelection;
                cin >> carModSelection;
                int modSelOption = 0;
                cin.ignore();

                while (modSelOption != 6) {
                    cout << "Please choose from the following: " << endl <<
                         "1. Maker" << endl <<
                         "2. Model" << endl <<
                         "3. VIN" << endl <<
                         "4. Year" << endl <<
                         "5. Price" << endl <<
                         "6. Exit" << endl;
                    cin >> modSelOption;
                    switch (modSelOption) {
                        case 1:
                            cin.ignore();
                            cout << "Enter the new Maker: " << endl;
                            getline(cin, carMake);
                            vecDealers[dealerIndex].carArrayPoint[carModSelection-1].setcarMake(carMake);
                            break;
                        case 2:
                            cin.ignore();
                            cout << "Enter the new Model: " << endl;
                            getline(cin, carModel);
                            vecDealers[dealerIndex].carArrayPoint[carModSelection-1].setcarModel(carModel);
                            break;
                        case 3:
                            cin.ignore();
                            cout << "Enter the new VIN: " << endl;
                            getline(cin, carVIN);
                            vecDealers[dealerIndex].carArrayPoint[carModSelection-1].setcarVIN(carVIN);
                            break;
                        case 4:
                            cin.ignore();
                            cout << "Enter the new year: " << endl;
                            cin >> carYear;
                            vecDealers[dealerIndex].carArrayPoint[carModSelection-1].setcarYear(carYear);
                            break;
                        case 5:
                            cin.ignore();
                            cout << "Enter the new price: " << endl;
                            cin >> carPrice;
                            vecDealers[dealerIndex].carArrayPoint[carModSelection-1].setcarPrice(carPrice);
                            break;
                        case 6:
                            cout << "Exiting to Menu." << endl;
                            break;
                        default:
                            break;
                    }

                }
            }
                case 2:
                    cout << "Returning to menu." << endl;
                break;
                default:
                    break;
            }
        }
    }


void writeFileout(ofstream &fileOut, vector<Dealer> &vecDealers) {
    for(int a = 0; a < vecDealers.size(); a++){
        fileOut << vecDealers[a].getdealerName() << endl;
        fileOut << vecDealers[a].getdealerNumber() << endl;
        fileOut << vecDealers[a].getnumberCars() << endl;
        for(int b = 0; b < vecDealers[a].getnumberCars(); b++) {
            fileOut << vecDealers[a].carArrayPoint[b].getcarVIN() << endl;
            fileOut << vecDealers[a].carArrayPoint[b].getcarMake() << endl;
            fileOut << vecDealers[a].carArrayPoint[b].getcarModel() << endl;
            fileOut << vecDealers[a].carArrayPoint[b].getcarYear() << endl;
            fileOut << vecDealers[a].carArrayPoint[b].getcarPrice() << endl;
        }
    }
}
