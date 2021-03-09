//
// Created by Jonathan Sanchez on 2019-04-17.
//

#include "Pilot.h"
#include "crewMember.h"

Pilot::Pilot()
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
    crewMember::printInfo();
    cout << "Rating Code: " << code << endl;
    cout << "Hours Flown: " << hours;
}