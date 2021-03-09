//
// Created by Jonathan Sanchez on 2019-03-26.
//

#ifndef HW4_CREWMEMBERS_H
#define HW4_CREWMEMBERS_H

#include <iostream>
#include <string>
#include <vector>
#include "crewMember.h"
#include "Pilot.h"
#include "CoPilot.h"
#include "cabinCrew.h"

class crewMembers
{
public:
    crewMembers();
    void addMember();
    void editMember();
    int findMemberByID(int id); //Declaring all of the functions
    void deleteMember();
    void printMembers();
    void printMemberByID();


private:
   vector<crewMember*> crewMemberVector; //Declaring a vector of type crewMember in order to use all of the functions within that class.


};

#endif //HW4_CREWMAMBERS_H
