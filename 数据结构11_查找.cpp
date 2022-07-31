#include<stdio.h>
#include<Windows.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define ENDFLAG -1
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;
//宏定义后面不需要;


typedef int KeyType;
typedef int InfoType;
//顺序查找
typedef struct {	//定义结点结构
	KeyType key;
	InfoType otherinfo;
}ElemType;
typedef struct {
	ElemType* R;
	int Length;
}SSTable;

int Search_Seq(SSTable ST, KeyType key) {
	for (int i = ST.Length; i >= 1; i--) {
		if (ST.R[i].key == key) { return i; }
		else {
			return 0;
		}
	}
}
//设置哨兵的顺序查找
int Search_Seq_(SSTable ST, KeyType key) {
	ST.R[0].key = key;
	int i;
	for (i = ST.Length; ST.R[i].key != key; --i);	//找到则跳出循环
	return i;
}

//折半查找
int Search_Bin(SSTable ST, KeyType key) {
	int low = 1;
	int high = ST.Length;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (key == ST.R[mid].key) {
			return mid;
		}
		else if (key < ST.R[mid].key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}//while
	return 0;
}
//分块查找

//二叉排序树	左子树不空，则左子树中都小于根，右子树不空，则右子树中都大于根
typedef struct {
	KeyType key;
	InfoType otherinfo;
}ElemType2;
typedef struct BSTNode{
	ElemType2 data;
	struct BSTNode  *lchild, * rchild;
}BSTNode,*BSTree;

//二叉排序树的查找
BSTree SearchBST(BSTree T, KeyType key) {
	if((!T) || key == T->data.key) {
		return T;	//如果为空或第一个就是要找的则返回
	}
	else if(key<T->data.key)
	{
		return SearchBST(T->lchild, key);
	}
	else {
		return SearchBST(T->rchild, key);
	}
}
//二叉排序树的插入，插入元素一定在叶子结点上
void InsertBST(BSTree& T, ElemType2 e) {
	if (!T) {	//如果为空则插入第一个,即找到叶子结点
		BSTNode* S = new BSTNode;
		S->data = e;
		S->lchild = S->rchild = NULL;
		T = S;
	}
	else if (e.key < T->data.key) {
		InsertBST(T->lchild, e);
	}
	else {
		InsertBST(T->rchild, e);
	}
}

//二叉排序树的创建
void CreateBST(BSTree& T) {
	T = NULL;
	ElemType2 e;
	//录入data域
	e.key = 1;
	while (e.key != ENDFLAG) {
		InsertBST(T, e);
	}
}
//二叉树的删除
void DeleteBST(BSTree& T, KeyType key) {
	BSTNode* p = T;
	BSTNode *f = NULL;
	while (p) {
		if (p->data.key == key) { break; }
		f = p;
		if (p->data.key > key) {
			p = p->rchild;
		}
		else {
			p = p->lchild;
		}//if
	}//while
		if (!p) { return; }	//找不到结点则返回
		//找到p为要删除的结点

		/// //////////////////////////////////////////////////////////////////////////////////////////////////
		//考虑三种情况,左右子树不为空，左子树为空，右子树为空
		BSTNode* q;
		if ((p->lchild) && (p->rchild)) {
			BSTNode* S = p->lchild;
			
			while (S->rchild) {
				q = S;			//q为S的双亲
				S = S->rchild;	//S为要删除结点中左子树的最大值,即删除结点的前驱	为叶子节点或有左子树
			}					
			p->data = S->data;	
			if (q != p) {
				q->rchild = S->lchild;
			}
			else {
				q->lchild = S->lchild;
			}
			delete S;		//释放辅助结点
			return;
		}//if
		else if (!p->rchild) {
			p = p->lchild;
		}
		else if (!p->lchild) {
			p = p->rchild;
		}

		if (!f) { T = p; }			//被删除结点为根节点，故前面没有找，f为NULL;不是删除根节点，则f为找到要删除的p的双亲
		else if (q == f->lchild) { f->lchild = p; }
		else { f->rchild = p; }
		delete q;			//释放辅助结点
}

//平衡二叉树

//散列表的查找
#define m 20
typedef struct {
	KeyType key;
	InfoType otherinfo;
}HashTable[m];		//hash数组

//散列函数
#define NULLKEY 0
int Hash(int key) {
	//一般选择除留余数法作为hash函数，而除数选择小于表长的质数
	return key % 19;
}

#define NULLKEY 0
int SearchHash(HashTable HT, KeyType key) {
	int H0 = Hash(key);
	if (HT[H0].key == NULLKEY) {
		return -1;		//如果数据存储，则一定地址，如果余数为0，(不使用地址0)即没有存储
	}
	else if (HT[H0].key == key) { return H0; }
	else {
		for (int i = 1; i < m; ++i) {		//使用线性探测
			int Hi = (H0 + 1) % m;
			if (HT[Hi].key == NULLKEY) { return -1; }
			else if (HT[Hi].key == key) { return Hi; }
		}
		return -1;
	}
}	


void main() {

}