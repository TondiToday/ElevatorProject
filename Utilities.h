#ifndef UTILITIES_H
#define UTILITIES_H

#include "Elevator.h"
#include "Modified_q.h"
#include "User.h"



const int userInputToConstant(int user_input);

// Enums
enum Tasks { DIRECTION = 0, FLOOR_REQUEST = 1 };
enum Direction { DOWN = 0, UP = 1 };

void printElevatorStatus(Elevator* elevator_obj, int direction);



#endif