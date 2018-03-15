#ifndef MODIFIEDQ_H
#define MODIFIEDQ_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;


struct node
{
	int data;// data stored in the node
	node * next; // pointer to point to the next node
	node(int x, node *y) { data = x; next = y; }// default constructior
};
class q_modified
{
protected:

	int size;// size of the queue that is number of requests made and which are waiting to be executed
	node * front;// pointer to point to the front of the queue
	node * back;// pointer to point to the back of the queue

public:

	int getsize(); // to get the nuumber of orders stored in the queue
	bool isempty();// to check if the queue is empty or not
	void push_up(int x);// to store requestes in increasing order (1,2,3,4,5)
	void push_down(int x);// to store requestes in decreasing order (5,4,,3,2,1)
	int print();// print out the stored data in the increasing queue 
	int front_value();// to return the front value of the queue
	int back_value(); // to return the back value of the queue
	void pop();// to remove all the element from the queue
	void pop_front();// to remove a node from the front of the queue
	q_modified();
};



#endif 