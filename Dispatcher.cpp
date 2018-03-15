#include "Elevator.h"
#include "Dispatcher.h"
#include "Utilities.h"

Elevator* ElevatorWorstCase(vector<Elevator*> elevators, int& direction, int& floor_request)
{
	// Create a vector of total distance elevator would need to travel
	vector<int> Total_Distance(elevators.size());
	if (direction == DOWN)
		for (int i = 0; i < elevators.size(); i++)
		{

			if (elevators[i]->moving_up() == true) // WRONG WAY
			{
				Total_Distance[i] = abs(elevators[i]->ele_up.front_value() - elevators[i]->ele_up.back_value())
					+ abs(elevators[i]->ele_down.back_value() - floor_request);
			}
			else if (elevators[i]->get_level() > floor_request) // ALREADY PASSED FLOOR
			{
				Total_Distance[i] = abs(elevators[i]->ele_up.front_value() - elevators[i]->ele_up.back_value())
					+ abs(elevators[i]->ele_down.front_value() - elevators[i]->ele_down.back_value())
					+ abs(floor_request - elevators[i]->ele_up.front_value());
			}
		}
	if (direction == UP)
	{
		for (int i = 0; i <= elevators.size(); i++)
		{
			if (elevators[i]->moving_up() == false) // WRONG WAY
			{
				Total_Distance[i] = abs(elevators[i]->ele_down.front_value() - elevators[i]->ele_down.back_value())
					+ abs(elevators[i]->ele_up.front_value() - floor_request);
			}
			else if (elevators[i]->get_level() > floor_request) // ALREADY PASSED FLOOR
			{
				Total_Distance[i] = abs(elevators[i]->ele_up.front_value() - elevators[i]->ele_up.back_value())
					+ abs(elevators[i]->ele_down.front_value() - elevators[i]->ele_down.back_value())
					+ abs(floor_request - elevators[i]->ele_down.back_value());
			}

		}
	}
	// Find index of smallest value 
	int index = 0;

	for (int i = 1; i < Total_Distance.size(); i++)
	{
		if (Total_Distance[i] < Total_Distance[index])
		{
			index = i;
		}
	}
	return elevators[index];
}

void dispatch(vector<Elevator*>& d_elevators, int& direction, int& floor_request)
{

	// assign job to elevator
	Elevator* placeholder = new Elevator(-1);
	placeholder = findBestElevator(d_elevators, direction, floor_request);

	int index_of_selected_elevator = placeholder->get_name();
	cout << "Best elevator: " << placeholder->get_name() << endl;
	
	printElevatorStatus(placeholder, direction);

	if (direction == 0)
	{
		d_elevators[index_of_selected_elevator]->ele_down.push_down(floor_request);
	}

	else if (direction == 1)
	{
		d_elevators[index_of_selected_elevator]->ele_up.push_up(floor_request);
	}
	
}

// remove bad elevators 
int dismissBadElevators(vector<Elevator*>& m_elevators);


