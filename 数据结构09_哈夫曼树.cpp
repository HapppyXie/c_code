#include"���ݽṹ09_����ɭ��.cpp"


//�洢�ṹ		�����д洢����
typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode,*HuffmanTree;

//�����������Ĵ洢��ʾ
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

//�����������
void CreateHuffmanTree(HuffmanTree &HT,int n) {
	if (n <= 1)return;
	int m = 2*n - 1;
	HT = new HTNode[m + 1];	//������λ��0
	for (int i = 1; i <= m; ++i) {
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; ++i) {	//����ǰn����Ԫ�н���Ȩ��
		char weight;
		scanf_s(&weight);
		HT[i].weight = weight;
		//��ʼ������
		//ͨ��n-1�ε�ѡ��ɾ�����ϲ���������������
		int s1 = 1; int s2 = 1;
		s1, s2 = Select(HT, i - 1);//��1<=k<=i-1��ѡ��������˫����Ϊ0��Ȩֵ��С�Ľ�㣬������������HT�е����s1.s2
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}


//���ݹ������������������
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
		HC[i] = new char[n - start];		//ΪHC�е�i�������洢�ռ�
		//strcopy(HC[i],&cd[start]);//����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�ǰ��
	}
	delete cd;		//�ͷ���ʱ�ռ�
}






