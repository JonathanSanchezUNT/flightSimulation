//
// Created by Jonathan Sanchez on 2019-03-26.
//

#ifndef HW4_FLIGHT_H
#define HW4_FLIGHT_H


#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Flight
{
public:
    Flight(); //Constructor
    Flight(string planeID, int flightID, int numOfPilots, int numOfCrew, int numOfCoPilots, vector<int> ListPilotID, vector<int> ListCrewID , vector<int> ListCoPilotID, vector<int> ListCabinCrewID ,
            time_t startTime, time_t endTime, string startAirportCode, string endAirportCode, int status); //Specialized Constructor


    string getPlaneID();
    void setPlaneID(string planeID);
    int getFlightID();
    void setFlightID(int flightID);
    int getNumOfPilots();
    void setNumOfPilots(int numOfPilots);
    int getNumOfCrew();
    void setNumOfCrew(int numOfCrew);
    int getNumOfCoPilots();
    void setNumOfCoPilots(int numOfCoPilots);
    vector<int> getListPilotID();
    void setListPilotID(vector<int> ListPilotID);
    vector<int> getListCrewID();
    void setListCrewID(vector<int> ListCrewID);     //All of function declarations for this class.
    vector<int> getListCoPilotID();
    void setListCoPilotID(vector<int> ListCoPilotID);
    vector<int> getListCabinCrewID();
    void setListCabinCrewID(vector<int> ListCabinCrewID);
    time_t getStartTime();
    void setStartTime(time_t startTime);
    time_t getEndTime();
    void setEndTime(time_t endTime);
    string getStartAirportCode();
    void setStartAirportCode(string startAirportCode);
    string getEndAirportCode();
    void setEndAirportCode(string endAirportCode);
    int getStatus();
    void setStatus(int status);

private:
    string planeID;
    int flightID;
    int numOfPilots;
    int numOfCrew;
    int numOfCoPilots;
    vector<int> ListPilotID;
    vector<int> ListCrewID;
    vector<int> ListCoPilotID;
    vector<int> ListCabinCrewID;
    time_t startTime;       //All of the variables that are parameters for functions.
    time_t endTime;
    string startAirportCode;
    string endAirportCode;
    int status;

};
#endif //HW4_FLIGHT_H
