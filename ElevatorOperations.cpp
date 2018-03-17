#include "ElevatorOperations.h"
#include "Elevator.h"
#include "Utilities.h"
#include "User.h"

// need to pass in floor request, if the elevator is at that floor and was the elevator dispatched to that floor
// not all elevators stops are due to a floor request 


void elevator_op(vector<Elevator*> &v, const int& number_of_floors, int& total_users)
{
	vector<Elevator*>::iterator el;

	for (el = v.begin(); el != v.end(); ++el)
	{
		int currentDirection;

		if (DEBUG == YES)
		{
			cout << "\t\t Elevator " << (*el)->get_name() << endl;
		};

		if ((*el)->get_level() == 0) {
			(*el)->set_direction(true);
		}
		else if ((*el)->get_level() == number_of_floors) {
			(*el)->set_direction(false);
		}


		// if the elevator is stationary and has no floor requests
		if ( ((*el)->is_stationary() == YES) && ( ((*el)->floorRequests_down.isempty()) && (*el)->floorRequests_up.isempty() ) )
		{
			continue;
		}

		// if the elevator is moving DOWN and a floor request matches the current floor
		if ( ((*el)->moving_up() == NO) && ((*el)->floorRequests_down.front_value() == (*el)->get_level())
			
			&& // AND  if the elevator's UP queue is empty and it's DOWN queue is not empty
			( ((*el)->ele_up.isempty() == YES) && (*el)->ele_down.isempty() == NO)

			// OR if the elevator is now stationary, but it had a DOWN request 
			|| (((*el)->is_stationary() == YES) && ((*el)->floorRequests_down.front_value() == (*el)->get_level())) )

		{
			(*el)->floorRequests_down.pop_front(); // removes request from the queue
			currentDirection = DOWN;
			cout << "Moving up? " << boolalpha << (*el)->moving_up() << endl;
			cout << "Direction? " << currentDirection << endl;

			vector<User*> users = generateUsers((*el)->get_level(), currentDirection, number_of_floors, total_users);
			printUserStatus(users);

			for (int index = 0; index < users.size(); index++)
			{
				(*el)->ele_down.push_down(users[index]->get_userDestination());

				if (DEBUG == YES)
				{
					cout << "User " << users[index]->get_UserID() << " entered Elevator " << (*el)->get_name() << endl;
				}
			}

			// Delete users vector (dynamic memory)
			deleteVector(users);

			(*el)->down_stops();
			cout << "\t\t Elevator " << (*el)->get_name() << "\t\t on floor " << (*el)->get_level() << endl;
		}

		// if the elevator is moving UP and a floor request matches the current floor
		else if ( (((*el)->moving_up() == YES) && ((*el)->floorRequests_up.front_value() == (*el)->get_level()))

			&& // AND  if the elevator's DOWN queue is empty and it's UP queue is not empty
			(((*el)->ele_down.isempty() == YES) && (*el)->ele_up.isempty() == NO)

			|| 	// if the elevator is now stationary, but it had an UP request 
			(((*el)->is_stationary() == YES) && ((*el)->floorRequests_up.front_value() == (*el)->get_level())) )

		{
			(*el)->floorRequests_up.pop_front(); // removes request from the queue
			currentDirection = UP;
			cout << "Moving up? " << boolalpha << (*el)->moving_up() << endl;
			cout << "Direction? " << currentDirection << endl;

			vector<User*> users = generateUsers((*el)->get_level(), currentDirection, number_of_floors, total_users);
			printUserStatus(users);

			for (int index = 0; index < users.size(); index++)
			{
				(*el)->ele_up.push_up(users[index]->get_userDestination());

				if (DEBUG == YES)
				{
					cout << "User " << users[index]->get_UserID() << " entered Elevator " << (*el)->get_name() << endl;
				}
			}

			// Delete users vector (dynamic memory)
			deleteVector(users);

			(*el)->up_stops();			
			cout << "\t\t Elevator " << (*el)->get_name() << "\t\t on floor " << (*el)->get_level() << endl;
		}


		

		else if ((*el)->ele_down.getsize() == 0 && (*el)->ele_up.getsize() == 0) {
			cout << "initial condition" << endl;
		}
		else if ((*el)->ele_down.getsize() != 0 && (*el)->ele_up.getsize() == 0) {
			(*el)->down_stops();
			cout << "\t\t Elevator " << (*el)->get_name() << "\t\t on floor " << (*el)->get_level() << endl;
		}
		else if ((*el)->ele_down.getsize() == 0 && (*el)->ele_up.getsize() != 0) {
			(*el)->up_stops();
			cout << "\t\t Elevator " << (*el)->get_name() << "\t\t on floor " << (*el)->get_level() << endl;
		}
		else if ((*el)->ele_up.getsize() != 0 && (*el)->moving_up() == true) {
			(*el)->up_stops();
			cout << "\t\t Elevator " << (*el)->get_name() << "\t\t on floor " << (*el)->get_level() << endl;
		}
		else if ((*el)->ele_down.getsize() != 0 && (*el)->moving_up() == false) {
			(*el)->down_stops();
			cout << "\t\t Elevator " << (*el)->get_name() << "\t\t on floor " << (*el)->get_level() << endl;
		}
		else if ((*el)->ele_up.getsize() != 0 && (*el)->moving_up() == false) {
			(*el)->set_direction(true);
		}
		else if ((*el)->ele_down.getsize() != 0 && (*el)->moving_up() == true) {
			(*el)->set_direction(false);
		}
		else { cout << "Nothing happend " << endl; }
	}
}


void calculateDistance(vector<Elevator*>& elevators, int task)
{
	// Calculates elevators' distances from requested floor
	for (int index = 0; index < elevators.size(); index++)
	{
		elevators[index]->set_distanceFromRequest(task);

		if (DEBUG == YES)
		{
			cout << "Elevator " << index << " distance from request: " <<
				elevators[index]->get_distanceFromRequest() << endl;
		}
	}
}