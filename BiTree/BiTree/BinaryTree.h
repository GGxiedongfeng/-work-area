#ifndef _BinaryTree_H_
#define _BinaryTree_H_

#include<string>
typedef struct  BiTNode {
	char   data;     // 数据域
	struct BiTNode  *lchild, *rchild;  // 左、右孩子指针
};

BiTNode* CreateBiTree(char* def, int pos, int size); //根据输入建立二叉树
void DestroyBiTree(BiTNode *t);//销毁

void preOrderTraverse(BiTNode t);   //前序遍历
void InOrderTraverse(BiTNode t);	//中序遍历
void PostOrderTraverse(BiTNode t);	//后序遍历
void LevelOrderTraverse(BiTNode t);	//层序遍历

int Value(BiTNode t);//运算
bool Ismark(char ch);//服务于运算
char* IntiValue(char* def, int len, int *cap);//将输入的前缀表达式改为放置二叉树的数组形式

#endif // !_BinaryTree_H_

