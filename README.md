# flightSimulation
A console-based flight tracker for scheduling pilots, crew members, and flights. Implemented in C++ for course CSCE 1040 at the University of North Texas.

AUTHOR: Jonathan Sanchez

EMAIL: Jonathan3001@mlive.com

COURSE: CSCE 1040

VERSION: 1.0.0

## Function Psuedo Code

### Plane/Aircrafts

#### Add Plane
Prompt user for the make, model, tail number, number of seats, range of plane, and the minimum of crew.
Create Plane Object.
Populate Object.
Add object to collection.

#### Edit Plane
Find plane by ID . (index in vector)
Prompt user for the make, model, tail number, number of seats, range of plane, and the minimum of crew.
Create Plane Object.
Populate Object.
Set the collection at Find plane by ID index to object.

#### Delete Plane
Find plane by ID. (the index in vector)
Erase that specific member of the list.

#### Find Plane By ID
This function will have a parameter of type int ID.
Search through all planes in plane list.
The search will check if ID is equal to the Plane list using the get tail number function.
If the ID is found then it will return the index of where the plane is inside of the Plane list.
Or else it will return a -1 to show that ID was not found within the plane list.

#### Print all Planes
Search through plane list and print out every plane inside of the list.

#### Print details for single plane
Prompt the user for the plane tail number.
If the Find the plane by ID (tail number) returns a valid statement
Then print out all of the information for that plane.

#### Find number of seats 
This function will pass in an index, then using the aircraft function getNumOfSeats will return the value at that index within the vector.

#### Find minimum of crew
This function will pass in an index, then using the aircraft function getMinNumOfCrew will return the value at that index within the vector.

### Flights

### Add Flight
A reference to plane/aircrafts will be passed into this refection
  Prompt the user for the plane ID (tail number)
    Check if plane ID is valid with the find plane by ID function.
   Error if does not exist.
   Check if the plane ID is free to fly (status).
   
Prompt for Start date (format: mmddyyyy)
Prompt Start time (format: 24 hour time “hhmm”)
Prompt End date 
Prompt End time
Check if the plane ID is free to fly (status) based on this specific time.
Calculate the duration of the flight.

Prompt Number of Pilots (flights over 8 hours require 2 pilots and 2 copilots)
If the flight is 8 hours or more check if the user entered 2.
Error if they did not.

Prompt Number of cabin crew (flights over 8 hours double the minimum)
 If the user did not enter double the crew minimum or more for a flight that is 8 hours or more, give an error message.
Re-prompt for the number of cabin crew.

Prompt for Starting Airport Code
Prompt for Ending AirPort Code 
Prompt for Number of passengers
If the input is greater than the aircrafts “num of seats” then display an error.
Re-prompt for number of passengers.

Prompt for pilot ID
Check if ID exists 
Repropmt if not

Prompt for cabin crew ID
Check if ID exists
Reprompt if not

Prompt for flight status(0-Complete, 1-Active, 2-Cancelled)
Automatically assign flight ID in incrementing fashion.
Create Flight Object.
Populate Object.
Add object to collection.

### Edit Flight
Find flight by ID . (index in vector)
Prompt user for the plane ID (tail number), Number of Pilots (flights over 8 hours require 2 pilots and 2 copilots), Number of cabin crew (flights over 8 hours double the minimum), Start date, Start time, End date, End time, Starting Airport Code, Ending AirPort Code, and Number of passengers.
Create Plane Object.
Populate Object.
Set the collection at Find plane by ID index to object.

### Delete Flight
Find flight by ID. (the index in vector)
Delete the flight

### Print Plane Schedule
Prompt for tail number to view the schedule 
Check if tail number exists, error if not
Search through all flights with matching tail number then print the schedule
If none match then the schedule is empty 

### Print Crew Schedule 
Prompt for crew ID and search through flights for matching crew ID, and print details.
If crew ID does not match any flights, print that no flights contain that crew id. 

### Print flight by status
Based on wether a flight contains [Active], [Complete], [Cancelled], print out all of the values saved in the vector by using the accessor functions.
		
### Delete Cancelled
If the vector contains [Cancelled = 2] use the erase function from the beginning of the vector until the instance where it was equal to 2.

### Delete Completed
If the vector contains [Completed = 0] use the erase function from the beginning of the vector until the instance where it was equal to 0.


### Update status
You have to create a struct tm variable to store the end time. If the current time of the computer is greater then the vector using the getEndTime accessor and if the vector using the getStatus is equal to 1 then set the vector status to the current time.

### Find Flight By ID 
This function will have a parameter of type int ID.
Search though all flights in flight list
The search will check if ID is equal to the flight list using the get flight number function.
If the ID is found then it will return the index of where the flight is inside of the flight list.
Or else it will return a -1 to show that ID was not found within the flight list.

### Print all Flights 
Search through flight list and print out every flight inside of the list.

### Print details for single flight.
Prompt the user for the flight ID number.
If the Find flight by ID returns a valid statement, then print out all of the information for that plane.

### Check Active Flight
If the vector using the accessor get status is equal to 1 then return true, else return false.

#### Crew Members

### Add Crew Member
Prompt user for name, ID number, and type of crew member (pilot, copilot, cabin).
Create Crew Member Object.
Populate Object.
Add object to collection.

### Edit Crew Member
Find Crew Member by ID . 
Prompt user for name, ID number, and type of crew member (pilot, copilot, cabin).
Create Crew Member Object.
Populate Object.
Set the collection at Find by Member index to object.

### Delete Crew Member
Find Crew Member by ID. 
Delete the crew member.

### Find Crew Member by ID
This function will have a parameter of type int ID.
Search through all crew member in crew member list.
The search will check if ID is equal to the crew member list using the get crew member ID function.
If the ID is found then it will return the index of where the crew member is inside of the crew member list.
Or else it will return a -1 to show that ID was not found within the crew member list.

### Print all Crew Members
Search through crew member list and print out every crew member inside of the list.

### Print details for single Crew Members 
Prompt the user for the crew member ID number.
If the Find crew member by ID returns a valid statement, then print out all of the information for that crew member.

### Delete member
Find crew member by ID. (the index in vector)
Delete the member

#### Crew Member

### Printinfo
This function is a virtual function, all of the subclasses will call it when you create the sub class printing functions. Allowing for the base class printinfo() to be printed along with the info of the sub classes.

### -SUBCLASSES OF CREW MEMBER-

### Pilot

#### Printinfo 
This function will call the base class virtual print-info function in order to print all of those members along with the specific things that will printed for Pilots.


### CoPilot 

#### Printinfo
This function will call the base class virtual print-info function in order to print all of those members along with the specific things that will printed for CoPilots.


### Cabin Crew

#### Printinfo
This function will call the base class virtual print-info function in order to print all of those members along with the specific things that will printed for cabin crew.
