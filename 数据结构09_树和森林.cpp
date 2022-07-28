#include<stdio.h>
#include<Windows.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_TREE_SIZE 100
//宏定义后面不需要;
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char TElemType;


//树的存储结构，以一般的顺序或链式存储，顺序和链式的复合结构
//1.双亲表示法
typedef struct PTNode {
	TElemType data;
	int parent;
}PTNOde;

typedef struct PTree{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;//表示根节点下标，
}PTree;

//2.孩子表示法	数组中存储链式结点
//孩子结点
typedef struct CTNode {
	int child;
	struct CTNode *next;
}*childPtr;
//双亲结点
typedef struct {
	TElemType data;
	childPtr firstchild;
}CTBox;
//树结构
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;//统计结点数和根结点数;
}CTree;

//.3.孩子兄弟法	(二叉链表示法)  兄弟相连留长子	链式存储
typedef struct CSNode {
	TElemType data;
	struct CSNode* firstchild, * nextchild;
}CSNode,*CSTree;


void main() {

}