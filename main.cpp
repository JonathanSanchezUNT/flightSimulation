#include <iostream>
#include "Flights.h"
#include "crewMembers.h"
#include "Aircrafts.h"
#include <stdio.h>
using namespace std;
/*
 *  Euid:js1612 (Jonathansanchez5@my.unt.edu)
 *  Date: April 20, 2019
 *  Description: This program will have a menu that allows the user to choose between 22 different choices in the menu that have to do with a plane,
 *  adding crew, adding planes, creating flights, etc. There is error checking to make sure the user is entering correct and valid values.
 *  Along with choices of being able to print out most of the things they have created.
 */

int main()
{
   Flights flight;
   Aircrafts aircraft;
   crewMembers crew;

   int choice = -1;

    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|                        Homework 4                           |" << endl;
    cout << "|            CSCE 1040.002 - Computer Science 2               |" << endl;
    cout << "|  Jonathan Sanchez    js1612    Jonathansanchez5@my.unt.edu  |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << endl;


   while (choice != 0) {
      cout << endl;
      cout << "---------------------------------------------------------------------" << endl;
      printf("What do you want to do?\n\n");
      printf(" 0 - QUIT\n\n"
             "~ADD FUNCTIONS~\n"
             " 1  - Add a new plane\n "
             "2  - Add a new crew member\n"
             " 3  - Add a new flight\n\n"
             "~EDIT FUNCTIONS~\n"
             " 4  - Edit plane\n"
             " 5  - Edit crew member\n"
             " 6  - Edit flight\n\n"
             "~DELETE FUNCTIONS~\n"
             " 7  - Delete plane\n"
             " 8  - Delete crew member\n "
             "9  - Delete flight\n\n"
             "~PRINTING FUNCTIONS~\n"
             " 10 - Print all planes\n"
             " 11 - Print plane by ID\n"
             " 12 - Print crew members\n"
             " 13 - Print crew member by ID\n"
             " 14 - Print flights \n"
             " 15 - Print flights by ID\n\n"
             "~MORE DELETE FUNCTIONS~\n"
             " 16 - Delete cancelled flights \n"
             " 17 - Delete completed flights \n\n"
             "~MORE PRINT FUNCTIONS~\n"
             " 18 - Print plane schedule\n"
             " 19 - Print crew schedule\n"
             " 20 - Print flights by status\n\n"
             "~UPDATE FLIGHT~\n"
             " 21 - Update flight status\n\n");
      cout << "Enter your selection: ";
      scanf("%d%*c", &choice);
      cout << endl;

      switch (choice) {

         case 1:
            aircraft.addPlane();
            break;

         case 2:
            crew.addMember();
            break;

         case 3:
           flight.addFlight(aircraft, crew);
           break;

         case 4:
            aircraft.editPlane();
            break;

         case 5:
            crew.editMember();
            break;

         case 6:
            flight.editFlight(aircraft, crew);
            break;

         case 7:
            aircraft.deletePlane();
            break;

          case 8:
             crew.deleteMember();
             break;

         case 9:
            flight.deleteFlight();
            break;

         case 10:
            aircraft.printAllPlanes();
            break;

          case 11:
             aircraft.printSinglePlane();

          case 12:
             crew.printMembers();
             break;

          case 13:
             crew.printMemberByID();
             break;

          case 14:
             flight.printFlights();
             break;

         case 15:
            flight.printFlightByID();
            break;

          case 16:
              flight.deleteCancelledFlights();
              break;

          case 17:
              flight.deleteCompletedFlights();
              break;

          case 18:
              flight.printPlaneSchedule();
              break;

          case 19:
              flight.printCrewSchedule();
              break;

          case 20:
              flight.printFlightsByStatus();
              break;

          case 21:
              flight.updateFlightStatus();
              break;

      }

   }

}
