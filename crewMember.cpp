//
// Created by Jonathan Sanchez on 2019-03-25.
//

#include "crewMember.h"
#include <stdio.h>
#include <iomanip>


crewMember::crewMember()    //Constructor definition
{
    name = " ";
    ID = 0;
    type = 0;
    crewStatus = 0;
}
crewMember::crewMember(string name, int ID, int type)    //Specialized Constructor
{
    this->name=name;
    this->ID=ID;
    this->type=type;
}

//All of the setter and getter functions that will be used in the crewMembers class and others.
string crewMember::getMemberName()
{
    return name;
}
void crewMember::setMemberName(string name)
{
    this->name = name;
}
int crewMember::getMemberID()
{
    return ID;
}
void crewMember::setMemberID(int ID)
{
    this->ID=ID;
}
int crewMember::getMemberType()
{
    return type;
}
void crewMember::setMemberType(int type)
{
    this->type=type;
}
int crewMember::getcrewStatus()
{
    return crewStatus;
}
void crewMember::setcrewStatus(int crewStatus)
{
    this->crewStatus = crewStatus;
}
void crewMember::printInfo()
{
    cout << "PRINTING INFO ... \n" << endl;

    cout << "Name: "  << name << endl;
    cout << "ID: " << ID << endl;

    cout << "Availability: ";
    if (crewStatus == AVAILABLE) {
        cout << "Available" << endl;
    }
    else if(crewStatus == LEAVE)
    {
        cout << "Leave" << endl;
    }
    else if(crewStatus == SICK)
    {
        cout << "Sick" << endl;
    }

    cout << "Type: ";
    if (type == PILOT) {
        cout << "Pilot" << endl;
    }
    else if(type == COPILOT)
    {
        cout << "CoPilot" << endl;
    }
    else if(type == CABIN)
    {
        cout << "Cabin Crew" << endl;
    }

}
/*
 * Pilot::Pilot()
{
    hours = 0;
    code = "NULL";
}
Pilot::Pilot(int hours, string code)
{
    this->hours = hours;
    this->code = code;
}
void Pilot::setCode(string code)
{
    this->code = code;
}
string Pilot::getCode()
{
    return code;
}
void Pilot::setHours(int hours)
{
    this->hours = hours;
}
int Pilot::getHours()
{
    return hours;
}
void Pilot::printInfo()
{
    cout << "Rating Code: " << code << endl;
    cout << "Hours Flown: " << hours;
}

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
   if(position == FIRSTCLASS)
   {

   }
}
CoPilot::CoPilot()
{
    hours = 0;
    code = "NULL";
}
CoPilot::CoPilot(int hours, string code)
{
    this->hours = hours;
    this->code = code;
}
void CoPilot::setCode(string code)
{
    this->code = code;
}
string CoPilot::getCode()
{
    return code;
}
void CoPilot::setHours(int hours)
{
    this->hours = hours;
}
int CoPilot::getHours()
{
    return hours;
}
void CoPilot::printInfo()
{
    cout << "Rating Code: " << code << endl;
    cout << "Hours Flown: " << hours;
}
*/