#include<iostream>
#include"Maxheap.h"
#include"Minheap.h"
using namespace std;
/****************最小堆********************/
/*删除*/
template <typename T>
void MinHeap<T>::Delete()
{
	delete[]heap;
}

/*打印小顶堆*/
template <typename T>
void MinHeap<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << heap[i] << " ";
}

/*插入元素*/
template <typename T>
bool MinHeap<T>::insert(T val)
{
	if (size == capacity) //如果数组已满，则返回false
		return false;
	heap[size] = val;
	filterUp(size);
	size++;
	return true;
}
/*从下到上调整堆*/
/*插入元素时候使用*/
template <typename T>
void MinHeap<T>::filterUp(int index)
{
	T value = heap[index];	//插入节点的值

	while (index > 0) //如果还未到达根节点，继续调整
	{
		int indexParent = (index - 1) / 2;  //求其双亲节点
		if (value >= heap[indexParent])
			break;
		else
		{
			heap[index] = heap[indexParent];
			index = indexParent;
		}
	}
	heap[index] = value;	//插入最后的位置
}

/*根据指定的数组来创建一个最小堆*/
template<typename T>
void MinHeap<T>::createMinHeap(T a[], int len)
{
	capacity = len;
	size = 0;
	heap = new T[capacity];
	for (int i = 0; i < len; i++)
	{
		insert(a[i]);
	}
}


/****************最大堆********************/

/*删除*/
template <typename T>
void MaxHeap<T>::Delete()
{
	delete[]heap;
}

/*打印大顶堆*/
template <typename T>
void MaxHeap<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << heap[i] << " ";
}

/*插入元素*/
template <typename T>
bool MaxHeap<T>::insert(T val)
{
	if (size == capacity) //如果数组已满，则返回false
		return false;
	heap[size] = val;
	filterUp(size);
	size++;
	return true;
}
/*从下到上调整堆*/
/*插入元素时候使用*/
template <typename T>
void MaxHeap<T>::filterUp(int index)
{
	T value = heap[index];	//插入节点的值

	while (index > 0) //如果还未到达根节点，继续调整
	{
		int indexParent = (index - 1) / 2;  //求其双亲节点
		if (value< heap[indexParent])
			break;
		else
		{
			heap[index] = heap[indexParent];
			index = indexParent;
		}
	}
	heap[index] = value;	//插入最后的位置
};

/*根据指定的数组来创建一个最大堆*/
template<typename T>
void MaxHeap<T>::createMaxHeap(T a[], int len)
{
	capacity = len;
	size = 0;
	heap = new T[capacity];
	for (int i = 0; i < len; i++)
	{
		insert(a[i]);
	}
}


int main()
{
	int len;
	while (1)
	{
		cout << "要输入数组长度（0退出）：" << endl;
		cin >> len;
		if (len == 0) break;
		int *num = new int[len];
		cout << "请输入数组：" << endl;
		for (int i = 0; i < len; i++)
			cin >> num[i];
		MinHeap <typename int> Tree1;
		Tree1.createMinHeap(num, len);
		cout << "最小堆(层输出)：" << endl;
		Tree1.print();
		cout << endl;
		Tree1.Delete();
		MaxHeap <typename int> Tree2;
		Tree2.createMaxHeap(num, len);
		cout << "最大堆(层输出)：" << endl;
		Tree2.print();
		cout << endl;
		Tree2.Delete();
		delete(num);
	}
}