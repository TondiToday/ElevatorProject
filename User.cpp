#include <cstdlib>
#include <iostream>
#include <ctime>
#include "User.h"

using namespace std;


// Generates destinations for users entering on a given floor
int User::generateUserRequests(int& current_floor, int& current_direction, const int& number_of_floors) 
{
	int userDestination;
		
	if (current_direction == 0) // if elevator is going 'down'
	{
		// generates floor requests from below current floor to bottom floor
		userDestination = (rand() % (current_floor - 1) + 1);
	}

	else if (current_direction == 1) // if elevator is going 'up'
	{
		// generates floor requests from above current floor to top floor
		userDestination = (rand() % (number_of_floors - current_floor + 1) + current_floor);
	}
		
	return userDestination;
}




// Creates a vector of User objects to be passed to the elevator's list
 vector<User> generateUsers(int& current_floor, int& current_direction, const int& number_of_floors, int& user_number)
 {
	srand(unsigned(time(0))); // set random seed
	int numberOfRequests = 1 + rand() % 5; // 1 to 5 requests
	vector<User> newRequests;

	for (int i = 0; i < numberOfRequests; i++)
	{
		User* newUser = new User(current_floor, current_direction, number_of_floors, user_number);
		newRequests.push_back(*newUser);
	}
	return newRequests;
}



 void displayVector(vector<User>& myVector)
 {
	 for (unsigned int i = 0; i < myVector.size(); i++)
	 {
		 cout << "User ID: " << myVector[i].get_UserID()
			 << ", Starting Floor: " << myVector[i].get_userFloor()
			 << ", Destination Floor: " << myVector[i].get_userDestination()
			 << ", Waiting Time: " << myVector[i].get_waitingTime()
			 << endl;
	 }
 }

