#ifndef UTILITIES_H
#define UTILITIES_H

#include "Elevator.h"
#include "Modified_q.h"
#include "User.h"

extern bool DEBUG; // global debug variable
void setDebug(); // set whether debug statements are displayed

const int userInputToConstant(int user_input);
void printElevatorStatus(Elevator* elevator_obj, int direction);
void printUserStatus(vector<User*>& users_vector);

void deleteVector(vector<Elevator*>);
void deleteVector(vector<User*>);


// Enums
enum Tasks { DIRECTION = 0, FLOOR_REQUEST = 1 };
enum Direction { DOWN = 0, UP = 1 };
enum Answer { NO = 0, YES = 1 };





#endif