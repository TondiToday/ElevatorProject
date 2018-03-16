#ifndef USER_H
#define USER_H

#include <vector>

using namespace std;


class User {

public:
// Constructor
	User(int& current_floor, int& current_direction, const int& number_of_floors, int& user_number) {
		userFloor = current_floor;
		userDestination = generateUserRequests(current_floor, current_direction, number_of_floors);
		userID = user_number;
	}

	// Getter Functions
	int get_UserID() {
		return userID;
	}

	int get_userFloor() {
		return userFloor;
	}

	int get_userDestination() {
		return userDestination;
	}

	

	int generateUserRequests(int& current_floor, int& current_direction, const int& number_of_floors);



	
private :
	int userID;
	int userFloor;
	int userDestination;
};

	vector<User*> generateUsers(int current_floor, int& current_direction, const int& number_of_floors, int& user_number);



#endif