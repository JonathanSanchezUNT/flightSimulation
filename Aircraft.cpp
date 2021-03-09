//
// Created by Jonathan Sanchez on 2019-03-26.
//

#include "Aircraft.h"

Aircraft::Aircraft()    //Constructor
{
    make = " ";
    model = " ";
    tailNumber = " ";
    numOfSeats = 0;
    range = 0;
    minCrew = 0;
}
Aircraft::Aircraft(string make, string model, string tailNumber, int numOfSeats, int range, int minCrew)    //Specified Constructor
{
    this->make=make;
    this->model=model;
    this->tailNumber=tailNumber;
    this->numOfSeats=numOfSeats;
    this->range=range;
    this->minCrew=minCrew;


}

//All of the setter and getter functions for the Aircraft class are below and will be used in the Aircrafts class.
string Aircraft::getMake()
{
    return make;
}
void Aircraft::setMake(string make)
{
    this->make=make;
}
string Aircraft::getModel()
{
    return model;
}
void Aircraft::setModel(string model)
{
    this->model=model;
}
string Aircraft::getTailNumber()
{
    return tailNumber;
}
void Aircraft::setTailNumber(string tailNumber)
{
    this->tailNumber=tailNumber;
}
int Aircraft::getNumOfSeats()
{
    return numOfSeats;
}
void Aircraft::setNumOfSeats(int numOfSeats)
{
    this->numOfSeats=numOfSeats;
}
int Aircraft::getRangeMiles()
{
    return range;
}
void Aircraft::setRangeMiles(int range)
{
    this->range=range;
}
int Aircraft::getMinNumOfCrew()
{
    return minCrew;
}
void Aircraft::setMinNumOfCrew(int minCrew)
{
    this->minCrew=minCrew;
}
