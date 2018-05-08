#ifndef _Maxheap_H_
#define _Maxheap_H_
/*�󶥶��ඨ��*/
template <typename T>
class MaxHeap
{
public:
	MaxHeap()
	{};
	~MaxHeap()
	{};
public:
	bool insert(T val);		//����Ԫ��
	void print();			//��ӡ��	
	void createMaxHeap(T a[], int len);//����ָ��������������һ������
	void Delete();

private:
	int capacity;	//����
	int size;		//�������
	T * heap;		//�ײ������
private:
	void filterUp(int index); //��index���ڽڵ㣬�����ڵ������

};

#endif // _Maxheap_H_
