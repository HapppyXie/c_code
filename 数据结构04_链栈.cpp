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
typedef char SElemType;

typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;

//初始化
Status InitStack(LinkStack& S) {
	S = NULL;
	return OK;
};
//入栈
Status Push(LinkStack &S,SElemType e) {
	StackNode* p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
//出栈
Status Pop(LinkStack& S, SElemType& e) {
	if (S == NULL) return ERROR;
	e = S->data;
	StackNode* p = S;
	S = S->next;
	delete p;
	return OK;
}
//取栈顶元素
SElemType GetTop(LinkStack S) {
	if (S != NULL)return S->data;
}


void main() {

}
