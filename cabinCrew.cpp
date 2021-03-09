//
// Created by Jonathan Sanchez on 2019-04-17.
//

#include "cabinCrew.h"
#include "crewMember.h"

cabinCrew::cabinCrew()
{
    position = 0;
}
cabinCrew::cabinCrew(int position)
{
    this->position = position;
}
void cabinCrew::setPosition(int position)
{
    this-> position = position;
}
int cabinCrew::getPosition()
{
    return position;
}
void cabinCrew::printInfo()
{
    crewMember::printInfo();

    cout << "Position: ";
    if(position == FIRSTCLASS)
    {
        cout << "FIRST CLASS" << endl;
    }
    else if(position == BUSINESSCLASS)
    {
        cout << "BUSINESS CLASS" << endl;
    }
    else if(position == ECONOMYFRONT)
    {
        cout << "ECONOMY FRONT" << endl;
    }
    else if(position == ECONOMYREAR)
    {
        cout << "ECONOMY REAR" << endl;
    }
    else if(position == LEAD)
    {
        cout <<"LEAD" << endl;
    }
    else
    {
        cout << "Error." << endl;
    }
}