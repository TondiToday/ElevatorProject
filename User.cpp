#include <cstdlib>
#include <iostream>
#include "User.h"
#include "Elevator.h"
#include "Utilities.h"

using namespace std;


// Generates destinations for users entering on a given floor
int User::generateUserRequests(int& current_floor, int& current_direction, const int& number_of_floors)
{
	if (current_direction == DOWN) // if elevator is going 'down'
	{
		// generates floor requests from below current floor to ground floor
		int userDestination = randomFloor(current_floor - 1, 0);
		return userDestination;
	}

	else if (current_direction == UP) // if elevator is going 'up'
	{
		// generates floor requests from above current floor to top floor
		int userDestination = randomFloor(number_of_floors , current_floor + 1);
		return userDestination;
	}
	else
	{
		cout << "Direction is neither 0 nor 1." << endl;
		throw exception();
	}
}




// Creates a vector of User objects to be passed to the elevator's list
	
 vector<User*> generateUsers(int current_floor, int& current_direction, const int& number_of_floors, int& user_number)
 {
	int numberOfRequests = 1 + rand() % 4; // 1 to 4 requests (User objects to be generated)
	vector<User*> newRequests;

	for (int i = 0; i < numberOfRequests; i++)
	{
		user_number++;
		User* newUser = new User(current_floor, current_direction, number_of_floors, user_number);
		newRequests.push_back(newUser);
	}
	return newRequests;
}


 