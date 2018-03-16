#include "Elevator.h"
#include "Utilities.h"
#include "FloorRequests.h"
#include "Dispatcher.h"
#include "ElevatorOperations.h"
#include <vector>
#include <ctime>


int main()
{
	srand(unsigned(time(0))); // set random seed, need to leave in main

	int userBuildingFloors;// for user inputted number of floors
	int userElevatorNumber; // for user inputted number of elevators
	int totalUsers = 0;
	int totalFloorRequests = 0;
	vector <Elevator*> elevators;

	setDebug();
	cout << "Debug statements: " << boolalpha << DEBUG << endl << endl;

	
	cout << "Please enter the number of floors in the building: ";
	cin >> userBuildingFloors;
	const int FLOORS_NUMBER = userInputToConstant(userBuildingFloors);

	cout << "Please enter the number of elevators in the building: ";
	cin >> userElevatorNumber;
	const int ELEVATORS_NUMBER = userInputToConstant(userElevatorNumber);


	for (int i = 0; i < userElevatorNumber; i++)
	{
		Elevator* createElevator = new Elevator(i, FLOORS_NUMBER, ELEVATORS_NUMBER);
		elevators.push_back(createElevator);
	}
	
	//******* TEMP ELEVATOR SETTINGS FOR MANUAL TESTING *******//
	/*
	// Elevator 0
	elevators[0]->set_level(1);
	elevators[0]->set_direction(true); // up
	//elevators[0]->ele_up.push_up(2);
	//elevators[0]->ele_up.push_up(5);
	//elevators[0]->ele_up.push_up(10);

	// Elevator 1
	elevators[1]->set_level(10);
	elevators[1]->set_direction(false); // down
	elevators[1]->ele_down.push_down(7);
	elevators[1]->ele_down.push_down(2);

	// Elevator 2
	elevators[2]->set_level(4);
	elevators[2]->set_direction(true); // up

	// Elevator 3
	elevators[3]->set_level(3);
	elevators[3]->set_direction(false); // down

	// Elevator 4
	elevators[4]->set_level(15);
	elevators[4]->set_direction(false); // down
	elevators[4]->ele_down.push_down(7);
	elevators[4]->ele_down.push_down(8);
	elevators[4]->ele_down.push_down(10);
	elevators[4]->ele_down.push_down(11);
	elevators[4]->ele_down.push_down(12);
	*/
	//**************************************//

	for (int start = 0; start < 100; start++)
	{
		cout << endl << "ITERATIONS: " << start << endl;

		// Get new floor
		int* newTaskPtr = floorRequest(FLOORS_NUMBER);
		int newTask[2]; // array to contain direction and floor number

		newTask[DIRECTION] = *newTaskPtr;
		newTask[FLOOR_REQUEST] = *(newTaskPtr + 1);

		// If no request was made
		if ((newTask[DIRECTION] == -1) || (newTask[FLOOR_REQUEST] == -1))
		{
			if (DEBUG == YES)
			{
				cout << "No floor request was made." << endl;
			}
		}

		else
		{
			if (DEBUG == YES)
			{
				cout << "Requested Direction: " << newTask[DIRECTION] << endl;
				cout << "Requested Floor Number: " << newTask[FLOOR_REQUEST] << endl;
			}
			
			calculateDistance(elevators, newTask[FLOOR_REQUEST]);
			dispatch(elevators, newTask[DIRECTION], newTask[FLOOR_REQUEST]);
			totalFloorRequests++;
		}
		elevator_op(elevators, FLOORS_NUMBER, totalUsers);



	}
	// Delete elevator vector (dynamic memory)
	deleteVector(elevators);
	
	cout << "Total users: " << totalUsers << endl;


	//system("pause");
	return 0;
}
