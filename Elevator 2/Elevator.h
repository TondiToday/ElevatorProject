#include "Modified_q.h"

class Elevator 
{
protected :
	int level;
	bool up;
	bool stationary;
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
	Elevator(int x);
	bool moving_up();
	void set_direction(bool x);
	bool is_stationary();
	void up_stops();
	void down_stops();

	void set_distanceFromRequest(int floor_request_level); // NEW
	int get_distanceFromRequest(); // NEW
	
	bool get_goodStatus(); // NEW
	void set_goodStatus(bool status); // NEW


};

bool Elevator::get_goodStatus()
{
	return goodStatus;
}

void Elevator::set_goodStatus(bool status) // NEW
{
	goodStatus = status;
}


void Elevator::set_distanceFromRequest(int floor_request_level) // NEW
{
	distanceFromRequest = abs(floor_request_level - level);
}


int Elevator::get_distanceFromRequest() // NEW
{
	return distanceFromRequest;
}





void Elevator::set_name(int x)
{
	name = x;
}
int Elevator::get_name()
{
	return name;
}
void Elevator::set_level(int x)
{
	
	level = x;
}
int Elevator::get_level()
{
	return level;
}

Elevator::Elevator(int x)
{
	set_name(x);
	level = 10*x;
	

}
bool Elevator::moving_up()
{
	return (up == true);

}


void Elevator :: set_direction(bool x)
{
	up = x;
	

}
bool Elevator::is_stationary()
{
	if (ele_up.getsize() == 0 && ele_down.getsize() == 0)
	{
		return true;
	}
	else
		return false;
}
void Elevator::up_stops()
{
	
		cout << "\t\t\t\t\t\t\t moving up" << endl;
		
		
		//set_level(ele_up.print());
		
		set_direction(true);
		
		ele_up.pop();
	
}
void Elevator::down_stops()
{
	
	
		cout << "\t\t\t\t\t\t\t moving down" << endl;
		//set_level (ele_down.print());
		set_direction(false);
		ele_down.pop();
	
}
