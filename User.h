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
		userID = user_number++;
	}

// Destructor
	~User() {
		cout << "User #" << userID << " destroyed." << endl;
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


	int get_waitingTime() {
		return userWaitingTime;
	}

	bool get_statusArrived() {
		return statusArrived;
	}

	// Setter Functions
	void set_statusArrived(bool arrived) {
		statusArrived = arrived;
	}

	
	int generateUserRequests(int& current_floor, int& current_direction, const int& number_of_floors);

	friend vector<User> generateUsers(int& current_floor, int& current_direction, const int& number_of_floors, int& user_number);

	// temp function
	friend void displayVector(vector<User>& myVector);

	
private :
	int userID;
	int userFloor;
	int userDestination;
	bool statusArrived = false;
	int userWaitingTime = -1; 
	double userStartTime;
};

#endif