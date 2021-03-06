#include<iostream>
#include<time.h>
#include"arithmetic.h"
#include"Astack.h"

using namespace std;

void InsertSort(int **num, int len)//插入排序
{
	for (int i = 1; i < len; i++)
	{
		int tem, pos = 0;
		tem = (*num)[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (tem < (*num)[j])//将大于插入数的数后移
			{
				(*num)[j + 1] = (*num)[j];
			}
			else
			{
				pos = j + 1;//记录插入位置
				break;
			}
		}
		(*num)[pos] = tem;
	}
}

void MergeSort(int **num, int len)//归并排序
{
	if (len == 1) return;
	else
	{
		int *numt = new int[len];//用来排序的数组
		int len1 = len / 2, len2 = len - len1;
		int *p1 = &(*num)[0], *p2 = &(*num)[len1];//将一分为2
		MergeSort(&p1, len1);
		MergeSort(&p2, len2);//子层继续分直到数量为1个
		int puted1, puted2;	//p1,p2已经存放的数量
		puted1 = puted2 = 0;
		//归并
		for (int i = 0; i < len; i++)
		{
			//先判断两个子层中哪个已经为空
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
				p1++;//指针后移
				continue;
			}
			//再判断两个子层中当前最小的数哪个数小
			if (p1[0] < p2[0])
			{
				numt[i] = p1[0];
				puted1++;
				p1++;//指针后移
			}
			else if (p1[0] > p2[0])
			{
				numt[i] = p2[0];
				puted2++;
				if (puted2 == len2);
				else p2++;
			}
		}
		*num = numt;//指向已经排序好的数组
	}
}

void CountSort(int **num, int len)//计数排序
{
	int max, min;
	max = min = (*num)[0];
	for (int i = 1; i < len; i++)//找出最大最小的值，之后建立计数数组开始计数
	{
		if (max < (*num)[i]) max = (*num)[i];
		if (min >(*num)[i]) min = (*num)[i];
	}
	int len1 = max - min + 1;
	int *count = new int[len1];//计数数组
	for (int i = 0; i < len1; i++)//初始化计数组
		count[i] = 0;
	for (int i = 0; i < len; i++)//开始计数
	{
		count[((*num)[i] - min)] += 1;//*num[i]-min为相对应下标
	}
	for (int i = 0, j = 0; i < len; i++)//排序
	{
		while ((count[j]) == 0)j++;
		(*num)[i] = j + min;
		count[j]--;
	}/*若是只用一个循环,排序的循环就改为
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
	 或者
	 //第二个循环，计算a中各个数排序后的位置
	 for(int i = 1;i < len;i++)
	 count[i] = count[i-1]+count[i];
	 int *numx=new int[len];
	 //第三个循环，把每个数放到正确的位置上
	 for(int i = 7;i >= 0;i --){
	 numx[count[a[i]]-1] = (*num)[i]; 
	 count[a[i]] --;
	 //将排序好的赋值回去
	 for (int i = 0; i < len; i++)
	 (*num)[i] = numx[i];
	 }
	 */
}

int Partion(int**num, int low, int high)//左小右大操作
{
	int part = (*num)[low];
	while (low<high)
	{
		while (low<high&&(*num)[high] >= part)
			high--;
		(*num)[low] = (*num)[high];
		while (low<high&&(*num)[low] <= part)
			low++;
		(*num)[high] = (*num)[low];
	}
	(*num)[low] = part;
	return low;//轴的位置
}

void QSort(int**num, int low, int high)//非递归快排
{
	AStack st;
	st.InitStack();
	int mid;//每一次轴位置
	if (low<high)
	{
		st.Push(low);
		st.Push(high);
		while (!st.isEmpty())
		{
			int j = st.Top(); st.Pop();
			int i = st.Top(); st.Pop();//取出一组来进行将小的放左大的放右操作
			mid = Partion(&(*num), i, j);
			if (i<mid - 1)//左边放入栈，保存
			{
				st.Push(i);
				st.Push(mid - 1);
			}
			if (mid + 1<j)//右边放入栈，保存
			{
				st.Push(mid + 1);
				st.Push(j);
			}
		}
	}
	st.DestroyStack();
}

void QSort_Recursion(int **num, int len)//递归版快排
{
	if (len == 1 || len == 0)return;
	else
	{
		int little;//判断第二位是否小于轴
		int tem, len1 = 0;//len1为轴左数组长度
		int *p1 = *num;//轴移动
		if ((*num)[0] > (*num)[1]) len1 = little = 1;//考虑轴最后是否要移动一次
		else little = 0;
		for (int i = 2; i < len; i++)//不理会第二个,要作为交换的位
		{
			if ((*num)[i] < (*num)[0])//遇到比轴小的数
			{
				p1++, len1++;//指针后移
				tem = p1[0], p1[0] = (*num)[i], (*num)[i] = tem;
			}
		}
		p1 += little;
		tem = p1[0], p1[0] = (*num)[0], (*num)[0] = tem;//移轴
		int len2 = len - len1 - 1;//len2为轴右数组长度
		int *num1 = *num, *num2 = &(*num)[len1 + 1];//num1为左数组，num2为有数组
		QSort_Recursion(&num1, len1);//左再来一次
		for (int i = 0; i < len1; i++)
			(*num)[i] = num1[i];
		QSort_Recursion(&num2, len2);//右再来一次
		for (int i = len1 + 1, j = 0; i < len; i++, j++)
			(*num)[i] = num2[j];
	}
}

void RadixCountsort(int **num, int len)
{
	int max = (*num)[0];
	int exp = 1;//位数
	int *numx = new int[len];

	//找出数组中最大的元素作为判断循环次数的依据
	for (int i = 1; i < len; i++)
		if ((*num)[i] > max)
			max = (*num)[i];
	while (max / exp > 0)
	{
		int count[10] = { 0 };
		for (int i = 0; i < len; i++)
			count[((*num)[i] / exp) % 10] = count[((*num)[i] / exp) % 10] + 1;

		//第二个循环，计算a中各个数排序后的位置
		for (int i = 1; i < 10; i++)
			count[i] = count[i - 1] + count[i];

		//第三个循环，把每个数放到正确的位置上
		for (int i = len - 1; i >= 0; i--) {
			numx[count[((*num)[i] / exp) % 10] - 1] = (*num)[i];
			count[((*num)[i] / exp) % 10] --;
		}

		//把numx复制给num
		for (int i = 0; i < len; i++)
			(*num)[i] = numx[i];
		exp = exp * 10;
	}
}

int main()
{
	int len;
	srand((int)time(NULL));//每次运行都重新
	while (1)
	{
		cout << "输入生成数据长度：" << endl;
		cin >> len;
		int *num = new int[len];
		//cout << "自动生成数据：" << endl;
		for (int i = 0; i < len; i++)
		{
			num[i] = rand();
			//cout << num[i] << " ";
		}
		cout << endl;
		cout << "请选择排序方式：1.计数排序2.插入排序3.归并排序4.非递归快排5.递归快排6.基数计数排序" << endl;
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1: CountSort(&num,len);
			break;
		case 2: InsertSort(&num, len);
			break;
		case 3: MergeSort(&num, len);
			break;
		case 4: QSort(&num,0,len-1);
			break;
		case 5: QSort_Recursion(&num, len);
			break;
		case 6: RadixCountsort(&num, len); 
			break;
		}
		cout << "排序后数据" << endl;
		for (int i = 0; i < len; i++)
			cout << num[i] << " ";
		cout << endl;		
		getchar();
		delete(num);
	}
}