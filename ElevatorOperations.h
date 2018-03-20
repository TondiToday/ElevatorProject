#ifndef ELEVATOR_OPERATIONS_H
#define ELEVATOR_OPERATIONS_H

#include "Elevator.h"

// Manages elevator movement and user boarding logic
void elevator_op(vector<Elevator*> &v, const int& number_of_floors, int& total_users, int& current_time, vector<int>& waiting_times);

// Calcutate the distance of each elevator from a new floor request
void calculateDistance(vector<Elevator*>& elevators, int task);


#endif