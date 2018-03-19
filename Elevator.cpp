#include "Elevator.h"
#include "Utilities.h"

Elevator::Elevator(int x)
{
	set_name(x);
}

Elevator::Elevator(int x, const int number_of_floors, const int number_of_elevators)
{
	set_name(x);
	// sets the elevators initial level based on number of floors
	level = x * (number_of_floors / number_of_elevators);
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

bool Elevator::moving_up()
{
	return (up == true);

}

bool Elevator::isBoarding()
{
	return Boarding;
}

void Elevator::setBoarding(bool boarding)
{
	Boarding = boarding;
}
void Elevator::set_direction(bool x)
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
	if (DEBUG == YES)
	{
		cout << "\t\t moving up" << endl;
	}
	int new_level = abs(abs(get_level()) + 1);
	if (abs(get_level() - ele_up.front_value()[FLOOR]) != 1) {
		set_level(new_level);
		set_direction(true);
	}
	else
	{

		set_level(ele_up.front_value()[FLOOR]);
		last_floor_up = ele_up.front_value()[FLOOR];
		set_direction(true);
		ele_up.pop_front();
		floors_stopped_between_request = floors_stopped_between_request + 1;
	}



}
void Elevator::down_stops()
{
	if (DEBUG == YES)
	{
		cout << "\t\t moving down" << endl;
	}
	int new_level = abs(abs(get_level()) - 1);
	if (abs(get_level() - ele_down.front_value()[FLOOR]) != 1) {
		set_level(new_level);
		set_direction(false);
	}
	else
	{

		set_level(ele_down.front_value()[FLOOR]);
		last_floor_down = ele_down.front_value()[FLOOR];
		set_direction(false);
		ele_down.pop_front();
	}


}

bool Elevator::get_goodStatus()
{
	return goodStatus;
}

void Elevator::set_goodStatus(bool status)
{
	goodStatus = status;
}

void Elevator::set_distanceFromRequest(int floor_request_level)
{
	distanceFromRequest = abs(floor_request_level - level);
}

int Elevator::get_distanceFromRequest()
{
	return distanceFromRequest;
}

