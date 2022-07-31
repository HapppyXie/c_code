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
//宏定义后面不需要;

//以下讨论的排序算法，以此结构
#define MAXSIZE 20
typedef int KeyType;
typedef int InfoType;
typedef struct {
	KeyType key;
	InfoType otherinfo;
}RedType;		//记录类型
typedef struct {
	RedType r[MAXSIZE];
	int length;
}SqList;			//使用顺序表结构数组
	

//插入排序
//直接插入排序
void InsertSort(SqList& L) {
	for (int i = 2; i < L.length; ++i) {
		if (L.r[i].key < L.r[i - 1].key) {		//如果前驱大则后移
			L.r[0] = L.r[i];
			L.r[i] = L.r[i - 1];
			int j;
			for (j = i - 2; L.r[0].key < L.r[j].key; --j) {
				L.r[j + 1] = L.r[j];
			}	//直到L.r[0].key>=L.r[j].key跳出循环
			L.r[j + 1] = L.r[0];
		}
	}
}

//折半插入排序
void BInsertSort(SqList& L) {
	for (int i = 2; i < L.length; ++i) {
		L.r[0] = L.r[i];
		int low = 1; 
		int high = i - 1;
		while (low <= high) {
			int m = (low + high) / 2;
			if (L.r[0].key < L.r[m].key) {
				high = m - 1;
			}
			else {
				low = m + 1;
			}		
		}	//直到low>high		但low=m+1，故high，m为插入位置
		for (int j = i - 1; j >= high + 1; --j) {
			L.r[j + 1] = L.r[j];
		}
		L.r[high + 1] = L.r[0];
	}
}

//希尔排序
void ShellInsert(SqList &L,int dk) {
	for (int i = dk + 1; i < L.length; ++i) {
		if (L.r[i].key < L.r[i - dk].key) {
			L.r[0] = L.r[i];
			int j;
			for (j = i - dk; (j > 0 && L.r[0].key < L.r[j].key); j -= dk) {
				L.r[j + dk] = L.r[j];
			}
			L.r[j + dk] = L.r[0];
		}
	}
}
void ShellSort(SqList& L, int dt[], int t) {
	//按增量序列dt[0...t-1]对顺序表L做t此希尔排序
	for (int k = 0; k < t; ++k) {
		ShellInsert(L,dt[k]);//最后一次的增量为1
	}
}

//交换排序
//冒泡排序
void BubbleSort(SqList& L) {
	int m = L.length - 1;
	int flag = 1;
	while ((m > 0) && (flag == 1)) {
		flag = 0;		//先将flag置为0，如果下面不发生排序则flag==0，下次不执行
		for (int j = 1; j <= m; j++) {
			if (L.r[j].key > L.r[j + 1].key) {
				flag = 1;
				RedType t = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = t;
			}//if
		}//for
		--m;
	}
}

//快速排序
//分表，返回枢轴
int Partition(SqList& L, int low, int high) {
	L.r[0] = L.r[low];
	KeyType pivotkey = L.r[low].key;
	while (low < high) {
		while ((low < high) && (L.r[high].key >= pivotkey)) {
			--high;
		}
		L.r[low] = L.r[high];
		while ((low < high) && (L.r[low].key <= pivotkey)) {
			--low;
		}
		L.r[high] = L.r[low];
	}//while
	L.r[low] = L.r[0];		//记录枢轴
	return low;
}

void QSort(SqList& L, int low, int high) {
	if (low < high) {
		int pivotloc = Partition(L, low, high);	//找到枢轴
		QSort(L, low, pivotloc - 1);	//递归左子表
		QSort(L, pivotloc + 1, high);	//递归右子表
	}
}

void  QuickSort(SqList& L) {
	QSort(L, 1, L.length);
}

//简单选择排序(直接选择排序)
void SelectSort(SqList& L) {
	for (int i = 1; L.length; ++i) {
		int k = i;
		for (int j = i + 1; j < L.length; ++j) {
			if (L.r[j].key < L.r[k].key) {
				k = j;
			}//if
		}//for
		if (k != i) {
			RedType t = L.r[i];
			L.r[i] = L.r[k];
			L.r[k] = t;
		}//if
	}//for
}

//堆排序
// 调整堆
void HeadAdjust(SqList& L, int s, int m) {
	//假设r[s+1...m]已经是大根堆,将其r[s....m]调整为大根堆
	RedType rc = L.r[s];
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m && (L.r[j].key < L.r[j + 1].key)) {
			++j;	//找到左右子树根节点中最大的
		}//if
		if (rc.key >= L.r[j].key) { break; }
		L.r[s] = L.r[j];
		s = j;
	}
	L.r[s] = rc;
}
//创建堆
void CreateHead(SqList& L) {
	//把无序序列L.r[1..n]建成大根堆
	int n = L.length;
	for (int i = n / 2; i > 0; --i) {		//从最后一个非叶子节点开始
		HeadAdjust(L,i,n);
	}
}
//堆排序算法
void HeadSort(SqList& L) {
	CreateHead(L);	//先建成大根堆
	for (int i = L.length; i > 1; --i) {		//最后一个为最小值
		RedType x = L.r[1];
		L.r[1] = L.r[i];
		L.r[i] = x;			//访问最后一个元素
		HeadAdjust(L, i, i - 1);		//将L.r[1..i-1]调整为大根堆
	}
}

//归并排序
//2-路归并(相邻两个有序子序列的归并)		将R分成两个子表....,最终归并到T中
void Merge(RedType R[], RedType T[], int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = low;
	while (i <= mid && j <= high) {		//两个子表均未到底
		if (R[i].key <= R[j].key) {
			T[k++] = R[i++];
		}
		else {
			T[k++] = R[j++];
		}
	}//while	有一个子表到底
	while (i <= mid) {
		T[k++] = R[i++];
	}
	while (j <= high) {
		T[k++] = R[j++];
	}
}


void main() {

}