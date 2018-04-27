# include<stdio.h>
# include<stdlib.h>
# include"Aqueue.h"

void InitAQueue(AQueue *Q)//��ʼ��
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


void DestoryAQueue(AQueue *Q)//���ٶ���
{
	if (*Q->data != NULL)
		free(Q->data);
	Q->front = Q->rear = 0;
	free(Q);
}

Status IsFullAQueue(const AQueue *Q)//��������
{
	if (Q->front == Q->rear && *Q->data != NULL)
		return TRUE;
	else
		return FLASE;
}

Status IsEmptyAQueue(const AQueue *Q)//���пգ�
{
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FLASE;
}


Status GetHeadAQueue(AQueue *Q, void**e)//ȡͷ
{
	if (Q->front == Q->rear)
		return FLASE;
	else
	{
		*e = Q->data[Q->front];
		return TRUE;
	}
}

int LengthAQueue(AQueue *Q)//����
{
	return (Q->rear - Q->front + 10) % 10;
}


Status EnAQueue(AQueue *Q, void *data)//����
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

Status DeAQueue(AQueue *Q)//����
{
	if (Q->front == Q->rear)
		return FLASE;
	else
		Q->front = (Q->front + 1) % 10;
	return TRUE;
}

void ClearAQueue(AQueue *Q)//�������
{
	Q->front = Q->rear = 0;
}


Status TraverseAQueue(const AQueue *Q, void(*foo)(void *q))//����
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

void *APrint(void *q)//���
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
	int sign;//ѡ������
	void *e = NULL;
	AQueue * Q = (AQueue *)malloc(sizeof(AQueue));
	InitAQueue(Q);
	char temp[10];
	int temp1[10];
	int i = 0;
	int choose = 1;
	while (choose != 0)
	{
		printf("0�����ٶ��в��˳� 1�������Ƿ�Ϊ�� 2����� 3������ 4��ȡ���е�ͷԪ�� 5����ն��� 6�����г��� 7����������\n");
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 0:break;
		case 1:
		{
			if (IsEmptyAQueue(Q) == TRUE)
				printf("����Ϊ��\n");
			else
			{
				printf("���в�Ϊ��\n");
			}
		}break;
		case 2:
		{
			if (IsEmptyAQueue(Q) == TRUE)
			{
				printf("����Ϊ��\n");

			}
			else if (IsFullAQueue(Q) == TRUE)
			{
				printf("This is full.\n");
				exit(-1);
			}
			if (n == 0)
			{
				printf("��ѡ����Ҫ�洢���������ͣ� ����ѡ��1�� �ַ���ѡ��2\n");
				scanf_s("%d", &n);
			}
			switch (n)
			{
			case 1:
			{
				sign = 1;
				printf("����������Ҫ��ӵ�Ԫ��\n");
				scanf_s("%d", &temp1[i]);
				EnAQueue(Q, &temp1[i]);
				printf("��ӳɹ�\n");
				i++;
				break;
			}
			case 2:
			{
				sign = 2;
				printf("����������Ҫ��ӵ�Ԫ��\n");
				scanf_s("%s", &temp[i]);
				EnAQueue(Q, &temp[i]);
				printf("��ӳɹ�\n");
				i++;
				break;
			}
			default:
			{
				printf("����������");
				exit(-1);
				break;
			}
			}
		}break;
		case 3:
		{
			if (IsEmptyAQueue(Q) == TRUE)
			{
				printf("����Ϊ��\n");
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
				printf("����Ϊ��\n");
				return;
			}
			if (sign == 1)
			{
				GetHeadAQueue(Q, &e);
				int * a = (int *)e;
				int number = *a;
				printf("ͷԪ��:%d\n", number);
			}
			else if (sign == 2)
			{
				GetHeadAQueue(Q, &e);
				(char*)e;
				printf("ͷԪ��:%s\n", e);
			}
		}break;
		case 5:
		{
			ClearAQueue(Q);
			printf("��ճɹ�\n");
		}
		break;
		case 6:
		{
			if (IsEmptyAQueue(Q) == TRUE)
			{
				printf("����Ϊ��\n");
				return;
			}
			int sum = LengthAQueue(Q);
			printf("�ɹ��õ�����:%d\n", sum);
		}break;
		case 7:
		{
			if (IsEmptyAQueue(Q) == TRUE)
			{
				printf("����Ϊ��\n");
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