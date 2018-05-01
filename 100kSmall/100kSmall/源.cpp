#include<iostream>
#include<time.h>
#include<fstream>
#include"arithmetic.h"
#include"Astack.h"

using namespace std;

void InsertSort(int **num, int len)//��������
{
	for (int i = 1; i < len; i++)
	{
		int tem, pos = 0;
		tem = (*num)[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (tem < (*num)[j])//�����ڲ�������������
			{
				(*num)[j + 1] = (*num)[j];
			}
			else
			{
				pos = j + 1;//��¼����λ��
				break;
			}
		}
		(*num)[pos] = tem;
	}
}

void MergeSort(int **num, int len)//�鲢����
{
	if (len == 1) return;
	else
	{
		int *numt = new int[len];//�������������
		int len1 = len / 2, len2 = len - len1;
		int *p1 = &(*num)[0], *p2 = &(*num)[len1];//��һ��Ϊ2
		MergeSort(&p1, len1);
		MergeSort(&p2, len2);//�Ӳ������ֱ������Ϊ1��
		int puted1, puted2;	//p1,p2�Ѿ���ŵ�����
		puted1 = puted2 = 0;
		//�鲢
		for (int i = 0; i < len; i++)
		{
			//���ж������Ӳ����ĸ��Ѿ�Ϊ��
			if (puted1 == len1)
			{
				numt[i] = p2[0];
				puted2++;
				if (puted2 == len2);
				else p2++;
				continue;
			}
			else if (puted2 == len2)
			{
				numt[i] = p1[0];
				puted1++;
				p1++;//ָ�����
				continue;
			}
			//���ж������Ӳ��е�ǰ��С�����ĸ���С
			if (p1[0] < p2[0])
			{
				numt[i] = p1[0];
				puted1++;
				p1++;//ָ�����
			}
			else if (p1[0] > p2[0])
			{
				numt[i] = p2[0];
				puted2++;
				if (puted2 == len2);
				else p2++;
			}
		}
		*num = numt;//ָ���Ѿ�����õ�����
	}
}

void CountSort(int **num, int len)//��������
{
	int max, min;
	max = min = (*num)[0];
	for (int i = 1; i < len; i++)//�ҳ������С��ֵ��֮�����������鿪ʼ����
	{
		if (max < (*num)[i]) max = (*num)[i];
		if (min >(*num)[i]) min = (*num)[i];
	}
	int len1 = max - min + 1;
	int *count = new int[len1];//��������
	for (int i = 0; i < len1; i++)//��ʼ��������
		count[i] = 0;
	for (int i = 0; i < len; i++)//��ʼ����
	{
		count[((*num)[i] - min)] += 1;//*num[i]-minΪ���Ӧ�±�
	}
	for (int i = 0, j = 0; i < len; i++)//����
	{
		while ((count[j]) == 0)j++;
		(*num)[i] = j + min;
		count[j]--;
	}
	delete count;
	/*����ֻ��һ��ѭ��,�����ѭ���͸�Ϊ
	 for(int i=0,j=0;i<len;)
	 {
	 if(count[j]==0)j++;
	 else
	 {
	 (*num)[i] = j + min;
	 i++;
	 count[j]--;
	 }
	 }

	 //�ڶ���ѭ��������a�и�����������λ��
	 for(int i = 1;i < len;i++)
	 count[i] = count[i-1]+count[i];
	 int *numx=new int[len];
	 //������ѭ������ÿ�����ŵ���ȷ��λ����
	 for(int i = 7;i >= 0;i --){
	 numx[count[a[i]]-1] = (*num)[i];  //ע������һ��Ҫ-1������Ϊb���±��Ǵ�0��ʼ�ģ�
	 count[a[i]] --;
	 //������õĸ�ֵ��ȥ
	 for (int i = 0; i < len; i++)
	 (*num)[i] = numx[i];
	 }
	 */
}

