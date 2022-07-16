#include<stdio.h>
#include<Windows.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef char SElemType;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

//˳��ջ�ĳ�ʼ��
Status InitStack(SqStack &S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

//˳��ջ����ջ
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)return ERROR;
	*S.top++ = e;
	return OK;
}
//��ջ
Status Pop(SqStack& S, SElemType& e) {
	if (S.top == S.base)return ERROR;
	e = *--S.top;
	return OK;
}
//ȡ��ջ��Ԫ��
SElemType GetTop(SqStack S) {
	if (S.top != S.base) return *(S.top-1);	//ȡ��ջ��Ԫ�أ���ָ�벻��
}

//����
Status StackEmpty(SqStack S) {
	if (S.top == S.base)return TRUE;
	else return FALSE;
}
int StackLength(SqStack S) {
	return S.top - S.base;
}
Status ClearStack(SqStack S) {
	if (S.base) {//�����Ϊ��
		S.top = S.base;
	}
	return OK;
}
Status DestoryStack(SqStack &S) {
	if (S.base) {
		delete S.base;//�ͷ���洢�ռ䣬���Ұָ�룬ָ������һ��λ��
		S.stacksize = 0;
		S.base = S.top = NULL;	//��Ұָ��ȫ����ΪNULL����������ָ
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