#include<stdio.h>
#include<Windows.h>
#include"数据结构08_线索树二叉树.cpp"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char SElemType;
typedef char TElemType;
typedef char TelemType;

//定义二叉树的链式存储
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//定义栈
typedef struct StackNode {
	BiTNode data;
	struct StackNode* next;
}StackNode, * LinkStack;

//定义二叉树的顺序存储
#define MAXTSIZE 100
typedef TElemType SqBiTree[MAXTSIZE];
SqBiTree bt;


//定义三叉链表
typedef struct TriNode {
	TelemType data;
	struct TriNode* lchild, * parent, * rchild;
}TriNode,*TriTree;

//栈
//初始化
Status InitStack(LinkStack& S) {
	S = NULL;
	return OK;
};
//入栈
Status Push(LinkStack& S, BiTNode e) {
	StackNode* p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
//出栈
Status Pop(LinkStack& S, BiTNode &e) {
	if (S == NULL) return ERROR;
	e = S->data;
	StackNode* p = S;
	S = S->next;
	delete p;
	return OK;
}
//取栈顶元素
BiTNode GetTop(LinkStack S) {
	if (S != NULL)return S->data;
}
Status StackEmpty(LinkStack S) {
	if (S == NULL)return OK;
	else return FALSE;
}

//二叉树树	采用链式存储结构
//递归遍历二叉树树	中序遍历		
Status InOrderTraverse(BiTree T) {
	if (T == NULL) return FALSE;
	else {
		InOrderTraverse(T->lchild);		//只需改变输出顺序，即可实现先序，后序遍历
		printf("%d\t", T ->data);
		InOrderTraverse(T->rchild);
	}
	return OK;
}

//循环结构实现中序遍历二叉树
void InOrderTraverse_(BiTree T) {
	BiTree p;
	LinkStack S;
	InitStack(S);
	p = T;
	BiTNode *q = new BiTNode;
	while (p || !StackEmpty(S)) {
		if (p) {
			Push(S, *p);
			p = p->lchild;
		}
		else {
			Pop(S, *q);
			printf("%d\t", q->data);
			p = q->rchild;
		}//while
	}
}

//创建二叉树
//先序创建,递归	根左右
void CreateBiTree(BiTree& T) {
	TElemType ch;
	scanf_s(&ch);
	if (ch == '#')T = NULL;
	else {
		T = new BiTNode;
		if (!T)exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
//复制二叉树
void Copy(BiTree T, BiTree &NewT) {
	if (T = NULL) { 
		NewT = NULL;
		return;
	}
	else {
		NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->rchild, NewT->rchild);
		Copy(T->lchild, NewT->lchild);
	}
}

//计算二叉树的深度
int Depth(BiTree T) {
	if (T == NULL) return FALSE;
	else {
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		if (m > n) {
			return m + 1;
		}
		else {
			return n + 1;
		}
	}
}

//计算二叉树中结点的个数
int NodeCount(BiTree T) {
	if (T == NULL) { return FALSE; }
	else {
		return NodeCount(T->lchild) + NodeCount(T->rchild)+1;
	}
}

//计算叶子数
int LeafCount(BiTree T) {
	if (T == NULL)return 0;
	else {
		if (T->lchild == NULL && T->rchild == NULL) {//说明到达底部了
			return 1;
		}
		else {
			return LeafCount(T->lchild) + LeafCount(T->rchild);
		}
	}
}

void main() {

}