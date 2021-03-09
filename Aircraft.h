//
// Created by Jonathan Sanchez on 2019-03-26.
//

#ifndef HW4_AIRCRAFT_H
#define HW4_AIRCRAFT_H

#include <iostream>
#include <string>
using namespace std;

class Aircraft
{
public:
    Aircraft(); //Constructor
    Aircraft(string make, string model, string tailNumber, int numOfSeats, int range, int minCrew); //Specialized constructor


    string getMake();
    void setMake(string make);
    string getModel();
    void setModel(string model);
    string getTailNumber();
    void setTailNumber(string tailNumber);  //Declerations for all of the set and get functions
    int getNumOfSeats();
    void setNumOfSeats(int numOfSeats);
    int getRangeMiles();
    void setRangeMiles(int range);
    int getMinNumOfCrew();
    void setMinNumOfCrew(int minCrew);

private:
    string make;
    string model;
    string tailNumber;
    int numOfSeats;     //All of the variables that are needed for certain functions.
    int range;
    int minCrew;

};
#endif //HW4_AIRCRAFT_H
