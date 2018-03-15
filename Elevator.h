#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Modified_q.h"


class Elevator 
{
protected :
	int level;
	bool up;
	bool stationary = true; // NEW initial to true
	int name;
	bool goodStatus = true; // NEW
	int distanceFromRequest; // NEW


public: 
	q_modified ele_up;
	q_modified ele_down;
	void set_name(int i);
	int get_name();
	void set_level(int x);
	int get_level();
	
	// constructor
	Elevator(int x, const int userBuildingFloors, const int userElevatorNumber);
	Elevator(int x);

	bool moving_up();
	void set_direction(bool x);
	bool is_stationary();
	void up_stops();
	void down_stops();
	bool get_goodStatus(); // NEW
	void set_goodStatus(bool status); // NEW
	int get_distanceFromRequest(); // NEW
	void set_distanceFromRequest(int floor_request_level); // NEW

};



#endif