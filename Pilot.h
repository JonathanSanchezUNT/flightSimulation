//
// Created by Jonathan Sanchez on 2019-04-17.
//

//#include <iostream>
//#include <string>
#include "crewMember.h"
using namespace std;

#ifndef HW4_PILOT_H
//#define HW4_PILOT_H

class Pilot : public crewMember
{
public:
    Pilot();
    Pilot(int hours, string code);
    void setHours(int hours);
    int getHours();
    void setCode(string code);
    string getCode();
    void printInfo();

private:
    int hours;
    string code;
};
#endif //HW4_PILOT_H
