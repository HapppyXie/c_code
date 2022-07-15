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
//typedef Book ElemType;
#define MAXSIZE 10000
typedef struct {
	char no[20];
	char name[50];
	float price[4];//ԭ��Ϊprice,û������С��λ��
}Book;
typedef struct {
	Book * elem;
	int length;
}SqList;

Status InitList(SqList);
Status GetElem(SqList, int, Book);
int LocateElem(SqList, Book);
Status ListInsert(SqList, int, Book);
Status ListDelete(SqList, int);
void DestroyList(SqList);
void ClearList(SqList);
int GetLength(SqList);
int IsEmpty(SqList);


void main() {
	SqList List,*L=&List;
	int result1=InitList(*L);
	printf("%d  1�ɹ�,0ʧ��\n", result1);

	//int result2 = GetLength(List);
	//printf("%d  ���", result2);
	
}


//˳���ĳ�ʼ��	ԭ������Ϊ&L
Status InitList(SqList L) {
	//����һ���յ�˳��� (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); c++��new�Ϳ���
	//ǰ�涨��charΪElemType,�����淢�ֲ����߼����޸�ΪBook
	L.elem = (Book*)malloc(sizeof(Book) * MAXSIZE);
	if (!L.elem)exit(OVERFLOW);
	L.length = 0;	
	return OK;
}

//˳����ȡֵ		Book e ԭ��Ϊ ElemType &e
Status GetElem(SqList L, int i,Book e) {
	if ((i<1 || i>L.length))return ERROR;
	e = L.elem[i - 1];
	return OK;
}

//˳���Ĳ���	����˳�����ֵΪe��Ԫ�أ���������� Book e ԭ��ΪElemType e
int LocateElem(SqList L, Book e) {
	for (int i = 0; i < L.length; i++) {
		//�޷��Ƚ�e==L.elem[i]
		if (e.no==L.elem[i].no) return i + 1;
	}
	return 0;
}
//˳���Ĳ���	��˳���ĵ�i��λ�ã���ţ������µ�Ԫ��e,i�ĺϷ���ΧΪ1<=i<=L.length+1   Book e ԭ��ΪElemType e
Status ListInsert(SqList L, int i, Book e) {
	if ((i < 1) || (i > L.length + 1))return ERROR;//��Χ�Ƿ�
	if (L.length == MAXSIZE)return ERROR;//������
	
	//����j=10��i=5
	for (int j = L.length - 1; j >= i; j--) {
		L.elem[j] = L.elem[j - 1];//�˴���ȡλ��ʱ����,Ӧ����ָ��ָ��
	}
	L.elem[i-1] = e;
	++L.length;
	return OK;
}
//˳����ɾ��
Status ListDelete(SqList L,int i) {
	//ɾ��˳����е�i��Ԫ��,i�ĺϷ���ΧΪ1<=i<=L.length
	if ((i < 1) || (i > L.length + 1))return ERROR;	//iֵ���Ϸ�
	//if (L.length == 0)return ERROR;//��Ϊ�յĲ������������fouѭ���ѽ��
	//�����������ǰ�ƶ�������Ҫɾ���������ٽ�˳����ȼ�1
	for (int j = i; j < L.length; j++) {
		L.elem[i - 1] = L.elem[i];
	}
	--L.length;
	return OK;
}
//����
//����˳���
void DestroyList(SqList L) {
	if (L.elem)free(&L);
}
//���˳���
void ClearList(SqList L) {
	L.length = 0;
}
//�����Ա��ȵĴ�С
int GetLength(SqList L) {
	return L.length;
}
//�ж����Ա�L�Ƿ�Ϊ��
int IsEmpty(SqList L) {
	if (L.length == 0) {
		return 1;
	}
	else {
		return 0;
	}
}