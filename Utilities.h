#ifndef UTILITIES_H
#define UTILITIES_H

#include "Elevator.h"
#include "Modified_q.h"
#include "User.h"

extern bool DEBUG; // global debug variable
void setDebug(); // set whether debug statements are displayed

const int userInputToConstant(int user_input);
void printElevatorStatus(Elevator*& elevator_obj, int direction);
void printUserStatus(vector<User*>& users_vector);

void deleteVector(vector<Elevator*>);
void deleteVector(vector<User*>);


// Enums
enum Tasks { DIRECTION_REQUEST = 0, FLOOR_REQUEST = 1 };
enum Direction { DOWN = 0, UP = 1 };
enum Answer { NO = 0, YES = 1 };
enum Requests { FLOOR = 0, DIRECTION = 1, TIME = 2};

int randomFloor(int max, int min);
double averageWaitingTime(vector<int>& waiting_times, int& total_users);

const int setFloorNumbers();
const int setElevatorNumbers(const int number_of_floors);
const int setSimTime(const int FLOORS_NUMBER, const int ELEVATORS_NUMBER);


void displayStatistics(const int& FLOORS_NUMBER, const int& ELEVATORS_NUMBER, const int& SIM_TIME,
	int& total_users, vector<int>& user_waiting_times);


#endif