#include "Modified_q.h"
#include "Utilities.h"

q_modified::q_modified()
{
	size = 0;
}

//Gets the size of the modified q
int q_modified::getsize()
{
	return size;
}

//Returns whether the modified q is empty
bool q_modified::isempty()
{

	return (front == NULL);
}

//add element to a UP modified q
void q_modified::push_up(vector<int> x)
{
	if (isempty())
	{
		front = new node(x, NULL);
		back = front;
		size++;
		return;

	}
	if (!isempty())
	{
		if (front->data[0] == x[0] || back->data[0] == x[0]) // to avoid duplicates in the queue
		{

		}
		else if (front->data[0] > x[0])// to add node before the front node
		{
			node *insert = new node(x, front);
			front = insert;
			size++;
		}
		else if (back->data[0] < x[0]) // to add node after the back node
		{
			node * insert = new node(x, NULL);
			back->next = insert;
			back = insert;
			size++;

		}
		else // to add node between the front and back node
		{
			node * insert = front;
			while (insert->next != NULL)
			{
				if (insert->data[0] == x[0])
				{
					return;
				}
				if (insert->data[0] < x[0])
				{
					node * add = new node(x, insert->next);
					insert->next = add;
					size++;
					return;
				}
				insert = insert->next;
			}
		}

	}

}

//add element to a DOWN modified q
void q_modified::push_down(vector<int> x)
{
	if (isempty())
	{
		front = new node(x, NULL);
		back = front;
		size++;
	}
	else if (!isempty())
	{
		if (front->data[0] == x[0] || back->data[0] == x[0]) // to avoid duplicates in the queue
		{
			return;
		}
		else if (front->data < x) // to add node before the front node
		{
			node * insert = new node(x, front);
			front = insert;
			size++;
		}
		else if (back->data > x) // to add node after the back node
		{
			node * insert = new node(x, NULL);
			back->next = insert;
			back = insert;
			size++;
		}
		else // to add node between the front and the back node
		{
			node * insert = front;
			while (insert->next != NULL)
			{
				if (insert->data == x)
				{
					return;
				}

				else
				{
					node *in = new node(x, insert->next);
					insert->next = in;
					size++;
					return;
				}
				insert->next = insert;
				
			}
		}

	}

}

//Print the content of a modified q
int q_modified::print()
{
	if (!isempty())
	{
		vector<int> x;
		node * pr = front;
		while (pr != NULL)
		{
			if (DEBUG == YES)
			{
				cout << " \t\t We are on floor  " << pr->data[0] << endl;
			}
			x = pr->data;
			pr = pr->next;


		}
		return x[0];

	}

}


//Remove all the elements of a modified q
void q_modified::pop()
{
	while (front != NULL)
	{
		node *pt = front;
		size--;
		front = front->next;
		delete pt;
	}

}

//Returns the back value of the modified queue
vector<int> q_modified::back_value()
{
	if (!isempty())
	{
		return back->data;
	}
	else
	{
		vector<int> temp = { 0, -1, -1 };
		return temp;
	}
}

//Returns the front value of the modified queue
vector<int> q_modified::front_value()
{
	if (!isempty())
	{
		return front->data;
	}
	if (isempty())
	{
		vector<int> temp = { 0, -1, -1 };
		return temp;
	}

}

//Removes the front value of the modified q
void q_modified::pop_front()
{
	if (!isempty())
	{
		node * pt = front;
		size--;
		front = front->next;
		delete pt;
	}
}