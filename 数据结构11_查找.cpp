#include<stdio.h>
#include<Windows.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define ENDFLAG -1
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
//�궨����治��Ҫ;


typedef int KeyType;
typedef int InfoType;
//˳�����
typedef struct {	//������ṹ
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
//�����ڱ���˳�����
int Search_Seq_(SSTable ST, KeyType key) {
	ST.R[0].key = key;
	int i;
	for (i = ST.Length; ST.R[i].key != key; --i);	//�ҵ�������ѭ��
	return i;
}

//�۰����
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
//�ֿ����

//����������	���������գ����������ж�С�ڸ������������գ����������ж����ڸ�
typedef struct {
	KeyType key;
	InfoType otherinfo;
}ElemType2;
typedef struct BSTNode{
	ElemType2 data;
	struct BSTNode  *lchild, * rchild;
}BSTNode,*BSTree;

//�����������Ĳ���
BSTree SearchBST(BSTree T, KeyType key) {
	if((!T) || key == T->data.key) {
		return T;	//���Ϊ�ջ��һ������Ҫ�ҵ��򷵻�
	}
	else if(key<T->data.key)
	{
		return SearchBST(T->lchild, key);
	}
	else {
		return SearchBST(T->rchild, key);
	}
}
//�����������Ĳ��룬����Ԫ��һ����Ҷ�ӽ����
void InsertBST(BSTree& T, ElemType2 e) {
	if (!T) {	//���Ϊ��������һ��,���ҵ�Ҷ�ӽ��
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

//�����������Ĵ���
void CreateBST(BSTree& T) {
	T = NULL;
	ElemType2 e;
	//¼��data��
	e.key = 1;
	while (e.key != ENDFLAG) {
		InsertBST(T, e);
	}
}
//��������ɾ��
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
		if (!p) { return; }	//�Ҳ�������򷵻�
		//�ҵ�pΪҪɾ���Ľ��

		/// //////////////////////////////////////////////////////////////////////////////////////////////////
		//�����������,����������Ϊ�գ�������Ϊ�գ�������Ϊ��
		BSTNode* q;
		if ((p->lchild) && (p->rchild)) {
			BSTNode* S = p->lchild;
			
			while (S->rchild) {
				q = S;			//qΪS��˫��
				S = S->rchild;	//SΪҪɾ������������������ֵ,��ɾ������ǰ��	ΪҶ�ӽڵ����������
			}					
			p->data = S->data;	
			if (q != p) {
				q->rchild = S->lchild;
			}
			else {
				q->lchild = S->lchild;
			}
			delete S;		//�ͷŸ������
			return;
		}//if
		else if (!p->rchild) {
			p = p->lchild;
		}
		else if (!p->lchild) {
			p = p->rchild;
		}

		if (!f) { T = p; }			//��ɾ�����Ϊ���ڵ㣬��ǰ��û���ң�fΪNULL;����ɾ�����ڵ㣬��fΪ�ҵ�Ҫɾ����p��˫��
		else if (q == f->lchild) { f->lchild = p; }
		else { f->rchild = p; }
		delete q;			//�ͷŸ������
}

//ƽ�������

//ɢ�б�Ĳ���
#define m 20
typedef struct {
	KeyType key;
	InfoType otherinfo;
}HashTable[m];		//hash����

//ɢ�к���
#define NULLKEY 0
int Hash(int key) {
	//һ��ѡ�������������Ϊhash������������ѡ��С�ڱ�������
	return key % 19;
}

#define NULLKEY 0
int SearchHash(HashTable HT, KeyType key) {
	int H0 = Hash(key);
	if (HT[H0].key == NULLKEY) {
		return -1;		//������ݴ洢����һ����ַ���������Ϊ0��(��ʹ�õ�ַ0)��û�д洢
	}
	else if (HT[H0].key == key) { return H0; }
	else {
		for (int i = 1; i < m; ++i) {		//ʹ������̽��
			int Hi = (H0 + 1) % m;
			if (HT[Hi].key == NULLKEY) { return -1; }
			else if (HT[Hi].key == key) { return Hi; }
		}
		return -1;
	}
}	


void main() {

}