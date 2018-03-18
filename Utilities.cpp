#include "Utilities.h"
#include "Modified_q.h"
#include "User.h"


bool DEBUG; // global debug variable

// Set whether debug statements are displayed
void setDebug() 
{
	DEBUG = true;
	/*
	string user_answer;

	while (true)
	{
		cout << "Display debug statements: Y/N: ";
		cin >> user_answer;

		if (toupper(user_answer[0]) == 'Y')
		{
			DEBUG = true;
			break;
		}
		else if (toupper(user_answer[0]) == 'N')
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
		return rand() % max;
	}
	else
	{
		if (rand() % ((max + 1) - min) + min > max) {
			return max - 1;
		}
		else{
			return rand() % ((max + 1) - min) + min;
		};

	}

}

double averageWaitingTime(vector<int>& waiting_times, int& total_users)
{
	double sum_of_waiting_times = 0;

	for (int i = 0; i < waiting_times.size(); i++)
	{
		sum_of_waiting_times += waiting_times[i];
	}
	return sum_of_waiting_times / total_users;
}

