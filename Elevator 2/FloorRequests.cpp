#include "FloorRequests.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

int* floorRequest(const int& number_of_floors)
{	
	srand(unsigned(time(0))); // set random seed
	int currentFloor = 1 + rand() % number_of_floors;


	int floorDirection; // 0 = down, 1 = up
	int floorNumber;
	int newFloorRequest[2];


	if (currentFloor == 1) { // if on ground floor, have to go up
		floorDirection = 1;
	}

	else if (currentFloor == number_of_floors) { // if on top floor, to go down
		floorDirection = 0;
	}

	else {
		srand(unsigned(time(0)));
		floorDirection = rand() % 2;
	}

	if (floorDirection == 0) {
		// generates floor requests from below current floor to bottom floor
		floorNumber = (rand() % (currentFloor - 1) + 1);
	}

	else if (floorDirection == 1) {
	// generates floor requests from above current floor to top floor
		floorNumber = (rand() % (number_of_floors - currentFloor + 1) + currentFloor);
	}

	// Add to array
	newFloorRequest[0] = floorDirection;
	newFloorRequest[1] = floorNumber;


	return newFloorRequest;



	


}
