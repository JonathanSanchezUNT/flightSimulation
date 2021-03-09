//
// Created by Jonathan Sanchez on 2019-03-26.
//

#include "Flights.h"

Flights::Flights()
{
    flightVector.clear();
}
void Flights::addFlight(Aircrafts& airCrafts, crewMembers& crewMembers)     //This function adds a flight and passes in an instance of Aircrafts and crewMembers.
{
    int year=0, month=0, day=0, hour=0, minute=0, numOfPilots, fStatus;     //All of the variable declarations.
    int numOfCabinCrew, numOfPassengers, pilotID, cabinCrewID, flightID, coPilotid;
    int numOfCoPilots, numOfCabinC;
    string sAirportCode, eAirportCode, tailNumber;
    time_t startTime;   //time_t variables
    time_t endTime;
    time_t flightDuration;
    struct tm  timeStruct; //time struct
    vector<int> temp;   //pilot ids
    vector<int> temp2; //cabin crew ids
    vector<int> coPilotID;
    vector<int> CabinCrewID;

    cout << "-ADD FLIGHT SELECTED-";
    cout << endl;
    cout << "--> Tail number? ";
    getline(cin, tailNumber);
    if(airCrafts.findPlaneByID(tailNumber) == -1)   //checking if the tail number entered is existent
    {
        cout << "Tail number not found.";
    }
    else
    {
        cout << "--> Flight ID? ";
        cin >> flightID;
        cin.ignore();

        cout << "--> Start year? ";
        cin >> year;
        cin.ignore();

        cout << "--> Start month? (1-12) ";
        cin >> month;
        cin.ignore();                           //Gathering user data

        cout << "--> Start day? (1-31) ";
        cin >> day;
        cin.ignore();

        cout << "--> Start hour? (0-23) ";
        cin >> hour;
        cin.ignore();

        cout << "--> Start minute? ";
        cin >> minute;
        cin.ignore();

        timeStruct.tm_year = year - 1900;
        timeStruct.tm_mon = month - 1;
        timeStruct.tm_mday = day;       //Declaring the time variables correctly and minusing the right values.
        timeStruct.tm_hour = hour;
        timeStruct.tm_min = minute;

        startTime = mktime(&timeStruct);    //using the mktime function to have the correct format.

        cout << "--> End year? ";
        cin >> year;
        cin.ignore();

        cout << "--> End month? (1-12) ";
        cin >> month;
        cin.ignore();

        cout << "--> End day? (1-31) ";
        cin >> day;
        cin.ignore();

        cout << "--> End hour? ";       //gather user data
        cin >> hour;
        cin.ignore();

        cout << "--> End minute? ";
        cin >> minute;
        cin.ignore();

        timeStruct.tm_year = year - 1900;
        timeStruct.tm_mon = month - 1;
        timeStruct.tm_mday = day;
        timeStruct.tm_hour = hour;
        timeStruct.tm_min = minute;

        endTime = mktime(&timeStruct);


        flightDuration = endTime - startTime;   //flight duration is equal to the end time minus the start time.


        do
        {
            cout << "-->Number of pilots? ";
            cin >> numOfPilots;
            cin.ignore();
            if(flightDuration > 28800 && numOfPilots < 2)
                cout << "The flight is longer than 8 hours, there must be 2 or more pilots." << endl;

        }while(flightDuration > 28800 && numOfPilots < 2);  //do while loop that will make sure that user input is correct based on how long the flight is and the number of pilots.


        do {
            cout << "-->Number of cabin crew? ";
            cin >> numOfCabinCrew;
            cin.ignore();
            if(flightDuration > 28800 && numOfCabinCrew < 2*(airCrafts.findMinOfCrew(airCrafts.findPlaneByID(tailNumber))))
            {
                cout << "Flights longer than 8 hours must have twice as many cabin crew members as the aircraft minimum number of cabin crew. " << endl;
            }
        }while(flightDuration > 28800 && numOfCabinCrew <  2*(airCrafts.findMinOfCrew(airCrafts.findPlaneByID(tailNumber))));    //do while loop that will continue to room if the flight duration is greater than 8 hours and number of cabin crew is less than 2 times the minimum of crew.

        //------------------------
        do {
            cout << "-->Number of CoPilots? ";
            cin >> numOfCoPilots;
            cin.ignore();
            if(flightDuration > 28800 && numOfCoPilots < 2*(airCrafts.findMinOfCrew(airCrafts.findPlaneByID(tailNumber))))
            {
                cout << "Flights longer than 8 hours must have twice as many cabin crew members as the aircraft minimum number of cabin crew. " << endl;
            }
        }while(flightDuration > 28800 && numOfCoPilots <  2*(airCrafts.findMinOfCrew(airCrafts.findPlaneByID(tailNumber))));    //do while loop that will continue to room if the flight duration is greater than 8 hours and number of cabin crew is less than 2 times the minimum of crew.

        //-------------------------------------
        cout << "-->Starting airport code? ";
        getline(cin, sAirportCode);

        cout << "-->Ending airport code? ";
        getline(cin, eAirportCode);

        do
        {

            cout << "-->Number of passengers? ";
            cin >> numOfPassengers;
            cin.ignore();

            if(numOfPassengers > airCrafts.findNumOfSeats(airCrafts.findPlaneByID(tailNumber)))
                cout << "Number of Passengers entered is greater than number of seats in the plane. Try again.";

        }while(numOfPassengers > airCrafts.findNumOfSeats(airCrafts.findPlaneByID(tailNumber)));    //do while loop will run while num of passengers is greater than the num of seats of the plane.

        //FIXME ASK FOR COPILOT ID etc.
        for(unsigned int i = 0; i < numOfPilots; i++)
        {

            do {
                cout << "--> Pilot ID #" << i + 1 << "? ";
                cin >> pilotID;

                if (crewMembers.findMemberByID(pilotID) != -1) {    //this if statement is checking that the pilot ID is existent and if it is then it will push back the temp vector and insert that pilot id.
                    temp.push_back(pilotID);
                }
                else
                {
                    cout << "Pilot ID does not exist." << endl;
                }
            }while(crewMembers.findMemberByID(pilotID) == -1);  //The do while loop run while the pilot id is non existent
        }

        for(unsigned int i = 0; i < numOfCabinCrew; i++)
        {

            do {
                cout << "--> Cabin crew ID #" << i + 1 << "? ";
                cin >> cabinCrewID;
                cin.ignore();
                if (crewMembers.findMemberByID(cabinCrewID) != -1) {    //this if statement is checking that the Cabin Crew ID is existent and if it is then it will push back the temp vector and insert that cabin crew id.
                    temp2.push_back(cabinCrewID);
                }
                else
                {
                    cout << "Crew member ID does not exist." << endl;
                }
            }while(crewMembers.findMemberByID(cabinCrewID) == -1); //The do while loop run while the cabin crew id is non existent
        }

        for(unsigned int i = 0; i < numOfCoPilots; i++)
        {

            do {
                cout << "--> CoPilot ID #" << i + 1 << "? ";
                cin >> coPilotid;
                cin.ignore();
                if (crewMembers.findMemberByID(coPilotid) != -1) {    //this if statement is checking that the Cabin Crew ID is existent and if it is then it will push back the temp vector and insert that cabin crew id.
                    temp2.push_back(coPilotid);
                }
                else
                {
                    cout << "Crew member ID does not exist." << endl;
                }
            }while(crewMembers.findMemberByID(coPilotid) == -1); //The do while loop run while the cabin crew id is non existent
        }

        do{
            cout << "--> Flight status? [0 = Complete, 1 = Active, 2 = Cancelled] :";   //This will be gathering the flight status of the flight that is being added with 0 = Complete, 1 = Active, 2 = Cancelled
            cin >> fStatus;
            cin.ignore();
            if (fStatus < 0 || fStatus > 2)
            {
                cout << "Wrong number, try again."; //Checking that the user input is between 0 and 2.
            }
        }
        while(fStatus < 0 || fStatus > 2);

        Flight tempFlight(tailNumber, flightID, numOfPilots, numOfCabinCrew, numOfCoPilots, temp, temp2, coPilotID, CabinCrewID, startTime, endTime, sAirportCode, //Setting all the values to an instance of the Flight constructor
                          eAirportCode, fStatus);
        flightVector.push_back(tempFlight); //Adding the instance of the Flight we just created to the flight vector.

    }
}
void Flights::editFlight(Aircrafts& airCrafts, crewMembers& crewMembers) //Edit flight works the same as add flight other than the last 2 lines.
{
    int year, month, day, hour, minute, numOfPilots, fStatus;
    int numOfCabinCrew, numOfPassengers, pilotID, cabinCrewID, flightID;
    int numOfCoPilots;
    string sAirportCode, eAirportCode, tailNumber;
    time_t startTime;
    time_t endTime;
    time_t flightDuration;
    struct tm * timeStruct;
    vector<int> temp;   //pilot ids
    vector<int> temp2; //cabin crew ids
    vector<int> coPilotID;
    vector<int> CabinCrewID;

    cout << "-EDIT FLIGHT SELECTED-";
    cout << endl;
    cout << "--> Tail number? ";
    getline(cin, tailNumber);
    if(airCrafts.findPlaneByID(tailNumber) == -1)
    {
        cout << "Tail number not found.";
    }
    else
    {
        cout << "--> Flight ID? ";
        cin >> flightID;
        cin.ignore();

        cout << "--> Start year? ";
        cin >> year;
        cin.ignore();

        cout << "--> Start month? (1-12) ";
        cin >> month;
        cin.ignore();

        cout << "--> Start day? (1-31) ";
        cin >> day;
        cin.ignore();

        cout << "--> Start hour? ";
        cin >> hour;
        cin.ignore();

        cout << "--> Start minute? ";
        cin >> minute;
        cin.ignore();

        timeStruct-> tm_year = year - 1900;
        timeStruct-> tm_mon = month - 1;
        timeStruct-> tm_mday = day;
        timeStruct-> tm_hour = hour;
        timeStruct-> tm_min = minute;

        startTime = mktime(timeStruct);     //FIXME

        cout << "--> End year? ";
        cin >> year;
        cin.ignore();

        cout << "--> End month? (1-12) ";
        cin >> month;
        cin.ignore();

        cout << "--> End day? (1-31) ";
        cin >> day;
        cin.ignore();

        cout << "--> End hour? ";
        cin >> hour;
        cin.ignore();

        cout << "--> End minute? ";
        cin >> minute;
        cin.ignore();

        timeStruct-> tm_year = year - 1900;
        timeStruct-> tm_mon = month - 1;
        timeStruct-> tm_mday = day;
        timeStruct-> tm_hour = hour;
        timeStruct-> tm_min = minute;

        endTime = mktime(timeStruct);

        flightDuration = endTime - startTime;

        cout << "-->Number of pilots? ";
        cin >> numOfPilots;
        cin.ignore();
        // if(flightDuration > 8)
        cout <<"-->Number of cabin crew? ";
        cin >> numOfCabinCrew;
        cin.ignore();

        cout << "-->Starting airport code? ";
        getline(cin, sAirportCode);

        cout << "-->Ending airport code? ";
        getline(cin, eAirportCode);

        cout << "-->Number of passengers? ";
        cin >> numOfPassengers;
        cin.ignore();
        if(numOfPassengers > airCrafts.findNumOfSeats(airCrafts.findPlaneByID(tailNumber)))
            for(unsigned int i = 0; i < numOfPilots; i++)
            {

                do {
                    cout << "Pilot ID #" << i + 1 << "? ";
                    cin >> pilotID;
                    if (crewMembers.findMemberByID(pilotID) != -1) {
                        temp.push_back(pilotID);
                    }
                    else
                    {
                        cout << "Pilot ID does not exist." << endl;
                    }
                }while(crewMembers.findMemberByID(pilotID) == -1);
            }

        for(unsigned int i = 0; i < numOfCabinCrew; i++)
        {

            do {
                cout << "--> Cabin crew ID #" << i + 1 << "? ";
                cin >> cabinCrewID;
                cin.ignore();
                if (crewMembers.findMemberByID(cabinCrewID) != -1) {
                    temp2.push_back(cabinCrewID);
                }
                else
                {
                    cout << "Crew member ID does not exist." << endl;
                }
            }while(crewMembers.findMemberByID(cabinCrewID) == -1);
        }
        //---------------------
        for(unsigned int i = 0; i < numOfCoPilots; i++) {
            do {
                cout << "-->Number of CoPilots? ";
                cin >> numOfCoPilots;
                cin.ignore();
                if (flightDuration > 28800 &&
                    numOfCoPilots < 2 * (airCrafts.findMinOfCrew(airCrafts.findPlaneByID(tailNumber)))) {
                    cout
                            << "Flights longer than 8 hours must have twice as many cabin crew members as the aircraft minimum number of cabin crew. "
                            << endl;
                }
            } while (flightDuration > 28800 && numOfCoPilots < 2 * (airCrafts.findMinOfCrew(airCrafts.findPlaneByID(
                    tailNumber))));    //do while loop that will continue to room if the flight duration is greater than 8 hours and number of cabin crew is less than 2 times the minimum of crew.
        }
        //--------------------------
        do{
            cout << "--> Flight status? [0 = Complete, 1 = Active, 2 = Cancelled] :";
            cin >> fStatus;
            cin.ignore();
            if (fStatus < 0 || fStatus > 2)
            {
                cout << "Wrong number, try again.";
            }
        }
        while(fStatus < 0 || fStatus > 2);

        Flight tempFlight(tailNumber, flightID, numOfPilots, numOfCabinCrew, numOfCoPilots, temp, temp2, coPilotID, CabinCrewID, startTime, endTime, sAirportCode,
                          eAirportCode, fStatus);
        flightVector.at(findFlightByID(flightID)) = tempFlight; //This is the only difference compared to add flight, instead of adding it to the flight vector we are replacing the instance that matches with the same flight id to all of the new edited values.

    }
}
int Flights::findFlightByID(int id) //This function is finding a flight by the ID
{
    unsigned int i;

    for(i=0; i < flightVector.size(); i++)
    {
        if(flightVector.at(i).getFlightID() == id)
        {
            return i;   //returning the index of where the id's matched.
        }
    }
    return -1;
}
void Flights::deleteFlight() //This function will delete the instance of flight that the user chooses based on flight id.
{
    int id;
    cout << "-DELETE FLIGHT SELECTED-";
    cout << endl;
    cout << "--> Flight ID?";
    cin >> id;
    cin.ignore();
    if(findFlightByID(id) == -1)    //checking the flight id is existent.
    {
        cout << "Flight ID not found.";
    } else {
        flightVector.erase(flightVector.begin() + findFlightByID(id)); //if it does exist then erase that instance of flight based on the flight id.
    }

}
void Flights::printFlights()    //This function will print out all of the flight created.
{
    unsigned int i;
    cout << "-PRINT FLIGHT SELECTED-";
    cout << endl;
    for(i = 0; i < flightVector.size(); i++)    //iterating through the flight vector
    {
        time_t startTemp =flightVector.at(i).getStartTime();
        time_t endTemp =flightVector.at(i).getEndTime();
        cout << "Flight #" << flightVector.at(i).getFlightID() << endl;
        cout << "Plane ID: " << flightVector.at(i).getPlaneID() << endl;
        cout << "# of Pilots: " << flightVector.at(i).getNumOfPilots() << endl;
        for(unsigned int j = 0; j < flightVector.at(i).getListPilotID().size(); j++)
        {
            cout << "Pilot ID: " << flightVector.at(i).getListPilotID().at(j) << endl;
        }
        cout << "# of Crew: " << flightVector.at(i).getNumOfCrew() << endl;
        for(unsigned int k = 0; k < flightVector.at(i).getListCrewID().size(); k++) //Printing out all of the information for each flight at the index, using the accessor functions to access the values.
        {
            cout << "Crew ID: " << flightVector.at(i).getListCrewID().at(k) << endl;
        }
        cout <<"Start Time: " <<  ctime(&startTemp) << endl;
        cout << "End Time: " << ctime(&endTemp) << endl;
        cout << "Start Airport Code: " << flightVector.at(i).getStartAirportCode() << endl;
        cout << "End Airport Code: " << flightVector.at(i).getEndAirportCode() << endl;
        cout << "Flight Status: " << flightVector.at(i).getStatus() << endl;
    }
}
void Flights::printFlightByID() //This function will print out a flight based on the flight id.
{
    int flightID = 0;
    cout << "-PRINT FLIGHT BY ID SELECTED-";
    cout << endl;
    cout << "Flight ID? ";
    cin >> flightID;
    if(findFlightByID(flightID) == -1)  //checking that the flight id is existent.
    {
        cout << "Flight ID not found.";
    } else {
        time_t startTemp =flightVector.at(findFlightByID(flightID)).getStartTime();
        time_t endTemp =flightVector.at(findFlightByID(flightID)).getEndTime();

        cout << "Flight #" << flightVector.at(findFlightByID(flightID)).getFlightID() << endl;
        cout << "Plane ID: " << flightVector.at(findFlightByID(flightID)).getPlaneID() << endl;
        cout << "# of Pilots: " << flightVector.at(findFlightByID(flightID)).getNumOfPilots() << endl;
        cout << "# of Crew: " << flightVector.at(findFlightByID(flightID)).getNumOfCrew() << endl;
        cout << "# of Crew: " << flightVector.at(findFlightByID(flightID)).getNumOfCoPilots() << endl;
        for(unsigned int i = 0; i < flightVector.at(findFlightByID(flightID)).getListPilotID().size(); i++)
        {
            cout << flightVector.at(findFlightByID(flightID)).getListPilotID().at(i) << endl;   //This is printing out all of the information for that particular flight by using the accessor functions.
        }
        for(unsigned int i = 0; i < flightVector.at(findFlightByID(flightID)).getListCrewID().size(); i++)
        {
            cout << flightVector.at(findFlightByID(flightID)).getListCrewID().at(i) << endl;
        }
        cout <<"Start Time: " <<  ctime(&startTemp) << endl;
        cout << "End Time: " << ctime(&endTemp) << endl;
        cout << flightVector.at(findFlightByID(flightID)).getStartAirportCode() << endl;
        cout << flightVector.at(findFlightByID(flightID)).getEndAirportCode() << endl;
        cout << flightVector.at(findFlightByID(flightID)).getStatus() << endl;
    }
}
void Flights::printPlaneSchedule()  //This function is printing out the plane schedule for a specific plane.
{
    string tailN;
    cout << "Tail Number?";
    cin >> tailN;

    for(unsigned int i = 0; i < flightVector.size(); i++)   //iterating through the flight vector.
    {
        if(flightVector.at(i).getPlaneID() == tailN)    //if the flight vector at the index and accessing its plane id is equal to the user entered tail number print out all of the information using accessor functions.
        {
            time_t startTemp =flightVector.at(i).getStartTime();
            time_t endTemp =flightVector.at(i).getEndTime();
            cout << "-->Starting Airport: " << flightVector.at(i).getStartAirportCode() << endl;
            cout << "-->Ending Airport: " << flightVector.at(i).getEndAirportCode() << endl;
            cout << "-->Flight ID: " << flightVector.at(i).getFlightID() << endl;
            cout << "-->Start Time & Date: " << ctime(&startTemp) << endl;
            cout << "-->End Time & Date: " << ctime(&endTemp);
        } else{
            cout << "-->Tail number not existent." << endl;
        }
    }
}
void Flights::printCrewSchedule()       //This function will print out the schedule for a specific crew member.
{
    int memberN;
    cout << "Member ID?";
    cin >> memberN;

    for (unsigned int i = 0; i < flightVector.size(); i++)   //iterating through flight vector
    {
        for (unsigned int j = 0; j < flightVector.at(i).getListCrewID().size(); j++) //iterating through the flight vector accessing the list of crew ids.
        {
            if (flightVector.at(i).getListCrewID().at(j) == memberN) //if the accessor of list crew ids matches the user entered member id then print out all of the info, else print error statement.
            {
                time_t startTemp = flightVector.at(i).getStartTime();
                time_t endTemp = flightVector.at(i).getEndTime();
                cout << "-->Starting Airport: " << flightVector.at(i).getStartAirportCode() << endl;
                cout << "-->Ending Airport: " << flightVector.at(i).getEndAirportCode() << endl;
                cout << "-->Flight ID: " << flightVector.at(i).getFlightID() << endl;
                cout << "-->Start Time & Date: " << ctime(&startTemp) << endl;
                cout << "-->End Time & Date: " << ctime(&endTemp);
            }
            else
            {
                cout << "-->Member ID is non existent." << endl;
            }

        }

        for (unsigned int j = 0; j < flightVector.at(i).getListPilotID().size(); j++) //iterating through the flight vector accessing the list of pilot ids.
        {
            if (flightVector.at(i).getListPilotID().at(j) ==
                memberN)    //if the accessor of list pilot ids matches the user entered member id then print out all of the info, else print error statement.
            {
                time_t startTemp = flightVector.at(i).getStartTime();
                time_t endTemp = flightVector.at(i).getEndTime();
                cout << "Starting Airport: " << flightVector.at(i).getStartAirportCode() << endl;
                cout << "Ending Airport: " << flightVector.at(i).getEndAirportCode() << endl;
                cout << "Flight ID: " << flightVector.at(i).getFlightID() << endl;
                cout << "Start Time & Date: " << ctime(&startTemp) << endl;
                cout << "End Time & Date: " << ctime(&endTemp);
            }

            //------------------------------------------------------------------ NEW

            for (unsigned int j = 0; j < flightVector.at(i).getListCoPilotID().size(); j++) //iterating through the flight vector accessing the list of pilot ids.
            {
                if (flightVector.at(i).getListCoPilotID().at(j) ==
                    memberN)    //if the accessor of list pilot ids matches the user entered member id then print out all of the info, else print error statement.
                {
                    time_t startTemp = flightVector.at(i).getStartTime();
                    time_t endTemp = flightVector.at(i).getEndTime();
                    cout << "Starting Airport: " << flightVector.at(i).getStartAirportCode() << endl;
                    cout << "Ending Airport: " << flightVector.at(i).getEndAirportCode() << endl;
                    cout << "Flight ID: " << flightVector.at(i).getFlightID() << endl;
                    cout << "Start Time & Date: " << ctime(&startTemp) << endl;
                    cout << "End Time & Date: " << ctime(&endTemp);
                }

            }
        }
    }
}
void Flights::printFlightsByStatus() {  //This function will print the flight depending on the flight status

    cout << "COMPLETED FLIGHTS" << endl;
    for (unsigned int i = 0; i < flightVector.size(); i++) {
        if (flightVector.at(i).getStatus() ==
            0) { //Completed FLights, printing out all of the information for the flight if the flight status is completed.
            time_t startTemp = flightVector.at(i).getStartTime();
            time_t endTemp = flightVector.at(i).getEndTime();
            cout << "-->Starting Airport: " << flightVector.at(i).getStartAirportCode() << endl;
            cout << "-->Ending Airport: " << flightVector.at(i).getEndAirportCode() << endl;
            cout << "-->Flight ID: " << flightVector.at(i).getFlightID() << endl;
            cout << "-->Start Time & Date: " << ctime(&startTemp) << endl;
            cout << "-->End Time & Date: " << ctime(&endTemp);
        }
    }

    cout << "ACTIVE FLIGHTS" << endl;
    for (unsigned int i = 0; i < flightVector.size(); i++) {
        if (flightVector.at(i).getStatus() ==
            1) {  //Active Flights, printing out all of the information for the flight if the flight status is active.
            time_t startTemp = flightVector.at(i).getStartTime();
            time_t endTemp = flightVector.at(i).getEndTime();
            cout << "-->Starting Airport: " << flightVector.at(i).getStartAirportCode() << endl;
            cout << "-->Ending Airport: " << flightVector.at(i).getEndAirportCode() << endl;
            cout << "-->Flight ID: " << flightVector.at(i).getFlightID() << endl;
            cout << "-->Start Time & Date: " << ctime(&startTemp) << endl;
            cout << "-->End Time & Date: " << ctime(&endTemp);
        }
    }

    cout << "CANCELLED FLIGHTS" << endl;
    for (unsigned int i = 0; i < flightVector.size(); i++) {
        if (flightVector.at(i).getStatus() ==
            2) {  //Cancelled Flights, printing out all of the information for the flight if the flight status is cancelled.
            time_t startTemp = flightVector.at(i).getStartTime();
            time_t endTemp = flightVector.at(i).getEndTime();
            cout << "-->Starting Airport: " << flightVector.at(i).getStartAirportCode() << endl;
            cout << "-->Ending Airport: " << flightVector.at(i).getEndAirportCode() << endl;
            cout << "-->Flight ID: " << flightVector.at(i).getFlightID() << endl;
            cout << "-->Start Time & Date: " << ctime(&startTemp) << endl;
            cout << "-->End Time & Date: " << ctime(&endTemp);
        }
    }
}

