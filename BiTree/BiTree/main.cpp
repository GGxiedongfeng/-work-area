#include<iostream>
#include"BinaryTree.h"
#include<string>
#include"queue.h"

using namespace std;

int main()
{
	cout << "������ǰ׺���ʽ����+2*34+*34�������ַ�������ABCD��12345����" << endl;
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
		cout << "��ѡ���ܣ�1.ǰ����� 2.������� 3.������� 4.������� 5.����  6.������������� 0.�����˳�" << endl;
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
				cout << "���ʽֵΪ��" << Value(*root) << endl;
			else
				cout << "������Ч�ı��ʽ" << endl;
		}break;
		case 6:
		{
			delete(def);
			cout << "������ǰ׺���ʽ����+2*34+*34�������ַ�������ABCD��12345����" << endl;
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