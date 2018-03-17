#include "ElevatorOperations.h"
#include "Elevator.h"
#include "Utilities.h"
#include "User.h"

// need to pass in floor request, if the elevator is at that floor and was the elevator dispatched to that floor
// not all elevators stops are due to a floor request 


void elevator_op(vector<Elevator*> &v, const int& number_of_floors, int& total_users)
{/*
	vector<Elevator*>::iterator el;
	for (el = v.begin(); el != v.end(); ++el)
	{

		if ((*el)->ele_up.getsize() != 0)
		{
			cout << "\t\t Elevator " << (*el)->get_name() << endl;

			(*el)->up_stops();
			//customer_input2((*el)->ele_up, (*el)->ele_down, *(*el));

			//START NEW//
			vector<User*> users = generateUsers((*el)->get_level(), number_of_floors, total_users);
			printUserStatus(users);

			for (int i = 0; i < users.size(); i++)
			{
				if (users[i]->get_userDestination() <= (*el)->get_level())
				{
					cout << "EO Event 1" << endl;
					(*el)->ele_down.push_down(users[i]->get_userDestination());
					
					if (DEBUG == YES)
					{
						cout << "User " << users[i]->get_UserID() << " entered Elevator " << (*el)->get_name() << endl;
					}
				}

				else if (users[i]->get_userDestination() >= (*el)->get_level())
				{
					cout << "EO Event 2" << endl;
					(*el)->ele_up.push_up(users[i]->get_userDestination());
					
					if (DEBUG == YES)
					{
						cout << "User " << users[i]->get_UserID() << " entered Elevator " << (*el)->get_name() << endl;
					}
				}
			}
			deleteVector(users);
			//END NEW/

			cout << "\t\t Elevator " << (*el)->get_name() << endl;
			(*el)->up_stops();
			if ((*el)->ele_down.getsize() != 0)
			{
				(*el)->down_stops();
			}

		}

		if ((*el)->ele_down.getsize() != 0)
		{

			cout << "\t\t Elevator " << (*el)->get_name() << endl;

			(*el)->down_stops();
			//customer_input2((*el)->ele_up, (*el)->ele_down, *(*el));

			//START NEW//
			vector<User*> users = generateUsers((*el)->get_level(), number_of_floors, total_users);
			printUserStatus(users);

			for (int i = 0; i < users.size(); i++)
			{
				if (users[i]->get_userDestination() <= (*el)->get_level())
				{
					cout << "EO Event 3" << endl;
					(*el)->ele_down.push_down(users[i]->get_userDestination());
					
					if (DEBUG == YES)
					{
						cout << "User " << users[i]->get_UserID() << " entered Elevator " << (*el)->get_name() << endl;
					}
				}
					
				else if (users[i]->get_userDestination() >= (*el)->get_level())
				{
					cout << "EO Event 4" << endl;
					(*el)->ele_up.push_up(users[i]->get_userDestination());
					
					if (DEBUG == YES)
					{
						cout << "User " << users[i]->get_UserID() << " entered Elevator " << (*el)->get_name() << endl;
					}
				}
			}
			deleteVector(users);
			//END NEW//

			cout << "\t\t Elevator " << (*el)->get_name() << endl;
			(*el)->down_stops();
			if ((*el)->ele_up.getsize() != 0)
			{
				(*el)->up_stops();
			}
		}
	}
}
*/

vector<Elevator*>::iterator el;
	for (el = v.begin(); el != v.end(); ++el)
	{
		//(*el)->up_stops();

		
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
		else {};
		int currentDirection = (*el)->moving_up();
		if ( (*el)->get_distanceFromRequest() == 0) {/*


			//customer_input2((*el)->ele_up, (*el)->ele_down, *(*el));

			vector<User*> users = generateUsers((*el)->get_level(), currentDirection, number_of_floors, total_users);
			printUserStatus(users);

			if (currentDirection == DOWN)
			{
				cout << "*****************************************************EVENT 1" << endl;

				for (int i = 0; i < users.size(); i++)
				{
					if (users[i]->get_userDestination() >(*el)->get_level()) {
						(*el)->ele_up.push_up(users[i]->get_userDestination());
					}
					else if (users[i]->get_userDestination() < (*el)->get_level()) {
						(*el)->ele_down.push_down(users[i]->get_userDestination());
					}
					else {};
				}
				(*el)->down_stops();
			}

			if (currentDirection == UP)
			{
				cout << "*****************************************************EVENT 1" << endl;

				for (int i = 0; i < users.size(); i++)
				{
					if (users[i]->get_userDestination() >(*el)->get_level()) {
						(*el)->ele_down.push_down(users[i]->get_userDestination());
					}
					else if (users[i]->get_userDestination() < (*el)->get_level()) {
						(*el)->ele_up.push_up(users[i]->get_userDestination());
					}
					else {};
				}
				(*el)->up_stops();
			}

			cout << "\t\t Elevator " << (*el)->get_name() << "\t\t on floor " << (*el)->get_level() << endl;


			// Delete users vector (dynamic memory)
			deleteVector(users);*/

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
		else if ((*el)->ele_down.getsize() != 0 && (*el)->moving_up() == true){
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