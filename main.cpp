#include "Simulation.h"
#include "Utilities.h"
#include <vector>


using namespace std;


int main()
{	/*
	// OLD Easier Testing
	int userBuildingFloors;// for user inputted number of floors
	int userElevatorNumber; // for user inputted number of elevators
	int totalUsers = 0;
	int totalFloorRequests = 0;
	vector <Elevator*> elevators;
	vector<int> userWaitingTimes;
	const int SIM_TIME = 100;

	setDebug();
	cout << "Debug statements: " << boolalpha << DEBUG << endl << endl;


	cout << "Please enter the number of floors in the building: ";
	cin >> userBuildingFloors;
	const int FLOORS_NUMBER = userInputToConstant(userBuildingFloors);

	cout << "Please enter the number of elevators in the building: ";
	cin >> userElevatorNumber;
	const int ELEVATORS_NUMBER = userInputToConstant(userElevatorNumber);
	// OLD Easier Testing
	*/
	
	
	const int FLOORS_NUMBER = setFloorNumbers();
	const int ELEVATORS_NUMBER = setElevatorNumbers(FLOORS_NUMBER);
	const int SIM_TIME = setSimTime(FLOORS_NUMBER, ELEVATORS_NUMBER);
	
	setDebug();
	simulation(FLOORS_NUMBER, ELEVATORS_NUMBER, SIM_TIME);





	return 0;
}
