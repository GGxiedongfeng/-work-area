#include<iostream>
#include<string>
#include"queue.h"
#include"BinaryTree.h"



void queue::Create(int len)
{
	capacity = len;
	date = new BiTNode[capacity];
	front = rear = number = 0;
}

int queue::Empty()
{
	if (number == 0)	 return 1;
	return 0;
}

void queue::Push(BiTNode num)
{
	if (capacity == 1)
	{
		if (number == 0)
		{
			number++;
			date[front] = num;
		}
		else return;
	}
	else if (number < capacity)//判断队列满没有
	{
		number++;
		date[rear] = num;
		if (number < capacity)//满了就不再继续往后挪尾部
		{
			rear++;
			if (rear >= capacity)
				rear -= capacity;
		}
	}
	else
	{
		return;
	}
}

void queue::Pop()
{
	if (Empty() == 1) return;
	else if (capacity == 1)
	{
		if (number == 1)
		{
			number--;
		}
		else return;
	}
	else if (number > 0)
	{
		number--;
		front++;
		if (front >= capacity) front -= capacity;

	}
}

BiTNode queue::Front()
{
	if (capacity == 1)
	{
		if (number == 1)
			return  date[front];
	}
	else
		return  date[front];
}

void queue::Destroy()
{
	delete date;
}
