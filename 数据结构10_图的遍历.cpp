#include"���ݽṹ10_ͼ.cpp";

//������ȱ���
//ʹ���ڽӾ����ʾͼ�������������������
bool visited1[MVNum];
void DFS_AM(AMGraph G, int v) {
	printf("%c", G.vexs[v]);
	visited1[v] = true;	//���ʵ�v������		ȷ����,�������η����У�����һ���꣬������һ������(����һ������������)����
	for (int w = 0; w < G.vexnum; w++) {
		if ((G.arcs[v][w] != MaxInt) && (!visited1[w])) {
			DFS_AM(G, w);
		}
	}
}

bool visited2[MVNum];
//ʹ���ڽӱ���ʾͼ�����������������
void DFS_AL(ALGraph G, int v) {
	printf("%c", G.vertices[v]);
	visited2[v] = true;			//���ʵ�v�����㣬�����ö�Ӧ�ı�־����Ϊtrue
	ArcNode* p = G.vertices[v].firstarc;
	while (p != NULL) {		//pΪͷ���ı߽�㣬��Ϊ��˵���б�		��v��w�ı�
		int w = p->adjvex;	
		if (!visited2[w]) {	//���û�����ʣ���ݹ����
			DFS_AL(G,w);	
		}
		p = p->nextarc;
	}
}

/////////////////////////////////////////////////////
//������ȱ���
//ʹ�ù����������������ͨͼ

	
