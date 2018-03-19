#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "Elevator.h"


void dispatch(vector<Elevator*>& elevators, int& direction, int& floor_request, int& current_time);
Elevator* findBestElevator(vector<Elevator*> elevators, int& direction, int& floor_request);
Elevator* ElevatorWorstCase(vector<Elevator*>& elevators, int& direction, int& floor_request);

// Sorting
int findMinJobs(vector<Elevator*>& elevators, int& direction);
int findMinDistance(vector<Elevator*>& elevators);

// Comparison Functions for vector sort
bool compareJobsUp(Elevator* elevator1, Elevator* elevator2);
bool compareJobsDown(Elevator* elevator1, Elevator* elevator2);
bool compareDistance(Elevator* elevator1, Elevator* elevator2);
// remove bad elevators 
int dismissBadElevators(vector<Elevator*>& m_elevators);

void resetElevatorStatus(vector<Elevator*>& elevators);

#endif