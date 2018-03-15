#include "ElevatorOperations.h"
#include "Elevator.h"



void elevator_op(vector<Elevator*> &v, const int& number_of_floors)
{
	vector<Elevator*>::iterator el;
	for (el = v.begin(); el != v.end(); ++el)
	{

		if ((*el)->ele_up.getsize() != 0)
		{

			cout << "\t\t Elevator " << (*el)->get_name() << endl;

			(*el)->up_stops();
			customer_input2((*el)->ele_up, (*el)->ele_down, *(*el));

			//
			//
			// We need to generate new User objects here
			//
			//

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
			customer_input2((*el)->ele_up, (*el)->ele_down, *(*el));
			
			//
			//
			// We need to generate new User objects here
			//
			//

			cout << "\t\t Elevator " << (*el)->get_name() << endl;
			(*el)->down_stops();
			if ((*el)->ele_up.getsize() != 0)
			{
				(*el)->up_stops();
			}

		}
	}
}



/*
void dispacher(q_modified & up, q_modified & d, int floor, vector <Elevator*> &v, int n_elevators)
{
for (int i = 0; i < n_elevators; i++)
{
int k = 0;

while (up.getsize() != 0 && k < floor)
{

if (((v[i]->get_level() + k == up.front_value()) || (v[i]->get_level() == up.front_value() + k)) && (k < 15))
{
if (v[i]->get_level() <= up.front_value())
{

v[i]->ele_up.push_up(up.front_value());
up.pop_front();
}

else if (v[i]->get_level() >= up.front_value())
{
v[i]->ele_down.push_down(up.front_value());
up.pop_front();

}
}
k++;
}

}


int j = 0;
while (d.getsize() != 0)
{
for (int i = 0; i < n_elevators; i++)
{



if ((v[i]->get_level() + j == d.front_value()) || (v[i]->get_level() == d.front_value() + j))
{
if (v[i]->get_level() <= d.front_value())
{

v[i]->ele_down.push_down(d.front_value());
d.pop_front();
}

else if (v[i]->get_level() >= d.front_value())
{
v[i]->ele_down.push_up(d.front_value());
d.pop_front();

}
}
}
j++;

}
}*/



/*
void customer_input(q_modified & dispach_up, q_modified & dispach_down)

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
cin >> dir >> floor;

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
*/


void customer_input2(q_modified & up, q_modified & down, Elevator &e)

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
			return;
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

/*void customer_input3(q_modified & up, q_modified & down, Elevator e)

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
/*
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


}*/
