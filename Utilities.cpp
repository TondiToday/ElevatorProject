#include "Utilities.h"
#include "Modified_q.h"
#include "User.h"
#include "time.h"
#include <iostream>
#include <iomanip>

bool DEBUG; // global debug variable

// Set whether debug statements are displayed
void setDebug() 
{
	//DEBUG = YES;
		
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
	
	if (DEBUG == YES)
	{
		cout << "Debug statements enabled" << endl << endl;
	}
	else
	{
		cout << "Debug statements disabled" << endl << endl;
	}
}

bool useDefault()
{
	string user_input;
	bool use_default;
	// Default values
	cout << "Default values: Floors: 20, Elevators: 8, Time: 720 iterations or 120 minutes" << endl;

	while (true)
	{
		cout << "Use default settings: Y/N: ";
		cin >> user_input;

		if (toupper(user_input[0]) == 'Y')
		{
			use_default = YES;
			break;
		}
		else if (toupper(user_input[0]) == 'N')
		{
			use_default = NO;
			break;
		}
		else
		{
			cout << "Invalid input." << endl;
			continue;
		}
	}

	if (use_default == YES)
	{
		cout << "Using default settings" << endl << endl;
	}
	else
	{
		cout << "Using custom settings" << endl << endl;
	}

	return use_default;
}


// Display Simulation Building Floor options and set
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
	const int FLOORS_NUMBER = userInputToConstant(userBuildingFloors);
	return FLOORS_NUMBER;
}



// Display Simulation Elevator Number options and set
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
	const int ELEVATORS_NUMBER = userInputToConstant(userElevatorNumber);
	return ELEVATORS_NUMBER;
}

// Display Simulation Sim Times options and set
const int setSimTime(const int FLOORS_NUMBER, const int ELEVATORS_NUMBER)
{
	bool repeat = true;
	string user_input;
	int userSimTime; // for loop iterations

	while (repeat)
	{
		cout << "Please enter simulation time in iterations (60 iterations = 10 minutes): ";
		cin >> user_input;

		for (int i = 0; i < user_input.length(); i++)
		{
			if (!isdigit(user_input[i]))
			{
				cout << "Invalid input." << endl;
				continue;
			}
		}
		userSimTime = stoi(user_input);
		if (userSimTime < 100)
		{
			cout << "A sim time of at least 100 is recommended." << endl;
			cout << "Consider a sim time of " << (FLOORS_NUMBER / ELEVATORS_NUMBER) * 50 << " iterations " 
				<< "or " << (((FLOORS_NUMBER / ELEVATORS_NUMBER) * 50 ) * 10 ) / 60 << " minutes. "
				<< "Ignore: Y/N: ";
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
	const int SIM_TIME = userInputToConstant(userSimTime);
	return SIM_TIME;
}



// Converts user input to a const int
const int userInputToConstant(int user_input)
{
	const int USER_INPUT_CONSTANT = user_input;
	return USER_INPUT_CONSTANT;
}


// Delete elevator vector (dynamic memory)
void deleteVector(vector<Elevator*> discarded_elevators)
{

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

// Delete users vector (dynamic memory)
void deleteVector(vector<User*> discarded_users)
{
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

//Print Elevator Debug Statuses
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
		{   // Warnings will always occur is all elevators have a bad status
			cout << "WARNING: Elevator is going the wrong direction!" << endl;
		}
		else if ((direction == UP) && (elevator_obj->moving_up() == false) && (elevator_obj->is_stationary() == false))
		{
			cout << "WARNING: Elevator is going the wrong direction!" << endl;
		}
	}

}

//Print User Debug Statuses
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


//Pick Random Floor
int randomFloor(int max, int min)
{
	// work-around for divide-by-zero errors
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

//Calculate average waiting time for floor requests
float averageWaitingTime(vector<int>& waiting_times, int& total_users)
{
	if (total_users == 0)
	{
		return 0;
	}

	float sum_of_waiting_times = 0;

	for (int i = 0; i < waiting_times.size(); i++)
	{
		sum_of_waiting_times += waiting_times[i];
	}
	return sum_of_waiting_times / total_users;
}

//Display Simulations Statitstics
void displayStatistics(const int& FLOORS_NUMBER, const int& ELEVATORS_NUMBER, const int& SIM_TIME,
	int& total_users, vector<int>& user_waiting_times)
{
	int time_setting = 10; // 10 seconds per iteration
	float avgWaitTime = averageWaitingTime(user_waiting_times, total_users);

	cout << endl;
	cout << "Simulation complete." << endl;
	cout << "Simulation time: " << SIM_TIME << " iterations or " 
		<< setprecision(2) <<  (SIM_TIME * 10) / 60 << " minutes " << endl;
	cout << "Number of floors: " << FLOORS_NUMBER << endl;
	cout << "Number of elevators: " << ELEVATORS_NUMBER << endl;
	cout << "Total users: " << total_users << endl;
	cout << "Average waiting time: " << avgWaitTime <<
		" iterations or " << setprecision(2) << (avgWaitTime * 10) / 60 << " minute(s)" << endl << endl;
	cout << "*Waiting time refers to the time from a floor request to the elevator arriving to "
		"pick up users." << endl;
}