void Flights::deleteCancelledFlights() //This function will delete all of the flights that are cancelled.
{
    for(unsigned int i = 0; i < flightVector.size(); i++)
    {
        if(flightVector.at(i).getStatus() == 2) //Checking if the status of the flight is equal to the cancelled value.
        {
            flightVector.erase(flightVector.begin() + i); //then erasing if true.
        }
    }
}
void Flights::deleteCompletedFlights() //This function will delete all of the flights that are completed.
{
    for(unsigned int i = 0; i < flightVector.size(); i++)
    {
        if(flightVector.at(i).getStatus() == 0) //Checking if the status of the flight is equal to the completed value.
        {
            flightVector.erase(flightVector.begin() + i); //then erasing if true.
        }
    }
}
void Flights::updateFlightStatus() //This function will uupdate the flight status depending on if the current time is greater than the flight end time.
{
    struct tm endTime;  //0 = Complete, 1 = Active, 2 = Cancelled

    for(unsigned int i = 0; i < flightVector.size(); i++)
    {
        if(time(0) > flightVector.at(i).getEndTime()) //checking if current time is greater than flight end time.
        {
            if(flightVector.at(i).getStatus() == 1) //checking if the flight status is equal to 1 which is active.
            {
                flightVector.at(i).setStatus(0); //setting the flight to complete
            }
        }
    }
}
bool Flights::checkActiveFlight(int fID) //This function checks if the flight is active.
{

    if(flightVector.at(findFlightByID(fID)).getStatus() == 1)   //if flight status is equal to 1 then return true else return false.
    {
        return true;
    } else
    {
        return false;
    }


}
