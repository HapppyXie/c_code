#include<stdio.h>
#include<Windows.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char ElemType;
//定义结点
typedef struct LNode {
	ElemType data;
	struct LNode* next;//自己定义自己
}LNode, * LinkList;


//单链表初始化
Status InitList(LinkList L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}
//取值							e原本为&e,应为LNode类型
Status GetElem(LinkList L, int i, ElemType e) {
	LNode* p = L->next;//定义一个LNode指向首元结点,设置计数器
	int j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;
	e = p->data;
	return OK;
}
//查找
LNode* LocateElem(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;		//返回类型为指针
}
//插入		LinkList &L
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
//删除			LinkList &L
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
	free(q);	//释放要删除的结点空间
	return OK;
}
//补充
//判断空表		LinkList &L
int ListEmpty(LinkList L) {
	if (L->next)return 0;
	else return 1;
}
//销毁链表		LinkList &L
Status DestoryList(LinkList L) {
	LNode *p;
	while (L) {
		p = L;
		L = L->next;
		free(p);
	}
}
//清空链表	LinkList &L
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
//求表长
int ListLength(LinkList L) {
	LinkList p;	//因为不包含头结点，所有需要定义一个不包含头结点的LinkList,再计数
	p = L->next;
	int i = 0;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

//创建单链表，即是具体的赋值
//前插法(头插法)	LinkList &L
void CreateList_H(LinkList L,int n) {
	L = (LinkList)malloc(sizeof(LinkList));
	L->next=NULL;
	for (int i = 0; i < n; i++) {
		LNode* p = (LNode*)malloc(sizeof(LNode));
		//输入元素赋值给p->data
		//cin>>p->data;
		p->next = L->next;
		L->next = p;
	}
}
	
//后插法	
void CreateList_R(LinkList L, int n) {
	L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL;
	LNode* r = L;
	for (int i = 0; i < n; i++) {
		LNode* p = (LNode*)malloc(sizeof(LNode));
		//输入元素赋值给p->data
		//cin>>p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

void main() {
	
}

