#include<stdio.h>
#include<Windows.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_TREE_SIZE 100
//�궨����治��Ҫ;
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef char TElemType;


//���Ĵ洢�ṹ����һ���˳�����ʽ�洢��˳�����ʽ�ĸ��Ͻṹ
//1.˫�ױ�ʾ��
typedef struct PTNode {
	TElemType data;
	int parent;
}PTNOde;

typedef struct PTree{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;//��ʾ���ڵ��±꣬
}PTree;

//2.���ӱ�ʾ��	�����д洢��ʽ���
//���ӽ��
typedef struct CTNode {
	int child;
	struct CTNode *next;
}*childPtr;
//˫�׽��
typedef struct {
	TElemType data;
	childPtr firstchild;
}CTBox;
//���ṹ
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;//ͳ�ƽ�����͸������;
}CTree;

//.3.�����ֵܷ�	(��������ʾ��)  �ֵ�����������	��ʽ�洢
typedef struct CSNode {
	TElemType data;
	struct CSNode* firstchild, * nextchild;
}CSNode,*CSTree;


void main() {

}