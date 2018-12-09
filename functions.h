#ifndef PA3_FUNCTIONS_H
#define PA3_FUNCTIONS_H
#include <iostream>
#include <fstream>
#include "Dealer.h"
#include <vector>
using namespace std;
// functions.h
/*
 * readFile function
 * printDealers
 * printCars
 * chooseDealCarDisplay
 * chooseDealCarAdd
 * chooseDealCarMod
 * chooseDealVINSort
 * writeFile
 * programExit
 */

void readFileIn (ifstream &file, vector<Dealer> &vector);
void displayDealers (vector<Dealer> &vector);
void displayDealerCars (vector<Dealer> &vector);
void addDealerCar (vector<Dealer> &vector);
void modDealerCar (vector<Dealer> &vector);



#endif //PA3_FUNCTIONS_H
