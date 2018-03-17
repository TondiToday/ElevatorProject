#include <cstdlib>
#include <iostream>
#include "User.h"
#include "Elevator.h"
#include "Utilities.h"

using namespace std;


// Generates destinations for users entering on a given floor

// Generates destinations for users entering on a given floor
int User::generateUserRequests(int& current_floor, int& current_direction, const int& number_of_floors)
{
	int userDestination;

	if (current_direction == 0) // if elevator is going 'down'
	{
		// generates floor requests from below current floor to bottom floor

		// fixes divide by zero errors if current level is 1
		if ((current_floor - 1) == 0)
		{
			int zeroFix = 1;
			userDestination = (rand() % (zeroFix)+1);
		}
		else
		{
			userDestination = (rand() % (current_floor - 1) + 1);
		}
	}

	else if (current_direction == 1) // if elevator is going 'up'
	{
		// generates floor requests from above current floor to top floor
		userDestination = (rand() % (number_of_floors - current_floor + 1) + current_floor);
	}

	return userDestination;
}

	// TEMP Overloaded
	int User::generateUserRequests(int& current_floor, const int& number_of_floors)
	{
		int userDestination;
		
		if ((current_floor - 1) == 0)
		{
			int zeroFix = 1;
			return userDestination = (rand() % (zeroFix)+1);
		}
		else
		{
			return userDestination = (rand() % (current_floor - 1) + 1);
		}
	}


// Creates a vector of User objects to be passed to the elevator's list
	
 vector<User*> generateUsers(int current_floor, int& current_direction, const int& number_of_floors, int& user_number)
 {
	int numberOfRequests = 1 + rand() % 10; // 1 to 10 requests
	vector<User*> newRequests;

	for (int i = 0; i < numberOfRequests; i++)
	{
		user_number++;
		User* newUser = new User(current_floor, /*current_direction,*/ number_of_floors, user_number);
		newRequests.push_back(newUser);
	}
	return newRequests;
}


 // TEMP Overloaded
 vector<User*> generateUsers(int current_floor, const int& number_of_floors, int& user_number)
 {
	 int numberOfRequests = 1 + rand() % 10; // 1 to 10 requests
	 vector<User*> newRequests;

	 for (int i = 0; i < numberOfRequests; i++)
	 {
		 user_number++;
		 User* newUser = new User(current_floor, number_of_floors, user_number);
		 newRequests.push_back(newUser);
	 }
	 return newRequests;
 }