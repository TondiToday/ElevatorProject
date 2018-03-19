#ifndef ELEVATOR_OPERATIONS_H
#define ELEVATOR_OPERATIONS_H

#include "Elevator.h"

void elevator_op(vector<Elevator*> &v, const int& number_of_floors, int& total_users, int& current_time, vector<int>& waiting_times);
void calculateDistance(vector<Elevator*>& elevators, int task);


#endif