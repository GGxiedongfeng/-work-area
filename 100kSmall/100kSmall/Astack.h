#ifndef _STACK_H_
#define _STACK_H_

class AStack {
public:
	AStack()
	{
	};
	~AStack()
	{
	};
	void InitStack();
	bool isEmpty();
	void Push(int val);
	void Pop();
	int Top() const;
	void DestroyStack();
	void IncreaseCapacity();

private:
	int *data;
	int size;
	int capacity;
};



void AStack::InitStack()
{
	capacity = 10000;
	data = new int[10000];
	size = -1;
}

bool AStack::isEmpty()
{
	if (size == -1)
		return true;
	else
		return false;
}

void AStack::Push(int val)
{
	if (size == (capacity - 1))
	{
		IncreaseCapacity();
		capacity += 10000;
	}
	size++;
	data[size] = val;
}

void AStack::Pop()
{
	if (size != -1)
		size--;
}

int AStack::Top()const
{
	if (size == -1)
		return -1;
	else
		return data[size];
}

void AStack::DestroyStack()
{
	delete data;
	data = NULL;
}

void AStack::IncreaseCapacity()
{
	int *newplease = NULL;
	newplease = new int[capacity + 1000];
	int i;
	for (i = 0; i < capacity; i++)
		newplease[i] = data[i];
	delete data;
	data = newplease;
}

#endif

