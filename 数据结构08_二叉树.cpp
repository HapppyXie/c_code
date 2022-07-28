#include<stdio.h>
#include<Windows.h>
#include"���ݽṹ08_������������.cpp"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef char SElemType;
typedef char TElemType;
typedef char TelemType;

//�������������ʽ�洢
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//����ջ
typedef struct StackNode {
	BiTNode data;
	struct StackNode* next;
}StackNode, * LinkStack;

//�����������˳��洢
#define MAXTSIZE 100
typedef TElemType SqBiTree[MAXTSIZE];
SqBiTree bt;


//������������
typedef struct TriNode {
	TelemType data;
	struct TriNode* lchild, * parent, * rchild;
}TriNode,*TriTree;

//ջ
//��ʼ��
Status InitStack(LinkStack& S) {
	S = NULL;
	return OK;
};
//��ջ
Status Push(LinkStack& S, BiTNode e) {
	StackNode* p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
//��ջ
Status Pop(LinkStack& S, BiTNode &e) {
	if (S == NULL) return ERROR;
	e = S->data;
	StackNode* p = S;
	S = S->next;
	delete p;
	return OK;
}
//ȡջ��Ԫ��
BiTNode GetTop(LinkStack S) {
	if (S != NULL)return S->data;
}
Status StackEmpty(LinkStack S) {
	if (S == NULL)return OK;
	else return FALSE;
}

//��������	������ʽ�洢�ṹ
//�ݹ������������	�������		
Status InOrderTraverse(BiTree T) {
	if (T == NULL) return FALSE;
	else {
		InOrderTraverse(T->lchild);		//ֻ��ı����˳�򣬼���ʵ�����򣬺������
		printf("%d\t", T ->data);
		InOrderTraverse(T->rchild);
	}
	return OK;
}

//ѭ���ṹʵ���������������
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

//����������
//���򴴽�,�ݹ�	������
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
//���ƶ�����
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

//��������������
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

//����������н��ĸ���
int NodeCount(BiTree T) {
	if (T == NULL) { return FALSE; }
	else {
		return NodeCount(T->lchild) + NodeCount(T->rchild)+1;
	}
}

//����Ҷ����
int LeafCount(BiTree T) {
	if (T == NULL)return 0;
	else {
		if (T->lchild == NULL && T->rchild == NULL) {//˵������ײ���
			return 1;
		}
		else {
			return LeafCount(T->lchild) + LeafCount(T->rchild);
		}
	}
}

void main() {

}