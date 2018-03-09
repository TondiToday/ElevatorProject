#include "Elevaator.h"
#include <vector>

void customer_input(q_modified & up, q_modified & d);
//void dispacher( q_modified & dup, q_modified & ddown, vector < Elevator> v);
void dispacher(q_modified & dup, q_modified & ddown);

void customer_input2(q_modified & up, q_modified & down, Elevator e);
void customer_input3(q_modified & up, q_modified & down, Elevator e);

q_modified dispach_up;
q_modified dispach_down;
//vector < Elevator> v;
Elevator e1(1);
Elevator e2(10);
Elevator e3(30);
Elevator e4(40);
int main()
{
	
		/*int n, number_floors;
		
		cout << "please enter the number of elevators in the building" << endl;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			Elevator e = new Elevator();
			v.push_back(e);
		}
		cout << "Please enter the number of floors in the building" << endl;
		cin >> number_floors;*/
	
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
