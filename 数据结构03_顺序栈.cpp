#include<stdio.h>
#include<Windows.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char SElemType;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

//顺序栈的初始化
Status InitStack(SqStack &S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

//顺序栈的入栈
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)return ERROR;
	*S.top++ = e;
	return OK;
}
//出栈
Status Pop(SqStack& S, SElemType& e) {
	if (S.top == S.base)return ERROR;
	e = *--S.top;
	return OK;
}
//取出栈顶元素
SElemType GetTop(SqStack S) {
	if (S.top != S.base) return *(S.top-1);	//取出栈顶元素，但指针不变
}

//补充
Status StackEmpty(SqStack S) {
	if (S.top == S.base)return TRUE;
	else return FALSE;
}
int StackLength(SqStack S) {
	return S.top - S.base;
}
Status ClearStack(SqStack S) {
	if (S.base) {//如果不为空
		S.top = S.base;
	}
	return OK;
}
Status DestoryStack(SqStack &S) {
	if (S.base) {
		delete S.base;//释放其存储空间，变成野指针，指向任意一个位置
		S.stacksize = 0;
		S.base = S.top = NULL;	//将野指针全部置为NULL，不让其乱指
	}
	return OK;
}


void main() {
	SqStack S;
	int result1 = InitStack(S);
	printf("%d\n", result1);
	SElemType data1 = 'A';
	int result2 = Push(S, data1);
	printf("%d\n", result2);
	SElemType result3 = GetTop(S);
	printf("%c\n", result3);
	
}