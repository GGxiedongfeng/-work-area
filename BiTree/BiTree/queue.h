#ifndef _Queue_H_
#define _Queue_H_
#include"BinaryTree.h"

class queue
{
public:
	queue()
	{};
	~queue()
	{};
	void Create(int len);
	int Empty();
	void Push(BiTNode num);
	void Pop();
	BiTNode Front();
	void Destroy();
private:
	int front;
	int rear;
	int number;
	int capacity;
	BiTNode *date;
};



#endif // !_Queue_H_

