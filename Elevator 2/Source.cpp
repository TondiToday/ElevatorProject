#include "Elevator.h"
#include "FloorRequests.h"
#include "ElevatorCompare.h"


#include <vector>
#include <cmath>


// NEW Compare Functions
Elevator* findBestElevator(vector<Elevator*> elevators, int direction, int floor_request);
int findMinJobs(vector<Elevator*>& elevators, int direction);
int findMinDistance(vector<Elevator*>& elevators);
bool compareJobsUp(Elevator* elevator1, Elevator* elevator2);
bool compareJobsDown(Elevator* elevator1, Elevator* elevator2);
bool compareDistance(Elevator* elevator1, Elevator* elevator2);



void customer_input(q_modified & up, q_modified & d);
//void dispacher( q_modified & dup, q_modified & ddown, vector < Elevator> v);
void dispacher(q_modified & dup, q_modified & ddown);

void customer_input2(q_modified & up, q_modified & down, Elevator e);
void customer_input3(q_modified & up, q_modified & down, Elevator e);

const int userInputToConstant(int user_input);

q_modified dispach_up;
q_modified dispach_down;
vector <Elevator*> elevators;

Elevator e1(1);
Elevator e2(10);
Elevator e3(30);
Elevator e4(40);

int main()
{

//******* INTIALIZE ELEVATOR & FLOOR NUMBERS *******//

	int userElevatorNumber = 5;
	int userBuildingFloors;
		
	//cout << "Please enter the number of elevators in the building: ";
	//cin >> userElevatorNumber;

	for (int i = 0; i < userElevatorNumber; i++)
	{
		Elevator* createElevator = new Elevator(i);
		elevators.push_back(createElevator);
	}





	//******* TEMP ELEVATOR SETTINGS *******//
		// Elevator 0
		elevators[0]->set_level(1);
		elevators[0]->set_direction(true); // up
		elevators[0]->ele_up.push_up(2);
		elevators[0]->ele_up.push_up(5);
		elevators[0]->ele_up.push_up(10);
		
		// Elevator 1
		elevators[1]->set_level(10);
		elevators[1]->set_direction(false); // down
		elevators[1]->ele_down.push_down(7);
		elevators[1]->ele_down.push_down(2);

		// Elevator 2
		elevators[2]->set_level(4);
		elevators[2]->set_direction(true); // up
		elevators[2]->ele_up.push_up(7);
		elevators[2]->ele_up.push_up(8);
		elevators[2]->ele_up.push_up(10);
		elevators[2]->ele_up.push_up(11);
		elevators[2]->ele_up.push_up(12);

		
		

		// Elevator 3
		elevators[3]->set_level(3);
		elevators[3]->set_direction(false); // down

		// Elevator 4
		elevators[4]->set_level(15);
		elevators[4]->set_direction(false); // down
		elevators[4]->ele_down.push_down(7);
		elevators[4]->ele_down.push_down(8);
		elevators[4]->ele_down.push_down(10);
		elevators[4]->ele_down.push_down(11);
		elevators[4]->ele_down.push_down(12);
	
	//**************************************//





	cout << "Please enter the number of floors in the building: ";
	cin >> userBuildingFloors;

	// converts user input to const int
	const int NUMBER_FLOORS = userInputToConstant(userBuildingFloors);

	
	int* newTaskPtr = floorRequest(NUMBER_FLOORS);
	int newTask[2];
	enum Tasks { DIRECTION = 0, FLOOR_REQUEST = 1};
	newTask[DIRECTION] = *newTaskPtr;
	newTask[FLOOR_REQUEST] = *(newTaskPtr + 1);
	
	

	cout << "Requested Direction: " << newTask[DIRECTION] << endl;
	cout << "Requested Floor Number: " << newTask[FLOOR_REQUEST] << endl;
	cout << endl;

	for (int i = 0; i < elevators.size(); i++)
	{
		cout << "Elevator " << i << " is going up? " << elevators[i]->moving_up() << endl;
		cout << "Elevator " << i << " is stationary? " << elevators[i]->is_stationary() << endl;

	}

	cout << endl;


	// Update Elevator Object "distanceFromRequest"
	for (int i = 0; i < elevators.size(); i++)
	{
		elevators[i]->set_distanceFromRequest(newTask[FLOOR_REQUEST]);
		cout << "Elevator " << i << " is " << elevators[i]->get_distanceFromRequest()
			<< " floors from requested floor " << newTask[FLOOR_REQUEST] << endl;
	}

	



	// ******* DISPATCHER LOGIC TEST *******//
		

		// *** Find the best elevator *** //
		Elevator* temp = new Elevator(-1);

		temp = findBestElevator(elevators, newTask[DIRECTION], newTask[FLOOR_REQUEST]);
		
		cout << endl;
		cout << "The best elevator is: " << temp->get_name() << endl;
		cout << "Stationary? " << temp->is_stationary() << endl;
		cout << "Is moving up? " << temp->moving_up() << endl;
		cout << "Total UP jobs: " << temp->ele_up.getsize() << endl;
		cout << "Total DOWN jobs: " << temp->ele_down.getsize() << endl;
		cout << "Distance from requested floor: " << temp->get_distanceFromRequest() << endl;

		if ( (newTask[DIRECTION] == 0) && (temp->moving_up() == true) )
		{
			cout << "WARNING: Elevator is going the wrong direction!" << endl;
		}
		else if ( (newTask[DIRECTION] == 1) && (temp->moving_up() == false) )
		{
			cout << "WARNING: Elevator is going the wrong direction!" << endl;
		}




	
	customer_input(dispach_up, dispach_down);
	dispacher(dispach_up, dispach_down);
	 
		 if (e1.ele_up.getsize() != 0)
		 {
			 cout << "\t\t elevator 1" << endl;
			 e1.up_stops();
			 customer_input2(e1.ele_up, e1.ele_down, e1);
			 cout << "\t\t\t\t elevator 1" << endl;
			 e1.up_stops();
			 if (e1.ele_down.getsize() != 0)
			 {
				 e1.down_stops();
			 }
			 
			 cout << endl << endl;

		 }
		 //cout << e2.ele_up.getsize() << "  " << e2.ele_down.getsize() << endl;

	 
		 if (e2.ele_up.getsize() > 0)
		 {
			 cout << "\t\t elevator 2" << endl;
			 e2.up_stops();
			 customer_input2(e2.ele_up, e2.ele_down, e2);
			 cout << "\t\t\t\t elevator 2" << endl;
			 e2.up_stops();
			 if (e2.ele_down.getsize() != 0)
			 {
				 e2.down_stops();
			 }
			 cout << endl << endl;
		 }
	 
	
	 
		 if (e3.ele_up.getsize() != 0)
		 {
			 cout << "\t\t elevator 3" << endl;

			 e3.up_stops();
			 customer_input2(e3.ele_up, e3.ele_down, e3);
			 cout << "\t\t elevator 3" << endl;
			 e3.up_stops();
			 if (e3.ele_down.getsize() != 0)
			 {
				 e3.down_stops();
			 }
			 cout << endl << endl;


		 }
	 
	 
	 
		 if (e4.ele_up.getsize() != 0)
		 {
			 cout << "\t\t elevator 4" << endl;
			 e4.up_stops();
			 customer_input2(e4.ele_up, e4.ele_down, e4);
			 cout << "\t\t elevator 4" << endl;
			 e4.up_stops();
			 if (e4.ele_down.getsize() != 0)
			 {
				 e4.down_stops();
			 }
			 cout << endl << endl;
		 }
	 
	
	 
		 if (e1.ele_down.getsize() != 0)
		 {
			 cout << "\t\t elevator 1" << endl;
			 e1.down_stops();
			 customer_input3(e1.ele_up, e1.ele_down, e1);
			 cout << "\t\t elevator 1" << endl;
			 e1.down_stops();
			 if (e1.ele_up.getsize() != 0)
			 {
				 e1.up_stops();
			 }
			 cout << endl << endl;
		 }
	 
	
	 
		 if (e2.ele_down.getsize() != 0)
		 {
			 cout << "\t\t elevator 2" << endl;
			 e2.down_stops();
			 customer_input3(e2.ele_up, e2.ele_down, e2);
			 cout << "\t\t elevator 2" << endl;
			 e2.down_stops();
			 if (e2.ele_up.getsize() != 0)
			 {
				 e2.up_stops();
			 }
			 cout << endl << endl;
		 }
	 
	
	 
		 if (e3.ele_down.getsize() != 0)
		 {
			 cout << "\t\t elevator 3" << endl;

			 e3.down_stops();
			 customer_input3(e3.ele_up, e3.ele_down, e3);
			 cout << "\t\t elevator 3" << endl;
			 e3.down_stops();
			 if (e3.ele_up.getsize() != 0)
			 {
				 e3.up_stops();
			 }
			 cout << endl << endl;

		 }
	
	
		 if (e4.ele_down.getsize() != 0)
		 {
			 cout << "\t\t elevator 4" << endl;
			 e4.down_stops();
			 customer_input3(e4.ele_up, e4.ele_down, e4);
			 cout << "\t\t elevator 4" << endl;
			 e4.down_stops();
			 if (e4.ele_up.getsize() != 0)
			 {
				 e4.up_stops();
			 }
			 cout << endl;
		 }
	 

	system("pause");
	return 0;
}
void customer_input (q_modified & dispach_up, q_modified & dispach_down)

