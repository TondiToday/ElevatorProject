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
	
	

	for (int currentTime = 0; currentTime < 100; currentTime++)
	{
		cout << endl << "ITERATIONS: " << currentTime << endl;

		// Get new floor
		int* newTaskPtr = floorRequest(FLOORS_NUMBER);
		int newTask[2]; // array to contain direction and floor number

		newTask[DIRECTION_REQUEST] = *newTaskPtr;
		newTask[FLOOR_REQUEST] = *(newTaskPtr + 1);

		// If no request was made
		if ((newTask[DIRECTION_REQUEST] == -1) || (newTask[FLOOR_REQUEST] == -1))
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
				cout << "Requested Direction: " << newTask[DIRECTION_REQUEST] << endl;
				cout << "Requested Floor Number: " << newTask[FLOOR_REQUEST] << endl;
			}
			
			calculateDistance(elevators, newTask[FLOOR_REQUEST]);
			dispatch(elevators, newTask[DIRECTION_REQUEST], newTask[FLOOR_REQUEST], currentTime);
			totalFloorRequests++;
		}
		elevator_op(elevators, FLOORS_NUMBER, totalUsers, currentTime);


	}
	// Delete elevator vector (dynamic memory)
	deleteVector(elevators);
	
	cout << "Total users: " << totalUsers << endl;


	//system("pause");
	return 0;
}
