#include "Simulation.h"
#include "Utilities.h"
#include <vector>


using namespace std;

/*This is the main simulation for the Elevator

IF you want to turn DEBUG mode off, go the Uitilities.cpp and change:
DEBUG = NO;
in setDebug()
*/
int main()
{	
	
	
	setDebug();
	const int FLOORS_NUMBER = setFloorNumbers();
	const int ELEVATORS_NUMBER = setElevatorNumbers(FLOORS_NUMBER);
	const int SIM_TIME = setSimTime(FLOORS_NUMBER, ELEVATORS_NUMBER);
	

	simulation(FLOORS_NUMBER, ELEVATORS_NUMBER, SIM_TIME);



	return 0;
}
