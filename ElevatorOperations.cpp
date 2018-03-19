#include "ElevatorOperations.h"
#include "Elevator.h"
#include "Utilities.h"
#include "User.h"

// need to pass in floor request, if the elevator is at that floor and was the elevator dispatched to that floor
// not all elevators stops are due to a floor request 


void elevator_op(vector<Elevator*> &v, const int& number_of_floors, int& total_users, int& current_time, vector<int>& waiting_times)
{
	vector<Elevator*>::iterator el;

	for (el = v.begin(); el != v.end(); ++el)
	{
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

// USER BOARDING LOGIC //

		// if the elevator is stationary and has no floor requests
		if ((*el)->isBoarding() == true)
		{
			if (DEBUG == YES)
			{
				cout << endl;
				cout << "***ELEVATOR Finished Boarding***" << endl;
				cout << endl;
			}
			(*el)->setBoarding(false);
			(*el)->last_floor_down = { -1, -1, -1 };
			(*el)->last_floor_up = { -1, -1, -1 };
		}
		/*else if ( ((*el)->is_stationary() == YES) && ( ((*el)->ele_down.isempty()) && (*el)->ele_up.isempty() ) )
		{
			continue;
		}*/
		// if the elevator is moving DOWN, and a floor request matches the current floor
		else if ((((*el)->moving_up() == NO) && ((*el)->last_floor_down[FLOOR] == (*el)->get_level()) && (*el)->ele_down.isempty() == NO)

			// OR if the elevator's UP queue is empty and it's DOWN queue is not empty, and a floor request matches the current floor
			|| ((((*el)->ele_up.isempty() == YES) && (*el)->ele_down.isempty() == NO) && ((*el)->last_floor_up[FLOOR] == (*el)->get_level()))

			// OR if the elevator is now stationary, but it had a DOWN request, and a floor request matches the current floor
			|| (((*el)->is_stationary() == YES) && ((*el)->last_floor_down[FLOOR] == (*el)->get_level())))
		{
			if (DEBUG == YES)
			{
				cout << endl;
				cout << "***Elevator Starts Boarding***" << endl;
				cout << "Elevator: " << (*el)->get_name() << " stops at " << (*el)->get_level() << endl;
				cout << "Request floor: " << (*el)->ele_down.front_value()[FLOOR] << endl;
				cout << "Request direction: " << (*el)->ele_down.front_value()[DIRECTION] << endl;
				cout << "Request time: " << (*el)->ele_down.front_value()[TIME] << endl;
				cout << "Current time: " << current_time << endl;
				cout << "Waiting time: " << current_time - (*el)->ele_down.front_value()[TIME] << endl;
				cout << endl;
			}
		


			vector<User*> users = generateUsers((*el)->get_level(), (*el)->ele_down.front_value()[DIRECTION], number_of_floors, total_users);
			printUserStatus(users);

			//vector<int> userRequests;

			//waiting_times.push_back(current_time - (*el)->ele_down.front_value()[TIME]); // add waiting time to vector

			for (int index = 0; index < users.size(); index++)
			{
				// vector for each users { FLOOR, DIRECTION, which matches the elevator's floor request direction, and the current time }
				vector<int> eachUserRequest = { users[index]->get_userDestination(), (*el)->last_floor_down[DIRECTION], current_time };

				(*el)->ele_down.push_down(eachUserRequest);

				waiting_times.push_back(current_time - (*el)->last_floor_down[TIME]); // add waiting time to vector
				/*users[index]->set_userDestination(userInputToConstant((*el)->get_level()), userInputToConstant(0), number_of_floors);
				userRequests.push_back(users[index]->get_userDestination());
				if (userRequests[0] < (*el)->get_level()) {


					(*el)->ele_down.push_down(userRequests);
				}
				else if (userRequests[0] > (*el)->get_level()) {
					(*el)->ele_up.push_up(userRequests);
				}
				else {};
				userRequests.pop_back();*/

				if (DEBUG == YES)
				{
					cout << "User " << users[index]->get_UserID() << " entered Elevator " << (*el)->get_name() << endl;
				}
			}

			// Delete users vector (dynamic memory)
			deleteVector(users);

			(*el)->ele_down.pop_front(); // removes request from the queue

			//(*el)->down_stops();
			//cout << "\t\t Elevator " << (*el)->get_name() << "\t\t on floor " << (*el)->get_level() << endl;
			(*el)->setBoarding(true);
		
		}

		// if the elevator is moving UP and a floor request matches the current floor
		else if ((((*el)->moving_up() == YES) && ((*el)->last_floor_up[FLOOR] == (*el)->get_level()))

			|| // OR  if the elevator's DOWN queue is empty and it's UP queue is not empty, and a floor request matches the current floor
			((((*el)->ele_down.isempty() == YES) && (*el)->ele_up.isempty() == NO) && ((*el)->last_floor_up[FLOOR] == (*el)->get_level()))

			|| // OR  if the elevator is now stationary, but it had an UP request 
			(((*el)->is_stationary() == YES) && ((*el)->last_floor_up[FLOOR] == (*el)->get_level())))


		{
			if (DEBUG == YES)
			{
				cout << endl;
				cout << "***Elevator Starts Boarding***" << endl;
				cout << "Elevator: " << (*el)->get_name() << " stops at " << (*el)->get_level() << endl;
				cout << "Request floor: " << (*el)->ele_up.front_value()[FLOOR] << endl;
				cout << "Request direction: " << (*el)->ele_up.front_value()[DIRECTION] << endl;
				cout << "Request time: " << (*el)->ele_up.front_value()[TIME] << endl;
				cout << "Current time: " << current_time << endl;
				cout << "Waiting time: " << current_time - (*el)->ele_up.front_value()[TIME] << endl;
				cout << endl;
			}



			vector<User*> users = generateUsers((*el)->get_level(), (*el)->ele_up.front_value()[DIRECTION], number_of_floors, total_users);
			printUserStatus(users);

			//vector<int> userRequests;

			//waiting_times.push_back(current_time - (*el)->ele_up.front_value()[TIME]); // add waiting time to vector

			for (int index = 0; index < users.size(); index++)
			{
				// vector for each users { FLOOR, DIRECTION, which matches the elevator's floor request direction, and the current time }
				vector<int> eachUserRequest = { users[index]->get_userDestination(), (*el)->last_floor_up[DIRECTION], current_time };

				(*el)->ele_up.push_up(eachUserRequest);

				waiting_times.push_back(current_time - (*el)->last_floor_up[TIME]); // add waiting time to vector
			
				/*users[index]->set_userDestination(userInputToConstant((*el)->get_level()), userInputToConstant(1), number_of_floors);
				userRequests.push_back(users[index]->get_userDestination());
				if (userRequests[0] < (*el)->get_level()) {


					(*el)->ele_down.push_down(userRequests);
				}
				else if (userRequests[0] > (*el)->get_level()) {
					(*el)->ele_up.push_up(userRequests);
				}
				else {

				};
				userRequests.pop_back();*/

				if (DEBUG == YES)
				{
					cout << "User " << users[index]->get_UserID() << " entered Elevator " << (*el)->get_name() << endl;
				}
			}

			//(*el)->ele_up.pop_front(); // removes request from the queue

			// Delete users vector (dynamic memory)
			deleteVector(users);

			//(*el)->up_stops();
			//cout << "\t\t Elevator " << (*el)->get_name() << "\t\t on floor " << (*el)->get_level() << endl;
			(*el)->setBoarding(true);
			
		}

		
// ELEVATOR MOVEMENT LOGIC //

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