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

#define MAXQSIZE 100
typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;

//初始化
Status InitQueue(SqQueue& Q) {
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear=0;
	return OK;
}
//球队列长度
int QueueLength(SqQueue Q) {
	return(Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//入队
Status EnQueue(SqQueue& Q, QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
//出队
Status DeQueue(SqQueue& Q, QElemType& e) {
	if (Q.rear == Q.front)return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
//取队头元素
QElemType GetHead(SqQueue Q) {
	if (Q.front != Q.rear)return Q.base[Q.front];
}

void main() {
	SqQueue Q;
	int result1= InitQueue(Q);
	printf("%d", result1);

}