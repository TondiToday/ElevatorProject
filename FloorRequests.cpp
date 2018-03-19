#include "FloorRequests.h"
#include "Utilities.h"
#include <vector>

/*
floorRequest generates a random floor request and a direction 
			 and returns a pointer to a 2-index array
*/

int* floorRequest(const int& number_of_floors)
{	
	int floorDirection; // 0 = DOWN, 1 = UP
	int floorNumber;
	int newFloorRequest[2];
	int isRequest = rand() % 2;
	//int isRequest = true; // force a request every iteration

	// No floor request was made
	if (isRequest == NO)
	{
		floorDirection = -1;
		floorNumber = -1;
	}

	// A floor request was made
	else if (isRequest == YES)
	{
		// Random floor generated
		int currentFloor = randomFloor(number_of_floors, 0); 

		if (currentFloor == 0) // if on ground floor, have to go up
		{
			floorDirection = UP;
		}

		else if (currentFloor == number_of_floors) // if on top floor, have to go down
		{
			floorDirection = DOWN;
		}

		else
		{
			// generates floor direction, down or up (0 or 1)
			floorDirection = randomFloor(1, 0);
		}

		if (floorDirection == DOWN) 
		{
			// generates floor requests from below current floor to bottom floor
			floorNumber = randomFloor(currentFloor - 1, 1);
		}


		else if (floorDirection == UP) 
		{
			// generates floor requests from above current floor to top floor
			floorNumber = randomFloor(number_of_floors , currentFloor + 1);
		}
	}

	// check for correct data
	if (floorDirection == 0 && floorNumber == 0)
	{
		floorDirection = 1;
	}


	// Add to array
	newFloorRequest[DIRECTION_REQUEST] = floorDirection;
	newFloorRequest[FLOOR_REQUEST] = floorNumber;
	return newFloorRequest;
}
