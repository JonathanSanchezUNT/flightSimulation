//
// Created by Jonathan Sanchez on 2019-03-26.
//

#ifndef HW4_FLIGHTS_H
#define HW4_FLIGHTS_H

#include <iostream>
#include <string>
#include <vector>

#include "crewMember.h"
#include "Flight.h"
#include "Aircrafts.h"
#include "crewMembers.h"

class Flights
{
public:
    Flights();
    void addFlight(Aircrafts& airCrafts, crewMembers& crewMembers); //Add and Edit flight both need Aircrafts and crewMembers to be passed into the function.
    void editFlight(Aircrafts& airCrafts, crewMembers& crewMembers);
    int findFlightByID(int id);
    void deleteFlight();
    void printFlights();
    void printFlightByID();
    void printPlaneSchedule();      //All of the function declarations for this class.
    void printCrewSchedule();
    void printFlightsByStatus();
    void deleteCancelledFlights();
    void deleteCompletedFlights();
    void updateFlightStatus();
    bool checkActiveFlight(int fID);

private:
    vector<Flight> flightVector;    //A vector of type Flight in order to use all of functions within that class.
};

#endif //HW4_FLIGHTS_H
