flightProgram: main.o crewMember.o crewMembers.o Aircraft.o Aircrafts.o Flight.o Flights.o cabinCrew.o Pilot.o CoPilot.o 
	g++ -std=c++11 main.cpp crewMember.cpp crewMembers.cpp Aircraft.cpp Aircrafts.cpp Flight.cpp Flights.cpp cabinCrew.cpp Pilot.cpp CoPilot.cpp -o flightProgram

main.o: main.cpp
	g++ -c -std=c++11 main.cpp
crewMember.o: crewMember.cpp
	g++ -c -std=c++11 crewMember.cpp
crewMembers.o: crewMembers.cpp
	g++ -c -std=c++11 crewMembers.cpp
Aircraft.o: Aircraft.cpp
	g++ -c -std=c++11 Aircraft.cpp
Aircrafts.o: Aircrafts.cpp
	g++ -c -std=c++11 Aircrafts.cpp
Flight.o: Flight.cpp
	g++ -c -std=c++11 Flight.cpp
Flights.o: Flights.cpp
	g++ -c -std=c++11 Flights.cpp
cabinCrew.o: cabinCrew.cpp
	g++ -c -std=c++11 cabinCrew.cpp
Pilot.o: Pilot.cpp
	g++ -c -std=c++11 Pilot.cpp
CoPilot.o: CoPilot.cpp
	g++ -c -std=c++11 CoPilot.cpp
run:
	./flightProgram
clean:
	rm *.o flightProgram