{
	
	int n = 4;
	string dir;
	int floor;
	int i = 1;
	while (n != 0)
	{
		cout << "...........................Enter order " << i << endl;
		cout << "up [u] or down [d] or  for No request  [n]" << ".... and then floor number where the request is coming from" << endl;
		cin >> dir >> floor;
		while (dir != "u" && dir != "d" && dir != "n")
		{
					cout << "Enter order " << i << endl;
					cout << "up [u] or down [d] or  for No request  [n]" << "   and floor number where the request is coming" << endl;
					cin >> dir>> floor;
				
		}
		if (dir == "u")
		{
			dispach_up.push_up(floor);
		}
		else if (dir == "d")
		{
			dispach_down.push_down(floor);
		}
		else if (dir == "n")
		{
			return;
		}
	
		n--;
		i++;
	}
}
void dispacher (q_modified & up, q_modified & d)

{
	/*vector < Elevator> ::iterator it = v.begin();
	cout << it->get_name() << endl;
	v[0].ele_up.push_up(up.front_value());
	//.ele_up.push_up(up.front_value);
	//it->ele_up.push_up(up.front_value());
	up.pop_front();
	
	//it->ele_up.push_up(up.front_value());
	//up.pop_front();*/

	/*for (it = e.begin(); it != e.end(); ++it)
	{
		if (up.front_value() != 0)
		{
			//it->push_up(u_p.front_value())
			it->ele_up.push_up(up.front_value());
		}
	}*/
	/*while (up.getsize() != 0)
	{
		if (e1.get_level() + 5 <= up.front_value ())
		{
			e1.ele_up.push_up(up.front_value());
			up.pop_front();

		}


		if (e2.get_level () + 5 <= up.front_value())
		{
			e2.ele_up.push_up(up.front_value());
			up.pop_front();
		}
		if (e3.get_level() + 5 <= up.front_value())
		{
			e3.ele_up.push_up(up.front_value());
			up.pop_front();

		}
		if (e2.get_level() + 5 <= up.front_value())
		{
			e4.ele_up.push_up(up.front_value());
			up.pop_front();
		}
	
	}*/
	
			if (up.getsize() != 0 )
			{
				e1.ele_up.push_up(up.front_value());
				up.pop_front();
				
			}
			

			 if (up.getsize() != 0 )
			{
				e2.ele_up.push_up(up.front_value());
				up.pop_front();
			}
			 if (up.getsize() != 0)
			{
				e3.ele_up.push_up(up.front_value());
				up.pop_front();
				
			}
			 if (up.getsize() != 0)
			{
				e4.ele_up.push_up(up.front_value());
				up.pop_front();
			}	

	
		if (d.front_value() != 0)
		{

			e3.ele_down.push_down(d.front_value());
			d.pop_front();
		}
		if (d.front_value() != 0)
		{
			e4.ele_down.push_down(d.front_value());
			d.pop_front();
		}
		if (d.front_value() != 0)
		{
			e1.ele_down.push_down(d.front_value());
			d.pop_front();
		}
		if (d.front_value() != 0)
		{
			e2.ele_down.push_down(d.front_value());
			d.pop_front();
		}

	

}
void customer_input2(q_modified & up, q_modified & down, Elevator e)
//void customer_input2(q_modified & go2)
{
	int go;
	bool entering = true;
	while (entering == true)
	{
		cout << "press the floor number where you want to go and then press close (0)  " << endl;
		cin >> go;
		/*while (go < 1 || go > 5 && go < 7 || go > 7)
		{
			cout << "press floor  1 2 3 4 5 and to close press (0)  " << endl;
			cin >> go;

		}*/

		if (go == 0)
		{
			entering = false;
		}
		else if (go < e.get_level())
		{
			down.push_down(go);

		}
		else
		{
			up.push_up(go);
		}
	}


}
void customer_input3(q_modified & up, q_modified & down, Elevator e)
//void customer_input3(q_modified & go2)
{
	int go;
	bool entering = true;
	while (entering == true)
	{
		cout << "press the floor number where you want to go and then press close (0)  " << endl;
		cin >> go;
		/*while (go < 1 || go > 5 && go < 7 || go > 7)
		{
		cout << "press floor  1 2 3 4 5 and to close press (0)  " << endl;
		cin >> go;

		}*/

		if (go == 0)
		{
			entering = false;
		}
		else if (go > e.get_level())
		{
			up.push_up(go);
		}
		else
		{
			down.push_down(go);
		}
	}


}




