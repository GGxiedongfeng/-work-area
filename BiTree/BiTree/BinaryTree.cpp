#include<iostream>
#include"BinaryTree.h"
#include<string>
#include"queue.h"


using namespace std;

int mark = 0;

BiTNode* CreateBiTree(char* def, int pos, int size)
{
	BiTNode * t;
	if (pos >= size)
	{
		return NULL;
	}
	else {
		if (def[pos] == '#')
			t = NULL;
		else {
			t = new BiTNode;
			t->data = def[pos];
			t->lchild = CreateBiTree(def, (pos * 2), size);
			t->rchild = CreateBiTree(def, (pos * 2 + 1), size);
		}
		return t;
	}
}

void preOrderTraverse(BiTNode t)
{
	cout << t.data << " ";
	if (t.lchild != NULL)
		preOrderTraverse(*(t.lchild));
	if (t.rchild != NULL)
		preOrderTraverse(*(t.rchild));
}


void InOrderTraverse(BiTNode t)
{
	if (t.lchild != NULL)
		InOrderTraverse(*(t.lchild));
	cout << t.data << " ";
	if (t.rchild != NULL)
		InOrderTraverse(*(t.rchild));
}

void PostOrderTraverse(BiTNode t)
{
	if (t.lchild != NULL)
		PostOrderTraverse(*(t.lchild));
	if (t.rchild != NULL)
		PostOrderTraverse(*(t.rchild));
	cout << t.data << " ";
}

void LevelOrderTraverse(BiTNode t)
{
	queue Aqueue;
	Aqueue.Create(10);
	Aqueue.Push(t);
	while (!Aqueue.Empty())
	{
		t = Aqueue.Front();
		Aqueue.Pop();
		cout << t.data << ' ';
		if (t.lchild != NULL)
			Aqueue.Push(*t.lchild);
		if (t.rchild != NULL)
			Aqueue.Push(*t.rchild);
	}
	Aqueue.Destroy();
	cout << endl;
}//²ãÐò±éÀú

bool Ismark(char ch)//ÅÐ¶ÏÊÇ·ñÎª·ûºÅ
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	else
		return false;
}

int Value(BiTNode t)
{
	int *T = new int[mark]; int markpos = 0, Lt = -1;
	char val = '#'; BiTNode *p = &t;
	while (p->data != 'T')
	{
		if (Ismark(p->data))
		{
			if (Ismark(p->lchild->data))
			{
				p = p->lchild;
				continue;
			}
			else if (Ismark(p->rchild->data))
			{
				if (p == &t)
					Lt = markpos - 1;
				p = p->rchild;
				continue;
			}
			else if (!Ismark(p->rchild->data) && !Ismark(p->lchild->data))
			{
				switch (p->data)
				{
				case '*':
				{
					if (p->lchild->data == 'T'&&p->rchild->data == 'T')
					{
						if (p == &t)
							T[markpos] = T[Lt] * T[markpos - 1];
						else
							T[markpos] = T[markpos - 1] * T[markpos - 2];
					}
					else if (p->lchild->data != 'T'&&p->rchild->data != 'T')
					{
						T[markpos] = (p->lchild->data - '0') *(p->rchild->data - '0');
					}
					else if (p->lchild->data != 'T')
						T[markpos] = (p->lchild->data - '0')*T[markpos - 1];
					else
					{
						if (p == &t)
							T[markpos] = T[Lt] * (p->rchild->data - '0');
						else
							T[markpos] = T[markpos - 1] * (p->rchild->data - '0');
					}
					p->data = 'T';
					markpos++;
				}break;
				case '/':
				{
					if (p->lchild->data == 'T'&&p->rchild->data == 'T')
					{
						if (p == &t)
							T[markpos] = T[Lt] / T[markpos - 1];
						else
							T[markpos] = T[markpos - 1] / T[markpos - 2];
					}
					else if (p->lchild->data != 'T'&&p->rchild->data != 'T')
						T[markpos] = (p->lchild->data - '0') / (p->rchild->data - '0');
					else if (p->lchild->data != 'T')
						T[markpos] = (p->lchild->data - '0') / T[markpos - 1];
					else
					{
						if (p == &t)
							T[markpos] = T[Lt] / (p->rchild->data - '0');
						else
							T[markpos] = T[markpos - 1] / (p->rchild->data - '0');
					}
					p->data = 'T';
					markpos++;
				}break;
				case '+':
				{
					if (p->lchild->data == 'T'&&p->rchild->data == 'T')
					{
						if (p == &t)
							T[markpos] = T[Lt] + T[markpos - 1];
						else
							T[markpos] = T[markpos - 1] + T[markpos - 2];
					}
					else if (p->lchild->data != 'T'&&p->rchild->data != 'T')
						T[markpos] = (p->lchild->data - '0') + (p->rchild->data - '0');
					else if (p->lchild->data != 'T')
						T[markpos] = (p->lchild->data - '0') + T[markpos - 1];
					else
					{
						if (p == &t)
							T[markpos] = T[Lt] + (p->rchild->data - '0');
						else
							T[markpos] = T[markpos - 1] + (p->rchild->data - '0');
					}
					p->data = 'T';
					markpos++;
				}break;
				case '-':
				{
					if (p->lchild->data == 'T'&&p->rchild->data == 'T')
					{
						if (p == &t)
							T[markpos] = T[Lt] - T[markpos - 1];
						else
							T[markpos] = T[markpos - 1] - T[markpos - 2];
					}
					else if (p->lchild->data != 'T'&&p->rchild->data != 'T')
						T[markpos] = (p->lchild->data - '0') - (p->rchild->data - '0');
					else if (p->lchild->data != 'T')
						T[markpos] = (p->lchild->data - '0') - T[markpos - 1];
					else
					{
						if (p == &t)
							T[markpos] = T[Lt] - (p->rchild->data - '0');
						else
							T[markpos] = T[markpos - 1] - (p->rchild->data - '0');
					}
					p->data = 'T';
					markpos++;
				}break;
				}
			}
		}
		p = &t;
	}
	return T[markpos - 1];
}

char* IntiValue(char* def, int len, int *cap)
{
	for (int i = 0; i<len; i++)
	{
		if (Ismark(def[i]))
			(*cap) *= 2;
		mark++;
	}
	char*p = new char[(*cap)]; char tem;
	for (int i = 0; i < (*cap); i++)
		p[i] = '#';
	for (int j = 0, i = 0; j < len; j++)
	{
		if (Ismark(def[j]))
		{
			while (1)
			{
				if (i > 3 && p[i / 2] == '#')
					i /= 2;
				else if (i > 3 && !Ismark(p[i / 2]))
					tem = p[i / 2], p[i / 2] = def[j], def[j] = tem;
				else
				{
					break;
				}
			}
			p[i] = def[j];
			if (Ismark(def[j]))
				i *= 2;
			else
				i++;
		}
		else
		{
			p[i] = def[j];
			i++;
		}
	}
	return p;
}

void DestroyBiTree(BiTNode *t)
{
	BiTNode *p = t;
	if ((*t).lchild != NULL)
		DestroyBiTree((*t).lchild);
	if ((*t).rchild != NULL)
		DestroyBiTree((*t).rchild);
	delete (p);
}