int Partion(int**num, int low, int high)
{
	int part = (*num)[low];
	while (low<high)
	{
		while (low<high && (*num)[high] >= part)
			high--;
		(*num)[low] = (*num)[high];
		while (low<high && (*num)[low] <= part)
			low++;
		(*num)[high] = (*num)[low];
	}
	(*num)[low] = part;
	return low;//���λ��
}

void QSort(int**num, int low, int high)
{
	AStack st;
	st.InitStack();
	int mid;//ÿһ����λ��
	if (low<high)
	{
		st.Push(low);
		st.Push(high);
		while (!st.isEmpty())
		{
			int j = st.Top(); st.Pop();
			int i = st.Top(); st.Pop();//ȡ��һ�������н�С�ķ����ķ��Ҳ���
			mid = Partion(&(*num), i, j);
			if (i<mid - 1)//��߷���ջ������
			{
				st.Push(i);
				st.Push(mid - 1);
			}
			if (mid + 1<j)//�ұ߷���ջ������
			{
				st.Push(mid + 1);
				st.Push(j);
			}
		}
	}
	st.DestroyStack();
}

void QSort_Recursion(int **num, int len)//�ݹ�����
{
	if (len == 1 || len == 0)return;
	else
	{
		int little;//�жϵڶ�λ�Ƿ�С����
		int tem, len1 = 0;//len1Ϊ�������鳤��
		int *p1 = *num;//���ƶ�
		if ((*num)[0] > (*num)[1]) len1 = little = 1;//����������Ƿ�Ҫ�ƶ�һ��
		else little = 0;
		for (int i = 2; i < len; i++)//�����ڶ���,Ҫ��Ϊ������λ
		{
			if ((*num)[i] < (*num)[0])//��������С����
			{
				p1++, len1++;//ָ�����
				tem = p1[0], p1[0] = (*num)[i], (*num)[i] = tem;
			}
		}
		p1 += little;
		tem = p1[0], p1[0] = (*num)[0], (*num)[0] = tem;//����
		int len2 = len - len1 - 1;//len2Ϊ�������鳤��
		int *num1 = *num, *num2 = &(*num)[len1 + 1];//num1Ϊ�����飬num2Ϊ������
		QSort_Recursion(&num1, len1);//������һ��
		for (int i = 0; i < len1; i++)
			(*num)[i] = num1[i];
		QSort_Recursion(&num2, len2);//������һ��
		for (int i = len1 + 1, j = 0; i < len; i++, j++)
			(*num)[i] = num2[j];
	}
}

void RadixCountsort(int **num, int len)
{
	int max = (*num)[0];
	int exp = 1;//λ��
	int *numx = new int[len];

	//�ҳ�����������Ԫ����Ϊ�ж�ѭ������������
	for (int i = 1; i < len; i++)
		if ((*num)[i] > max)
			max = (*num)[i];
	while (max / exp > 0)
	{
		int count[10] = { 0 };
		for (int i = 0; i < len; i++)
			count[((*num)[i] / exp) % 10] = count[((*num)[i] / exp) % 10] + 1;

		//�ڶ���ѭ��������a�и�����������λ��
		for (int i = 1; i < 10; i++)
			count[i] = count[i - 1] + count[i];

		//������ѭ������ÿ�����ŵ���ȷ��λ����
		for (int i = len - 1; i >= 0; i--) {
			numx[count[((*num)[i] / exp) % 10] - 1] = (*num)[i];
			count[((*num)[i] / exp) % 10] --;
		}

		//��numx���Ƹ�num
		for (int i = 0; i < len; i++)
			(*num)[i] = numx[i];
		exp = exp * 10;
	}
}

