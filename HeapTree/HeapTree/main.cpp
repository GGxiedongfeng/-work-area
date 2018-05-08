#include<iostream>
#include"Maxheap.h"
#include"Minheap.h"
using namespace std;
/****************��С��********************/
/*ɾ��*/
template <typename T>
void MinHeap<T>::Delete()
{
	delete[]heap;
}

/*��ӡС����*/
template <typename T>
void MinHeap<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << heap[i] << " ";
}

/*����Ԫ��*/
template <typename T>
bool MinHeap<T>::insert(T val)
{
	if (size == capacity) //��������������򷵻�false
		return false;
	heap[size] = val;
	filterUp(size);
	size++;
	return true;
}
/*���µ��ϵ�����*/
/*����Ԫ��ʱ��ʹ��*/
template <typename T>
void MinHeap<T>::filterUp(int index)
{
	T value = heap[index];	//����ڵ��ֵ

	while (index > 0) //�����δ������ڵ㣬��������
	{
		int indexParent = (index - 1) / 2;  //����˫�׽ڵ�
		if (value >= heap[indexParent])
			break;
		else
		{
			heap[index] = heap[indexParent];
			index = indexParent;
		}
	}
	heap[index] = value;	//��������λ��
}

/*����ָ��������������һ����С��*/
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


/****************����********************/

/*ɾ��*/
template <typename T>
void MaxHeap<T>::Delete()
{
	delete[]heap;
}

/*��ӡ�󶥶�*/
template <typename T>
void MaxHeap<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << heap[i] << " ";
}

/*����Ԫ��*/
template <typename T>
bool MaxHeap<T>::insert(T val)
{
	if (size == capacity) //��������������򷵻�false
		return false;
	heap[size] = val;
	filterUp(size);
	size++;
	return true;
}
/*���µ��ϵ�����*/
/*����Ԫ��ʱ��ʹ��*/
template <typename T>
void MaxHeap<T>::filterUp(int index)
{
	T value = heap[index];	//����ڵ��ֵ

	while (index > 0) //�����δ������ڵ㣬��������
	{
		int indexParent = (index - 1) / 2;  //����˫�׽ڵ�
		if (value< heap[indexParent])
			break;
		else
		{
			heap[index] = heap[indexParent];
			index = indexParent;
		}
	}
	heap[index] = value;	//��������λ��
};

/*����ָ��������������һ������*/
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
		cout << "Ҫ�������鳤�ȣ�0�˳�����" << endl;
		cin >> len;
		if (len == 0) break;
		int *num = new int[len];
		cout << "���������飺" << endl;
		for (int i = 0; i < len; i++)
			cin >> num[i];
		MinHeap <typename int> Tree1;
		Tree1.createMinHeap(num, len);
		cout << "��С��(�����)��" << endl;
		Tree1.print();
		cout << endl;
		Tree1.Delete();
		MaxHeap <typename int> Tree2;
		Tree2.createMaxHeap(num, len);
		cout << "����(�����)��" << endl;
		Tree2.print();
		cout << endl;
		Tree2.Delete();
		delete(num);
	}
}