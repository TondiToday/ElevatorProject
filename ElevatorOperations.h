#ifndef ELEVATOR_OPERATIONS_H
#define ELEVATOR_OPERATIONS_H

#include "Elevator.h"

void elevator_op(vector<Elevator*> &v, const int& number_of_floors);

// old functions
//void customer_input(q_modified & up, q_modified & d);
//void dispacher(q_modified & dup, q_modified & ddown, int n, vector<Elevator*> &v, int n_elevators);
void customer_input2(q_modified & up, q_modified & down, Elevator &e);
//void customer_input3(q_modified & up, q_modified & down, Elevator e);


#endif