int main()
{
	ofstream fout;
	fout.open("output.txt");
	int len = 100;	
	int *num = new int[len];
	srand((int)time(NULL));//ÿ�����ж�����
	long times = 100000;
	clock_t sum1=0, sum2=0,sum3=0, sum4=0, sum5=0, sum6=0;
	cout << "100k��100����������ʱ���" << endl;
	cout << "___________________________________________________________________"  << endl;
	cout << "��������                          ʱ��    " << endl;
	fout << "100k��100����������ʱ���" << endl;
	fout << "___________________________________________________________________"  << endl;
	fout << "��������                          ʱ��    " << endl;
	while (times > 0)
	{
		for (int i = 0; i < len; i++)
		{
			num[i] = rand();
		}
		clock_t start1 = clock();
		CountSort(&num, len);
		clock_t diff1 = clock() - start1;
		sum1 += diff1;
		times--;
	}
	cout << "      ��������              " << "             ";
	cout << "    " << sum1 << "  " << endl;
	cout << "___________________________________________________________________" << endl;
	fout << "      ��������              " << "             ";
	fout << "    " << sum1 << "  " << endl;
	fout << "___________________________________________________________________" << endl;
	times = 100000;
	while (times > 0)
	{
		for (int i = 0; i < len; i++)
		{
			num[i] = rand();
		}
		clock_t start2 = clock();
		InsertSort(&num, len);
		clock_t diff2 = clock() - start2;
		sum2 += diff2;
		times--;
	}
	cout << "      ��������              " << "             ";
	cout << "    " << sum2 << "  " << endl;
	cout << "___________________________________________________________________" << endl;
	fout << "      ��������              " << "             ";
	fout << "    " << sum2 << "  " << endl;
	fout << "___________________________________________________________________" << endl;
	times = 100000;
	while (times > 0)
	{
		for (int i = 0; i < len; i++)
		{
			num[i] = rand();
		}
		clock_t start3 = clock();
		MergeSort(&num, len);
		clock_t diff3 = clock() - start3;
		sum3 += diff3;
		times--;
	}
	cout << "      �鲢����              " << "             ";
	cout << "    " << sum3 << "  " << endl;
	cout << "___________________________________________________________________" << endl;
	fout << "      �鲢����              " << "             ";
	fout << "    " << sum3 << "  " << endl;
	fout << "___________________________________________________________________" << endl;
	times = 100000;
	while (times > 0)
	{
		for (int i = 0; i < len; i++)
		{
			num[i] = rand();
		}
		clock_t start4 = clock();
		QSort(&num,0,len-1);
		clock_t diff4 = clock() - start4;
		sum4 += diff4;
		times--;
	}
	cout << "      �������򣨷ǣ�              " << "             ";
	cout << "    " << sum4 << "  " << endl;
	cout << "___________________________________________________________________" << endl;
	fout << "      �������򣨷ǣ�              " << "             ";
	fout << "    " << sum4 << "  " << endl;
	fout << "___________________________________________________________________" << endl;
	times = 100000;
	while (times > 0)
	{
		for (int i = 0; i < len; i++)
		{
			num[i] = rand();
		}
		clock_t start5 = clock();
		QSort_Recursion(&num, len);
		clock_t diff5 = clock() - start5;
		sum5 += diff5;
		times--;
	}
	cout << "      �������򣨵ݹ飩              " << "             ";
	cout << "    " << sum5 << "  " << endl;
	cout << "___________________________________________________________________" << endl;
	fout << "      �������򣨵ݹ飩              " << "             ";
	fout << "    " << sum5 << "  " << endl;
	fout << "___________________________________________________________________" << endl;
	times = 100000;
	while (times > 0)
	{
		for (int i = 0; i < len; i++)
		{
			num[i] = rand();
		}
		clock_t start6 = clock();
		RadixCountsort(&num, len);
		clock_t diff6 = clock() - start6;
		sum6 += diff6;
		times--;
	}
	cout << "      ������������              " << "             ";
	cout << "    " << sum6 << "  " << endl;
	cout << "___________________________________________________________________" << endl;
	fout << "      ������������              " << "             ";
	fout << "    " << sum6 << "  " << endl;
	fout << "___________________________________________________________________" << endl;
	fout.close();
	getchar();
}