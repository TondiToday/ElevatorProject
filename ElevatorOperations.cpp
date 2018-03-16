#include "ElevatorOperations.h"
#include "Elevator.h"
#include "Utilities.h"
#include "User.h"

// need to pass in floor request, if the elevator is at that floor and was the elevator dispatched to that floor
// not all elevators stops are due to a floor request 


int tempCount = 0;



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
void elevator_op(vector<Elevator*> &v, const int& number_of_floors, int& total_users)
{
	vector<Elevator*>::iterator el;
	for (el = v.begin(); el != v.end(); ++el)
	{


		//(*el)->up_stops();

		int currentDirection = (*el)->moving_up();

		if (DEBUG == YES)
		{
			cout << "\t\t Elevator " << (*el)->get_name() << endl;
		};
		if (/*(*el)->get_level() == (*el)->last_floor_up || (*el)->get_level() == (*el)->last_floor_down */ (*el)->get_distanceFromRequest() == 0){


				//customer_input2((*el)->ele_up, (*el)->ele_down, *(*el));

				vector<User*> users = generateUsers((*el)->get_level(), currentDirection, number_of_floors, total_users);
				printUserStatus(users);

				if (currentDirection == DOWN)
				{
					cout << "*****************************************************EVENT 1" << endl;

					for (int i = 0; i < users.size(); i++)
					{
						if (users[i]->get_userDestination() > (*el)->get_level()) {
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
						if (users[i]->get_userDestination() > (*el)->get_level()) {
							(*el)->ele_down.push_down(users[i]->get_userDestination());
						}
						else if (users[i]->get_userDestination() < (*el)->get_level()) {
							(*el)->ele_up.push_up(users[i]->get_userDestination());
						}
						else {};
					}
					(*el)->up_stops();
				}

				cout << "\t\t Elevator " << (*el)->get_name() << endl;

				// Delete users vector (dynamic memory)
				deleteVector(users);

			}

		else if ((*el)->ele_down.getsize() == 0 && (*el)->ele_up.getsize() == 0) {
		}
		else if ((*el)->ele_down.getsize() != 0 && (*el)->ele_up.getsize() == 0 && (*el)->get_level() >= number_of_floors ) {
			(*el)->down_stops();
		}
		else if ((*el)->ele_down.getsize() == 0 && (*el)->ele_up.getsize() != 0 && (*el)->get_level() <= 0) {
			(*el)->up_stops();
		}
		else if ((*el)->moving_up() == true && (*el)->get_level() <= 0){
			(*el)->up_stops();
		}
		else if ((*el)->moving_up() == false && (*el)->get_level() >= number_of_floors ) {
			(*el)->down_stops();
		}
		else { }
	};
}


