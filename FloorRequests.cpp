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
	//int isRequest = true;

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
		int currentFloor = 1 + rand() % number_of_floors;

		if (currentFloor == 1) // if on ground floor, have to go up
		{
			floorDirection = 1;
		}

		else if (currentFloor == number_of_floors) // if on top floor, to go down
		{
			floorDirection = 0;
		}

		else
		{
			// generates floor direction, down or up (0 or 1)
			//floorDirection = rand() % 2;
			floorDirection = randomFloor(1, 0);
		}

		if (floorDirection == DOWN) 
		{
			// generates floor requests from below current floor to bottom floor

			floorNumber = randomFloor(currentFloor - 1, 0);
		}


		else if (floorDirection == UP) 
		{
			// generates floor requests from above current floor to top floor
			floorNumber = randomFloor(number_of_floors - currentFloor, currentFloor + 1);
		}
	}

	// Add to array
	newFloorRequest[DIRECTION_REQUEST] = floorDirection;
	newFloorRequest[FLOOR_REQUEST] = floorNumber;
	//newFloorRequest[DIRECTION] = 0;

	return newFloorRequest;
}
