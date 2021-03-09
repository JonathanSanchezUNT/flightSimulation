//
// Created by Jonathan Sanchez on 2019-03-25.
//

#ifndef HW4_CREWMEMBER_H
#define HW4_CREWMEMBER_H

#include <iostream>
#include <string>
//#include "Pilot.h"
//#include "CoPilot.h"
//#include "cabinCrew.h"
using namespace std;

enum type {PILOT = 1, COPILOT = 2, CABIN = 3};
enum position {FIRSTCLASS = 1, BUSINESSCLASS, ECONOMYFRONT, ECONOMYREAR, LEAD};
enum crewStatus {AVAILABLE = 1, LEAVE = 2, SICK = 3};

class crewMember
{
public:
    crewMember();   //Constructor
    crewMember(string name, int ID, int type);   //Specialized Constructor

    string getMemberName();
    void setMemberName(string name);
    int getMemberID();
    void setMemberID(int ID);   //All of the function declarations
    int getMemberType();
    void setMemberType(int type);
    int getcrewStatus();
    void setcrewStatus(int crewStatus);
    virtual void printInfo();

private:
    string name;
    int ID;     //Variables that will be ued within functions.
    int type;
    int crewStatus;

};

/*
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
 */

#endif //HW4_CREWMEMBER_H
