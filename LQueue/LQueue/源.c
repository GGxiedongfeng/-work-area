#include<stdio.h>
#include<stdlib.h>

 struct queue
 {					
		int date;
		struct queue  *next1, *next2;
} *front,*rear;

 int number;
	

void Create()//����������
{	 
	front = rear =(struct queue*)malloc(sizeof(struct queue));//������ͷָ��λ��	 
	front->next1 = NULL;
}

int QueueEmpty()
{
	if (number == 0)	 return 1;
	return 0;
}

void QueueClear()
{
	number = 0;
	struct queue *p1, *p2;
	p2 = p1 = front;
	for (; p2->next1 != NULL;)
	{
		p2 = p1->next1;//������һ���ռ�
		free (p1);//ɾ����һ���ռ�
		p1 = p2;//ָ��ͬһ���ռ�ȴ���һ�ε��ƶ�
	}
	front = rear=p2;
	
}

void QueueEnter(int num)
{
	number++;
	struct queue *p;
	rear->date = num;
	p = rear->next1 = (struct queue*)malloc(sizeof(struct queue));
	p->next2 = rear;
	p->next1 = NULL;
	rear = p;
}

void Queueout()
{
	if (number==0)  printf("This is empty");
	else
	{
		number--;
		struct queue *p;
		p = front;
		front = p->next1;
		free(p);
	}
}
void Getfront()
{
	if (QueueEmpty() == 1)printf("This is empty");
	else
	printf("%d", front->date);
}

void Getall()
{
	struct queue *p;
	if (QueueEmpty() == 1)printf("This is empty");
	else 
		for (p = front; p->next1 != NULL; p = p->next1) 
			printf("%d ", p->date);
}

void Destory()
{
	struct queue *p1, *p2;
	p2 = p1 = front;
	for (; p2->next1 != NULL;)
	{
		p2 = p1->next1;//������һ���ռ�
		free(p1);//ɾ����һ���ռ�
		p1 = p2;//ָ��ͬһ���ռ�ȴ���һ�ε��ƶ�
	}
	free(p2);
	front = NULL;
}

int main()
{

	int cho = 1;
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
			QueueEnter(num);
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
			Destory();
			break;
		}
	}
	return 0;
}