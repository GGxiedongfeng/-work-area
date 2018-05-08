#ifndef _BinaryTree_H_
#define _BinaryTree_H_

#include<string>
typedef struct  BiTNode {
	char   data;     // ������
	struct BiTNode  *lchild, *rchild;  // ���Һ���ָ��
};

BiTNode* CreateBiTree(char* def, int pos, int size); //�������뽨��������
void DestroyBiTree(BiTNode *t);//����

void preOrderTraverse(BiTNode t);   //ǰ�����
void InOrderTraverse(BiTNode t);	//�������
void PostOrderTraverse(BiTNode t);	//�������
void LevelOrderTraverse(BiTNode t);	//�������

int Value(BiTNode t);//����
bool Ismark(char ch);//����������
char* IntiValue(char* def, int len, int *cap);//�������ǰ׺���ʽ��Ϊ���ö�������������ʽ

#endif // !_BinaryTree_H_

