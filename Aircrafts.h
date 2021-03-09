//
// Created by Jonathan Sanchez on 2019-03-26.
//

#ifndef HW4_AIRCRAFTS_H
#define HW4_AIRCRAFTS_H

#include <vector>
#include <iostream>
#include <string>
#include "Aircraft.h"
using namespace std;

class Aircrafts
{
public:
    Aircrafts();    //Constructor

    void addPlane();
    void editPlane();
    void deletePlane();
    int findPlaneByID(string tailNumber);   //All of the function declarations
    void printAllPlanes();
    void printSinglePlane();
    int findNumOfSeats(int index);
    int findMinOfCrew(int index);

private:
    vector<Aircraft> AircraftVector;    //A vector of type "Aircraft" in order to use all of the functions within Aircraft.

};

#endif //HW4_AIRCRAFTS_H
