#ifndef _Minheap_H_
#define _Minheap_H_

/*小顶堆类定义*/
template <typename T>
class MinHeap
{
public:
	MinHeap()
	{};
	~MinHeap()
	{};
public:
	bool insert(T val);		//二叉堆中插入元素
	void print();			//打印堆
	void createMinHeap(T a[], int len);//根据指定的数组来创建一个最小堆
	void Delete();

private:
	int capacity;	//容量
	int size;		//插入个数
	T * heap;		//底层的数组
private:
	void filterUp(int index); //从index所在节点，往根节点调整堆
};
#endif // _Minheap_H_