//
// Created by Jonathan Sanchez on 2019-03-26.
//

#include "Aircrafts.h"

Aircrafts::Aircrafts()  //This function clears the vector of any garbage value.
{
    AircraftVector.clear();
}

void Aircrafts::addPlane()  //This function will allow the user to add a plane.
{

    string make, model, tailNumber;
    int numOfSeats, planeRange, MinCrew, numberOfCrew;
    cout << "-ADD PLANE SELECTED-";
    cout << endl;
    cout << "--> Tail Number?";
    getline(cin,tailNumber);
    cout << "--> Make? ";
    getline(cin, make);
    cout << "--> Model? ";
    getline(cin, model);
    cout << "--> Number of seats? ";       //This block of code will gather all of the user input.
    cin >> numOfSeats;
    cin.ignore();
    cout << "--> Plane range (miles)? ";
    cin >> planeRange;
    cin.ignore();
    cout << "--> Minimum crew number? ";
    cin >> MinCrew;
    cin.ignore();


    Aircraft temp(make, model, tailNumber, numOfSeats, planeRange, MinCrew);   //This uses the specialized constructor and sets all the values of the variables passed in, into the respective set classes, saving an "aircraft".
    AircraftVector.push_back(temp); //This inserts the speicalized constructor that was used before this to save an "Airplane" into the vector from the back. Saving all the data into the vector.
    cout << "ADDING PLANE...";
}
void Aircrafts::editPlane() //This Function works exactly the same as addPlane other than some minor differences.
{
    string make, model, tailNumber;
    int numOfSeats, planeRange, MinCrew;
    cout << "-EDIT PLANE SELECTED-";
    cout << endl;
    cout << "--> Tail Number?";
    getline(cin,tailNumber);
    if(findPlaneByID(tailNumber) == -1)     //This checks if the tail number that was entered was existent, in order to edit the plane there must be one created.
    {
        cout << "Tail Number not found.";
    }
    cout << "--> Make?";
    getline(cin, make);
    cout << "--> Model?";
    getline(cin, model);
    cout << "--> Number of seats?";
    cin >> numOfSeats;
    cin.ignore();
    cout << "--> Plane range (miles)?";
    cin >> planeRange;
    cin.ignore();
    cout << "--> Minimum crew number?";
    cin >> MinCrew;
    cin.ignore();

    Aircraft temp(make, model, tailNumber, numOfSeats, planeRange, MinCrew);
    AircraftVector.at(findPlaneByID(tailNumber)) = temp;    //Instead of adding the instance of the airplane to the back of the vector, it replaces the spot of wherever the "tailnumber" that the user entered was found.

}
void Aircrafts::deletePlane()   //This function will an airplane.
{
    string tailNumber;
    cout << "-DELETE PLANE SELECTED-";
    cout << endl;
    cout << "--> Tail Number?";
    getline(cin, tailNumber);
    if(findPlaneByID(tailNumber) == -1) //Making sure that the tail number exists.
    {
        cout << "Tail Number not found.";
    }
    AircraftVector.erase(AircraftVector.begin() + findPlaneByID(tailNumber));  //Erasing the instance of the airplane by using the vector erase function.
}
int Aircrafts::findPlaneByID(string tailNumber) //Finding a plane by ID, this is used frequently
{
    unsigned int i;

    for(i=0; i < AircraftVector.size(); i++)    //Iterating through the vector size
    {
        if(AircraftVector.at(i).getTailNumber() == tailNumber)  //Checking if vector at i with a tail number is equal to the user entered tail number.
        {
            return i; //If so, return the index where they are the same, thus finding a plane by the id.
        }
    }
    return -1;

}
void Aircrafts::printAllPlanes()    //Printing all of the planes created.
{
    unsigned int i;
    cout << "-PRINT ALL PLANES SELECTED-";
    cout << endl;
    for(i = 0; i < AircraftVector.size(); i++)  //Iterating through the vector size
    {
        cout << "Plane #" << i+1 << endl;
        cout << AircraftVector.at(i).getMake() << endl;
        cout << AircraftVector.at(i).getModel() << endl;
        cout << AircraftVector.at(i).getTailNumber() << endl;      //Printing out and getting all of the information at the specific index.
        cout << AircraftVector.at(i).getNumOfSeats() << endl;
        cout << AircraftVector.at(i).getRangeMiles() << endl;
        cout << AircraftVector.at(i).getMinNumOfCrew() << endl;
    }
}
void Aircrafts::printSinglePlane()  //Printing a single plane by ID
{
    string tailNumber = " ";
    cout << "-PRINT PLANE BY ID SELECTED-";
    cout << endl;
    cout << "Tail Number?";
    cin >> tailNumber;
    if(findPlaneByID(tailNumber) == -1) //Checking if the tail number exists
    {
        cout << "Tail Number not found.";
    } else {
        cout << AircraftVector.at(findPlaneByID(tailNumber)).getMake() << endl;
        cout << AircraftVector.at(findPlaneByID(tailNumber)).getModel() << endl;
        cout << AircraftVector.at(findPlaneByID(tailNumber)).getTailNumber() << endl;   //If it does exist then print and get all information at the particular plane ID using find plane by ID.
        cout << AircraftVector.at(findPlaneByID(tailNumber)).getNumOfSeats() << endl;
        cout << AircraftVector.at(findPlaneByID(tailNumber)).getRangeMiles() << endl;
        cout << AircraftVector.at(findPlaneByID(tailNumber)).getMinNumOfCrew() << endl;
    }
}
int Aircrafts::findNumOfSeats(int index)   //This function will get the number of seats in the plane based on the index of the vector.
{
  return AircraftVector.at(index).getNumOfSeats();

}
int Aircrafts::findMinOfCrew(int index)   //This will find the minimum of crew in the plane based on the index of the vector.
{
    return AircraftVector.at(index).getMinNumOfCrew();
}