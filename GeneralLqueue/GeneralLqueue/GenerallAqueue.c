# include<stdio.h>
# include<stdlib.h>
# include"Aqueue.h"

void InitAQueue(AQueue *Q)//初始化
{
	*Q->data = (void *)malloc(sizeof(void*));
	if (*Q->data == NULL)
		return;
	else
		Q->rear = 0;
	Q->front = 0;
	Q->data_size = 10;
	return;
}


void DestoryAQueue(AQueue *Q)//销毁队列
{
	if (*Q->data != NULL)
		free(Q->data);
	Q->front = Q->rear = 0;
	free(Q);
}

Status IsFullAQueue(const AQueue *Q)//队列满？
{
	if (Q->front == Q->rear && *Q->data != NULL)
		return TRUE;
	else
		return FLASE;
}

Status IsEmptyAQueue(const AQueue *Q)//队列空？
{
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FLASE;
}


Status GetHeadAQueue(AQueue *Q, void**e)//取头
{
	if (Q->front == Q->rear)
		return FLASE;
	else
	{
		*e = Q->data[Q->front];
		return TRUE;
	}
}

int LengthAQueue(AQueue *Q)//长度
{
	return (Q->rear - Q->front + 10) % 10;
}


Status EnAQueue(AQueue *Q, void *data)//入列
{
	if ((Q->rear + 1) % 10 == Q->front)
	{
		printf("This is full");
		exit(-1);
	}
	else
	{
		Q->data[Q->rear] = data;
		Q->rear = (Q->rear + 1) % 10;
		return TRUE;
	}

}

Status DeAQueue(AQueue *Q)//出列
{
	if (Q->front == Q->rear)
		return FLASE;
	else
		Q->front = (Q->front + 1) % 10;
	return TRUE;
}

void ClearAQueue(AQueue *Q)//清除数据
{
	Q->front = Q->rear = 0;
}


Status TraverseAQueue(const AQueue *Q, void(*foo)(void *q))//遍历
{
	if (Q->front == Q->rear)
		return FLASE;
	int i;
	i = Q->front;
	while (i != Q->rear)
	{
		(*foo)(Q->data[i]);
		i = (i + 1) % 10;
	}
	return FLASE;
}

void *APrint(void *q)//输出
{
	int *a;
	a = (int *)q;
	int number = *a;
	if (number > 10000000)
	{
		(char *)q;
		printf("%s<-", q);
		return;
	}
	printf("%d<-", number);
	return;
}

void main()
{
	int mark = 0; int n=0;
	int sign;//选择类型
	void *e = NULL;
	AQueue * Q = (AQueue *)malloc(sizeof(AQueue));
	InitAQueue(Q);
	char temp[10];
	int temp1[10];
	int i = 0;
	int choose = 1;
	while (choose != 0)
	{
		printf("0、销毁队列并退出 1、队列是否为空 2、入队 3、出队 4、取队列的头元素 5、清空队列 6、队列长度 7、遍历队列\n");
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 0:break;
		case 1:
		{
			if (IsEmptyAQueue(Q) == TRUE)
				printf("队列为空\n");
			else
			{
				printf("队列不为空\n");
			}
		}break;
		case 2:
		{
			if (IsEmptyAQueue(Q) == TRUE)
			{
				printf("队列为空\n");

			}
			else if (IsFullAQueue(Q) == TRUE)
			{
				printf("This is full.\n");
				exit(-1);
			}
			if (n == 0)
			{
				printf("请选择需要存储的数据类型， 整型选择1， 字符型选择2\n");
				scanf_s("%d", &n);
			}
			switch (n)
			{
			case 1:
			{
				sign = 1;
				printf("请输入你需要入队的元素\n");
				scanf_s("%d", &temp1[i]);
				EnAQueue(Q, &temp1[i]);
				printf("入队成功\n");
				i++;
				break;
			}
			case 2:
			{
				sign = 2;
				printf("请输入你需要入队的元素\n");
				scanf_s("%s", &temp[i]);
				EnAQueue(Q, &temp[i]);
				printf("入队成功\n");
				i++;
				break;
			}
			default:
			{
				printf("操作不存在");
				exit(-1);
				break;
			}
			}
		}break;
		case 3:
		{
			if (IsEmptyAQueue(Q) == TRUE)
			{
				printf("队列为空\n");
			}
			else
			{
				DeAQueue(Q);
			}
		}break;
		case 4:
		{
			if (IsEmptyAQueue(Q) == TRUE)
			{
				printf("队列为空\n");
				return;
			}
			if (sign == 1)
			{
				GetHeadAQueue(Q, &e);
				int * a = (int *)e;
				int number = *a;
				printf("头元素:%d\n", number);
			}
			else if (sign == 2)
			{
				GetHeadAQueue(Q, &e);
				(char*)e;
				printf("头元素:%s\n", e);
			}
		}break;
		case 5:
		{
			ClearAQueue(Q);
			printf("清空成功\n");
		}
		break;
		case 6:
		{
			if (IsEmptyAQueue(Q) == TRUE)
			{
				printf("队列为空\n");
				return;
			}
			int sum = LengthAQueue(Q);
			printf("成功得到总数:%d\n", sum);
		}break;
		case 7:
		{
			if (IsEmptyAQueue(Q) == TRUE)
			{
				printf("队列为空\n");
				return;
			}
			else
			{
				TraverseAQueue(Q, APrint(Q));
			}
		}break;
		}
	}
}