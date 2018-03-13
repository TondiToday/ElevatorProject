#ifndef SORT_ELEVATORS_H
#define SORT_ELEVATORS_H

#include "Elevator.h"
#include "Modified_q.h"

//Elevator findBestElevator(vector<Elevator>& elevators, int& direction, int& request_at_floor);

bool compareJobsUp(Elevator* elevator1, Elevator* elevator2);

bool compareJobDown(Elevator* elevator1, Elevator* elevator2);





#endif