// pqueue.cpp

#include "PQueue.h"
#include <iostream>
#include "Job.h"

using namespace std;

P_Queue::P_Queue()
{
	heap = new ItemType[10];
	size = 0;
	capacity = 10;
}

P_Queue::P_Queue(int capacity)
{
	heap = new ItemType[capacity];
	size = 0;
	this->capacity = capacity;
}

int P_Queue::length()
{
	return size;
}

ItemType& P_Queue::getHighest()
{
	// if size==0 
	return heap[0];
}

void P_Queue::addItem(const ItemType & item)
{
	heap[size] = item;
	int i, parent;
	i = size;
	parent = (size - 1) / 2;
	while (heap[parent]>heap[i] && parent >= 0)// parent or i >0 
	{
		swap(heap[parent], heap[i]);
		i = parent;
		parent = (i - 1) / 2;
	}
	size++;
}

int P_Queue::getSize()
{
	return size;
}

bool P_Queue::empty()
{
	return size == 0;
}

void P_Queue::removeHighest()
{
	if (size == 1)
	{
		//heap[0]=NULL;
		size--;
	}
	else
	{
		heap[0] = heap[size - 1];
		int i = 0;
		bool finish = false;
		bool Swap = true;
		while (!finish&&Swap)
		{
			Swap = false;
			if (2 * i + 2 >= size)
			{
				if (2 * i + 1 >= size)
				{
					finish = true;
				}
				else
				{
					if (heap[2 * i + 1]<heap[i])
					{
						swap(heap[2 * i + 1], heap[i]);
					}
					finish = true;
				}

			}
			else
			{
				if (heap[2 * i + 1] <= heap[2 * i + 2])
				{
					if (heap[i]>heap[2 * i + 1])
					{
						swap(heap[i], heap[2 * i + 1]);
						i = 2 * i + 1;
						Swap = true;
					}
				}
				else if (heap[2 * i + 1]>heap[2 * i + 2])
				{
					if (heap[i]>heap[2 * i + 2])
					{
						swap(heap[i], heap[2 * i + 2]);
						i = 2 * i + 2;
						Swap = true;
					}
				}//i conditon degisikligi
			}
			i++;
		}
		size--;
	}
}

void P_Queue::display()
{
	for (int i = 0; i<size; i++)
	{
		cout << heap[i].getId() << " " << heap[i].getPriority() << "" << heap[i].getHour();
	}
}

ostream& operator<<(ostream& os, const P_Queue& q)
{
	for (int i = 0; i<q.size; i++)
	{
		os << q.heap[i].getHour() << "  " << q.heap[i].getPriority() << "  " << q.heap[i].getId() << endl;
	}
	return os;
}

void P_Queue::swap(ItemType& first, ItemType& second)
{
	ItemType temp;
	temp = first;
	first = second;
	second = temp;
}

P_Queue::P_Queue(const P_Queue &obj)
{
	// pre condition check
	size = obj.size;
	capacity = obj.capacity;
	heap = new ItemType[obj.capacity];
	for (int i = 0; i<obj.size; i++)
	{
		heap[i] = obj.heap[i];
	}
}	

P_Queue::~P_Queue()
{
	delete[] heap;
}

P_Queue& P_Queue::operator=(const P_Queue &obj)
{
	// condition check
	delete[] heap;
	size = obj.size;
	capacity = obj.capacity;
	heap = new ItemType[obj.capacity];
	for (int i = 0; i<obj.size; i++)
	{
		heap[i] = obj.heap[i];
	}
	return *this;
}