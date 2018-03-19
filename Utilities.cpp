#include "Utilities.h"
#include "Modified_q.h"
#include "User.h"
#include "time.h"
#include <iostream>

bool DEBUG; // global debug variable

// Set whether debug statements are displayed
void setDebug() 
{
	DEBUG = YES;
	/*
	string user_input;

	while (true)
	{
		cout << "Display debug statements: Y/N: ";
		cin >> user_input;

		if (toupper(user_input[0]) == 'Y')
		{
			DEBUG = true;
			break;
		}
		else if (toupper(user_input[0]) == 'N')
		{
			DEBUG = false;
			break;
		}
		else
		{
			cout << "Invalid input." << endl;
			continue;
		}
	}
	cout << endl;*/
	if (DEBUG == YES)
	{
		cout << "Debug statements: " << boolalpha << DEBUG << endl << endl;
	}
}


const int setFloorNumbers()
{
	bool repeat = true;
	string user_input;
	int userBuildingFloors; // for user inputted number of floors

	while (repeat)
	{
		cout << "Please enter the number of floors in the building: ";
		cin >> user_input;
		
		for (int i = 0; i < user_input.length(); i++)
		{
			if (!isdigit(user_input[i]))
			{
				cout << "Invalid input." << endl;
				continue;
			}
			userBuildingFloors = stoi(user_input);

			if (userBuildingFloors > 20)
			{
				cout << "More than 20 floors requires a longer simulation running time to work properly. "
					"Ignore: Y/N: ";
				string user_input;
				cin >> user_input;

				if (toupper(user_input[0]) == 'Y')
				{
					repeat = false;
					break;
				}
				else if (toupper(user_input[0]) == 'N')
				{
					continue;
				}
				else
				{
					cout << "Invalid input." << endl;
					continue;
				}
			}
			else if (userBuildingFloors < 2)
			{
				cout << "At least two floors are required." << endl;
				continue;
			}
			else
			{
				repeat = false;
				break;
			}
		}
		
		
	}
	const int FLOORS_NUMBER = userInputToConstant(userBuildingFloors);
	return FLOORS_NUMBER;
}



const int setElevatorNumbers(const int FLOORS_NUMBER)
{
	bool repeat = true;
	string user_input;
	int userElevatorNumber; // for user inputted number of elevators

	while (repeat)
	{
		cout << "Please enter the number of elevators in the building: ";
		cin >> user_input;

		for (int i = 0; i < user_input.length(); i++)
		{
			if (!isdigit(user_input[i]))
			{
				cout << "Invalid input." << endl;
				continue;
			}
			userElevatorNumber = stoi(user_input);

			// floor to elevator ratio should be 2:1 or 2.5:1
			float floorToElevatorRatio = FLOORS_NUMBER / userElevatorNumber;

			if ((floorToElevatorRatio < 2) || (floorToElevatorRatio > 2.5))
			{
				cout << "A floor to elevator ratio of 2:1 or 2.5:1 will provide more realistic results." << endl;
				cout << "Consider using " << ceil(FLOORS_NUMBER / 2.5) << " elevators. " << "Ignore: Y/N: ";
				string user_input;
				cin >> user_input;

				if (toupper(user_input[0]) == 'Y')
				{
					repeat = false;
					break;
				}
				else if (toupper(user_input[0]) == 'N')
				{
					continue;
				}
				else
				{
					cout << "Invalid input." << endl;
					continue;
				}
			}
			else
			{
				repeat = false;
				break;
			}
		}
	}
	const int ELEVATORS_NUMBER = userInputToConstant(userElevatorNumber);
	return ELEVATORS_NUMBER;
}