Elevator* findBestElevator(vector<Elevator*> elevators, int& direction, int& floor_request)
{	// elevators must be passed by value because it will modified later!
	
	// Variables
	int number_of_idle_elevators = 0;
	int elevators_with_bad_status = 0;
	bool closest_and_idle = true;
	int number_of_elevators = elevators.size();


	// Output current elevators for debug
	for (int i = 0; i < elevators.size(); i++)
	{
		cout << "Elevator " << elevators[i]->get_name() << " is at floor #: " << elevators[i]->get_level() << endl;
	}


	// FIRST CHECK: if there's only one elevator, DISPATCH
	if (elevators.size() == 1) 
	{
		cout << "Decision: There is only one elevator." << endl;
		return elevators.front();
	}
	

	// Sort a copy of the elevators vector based on distance
	vector<Elevator*> elevatorsDistance = elevators; // shallow copy of elevators vector
	sort(elevatorsDistance.begin(), elevatorsDistance.end(), compareDistance);


	// SECOND CHECK: if the closest elevator is idle OR all elevators are idle, DISPATCH the closest
	for (int index = 0; index < elevators.size(); index++)
	{
		if (elevators[index]->is_stationary() == true)
		{
			// if the first elevator is stationary and is the closest elevator, DISPATCH without continuing
			if ((closest_and_idle == true) && (elevators[index]->get_distanceFromRequest() == elevatorsDistance.front()->get_distanceFromRequest()))
			{
				cout << "Decision: Closest and idle" << endl;
				return elevatorsDistance.front();
			}
			else
			{
				closest_and_idle == false;
				number_of_idle_elevators++;
			}
		}
	}

	// if all elevators are stationary, send the closest
	if (number_of_idle_elevators == elevators.size())
	{
		cout << "Decision: All elevators stationary. Closest and idle." << endl;
		return elevatorsDistance.front();
	}



	// THIRD CHECK
	for (int index = 0; index < number_of_elevators; index++)
	{			
		// If Floor Request is 0 ('DOWN')
		if (direction == DOWN)
		{
			for (int index = 0; index < elevators.size(); index++)
			{
				// mark elevator for removal if it's going in the wrong direction or has already passed the floor request

				if (elevators[index]->moving_up() == true) // WRONG WAY
				{
					cout << "Elevator " << elevators[index]->get_name() << " marked with bad status"
						<< "; Reason: heading in the wrong direction." << endl;
					elevators[index]->set_goodStatus(false);
					elevators_with_bad_status++;
				}
				else if (elevators[index]->get_level() < floor_request) // ALREADY PASSED FLOOR
				{
					cout << "Elevator " << elevators[index]->get_name() << " marked with bad status"
						<< "; Reason: already passed requested floor." << endl;
					elevators[index]->set_goodStatus(false);
					elevators_with_bad_status++;
				}
			}

			// WORST CASE: all elevators are going in the wrong direction or have already passed floor
			if (elevators_with_bad_status == elevators.size())
			{
				cout << "All elevators have bad status" << endl;
				cout << "Decision: Elevator with Shortest Travel Distance" << endl;
				ElevatorWorstCase(elevators, direction, floor_request);
			}
			/*{
				cout << "All elevators have bad status" << endl;
				cout << "Decision: Fewest jobs." << endl;

				// find elevator with min jobs
				int indexOfMinJobs = findMinJobs(elevators, direction);

				return elevators[indexOfMinJobs];

				//FUNCTION TO FIND THE WORST CASE
			
			}*/
			
			
			// Remove elevators marked with a bad status
			int number_of_elevators = dismissBadElevators(elevators);
			
			// find the elevator with min distance to the floor request
			int indexOfMinDistance = findMinDistance(elevators);

			// find the elevator with min jobs
			int indexOfMinJobs = findMinJobs(elevators, direction);

			
			if (elevators[index]->get_goodStatus() == true)
			{
				// if the closest elevator has more jobs than than the elevator with the fewest jobs,
				// send the elevator with the fewest jobs

				if ((elevators[indexOfMinDistance]->ele_up.getsize()) > (elevators[indexOfMinJobs]->ele_up.getsize()))
				{
					cout << "Decision: Same direction and fewest jobs." << endl;
					return elevators[indexOfMinJobs];
				}
				else
				{
					cout << "Decision: Same direction and minimum distance" << endl;
					return elevators[indexOfMinDistance];
				}
			}
		}

		// If Floor Request is 1 ('UP')
		else if (direction == UP)
		{
			for (int index = 0; index < elevators.size(); index++)
			{
				// mark elevator for removal if it's going in the wrong direction or has already passed the floor request

				if (elevators[index]->moving_up() == false) // WRONG WAY
				{

					cout << "Elevator " << elevators[index]->get_name() << " marked with bad status"
						<< ", Reason: heading in the wrong direction." << endl;
					elevators[index]->set_goodStatus(false);
					elevators_with_bad_status++;
				}
				else if (elevators[index]->get_level() > floor_request) // ALREADY PASSED FLOOR
				{
					cout << "Elevator " << elevators[index]->get_name() << " marked with bad status"
						<< ", Reason: already passed requested floor." << endl;
					elevators[index]->set_goodStatus(false);
					elevators_with_bad_status++;
				}
			}

			// WORST CASE: all elevators are going in the wrong direction or have already passed floor
			if (elevators_with_bad_status == elevators.size())
			{
				cout << "All elevators have bad status" << endl;
				cout << "Decision: Elevator with Shortest Travel Distance" << endl;
				ElevatorWorstCase(elevators, direction, floor_request);
			}
		
			/*{
				cout << "All elevators have bad status" << endl;
				cout << "Decision: Fewest jobs." << endl;

				// find elevator with min jobs
				int indexOfMinJobs = findMinJobs(elevators, direction);

				return elevators[indexOfMinJobs];
			}*/

			// Remove elevators marked a with bad status
			int number_of_elevators = dismissBadElevators(elevators);


			// find index of elevator with min distance to floor
			int indexOfMinDistance = findMinDistance(elevators);

			// find index of elevator with min jobs
			int indexOfMinJobs = findMinJobs(elevators, direction);


			if (elevators[index]->get_goodStatus() == true)
			{
				// if the closest elevator has more jobs than than the elevator with the fewest jobs,
				//send the elevator with the fewest jobs

				if ((elevators[indexOfMinDistance]->ele_up.getsize()) > (elevators[indexOfMinJobs]->ele_up.getsize()))
				{
					cout << "Decision: Same direction and fewest jobs." << endl;
					return elevators[indexOfMinJobs];
				}
				else
				{
					cout << "Decision: Same direction and minimum distance" << endl;
					return elevators[indexOfMinDistance];
				}
			}
		}
	}
	throw exception("All elevators were dismissed. Something went wrong.");

}


