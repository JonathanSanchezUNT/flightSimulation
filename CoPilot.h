//
// Created by Jonathan Sanchez on 2019-04-17.
//

#include <iostream>
#include <string>
#include "crewMember.h"
using namespace std;

#ifndef HW4_COPILOT_H
#define HW4_COPILOT_H

class CoPilot : public crewMember
{
public:
    CoPilot();
    CoPilot(int hours, string code);
    void setHours(int hours);
    int getHours();
    void setCode(string code);
    string getCode();
    void printInfo();

private:
    int hours;
    string code;
};

#endif //HW4_COPILOT_H
