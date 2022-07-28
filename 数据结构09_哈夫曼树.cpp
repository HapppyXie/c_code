#include"数据结构09_树和森林.cpp"


//存储结构		数组中存储数组
typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode,*HuffmanTree;

//哈夫曼编码表的存储表示
typedef char** HuffmanCode;

int Select(HuffmanTree HT, int i) {
	int min1 = 1;
	int min2 = 1;
	for (int j = 2; j <= i; j++) {
		if (HT[i].weight < HT[min1].weight) {
			min1 = i;
		}
		if (HT[i].weight < HT[min2].weight && HT[min2].weight>HT[min1].weight) {
			min2 = i;
		}
	}
	return min1, min2;
}

//构造哈夫曼树
void CreateHuffmanTree(HuffmanTree &HT,int n) {
	if (n <= 1)return;
	int m = 2*n - 1;
	HT = new HTNode[m + 1];	//不适用位置0
	for (int i = 1; i <= m; ++i) {
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; ++i) {	//输入前n个单元中结点的权重
		char weight;
		scanf_s(&weight);
		HT[i].weight = weight;
		//初始化结束
		//通过n-1次的选择，删除，合并来创建哈夫曼树
		int s1 = 1; int s2 = 1;
		s1, s2 = Select(HT, i - 1);//在1<=k<=i-1中选择两个其双亲域为0且权值最小的结点，并返回它们在HT中的序号s1.s2
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}


//根据哈夫曼树求哈夫曼编码
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n) {
	HC = new char* [n + 1];
	char *cd = new char[n];
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0) {
			--start;
			if (HT[f].lchild == c)cd[start] = 0;
			else cd[start] = 1;
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];		//为HC中第i个便分配存储空间
		//strcopy(HC[i],&cd[start]);//将求得的编码从临时空间cd复制到HC的当前行
	}
	delete cd;		//释放临时空间
}






