#ifndef _Minheap_H_
#define _Minheap_H_

/*С�����ඨ��*/
template <typename T>
class MinHeap
{
public:
	MinHeap()
	{};
	~MinHeap()
	{};
public:
	bool insert(T val);		//������в���Ԫ��
	void print();			//��ӡ��
	void createMinHeap(T a[], int len);//����ָ��������������һ����С��
	void Delete();

private:
	int capacity;	//����
	int size;		//�������
	T * heap;		//�ײ������
private:
	void filterUp(int index); //��index���ڽڵ㣬�����ڵ������
};
#endif // _Minheap_H_