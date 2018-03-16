#include "Modified_q.h"
#include "Utilities.h"

q_modified::q_modified()
{
	size = 0;
}
int q_modified::getsize()
{
	return size;
}
bool q_modified::isempty()
{

	return (front == NULL);
}
void q_modified::push_up(int x)
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
		if (front->data == x || back->data == x) // to avoid duplicates in the queue
		{

		}
		else if (front->data > x)// to add node before the front node
		{
			node *insert = new node(x, front);
			front = insert;
			size++;
		}
		else if (back->data < x) // to add node after the back node
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
				if (insert->data == x)
				{
					return;
				}
				if (insert->data < x)
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
void q_modified::push_down(int x)
{

	if (isempty())
	{
		front = new node(x, NULL);
		back = front;
		size++;
	}
	else if (!isempty())
	{
		if (front->data == x || back->data == x) // to avoid duplicates in the queue
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
			while (insert != NULL)
			{
				if (insert->data == x)
				{
					return;
				}
				else if (insert->next->data < x)
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
int q_modified::print()
{
	
		int x;
		node * pr = front;
		while (pr != NULL)
		{
			if (DEBUG == YES)
			{
				cout << " \t\t We are on floor  " << pr->data << endl;
			}
			x = pr->data;
			pr = pr->next;


		}
		return x;

	

}
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
int q_modified::back_value()
{
	if (!isempty())
	{
		return back->data;
	}
}
int q_modified::front_value()
{
	if (!isempty())
	{
		return front->data;
	}
	if (isempty())
	{
		return 0;
	}

}


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