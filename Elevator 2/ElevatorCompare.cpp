#include "Elevator.h"
#include "ElevatorCompare.h"


bool compareJobsUp(Elevator* elevator1, Elevator* elevator2)
{
	return elevator1->ele_up.getsize() < elevator2->ele_up.getsize();
}