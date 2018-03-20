#ifndef UTILITIES_H
#define UTILITIES_H

#include "Elevator.h"
#include "Modified_q.h"
#include "User.h"

extern bool DEBUG; // global debug variable
void setDebug(); // set whether debug statements are displayed

// User console input functions
bool useDefault(); // default values for testing function
const int setFloorNumbers();
const int setElevatorNumbers(const int number_of_floors);
const int setSimTime(const int FLOORS_NUMBER, const int ELEVATORS_NUMBER);

const int userInputToConstant(int user_input); // converts user input to constant

void printElevatorStatus(Elevator*& elevator_obj, int direction); // prints debug info for Elevator status
void printUserStatus(vector<User*>& users_vector); // prints debug info for User status

// Deletes dynamic memory in a vector
void deleteVector(vector<Elevator*>); 
void deleteVector(vector<User*>);

// Enums
enum Tasks { DIRECTION_REQUEST = 0, FLOOR_REQUEST = 1 };
enum Direction { DOWN = 0, UP = 1 };
enum Answer { NO = 0, YES = 1 };
enum Requests { FLOOR = 0, DIRECTION = 1, TIME = 2};

// Generates a random floor 
int randomFloor(int max, int min);

// Calculates user waiting time from the floor request creation to the elevator's arrival at the floor request
float averageWaitingTime(vector<int>& waiting_times, int& total_users);

// Displays stats at the end of the simulation
void displayStatistics(const int& FLOORS_NUMBER, const int& ELEVATORS_NUMBER, const int& SIM_TIME,
	int& total_users, vector<int>& user_waiting_times);


#endif