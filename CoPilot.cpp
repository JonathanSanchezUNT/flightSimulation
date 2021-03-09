//
// Created by Jonathan Sanchez on 2019-04-17.
//

#include "CoPilot.h"
#include "crewMember.h"

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
    crewMember::printInfo();
    cout << "Rating Code: " << code << endl;
    cout << "Hours Flown: " << hours;
}
