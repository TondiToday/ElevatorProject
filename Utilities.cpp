#include "Utilities.h"
#include "Modified_q.h"
#include "User.h"


// Converts user input to a const int
const int userInputToConstant(int user_input)
{
	const int USER_INPUT_CONSTANT = user_input;
	return USER_INPUT_CONSTANT;
}



void printElevatorStatus(Elevator* elevator_obj, int direction)
{
	cout << endl;
	cout << "The best elevator is: " << elevator_obj->get_name() << endl;
	cout << "Stationary? " << elevator_obj->is_stationary() << endl;
	cout << "Is moving up? " << elevator_obj->moving_up() << endl;
	cout << "Total jobs UP: " << elevator_obj->ele_up.getsize() << endl;
	cout << "Total jobs DOWN: " << elevator_obj->ele_down.getsize() << endl;
	cout << "Distance from requested floor: " << elevator_obj->get_distanceFromRequest() << endl;

	if ((direction == DOWN) && (elevator_obj->moving_up() == true) && (elevator_obj->is_stationary() == false))
	{
		cout << "WARNING: Elevator is going the wrong direction!" << endl;
	}
	else if ((direction == UP) && (elevator_obj->moving_up() == false) && (elevator_obj->is_stationary() == false))
	{
		cout << "WARNING: Elevator is going the wrong direction!" << endl;
	}
}







