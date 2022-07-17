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
typedef char QElemType;

typedef struct QNode{
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;	//队头队尾元素,而非双向链表
}LinkQueue;

Status InitQueue(LinkQueue Q) {
	Q.front = Q.rear = 0;
	Q.front->next = NULL;
	return OK;
}
Status EnQueue(LinkQueue& Q, QElemType e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
//出队
Status DeQueue(LinkQueue& Q, QElemType& e) {
	if (Q.front == Q.rear)return ERROR;	//判断是否为空
	QNode* p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) { Q.rear = Q.front; }
	delete p;
	return OK;
}
//取队头元素
QElemType GetHead(LinkQueue Q) {
	if (Q.rear != Q.front) return Q.front->data;
}


void main() {

}


