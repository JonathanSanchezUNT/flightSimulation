//
// Created by Jonathan Sanchez on 2019-03-26.
//

#include "crewMembers.h"

crewMembers::crewMembers()
{
    crewMemberVector.clear();   //Clearing any data inside of crew members vector
}
void crewMembers::addMember()   //This function allows the user to add a member to the crew members vector.
{
    string name, rating;
    int ID, type, hours, crewStatus;
    int position;

    Pilot* tempPilot = NULL;
    CoPilot* tempCoPilot = NULL;
    cabinCrew* tempCabinCrew = NULL;

    crewMember* temp = NULL;

    cout << "-ADD CREW MEMBER SELECTED-";
    cout << endl;

    cout << "--> Name?";
    getline(cin, name);

    cout << "--> ID?";
    cin >> ID;
    cin.ignore();

    do
    {
        cout << "--> Availability? (1 = Available, 2 = Leave, 3 = Sick) ";
        cin >> crewStatus;
        cin.ignore();

        if(crewStatus < AVAILABLE || crewStatus > SICK)
            cout << " Error." << endl;

    }while(crewStatus < AVAILABLE || crewStatus > SICK);

    do
    {
        cout << "--> Type? (1 = Pilot, 2 = CoPilot, 3 = Cabin)";
        cin >> type;
        cin.ignore();

        if(type != PILOT && type != COPILOT && type != CABIN)
            cout << " [error] ..." << endl;

    }while(type != PILOT && type != COPILOT && type != CABIN);


    if(type == PILOT)
    {
        temp = new Pilot;
        tempPilot = dynamic_cast<Pilot*>(temp);
        do {
            cout << "5 Character Rating Code: ";
            getline(cin, rating);
            if(rating.length() != 5)
            {
                cout << "Must be 5 characters long, try again." << endl;
            }
        }while(rating.length() != 5);

        cout << "Flight hours as pilot: ";
        cin >> hours;
        cin.ignore();

        tempPilot->setMemberName(name);
        tempPilot->setMemberID(ID);
        tempPilot->setMemberType(type);
        tempPilot->setcrewStatus(crewStatus);
        tempPilot->setCode(rating);
        tempPilot->setHours(hours);

        crewMemberVector.push_back(tempPilot);
    }
    else if(type == COPILOT)
    {

        temp = new CoPilot;
        tempCoPilot = dynamic_cast<CoPilot*>(temp);
        do {
            cout << "4 Character Rating Code: ";
            getline(cin, rating);
            if(rating.length() != 4)
            {
                cout << "Must be 4 characters long, try again." << endl;
            }
        }while(rating.length() != 4);

        cout << "Flight hours as CoPilot: ";
        cin >> hours;
        cin.ignore();

        tempCoPilot->setMemberName(name);
        tempCoPilot->setMemberID(ID);
        tempCoPilot->setMemberType(type);
        tempCoPilot->setcrewStatus(crewStatus);
        tempCoPilot->setCode(rating);
        tempCoPilot->setHours(hours);

        crewMemberVector.push_back(tempCoPilot);

    }
    else if(type == CABIN)
    {

        temp = new cabinCrew;
        tempCabinCrew = dynamic_cast<cabinCrew*>(temp);
        do {

            cout << "Cabin Crew Position, Choose one of the following." << endl;
            cout << "-->1 = FIRST CLASS" << endl;
            cout << "-->2 = BUSINESS CLASS" << endl;
            cout << "-->3 = ECONOMY FRONT" << endl;
            cout << "-->4 = ECONOMY REAR" << endl;
            cout << "-->5 = LEAD" << endl;
            cin >> position;

            if(position < FIRSTCLASS || position > LEAD)
            {
                cout << "Error, try again." << endl;
            }


        }while(position < FIRSTCLASS || position > LEAD);





        tempCabinCrew->setMemberName(name);
        tempCabinCrew->setMemberID(ID);
        tempCabinCrew->setMemberType(type);
        tempCabinCrew->setcrewStatus(crewStatus);
        tempCabinCrew->setPosition(position);

        crewMemberVector.push_back(tempCabinCrew);
    }
}
void crewMembers::editMember()  //This function allows the user to edit an existing member in the crew members vector.
{
    string name, rating;
    int ID, type, hours;
    int position;

    Pilot *tempPilot = NULL;
    CoPilot *tempCoPilot = NULL;
    cabinCrew *tempCabinCrew = NULL;

    crewMember *temp = NULL;

    cout << "-EDIT CREW MEMBER SELECTED-";
    cout << endl;
    cout << "--> Name?";
    getline(cin, name);
    cout << "--> ID?";
    cin >> ID;
    cin.ignore();
    if (findMemberByID(ID) == -1)    //Checking if the user entered member id is existent.
    {
        cout << "Member ID not found." << endl;
    }
    else
    {
        do
        {

            cout << "--> Type?";
            cin >> type;
            cin.ignore();

            if (type != PILOT && type != COPILOT && type != CABIN)
                cout << " [error] ..." << endl;

        } while (type != PILOT && type != COPILOT && type != CABIN);


        if (type == PILOT) {
            temp = new Pilot;
            tempPilot = dynamic_cast<Pilot *>(temp);
            do {
                cout << "5 Character Rating Code: ";
                getline(cin, rating);
                if (rating.length() != 5) {
                    cout << "Must be 5 characters long, try again." << endl;
                }
            } while (rating.length() != 5);

            cout << "Flight hours as pilot: ";
            cin >> hours;
            cin.ignore();

            tempPilot->setMemberName(name);
            tempPilot->setMemberID(ID);
            tempPilot->setMemberType(type);
            tempPilot->setCode(rating);
            tempPilot->setHours(hours);

            crewMemberVector.at(findMemberByID(ID)) = tempPilot;


        } else if (type == COPILOT) {

            temp = new CoPilot;
            tempCoPilot = dynamic_cast<CoPilot *>(temp);
            do {
                cout << "4 Character Rating Code: ";
                getline(cin, rating);
                if (rating.length() != 4) {
                    cout << "Must be 4 characters long, try again." << endl;
                }
            } while (rating.length() != 4);

            cout << "Flight hours as CoPilot: ";
            cin >> hours;
            cin.ignore();

            tempCoPilot->setMemberName(name);
            tempCoPilot->setMemberID(ID);
            tempCoPilot->setMemberType(type);
            tempCoPilot->setCode(rating);
            tempCoPilot->setHours(hours);

            crewMemberVector.at(findMemberByID(ID)) = tempCoPilot;

        } else if (type == CABIN) {

            temp = new cabinCrew;
            tempCabinCrew = dynamic_cast<cabinCrew *>(temp);
            do {

                cout << "Cabin Crew Position, Choose one of the following." << endl;
                cout << "-->1 = FIRST CLASS" << endl;
                cout << "-->2 = BUSINESS CLASS" << endl;
                cout << "-->3 = ECONOMY FRONT" << endl;
                cout << "-->4 = ECONOMY REAR" << endl;
                cout << "-->5 = LEAD" << endl;
                cin >> position;

                if (position < FIRSTCLASS || position > LEAD) {
                    cout << "Error, try again." << endl;
                }


            } while (position < FIRSTCLASS || position > LEAD);


            tempCabinCrew->setMemberName(name);
            tempCabinCrew->setMemberID(ID);
            tempCabinCrew->setMemberType(type);
            tempCabinCrew->setPosition(position);
            //Saving all of the user data into the crew member specialized constructor.

            crewMemberVector.at(findMemberByID(ID)) = tempCabinCrew; //Replacing the data that is saved at the index where the matching crew member id exists with this new data.
        }

    }
}

