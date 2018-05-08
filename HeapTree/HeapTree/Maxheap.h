#ifndef _Maxheap_H_
#define _Maxheap_H_
/*大顶堆类定义*/
template <typename T>
class MaxHeap
{
public:
	MaxHeap()
	{};
	~MaxHeap()
	{};
public:
	bool insert(T val);		//插入元素
	void print();			//打印堆	
	void createMaxHeap(T a[], int len);//根据指定的数组来创建一个最大堆
	void Delete();

private:
	int capacity;	//容量
	int size;		//插入个数
	T * heap;		//底层的数组
private:
	void filterUp(int index); //从index所在节点，往根节点调整堆

};

#endif // _Maxheap_H_