int dismissBadElevators(vector<Elevator*>& d_elevators)
{
	cout << "Removing elevators with bad statuses..." << endl << endl;
	int num_elevators = d_elevators.size();
	int original_index_count = 0;

	for (vector<Elevator*>::iterator iter = d_elevators.begin(); iter != d_elevators.end();)
	{
		if ((*iter)->get_goodStatus() == false)
		{
			iter = d_elevators.erase(iter);
			cout << "Removed Elevator " << original_index_count << " due to bad status" << endl;
			num_elevators--;
			original_index_count++;
		}
		else
		{
			++iter;
			original_index_count++;
		}
	}
	return num_elevators;

}


int findMinJobs(vector<Elevator*>& elevators, int& direction)
{
	vector<Elevator*>::iterator iter;

	// finds the position of the elevators with the fewest jobs in the given direction
	if (direction == 0)
	{
		iter = min_element(elevators.begin(), elevators.end(), compareJobsDown);
	}
	if (direction == 1)
	{
		iter = min_element(elevators.begin(), elevators.end(), compareJobsUp);
	}
	// returns the int distance from the iterator beginning to the target
	// to be used with the [] operator
	return distance(elevators.begin(), iter);
}

int findMinDistance(vector<Elevator*>& elevators)
{
	vector<Elevator*>::iterator iter = min_element(elevators.begin(), elevators.end(), compareDistance);

	return distance(elevators.begin(), iter);
}


// Comparison Functions for Vector Sort
bool compareJobsUp(Elevator* elevator1, Elevator* elevator2)
{
	return elevator1->ele_up.getsize() < elevator2->ele_up.getsize();
}

bool compareJobsDown(Elevator* elevator1, Elevator* elevator2)
{
	return elevator1->ele_down.getsize() < elevator2->ele_down.getsize();
}

bool compareDistance(Elevator* elevator1, Elevator* elevator2)
{
	return elevator1->get_distanceFromRequest() < elevator2->get_distanceFromRequest();
}



