#include<stdio.h>
#include<Windows.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef char ElemType;
//������
typedef struct LNode {
	ElemType data;
	struct LNode* next;//�Լ������Լ�
}LNode, * LinkList;


//�������ʼ��
Status InitList(LinkList L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}
//ȡֵ							eԭ��Ϊ&e,ӦΪLNode����
Status GetElem(LinkList L, int i, ElemType e) {
	LNode* p = L->next;//����һ��LNodeָ����Ԫ���,���ü�����
	int j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;
	e = p->data;
	return OK;
}
//����
LNode* LocateElem(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;		//��������Ϊָ��
}
//����		LinkList &L
Status ListInsert(LinkList L,int i,ElemType e) {
	LNode* p = L->next;
	int j = 0;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)return ERROR;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
//ɾ��			LinkList &L
Status ListDelete(LinkList L, int i) {
	LNode* p = L->next;
	int j = 0;
	while ((p->next) && j < i - 1) {
		p = p->next;
		++j;
	}
	if ((p->next) || j > i - 1)return ERROR;
	LNode* q = p->next;
	p->next = q->next;
	free(q);	//�ͷ�Ҫɾ���Ľ��ռ�
	return OK;
}
//����
//�жϿձ�		LinkList &L
int ListEmpty(LinkList L) {
	if (L->next)return 0;
	else return 1;
}
//��������		LinkList &L
Status DestoryList(LinkList L) {
	LNode *p;
	while (L) {
		p = L;
		L = L->next;
		free(p);
	}
}
//�������	LinkList &L
Status ClearList(LinkList L) {
	LNode* q, * p;
	p = L->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}
//���
int ListLength(LinkList L) {
	LinkList p;	//��Ϊ������ͷ��㣬������Ҫ����һ��������ͷ����LinkList,�ټ���
	p = L->next;
	int i = 0;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

//�������������Ǿ���ĸ�ֵ
//ǰ�巨(ͷ�巨)	LinkList &L
void CreateList_H(LinkList L,int n) {
	L = (LinkList)malloc(sizeof(LinkList));
	L->next=NULL;
	for (int i = 0; i < n; i++) {
		LNode* p = (LNode*)malloc(sizeof(LNode));
		//����Ԫ�ظ�ֵ��p->data
		//cin>>p->data;
		p->next = L->next;
		L->next = p;
	}
}
	
//��巨	
void CreateList_R(LinkList L, int n) {
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL;
	LNode* r = L;
	for (int i = 0; i < n; i++) {
		LNode* p = (LNode*)malloc(sizeof(LNode));
		//����Ԫ�ظ�ֵ��p->data
		//cin>>p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

void main() {
	
}

