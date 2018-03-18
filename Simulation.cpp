#include "Elevator.h"
#include "Utilities.h"
#include "FloorRequests.h"
#include "Dispatcher.h"
#include "ElevatorOperations.h"
#include <vector>
#include <ctime>


void simulation(const int& FLOORS_NUMBER, const int& ELEVATORS_NUMBER, const int& SIM_TIME)
{

	srand(unsigned(time(0))); // set random seed, need to leave in main

	int totalUsers = 0;
	int totalFloorRequests = 0;
	vector <Elevator*> elevators;
	vector<int> userWaitingTimes;

	
	
	for (int i = 0; i < ELEVATORS_NUMBER; i++)
	{
		Elevator* createElevator = new Elevator(i, FLOORS_NUMBER, ELEVATORS_NUMBER);
		elevators.push_back(createElevator);
	}
	

	for (int currentTime = 0; currentTime < SIM_TIME; currentTime++)
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
		elevator_op(elevators, FLOORS_NUMBER, totalUsers, currentTime, userWaitingTimes);

		system("pause");
	}
	// Delete elevator vector (dynamic memory)
	deleteVector(elevators);
	
	//cout << "Total users: " << totalUsers << endl;
	//cout << "Average waiting time iterations: " << averageWaitingTime(userWaitingTimes, totalUsers) << endl;

	int stats_array[6] = { FLOORS_NUMBER, ELEVATORS_NUMBER, SIM_TIME, 
		totalUsers, averageWaitingTime(userWaitingTimes, totalUsers) };
	
	displayStatistics(FLOORS_NUMBER, ELEVATORS_NUMBER, SIM_TIME, totalUsers, userWaitingTimes);


	//system("pause");
}
