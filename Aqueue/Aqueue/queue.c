#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int front;
	int rear;
	int number;
	int capacity;
	int *date;
}Aqueue;


void Create()
{
	Aqueue.date = (int*)malloc(Aqueue.capacity * sizeof(int));
	Aqueue.front = Aqueue.rear = Aqueue.number = 0;
}

int QueueEmpty()
{
	if (Aqueue.number == 0)	 return 1;
	return 0;
}

void QueueClear()
{
	Aqueue.rear = Aqueue.front;
	Aqueue.number = 0;
}

void QueueEnter(int num)
{
	if (Aqueue.capacity == 1)
	{
		if (Aqueue.number == 0)
		{
			Aqueue.number++;
			Aqueue.date[Aqueue.front] = num;
		}
		else printf("This is full!");
	}
	else if (Aqueue.number < Aqueue.capacity)//�ж϶�����û��
	{
		Aqueue.number++;
		Aqueue.date[Aqueue.rear] = num;
		if (Aqueue.number < Aqueue.capacity)//���˾Ͳ��ټ�������Ųβ��
		{
			Aqueue.rear++;
			if (Aqueue.rear >= Aqueue.capacity)
				Aqueue.rear -= Aqueue.capacity;
		}
	}
	else
	{
		printf("This is full!");
	}
}

void Queueout()
{
	if (QueueEmpty() == 1) printf("This is empty");
	else if (Aqueue.capacity == 1)
	{
		if (Aqueue.number == 1)
		{
			Aqueue.number--;
		}
		else printf("This is empty");
	}
	else if (Aqueue.number > 0)
	{
		Aqueue.number--;
		Aqueue.front++;
		if (Aqueue.front >= Aqueue.capacity) Aqueue.front -= Aqueue.capacity;
		if (Aqueue.front == Aqueue.rear)
			if (Aqueue.rear >= Aqueue.capacity) Aqueue.rear -= (Aqueue.capacity - 1);
			else  Aqueue.rear++;
	}
}

void Getfront()
{
	if (QueueEmpty() == 1)printf("This is empty");
	else if (Aqueue.capacity == 1)
	{
		if (Aqueue.number == 1)
			printf("%d", Aqueue.date[Aqueue.front]);
	}
	else
		printf("%d", Aqueue.date[Aqueue.front]);
}

void Getall()
{
	for (int i = 0; i<Aqueue.number; i++)
	{
		if (i + Aqueue.front >= Aqueue.capacity)
			printf("%d ", Aqueue.date[i + Aqueue.front - Aqueue.capacity]);
		else
			printf("%d ", Aqueue.date[i + Aqueue.front]);
	}
}

void Destroy()
{
	free(Aqueue.date);
}

int main()
{

	int cho = 1;
	printf("�㴴�����е�������\n");
	scanf_s("%d", &Aqueue.capacity);
	Create();
	while (cho != 0)
	{
		printf("\n");
		printf("��ѡ���� 1.���� 2.���� 3.ȡͷ 4.���� 0.���ٽ���\n");
		scanf_s("%d", &cho);
		switch (cho)
		{
		case 1:
		{
			int num;
			scanf_s("%d", &num);
			QueueEnter (num);
		}
		break;
		case 2:
		{
			Queueout();
		}
		break;
		case 3:
		{
			Getfront();
		}
		break;
		case 4:
		{
			Getall();
		}
		break;
		case 0:
			Destroy();
			break;
		}
	}
}