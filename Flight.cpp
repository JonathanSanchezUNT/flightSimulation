//
// Created by Jonathan Sanchez on 2019-03-26.
//

#include "Flight.h"

Flight::Flight()    //Constructor
{
    planeID = " ";
    flightID = 0;
    numOfPilots = 0;
    numOfCrew = 0;
    numOfCoPilots = 0;
    ListPilotID.clear();
    ListCrewID.clear();
    startTime = 0;
    endTime = 0;
    startAirportCode = " ";
    endAirportCode = " ";
    status = 0;

}
Flight::Flight(string planeID, int flightID, int numOfPilots, int numOfCrew, int numOfCoPilots,   vector<int> ListPilotID, vector<int> ListCrewID, vector<int> ListCoPilotID, vector<int> ListCabinCrewID ,
time_t startTime, time_t endTime, string startAirportCode, string endAirportCode, int status)   //Specialized Constructor
{
    this->planeID = planeID;
    this->flightID = flightID;
    this->numOfPilots = numOfPilots;
    this->numOfCrew = numOfCrew;
    this->numOfCoPilots = numOfCoPilots;
    this->ListPilotID = ListPilotID;
    this->ListCrewID = ListCrewID;
    this->ListCabinCrewID = ListCabinCrewID;
    this->ListCoPilotID = ListCoPilotID;
    this->startTime = startTime;
    this->endTime = endTime;
    this->startAirportCode = startAirportCode;
    this->endAirportCode = endAirportCode;
    this->status = status;

}

//All of the setter and getter functions needed for this class.
string Flight::getPlaneID()
{
    return planeID;
}
void Flight::setPlaneID(string planeID)
{
    this->planeID = planeID;
}
int Flight::getFlightID()
{
    return flightID;
}
void Flight::setFlightID(int flightID)
{
    this->flightID=flightID;
}
int Flight::getNumOfPilots()
{
    return numOfPilots;
}
void Flight::setNumOfPilots(int numOfPilots)
{
    this->numOfPilots=numOfPilots;
}
int Flight::getNumOfCoPilots()
{
    return numOfCoPilots;
}
void Flight::setNumOfCoPilots(int numOfCoPilots)
{
    this->numOfCoPilots = numOfCoPilots;
}
int Flight::getNumOfCrew()
{
    return numOfCrew;
}
void Flight::setNumOfCrew(int numOfCrew)
{
    this->numOfCrew=numOfCrew;
}
void Flight::setListPilotID(vector<int> ListPilotID)
{
    this->ListPilotID = ListPilotID;
}
vector<int> Flight::getListPilotID()
{
    return ListPilotID;
}
vector<int> Flight::getListCrewID()
{
    return ListCoPilotID;
}
void Flight::setListCrewID(vector<int> ListCrewID)
{
    this->ListCrewID=ListCrewID;
}
void Flight::setListCoPilotID(vector<int> ListCoPilotID)
{
    this->ListCoPilotID=ListCoPilotID;
}
vector<int> Flight::getListCoPilotID()
{
    return ListCoPilotID;
}
void Flight::setListCabinCrewID(vector<int> ListCabinCrewID)
{
    this->ListCabinCrewID=ListCabinCrewID;
}
vector<int> Flight::getListCabinCrewID()
{
    return ListCabinCrewID;
}
time_t Flight::getStartTime()
{
    return startTime;
}
void Flight::setStartTime(time_t startTime)
{
    this->startTime = startTime;
}

time_t Flight::getEndTime()
{
    return endTime;
}
void Flight::setEndTime(time_t endTime)
{
    this->endTime=endTime;
}
string Flight::getStartAirportCode()
{
    return startAirportCode;
}
void Flight::setStartAirportCode(string startAirportCode)
{
    this->startAirportCode=startAirportCode;
}
string Flight::getEndAirportCode()
{
    return endAirportCode;
}
void Flight::setEndAirportCode(string endAirportCode)
{
    this->endAirportCode=endAirportCode;
}
int Flight::getStatus()
{
    return status;
}
void Flight::setStatus(int status)
{
    this->status = status;
}