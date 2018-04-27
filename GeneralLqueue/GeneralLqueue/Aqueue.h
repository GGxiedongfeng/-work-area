#ifndef _QUEUE_H_
#define _QUEUE_H_I

typedef struct Aqueue
{
	void *data[10];  	//������
	int front;
	int rear;
	size_t data_size;		//�������ڴ��С
} AQueue;  


typedef enum
{
	FLASE = 0, TRUE = 1
} Status;//bool;

void InitAQueue(AQueue *Q);
void DestoryAQueue(AQueue *Q);
Status IsFullAQueue(const AQueue *Q);
Status IsEmptyAQueue(const AQueue *Q);
Status EnAQueue(AQueue *Q, void *data);
Status DeAQueue(AQueue *Q);
Status GetHeadAQueue(AQueue *Q, void **e);
int LengthAQueue(AQueue *Q);
void ClearAQueue(AQueue *Q);
Status TraverseAQueue(const AQueue *Q, void(*foo)(void *q));//q����������APrint
void* APrint(void *q);
#endif;