const int userInputToConstant(int user_input) {
	const int USER_INPUT_CONSTANT = user_input;
	return USER_INPUT_CONSTANT;
}

Elevator* findBestElevator(vector<Elevator*> elevators, int direction, int floor_request)
{
	enum Direction { DOWN = 0, UP = 1};
	int elevators_with_bad_status = 0;

	// SORT copy of elevator vector based on distance
	vector<Elevator*> elevatorsDistance;
	elevatorsDistance = elevators; // shallow copy of elevators vector
	sort(elevatorsDistance.begin(), elevatorsDistance.end(), compareDistance);
	

	int number_of_elevators = elevators.size();
		
	for (int index = 0; index < number_of_elevators; index++)
	{
		cout << "Floor direction: " << direction << endl << endl;
		
		for (int i = 0; i < elevators.size(); i++)
		{
			cout << "Current Elevators: " << elevators[i]->get_name() << ", Floor #: " << elevators[i]->get_level() << endl;
		}
		
		
		if (elevators[index]->is_stationary() == true)
		{
			// if the elevator is stationary and is the closest elevator, DISPATCH!
			if (elevators[index]->get_distanceFromRequest() == elevatorsDistance.front()->get_distanceFromRequest())
			{
				cout << "Decision: Closest and idle" << endl;

				return elevatorsDistance.front();
			}
		}
		
		
		if (direction == DOWN)
		{
			for (int index = 0; index < elevators.size(); index++)
			{
				// remove elevator if it's going in the wrong direction or has already passed the floor request

				if (elevators[index]->moving_up() == true) // WRONG WAY
				{
					cout << "Elevator " << elevators[index]->get_name() << " marked with bad status"
						<< ", Reason: heading in the wrong direction." << endl;
					elevators[index]->set_goodStatus(false);
					elevators_with_bad_status++;
				}
				else if (elevators[index]->get_level() < floor_request) // ALREADY PASSED FLOOR
				{
					cout << "Elevator " << elevators[index]->get_name() << " marked with bad status"
						<< ", Reason: already passed requested floor." << endl;
					elevators[index]->set_goodStatus(false);
					elevators_with_bad_status++;
				}
			}
			
			if (elevators_with_bad_status == elevators.size())
			{
				cout << "All elevators have bad status" << endl;
				cout << "Decision: Fewest jobs." << endl;

				// find elevator with min jobs
				int indexOfMinJobs = findMinJobs(elevators, direction);

				return elevators[indexOfMinJobs];
			}



			cout << "Removing elevators with bad statuses..." << endl << endl;

			for (vector<Elevator*>::iterator iter = elevators.begin(); iter != elevators.end();)
			{
				if ((*iter)->get_goodStatus() == false)
				{
					iter = elevators.erase(iter);
					cout << "Removed Elevator: due to bad status" << endl;
					number_of_elevators--;
				}
				else
				{
					++iter;
				}
			}

			cout << "Available elevators: " << elevators.size() << endl;



			// find elevator with min distance to floor
			int indexOfMinDistance = findMinDistance(elevators);

			// find elevator with min jobs
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



		else if (direction == UP)
		{
			for (int index = 0; index < elevators.size(); index++)
			{
				// remove elevator if it's going in the wrong direction or has already passed the floor request

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
			

			if (elevators_with_bad_status == elevators.size())
			{
				cout << "All elevators have bad status" << endl;
				cout << "Decision: Fewest jobs." << endl;

				// find elevator with min jobs
				int indexOfMinJobs = findMinJobs(elevators, direction);

				return elevators[indexOfMinJobs];
			}

			
			
			cout << "Removing elevators with bad statuses..." << endl << endl;

			for (vector<Elevator*>::iterator iter = elevators.begin(); iter != elevators.end();)
			{
				if ((*iter)->get_goodStatus() == false)
				{
					iter = elevators.erase(iter);
					cout << "Removed Elevator: due to bad status" << endl;
					number_of_elevators--;
				}
				else
				{
					++iter;
				}
			}

			cout << "Available elevators: " << elevators.size() << endl;

			

			// find elevator with min distance to floor
			int indexOfMinDistance = findMinDistance(elevators);

			// find elevator with min jobs
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

		
		
		// Probably don't need this
		if (elevators.size() == 1)
			{
				cout << "Decision: No other elevators left." << endl;
				return elevators.front();
			}

	}

	cout << "Something went wrong :(" << endl;
	
	Elevator* temp = new Elevator(-1);
	return temp;

}


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

int findMinJobs(vector<Elevator*>& elevators, int direction)
{
	vector<Elevator*>::iterator it;

	// finds the position of the elevators with the fewest jobs in the given direction
	if (direction == 0) 
	{	
		it = min_element(elevators.begin(), elevators.end(), compareJobsDown);
	}
	if (direction == 1)
	{
		it = min_element(elevators.begin(), elevators.end(), compareJobsUp);
	}
	// returns the int distance from the iterator beginning to the target
	// to be used with the [] operator
	return distance(elevators.begin(), it);
}

int findMinDistance(vector<Elevator*>& elevators)
{
	vector<Elevator*>::iterator it;
	
	it = min_element(elevators.begin(), elevators.end(), compareDistance);
	
	return distance(elevators.begin(), it);
}