const int setSimTime(const int FLOORS_NUMBER, const int ELEVATORS_NUMBER)
{
	bool repeat = true;
	string user_input;
	int userSimTime; // for loop iterations

	while (repeat)
	{
		cout << "Please enter simulation time in iterations: ";
		cin >> user_input;

		for (int i = 0; i < user_input.length(); i++)
		{
			if (!isdigit(user_input[i]))
			{
				cout << "Invalid input." << endl;
				continue;
			}
			userSimTime = stoi(user_input);
			if (userSimTime < 100)
			{
				cout << "A sim time of at least 100 is recommended." << endl;
				cout << "Consider a sim time of " << (FLOORS_NUMBER / ELEVATORS_NUMBER) * 50 << " iterations. " << "Ignore: Y/N: ";
				string user_input;
				cin >> user_input;

				if (toupper(user_input[0]) == 'Y')
				{
					repeat = false;
					break;
				}
				else if (toupper(user_input[0]) == 'N')
				{
					continue;
				}
				else
				{
					cout << "Invalid input." << endl;
					continue;
				}
			}
			else
			{
				repeat = false;
				break;
			}
		}
	}	
	const int SIM_TIME = userInputToConstant(userSimTime);
	return SIM_TIME;
}




// Converts user input to a const int
const int userInputToConstant(int user_input)
{
	const int USER_INPUT_CONSTANT = user_input;
	return USER_INPUT_CONSTANT;
}

void deleteVector(vector<Elevator*> discarded_elevators)
{
	// Delete elevator vector (dynamic memory)
	while (!discarded_elevators.empty())
	{
		if (DEBUG == YES)
		{
			cout << "Deleting Elevator: " << discarded_elevators.back()->get_name() << endl;
		}

		delete discarded_elevators.back();
		discarded_elevators.pop_back();
	}
}

void deleteVector(vector<User*> discarded_users)
{
	// Delete users vector (dynamic memory)
	while (!discarded_users.empty())
	{
		if (DEBUG == YES)
		{
			cout << "Deleting User: " << discarded_users.back()->get_UserID() << endl;
		}

		delete discarded_users.back();
		discarded_users.pop_back();
	}
}


void printElevatorStatus(Elevator*& elevator_obj, int direction)
{
	if (DEBUG == YES)
	{
		cout << endl;
		cout << "The best elevator: " << elevator_obj->get_name() << endl;
		cout << "Stationary? " << boolalpha << elevator_obj->is_stationary() << endl;
		cout << "Moving up? " << boolalpha << elevator_obj->moving_up() << endl;
		cout << "Total jobs up: " << elevator_obj->ele_up.getsize() << endl;
		cout << "Total jobs down: " << elevator_obj->ele_down.getsize() << endl;
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

}

void printUserStatus(vector<User*>& users_vector)
{
	if (DEBUG == YES)
	{
		for (unsigned int i = 0; i < users_vector.size(); i++)
		{
			cout << "User ID: " << users_vector[i]->get_UserID()
				<< ", Starting Floor: " << users_vector[i]->get_userFloor()
				<< ", Destination Floor: " << users_vector[i]->get_userDestination() << endl;
		}
	}	
}

int randomFloor(int max, int min)
{
	if ((max - min + 1) == 0)
	{
		int zeroFix = 1;
		return rand() % zeroFix;
	}
	else
	{
		if (rand() % ((max + 1) - min) + min > max) 
		{
			return max - 1;
		}
		else 
		{
			return rand() % ((max + 1) - min) + min;
		};
	}
}
/*
int randomFloor(int max, int min)
{

	int num = (min + (rand() % (int)(max - min + 1)));
	return num;
}
*/

double averageWaitingTime(vector<int>& waiting_times, int& total_users)
{
	if (total_users == 0)
	{
		return 0;
	}

	double sum_of_waiting_times = 0;

	for (int i = 0; i < waiting_times.size(); i++)
	{
		sum_of_waiting_times += waiting_times[i];
	}
	return sum_of_waiting_times / total_users;
}

void displayStatistics(const int& FLOORS_NUMBER, const int& ELEVATORS_NUMBER, const int& SIM_TIME,
	int& total_users, vector<int>& user_waiting_times)
{
	cout << endl;
	cout << "Simulation complete." << endl;
	cout << "Simulation time: " << SIM_TIME << " iterations" << endl;
	cout << "Number of floors: " << FLOORS_NUMBER << endl;
	cout << "Number of elevators: " << ELEVATORS_NUMBER << endl;
	cout << "Total users: " << total_users << endl;
	cout << "Average waiting time: " << averageWaitingTime(user_waiting_times, total_users) << 
		" iterations" << endl << endl;
	cout << "Waiting time refers to the time when a floor request to the elevator arriving to "
		"pick up users." << endl;
}