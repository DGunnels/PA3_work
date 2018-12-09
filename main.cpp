#include <iostream>
#include <fstream>
#include <vector>
#include "Dealer.h"
#include "functions.h"
using namespace std;
// Derek Gunnels - 109352533 - CSCI 1410

int main() {
    vector<Dealer> vecDealers;
    ifstream fileIn;
    // variables for reading
    string fileInput;

    // main.cpp

    // Create a vector for Dealers (vecDealer) 0 to unknown value/inf value
    // Create dynamic array for use by each dealer to represent 0 to many cars on lot

    // Create a for loop switch menu for function option
    // Include the option to go to the upper level. ie. back out of menu
    int menuInput = 0;
    while(menuInput != 8){
        cout << "Option 1: Read in.txt file" << endl <<
             "Option 2: Display Dealers" << endl <<
             "Option 3: Choose Dealer and display cars" << endl <<
             "Option 4: Choose Dealer and add a car" << endl <<
             "Option 5: Modify a Dealers' car" << endl <<
             "Option 6: Sort a Dealers' Cars by VIN" << endl <<
             "Option 7: Write to File out.txt" << endl <<
             "Option 8: Exit Program" << endl << endl << "Please select an option: " << endl;
        cin >> menuInput;
        switch(menuInput) {
            case 1: // read Dealers and Cars from in.txt

            fileIn.open("in.txt");
            if(fileIn.is_open()) {
                cout << "The file opened." << endl;
                readFileIn(fileIn, vecDealers);
            } else {
                cout << "Error." << endl;
            }
            /*      TEST SECTION FOR ENSURING STORAGE OF VALUES IN POINTER AND VECTOR
            for (int i = 0; i < 3; i++) {
                cout << endl << endl << endl;
                cout << "THIS IS DEALER " << i << ": " << vecDealers[i].getdealerName() << endl;
                //for (int j = 0; j < 1; j++) {
                    cout << "THEIR DEALER NUMBER IS: " << vecDealers[i].getdealerNumber() << endl;
                    cout << "THEIR NUMBER OF CARS IS: " << vecDealers[i].getnumberCars() << endl;

                for (int k = 0; k < vecDealers[i].getnumberCars(); k++) {
                    cout << "CAR VIN: " << vecDealers[i].carArrayPoint[k].getcarVIN() << endl;
                    cout << "CAR MAKE: " << vecDealers[i].carArrayPoint[k].getcarMake() << endl;
                    cout << "CAR MODEL: " << vecDealers[i].carArrayPoint[k].getcarModel() << endl;
                    cout << "CAR YEAR: " << vecDealers[i].carArrayPoint[k].getcarYear() << endl;
                    cout << "CAR PRICE: " << vecDealers[i].carArrayPoint[k].getcarPrice() << endl;
                //}
            }
                cout << endl << endl << endl;
            }
             */
                break;
            case 2: // Display Dealers
            displayDealers(vecDealers);
                break;
            case 3: // choose a dealer, display cars
                displayDealerCars(vecDealers);
                break;

            case 4: // choose a dealer, display cars, add car
                break;
            case 5: // choose dealer, display cars, modify car
                break;
            case 6: // choose dealer, sort cars by VIN via bubbleSort; Submenu for ascending and descending
                break;
            case 7: // Write dealers and cars to file out.txt
                break;
            case 8: // Exit program
                break;
            default: // Catch-all for other inputs
                cout << "Please enter a valid input." << endl;
                break;
        }
    }



    /* loop including:
     * 1. Read Dealers and Cars from file - Read in through a loop to appropriate vector or array (or both), return to menu
     *      - use getline and infile.ignore()
     *      - use file name in.txt
     *      - readFile function using for loop
     * 2. Display Dealers - print out dealer vector via loop, return to menu
     *      - printDealers function using a for loop
     * 3. Choose a Dealer Number, Display Cars - Take number entered subtract 1 to get appropriate car and dealer selection print selection, return to menu
     *      - pass-by-reference vect of dealers into func; display names and numbers, ask user for the dealer number
     *      - Display all cars with a for loop, 0 - size
     * 4. Choose a dealer number, list cars, and add a car - do above, but add car via dynamic array, return to menu
     *      - pass dealer vec by reference into func;
     *      - Ask for dealer number and new car info
     *      - increase dynamic array (lab 09 for reference)
     * 5. Choose a dealer number, list cars, modify car - do above, but modify car entry based on selection, via sub-menu using for and switch, rather than adding new car to dynamic array
     *      - pass dealer vec by reference into func;
     *      - ask for dealer number and then select car;
     *      - modify car info
     * 6. Choose a dealer, sort cars by VIN (extra credit) - sort cars by VIN via bubble sort or similar, possibly use submenu to sort ascending and descending
     *      - Pass vector into func by reference; Display names and numbers; Ask user for dealer number, sort cars by vin and display with blank lines between each
     * 7. Write dealers and cars to file (extra credit) - Write out Dealers to dealers.txt, write out cars to cars.txt, write out both to dealers-and-cars.txt (submenu options via for loop and switch)
     *      - Pass dealer vector by reference, and filestream by reference; Call output file out.txt; write all dealers and cars to separate output file in the same format as item #1
     * 8. Exit
     *      - Exit the menu and program, print a message stating this
     * Utilises classes, not structs
     *      - class Dealer w/ private and public using friend
     *      - class Car w/ private and public
     */



    return 0;
}
