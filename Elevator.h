#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Modified_q.h"
#include <vector>

class Elevator 
{
private :
	int level;
	bool up;
	bool stationary = true;
	int name;
	bool goodStatus = true; 
	int distanceFromRequest; 
	bool Boarding = false;
	bool Leaving = false;


public: 

	// Constructor
	Elevator(int x, const int userBuildingFloors, const int userElevatorNumber);
	Elevator(int x);

	q_modified ele_up;   // both floor requests and user requests
	q_modified ele_down; // both floor requests and user requests

	void set_name(int i);
	int get_name();
	void set_level(int x);
	int get_level();
	bool moving_up();
	bool isBoarding();
	bool isLeaving();
	void setBoarding(bool x);
	void setLeaving(bool x);
	void set_direction(bool x);
	bool is_stationary();
	void up_stops();
	void down_stops();
	bool get_goodStatus();
	void set_goodStatus(bool status); 
	int get_distanceFromRequest(); 
	void set_distanceFromRequest(int floor_request_level); 
	vector<int> last_floor_down = { -1, -1, -1 };
	vector<int> last_floor_up = { -1, -1, -1 };
};



#endif