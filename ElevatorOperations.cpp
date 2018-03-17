#include "ElevatorOperations.h"
#include "Elevator.h"
#include "Utilities.h"
#include "User.h"

// need to pass in floor request, if the elevator is at that floor and was the elevator dispatched to that floor
// not all elevators stops are due to a floor request 


void elevator_op(vector<Elevator*> &v, const int& number_of_floors, int& request_direction, int& total_users)
{
	vector<Elevator*>::iterator el;
	for (el = v.begin(); el != v.end(); ++el)
	{

		if ((*el)->ele_up.getsize() != 0)
		{
			cout << "\t\t Elevator " << (*el)->get_name() << endl;

			(*el)->up_stops();
			//customer_input2((*el)->ele_up, (*el)->ele_down, *(*el));

			/*START NEW*/
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
			/*END NEW*/

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

			/*START NEW*/
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
			/*END NEW*/

			cout << "\t\t Elevator " << (*el)->get_name() << endl;
			(*el)->down_stops();
			if ((*el)->ele_up.getsize() != 0)
			{
				(*el)->up_stops();
			}
		}
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