int crewMembers::findMemberByID(int id) //This function will find a crew member by ID
{
    unsigned int i;

    for(i=0; i < crewMemberVector.size(); i++) //Iterating through the crew member vector
    {
        if(crewMemberVector.at(i)->getMemberID() == id)  //Checking if the index of the crew member vector has the same ID as the user entered ID.
        {
            return i;   //If it does, then return the index where it was found.
        }
    }
    return -1;

}
void crewMembers::deleteMember() //This function deletes a memebr
{
    int id;
    cout << "-DELETE CREW MEMBER SELECTED-";
    cout << endl;
    cout << "--> Member ID?";
    cin >> id;
    cin.ignore();
    if(findMemberByID(id) == -1)    //Checks if the user entered member id returns -1, meaning that the id does not exist.
    {
        cout << "Member ID not found.";
    }
    else {
        crewMemberVector.erase(crewMemberVector.begin() + findMemberByID(id)); // But if it does exist then erase the instance of that crew member and all of its data.
    }
}
void crewMembers::printMembers() //This functin will print all of the members created.
{
    unsigned int i;
    cout << "-PRINT MEMBERS SELECTED-" << endl;
    cout << endl;
    for(i = 0; i < crewMemberVector.size(); i++)    //Iterating through the crew member vector
    {
        cout << "Member #" << i+1 << endl;
        crewMemberVector.at(i)->printInfo();
    }
}
void crewMembers::printMemberByID() //This functino will print a specific crew member
{
    int id = 0;
    cout << "-PRINT CREW MEMBERS BY ID SELECTED-";
    cout << endl;
    cout << "Member ID?";
    cin >> id;
    if(findMemberByID(id) == -1)   //Checking if the user entered id exists.
    {
        cout << "Member ID not found.";
    } else {
        cout << crewMemberVector.at(findMemberByID(id))->getMemberName() << endl;
        cout << crewMemberVector.at(findMemberByID(id))->getMemberID() << endl;  //If the ID does exist then print and get all of the data at that index of the vector.
        cout << crewMemberVector.at(findMemberByID(id))->getMemberType() << endl;
    }
}

