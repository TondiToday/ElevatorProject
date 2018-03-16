#include "ElevatorOperations.h"
#include "Elevator.h"
#include "Utilities.h"
#include "User.h"

// need to pass in floor request, if the elevator is at that floor and was the elevator dispatched to that floor
// not all elevators stops are due to a floor request 


int tempCount = 0;


void elevator_op(vector<Elevator*> &v, const int& number_of_floors, int& total_users)
{
	vector<Elevator*>::iterator el;
	for (el = v.begin(); el != v.end(); ++el)
	{


		(*el)->up_stops();

		int currentDirection = (*el)->moving_up();


		if ((*el)->ele_up.getsize() != 0)
		{
			if (DEBUG == YES)
			{
				cout << "\t\t Elevator " << (*el)->get_name() << endl;
			}
						
			//customer_input2((*el)->ele_up, (*el)->ele_down, *(*el));
			
			vector<User*> users = generateUsers((*el)->get_level(), currentDirection, number_of_floors, total_users);
			printUserStatus(users);

			if (currentDirection == DOWN)
			{
				cout << "*****************************************************EVENT 1" << endl;

				for (int  i = 0; i < users.size(); i++)
				{
					(*el)->ele_down.push_down(users[i]->get_userDestination());
				}
			}

			else if (currentDirection == UP)
			{
				cout << "*****************************************************EVENT 2" << endl;

				for (int i = 0; i < users.size(); i++)
				{
					(*el)->ele_up.push_up(users[i]->get_userDestination());
				}
			}

			cout << "\t\t Elevator " << (*el)->get_name() << endl;
			(*el)->up_stops();
			if ((*el)->ele_down.getsize() != 0)
			{
				(*el)->down_stops();
			}

			// Delete users vector (dynamic memory)
			deleteVector(users);

		}
		if ((*el)->ele_down.getsize() != 0)
		{
			if (DEBUG == YES)
			{
				cout << "\t\t Elevator " << (*el)->get_name() << endl;
			}

			(*el)->down_stops();
			
			vector<User*> users = generateUsers((*el)->get_level(), currentDirection, number_of_floors, total_users);
			printUserStatus(users);

			if (currentDirection == DOWN)
			{ 
				cout << "*****************************************************EVENT 3" << endl;
				for (int i = 0; i < users.size(); i++)
				{
					(*el)->ele_down.push_down(users[i]->get_userDestination());
				}
			}

			else if (currentDirection == UP)
			{
				cout << "*****************************************************EVENT 4" << endl;

				for (int i = 0; i < users.size(); i++)
				{
					(*el)->ele_up.push_up(users[i]->get_userDestination());
				}
			}

			if (DEBUG == YES)
			{
				cout << "\t\t Elevator " << (*el)->get_name() << endl;
			}
			
			(*el)->down_stops();
			if ((*el)->ele_up.getsize() != 0)
			{
				(*el)->up_stops();
			}
			
			// Delete users vector (dynamic memory)
			deleteVector(users);
			
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
