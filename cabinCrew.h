//
// Created by Jonathan Sanchez on 2019-04-17.
//

#include <iostream>
#include <string>
#include "crewMember.h"
using namespace std;

#ifndef HW4_CABINCREW_H
#define HW4_CABINCREW_H
class cabinCrew : public crewMember
{
public:
    cabinCrew();
    cabinCrew(int position);
    void setPosition(int position);
    int getPosition();
    void printInfo();

private:
    int position;
};
#endif //HW4_CABINCREW_H
