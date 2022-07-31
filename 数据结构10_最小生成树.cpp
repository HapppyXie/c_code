#include"���ݽṹ10_ͼ.cpp"

//��С����������һ����ͨ���������������У����ߵĴ���֮����С���ǿ���������Ϊ����ͨ������С��������������С��������
//������С�������ķ���
//prim����ķ�㷨
struct {
	VerTexType adjvex;	//��С����U�е��Ǹ�����
	ArcType lowcost;	//��С���ϵ�Ȩֵ
}closedge[MVNum];	//U��



void MinSpanTree_Prim(AMGraph G, VerTexType u) {
//����ͼG���ڽӾ�����ʽ�洢���Ӷ���u����������С������T�����T�ĸ���	
	int k = LocateVex(G,u);	//�ҳ�u�ڶ�����е��±�k
	for (int j = 0; j < G.vexnum; ++j) {
		if (j != k) {
			closedge[j] = { u,G.arcs[k][j]};		//��ʼ��closedge�ṹ���飨�洢k�����k�����Ķ��㣩,��k�������Ķ���ıߺ�Ȩ�ظ�ֵ���˽ṹ����
		}
	}//for
	closedge[k].lowcost = 0;//Ȩ��Ϊ0�������U��

	for (int i = 1; i < G.vexnum; ++i) {
		//k = Min(closedge);	//�ڽṹ������Ѱ�ҵ�����Ȩ����С�Ķ��㣬�������±�k
		int u0 = closedge[k].adjvex;	//��С�ߵ�һ������	u0����U
		int v0 = G.vexs[k];				//��С�ߵ���һ������	v0����V-U
		//���u0,v0
		closedge[k].lowcost = 0;	//����k���������U��
		for (int j = 0; j < G.vexnum; ++j) {	//�˴��ڽӾ�����Ȩ����Ȩ����Ȩ����Ȩ�������MaxInt
			if (G.arcs[k][j]<closedge[j].lowcost) {
	//�����ҵ���k����ĸ�·Ȩ--��--ǰһ���ҵ��Ķ����·Ȩ���,���ǰһ����Ȩ�������ҵ���k����Ȩ�������ڸ����ṹ�����е�λ��
				closedge[j] = { G.vexs[k],G.arcs[k][j] };
			}
		}//for
	}//for

}

//���·������-��Դ���·��
//�Ͻ�˹�����㷨
void ShortestPath_DIJ(AMGraph G, int v0) {
	//��������G��v0���㵽���ඥ������·��
	int n = G.vexnum;
	bool *S = new bool[n];	//������·�������õ���Ϊtrue������Ϊfalse
	int *Path = new int[n];	//��¼��Դ��v0���յ�vi��ֱ��ǰ��	���v0��vi�л�����vi��ֱ��ǰ��Ϊv0,����Ϊ-1
	int *D = new int[n];	//��¼��Դ��v0��vi�ĵ�ǰ���·�����л�����Ȩ�أ�����������MaxInt
	
	for (int v = 0; v < n; ++v) {
		S[v] = false;
		D[v] = G.arcs[v0][v];
		if (D[v] < MaxInt) { Path[v] = v0; }
		else { Path[v] = -1; }
	}
	S[v0] = true;
	D[v0] = 0;

	//��ʼ������
	for (int i = 1; i < n; ++i) {
		int min = MaxInt;
		int v;
		for (int w = 0; w < n; ++w) {
			if (!S[w] && D[w] < min) {
				v = w; min = D[w];	//ѭ������,minΪ��С
			}
		}//for

		S[v] = true;
		for (int w = 0; w < n; ++w) {	//����v0����������V-S�����ж�������·������
			if (!S[w] && (D[v] + G.arcs[v][w] < D[w])) {
				D[w] = D[v] + G.arcs[v][w];
				Path[w] = v;
			}
		}//for

	}//for
}