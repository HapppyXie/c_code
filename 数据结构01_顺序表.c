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
//typedef Book ElemType;
#define MAXSIZE 10000
typedef struct {
	char no[20];
	char name[50];
	float price[4];//原本为price,没有限制小数位数
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
	printf("%d  1成功,0失败\n", result1);

	//int result2 = GetLength(List);
	//printf("%d  求表长", result2);
	
}


//顺序表的初始化	原本参数为&L
Status InitList(SqList L) {
	//构造一个空的顺序表 (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); c++中new就可以
	//前面定义char为ElemType,但后面发现不和逻辑，修改为Book
	L.elem = (Book*)malloc(sizeof(Book) * MAXSIZE);
	if (!L.elem)exit(OVERFLOW);
	L.length = 0;	
	return OK;
}

//顺序表的取值		Book e 原本为 ElemType &e
Status GetElem(SqList L, int i,Book e) {
	if ((i<1 || i>L.length))return ERROR;
	e = L.elem[i - 1];
	return OK;
}

//顺序表的查找	查找顺序表中值为e的元素，返回其序号 Book e 原本为ElemType e
int LocateElem(SqList L, Book e) {
	for (int i = 0; i < L.length; i++) {
		//无法比较e==L.elem[i]
		if (e.no==L.elem[i].no) return i + 1;
	}
	return 0;
}
//顺序表的插入	在顺序表的第i个位置（序号）插入新的元素e,i的合法范围为1<=i<=L.length+1   Book e 原本为ElemType e
Status ListInsert(SqList L, int i, Book e) {
	if ((i < 1) || (i > L.length + 1))return ERROR;//范围非法
	if (L.length == MAXSIZE)return ERROR;//表已满
	
	//假设j=10，i=5
	for (int j = L.length - 1; j >= i; j--) {
		L.elem[j] = L.elem[j - 1];//此处读取位置时报错,应该是指针指错
	}
	L.elem[i-1] = e;
	++L.length;
	return OK;
}
//顺序表的删除
Status ListDelete(SqList L,int i) {
	//删除顺序表中第i个元素,i的合法范围为1<=i<=L.length
	if ((i < 1) || (i > L.length + 1))return ERROR;	//i值不合法
	//if (L.length == 0)return ERROR;//表为空的操作，但后面的fou循环已解决
	//将后面的数往前移动，覆盖要删除的数，再将顺序表长度减1
	for (int j = i; j < L.length; j++) {
		L.elem[i - 1] = L.elem[i];
	}
	--L.length;
	return OK;
}
//补充
//销毁顺序表
void DestroyList(SqList L) {
	if (L.elem)free(&L);
}
//清空顺序表
void ClearList(SqList L) {
	L.length = 0;
}
//求线性表长度的大小
int GetLength(SqList L) {
	return L.length;
}
//判断线性表L是否为空
int IsEmpty(SqList L) {
	if (L.length == 0) {
		return 1;
	}
	else {
		return 0;
	}
}