#include "Simulation.h"
#include "Utilities.h"
#include <vector>


using namespace std;

int main()
{	
	setDebug();
	bool defaultValues = useDefault();

	if (defaultValues == YES)
	{
		const int FLOORS_NUMBER = 20;
		const int ELEVATORS_NUMBER = 8;
		const int SIM_TIME = 720;
		simulation(FLOORS_NUMBER, ELEVATORS_NUMBER, SIM_TIME);
	}
	else
	{
		const int FLOORS_NUMBER = setFloorNumbers();
		const int ELEVATORS_NUMBER = setElevatorNumbers(FLOORS_NUMBER);
		const int SIM_TIME = setSimTime(FLOORS_NUMBER, ELEVATORS_NUMBER);
		simulation(FLOORS_NUMBER, ELEVATORS_NUMBER, SIM_TIME);
	}

	return 0;
}
