#include<iostream>
#include"BinaryTree.h"
#include<string>
#include"queue.h"

using namespace std;

int main()
{
	cout << "请输入前缀表达式（如+2*34+*34）或者字符串（如ABCD或12345）：" << endl;
	string definition;
	cin >> definition;
	char * def = NULL;
	def = new char[definition.size() + 1];
	def[0] = '#';
	for (int i = 0; i < definition.size(); i++)
		def[i + 1] = definition[i];
	int len = definition.size();
	BiTNode *root;
	int cap = 2;	char *c;
	if (Ismark(def[1]))
	{
		c = IntiValue(def, definition.size() + 1, &cap);
		root = CreateBiTree(c, 1, cap);
	}
	else
	{
		root = CreateBiTree(def, 1, definition.size() + 1);
	}
	int choose = 1;
	while (choose != 0)
	{
		cout << "请选择功能：1.前序遍历 2.中序遍历 3.后序遍历 4.层序遍历 5.运算  6.重新输入二叉树 0.销毁退出" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			preOrderTraverse(*root);
			cout << endl;
		}break;
		case 2:
		{
			InOrderTraverse(*root);
			cout << endl;
		}break;
		case 3:
		{
			PostOrderTraverse(*root);
			cout << endl;
		}break;
		case 4:
		{
			LevelOrderTraverse(*root);
		}break;
		case 5:
		{
			if (Ismark(def[1]))
				cout << "表达式值为：" << Value(*root) << endl;
			else
				cout << "不是有效的表达式" << endl;
		}break;
		case 6:
		{
			delete(def);
			cout << "请输入前缀表达式（如+2*34+*34）或者字符串（如ABCD或12345）：" << endl;
			cin >> definition;
			def = new char[definition.size() + 1];
			def[0] = '#';
			for (int i = 0; i < definition.size(); i++)
				def[i + 1] = definition[i];
			len = definition.size();
			if (Ismark(def[1]))
			{
				cap = 2;
				c = IntiValue(def, definition.size() + 1, &cap);
				root = CreateBiTree(c, 1, cap);
			}
			else
			{
				root = CreateBiTree(def, 1, definition.size() + 1);
			}
		}break;
		case 0:
		{
			DestroyBiTree(root);
			delete(def);
		}break;
		}
	}
}