#include "Simulation.h"
#include "Utilities.h"
#include <vector>


using namespace std;


int main()
{	
	
	setDebug();
	const int FLOORS_NUMBER = setFloorNumbers();
	const int ELEVATORS_NUMBER = setElevatorNumbers(FLOORS_NUMBER);
	const int SIM_TIME = setSimTime(FLOORS_NUMBER, ELEVATORS_NUMBER);
	simulation(FLOORS_NUMBER, ELEVATORS_NUMBER, SIM_TIME);





	return 0;
}
