#include<stdio.h>
#include<Windows.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef char ElemType;

//ͼ���ڽӾ����ʾ��
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;

//ͼ���ڽӱ�洢��ʾ��
typedef char OtherInfo;
typedef struct ArcNode {	//�߽��
	int adjvex;					//�ı���ָ��Ķ���λ��
	struct ArcNode* nextarc;	//��һ���߽��ĵ�ַ
	OtherInfo info;				//������Ϣ
}ArcNode;
typedef struct VNode {		//ͷ���
	VerTexType data;		//��Ϣ
	ArcNode* firstarc;		//��һ���߽���λ��
}VNode,AdjList[MVNum];
typedef struct {		//�ڽӱ�
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;



//���ݶ����ֵ�������ڶ�����е��±꣬���������ڽӾ���ĸ�������
int LocateVex(AMGraph G, VerTexType vex) {
	for (int i = 0; i < G.vexnum; ++i) {
		if (vex == G.vexs[i]) {
			return i;
		}
	}
}
//���������ڽӾ���
Status createUDN(AMGraph &G) {
	//���붥�������ܱ���
	printf("�����붥����:");
	scanf_s("%d",&G.vexnum);
	printf("�������ܱ���:");
	scanf_s("%d", &G.arcnum);

	for (int i = 0; G.vexnum; ++i) {
		printf("ѭ�����������:");
		scanf_s("%d",&G.vexs[i]);
	}
	for (int i = 0; i < G.vexnum; ++i) {
		for (int j = 0; j < G.vexnum; ++j) {
			G.arcs[i][j] = MaxInt;	//��ʼ���ڽӾ���
		}
	}
	for (int k = 0; k < G.arcnum; ++k) {
		//������������Ĺؼ�ֵ��������ߣ��ٶԱ߸�ֵ���ޱ߱��������
		VerTexType v1;
		VerTexType v2;
		printf("�������һ���ߵĹؼ���");
		scanf_s("%d", &v1);
		printf("��������һ���ߵĹؼ���");
		scanf_s("%d", &v2);
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		printf("������ı�Ȩ��:");
		ArcType weight;
		scanf_s("%d", &weight);
		G.arcs[i][j] = weight;
		G.arcs[j][i] = weight;
	}
	return OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//���ݶ����ֵ�������ڶ�����е��±꣬���������ڽӱ�ĸ�������
int LocateVex2(ALGraph G, VerTexType vex) {
	for (int i = 0; i < G.vexnum; ++i) {
		if (vex == G.vertices[i].data) {
			return i;
		}
	}
}
//ʹ���ٽֱ�������ͼ
Status CreateUDG(ALGraph& G) {
	//���붥�������ܱ���
	printf("�����붥����:");
	scanf_s("%d", &G.vexnum);
	printf("�������ܱ���:");
	scanf_s("%d", &G.arcnum);
	for(int i=0;i<G.vexnum;++i){
			//���붥����Ϣ data
		G.vertices[i].data = 'x';
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; ++k) {
		//������������Ĺؼ�ֵ��������ߣ��ٶԱ߸�ֵ���ޱ߱��������
		VerTexType v1;
		VerTexType v2;
		printf("�������һ���ߵĹؼ���");
		scanf_s("%d", &v1);
		printf("��������һ���ߵĹؼ���");
		scanf_s("%d", &v2);
		int i = LocateVex2(G, v1);
		int j = LocateVex2(G, v2);
		//����һ���߽��		��iָ��j
		ArcNode* p1 = new ArcNode;	
		p1->adjvex = j;		//ָ���±�j��ͷ���
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;		//ͷ�巨������i��ͷ���ĺ���
		//����һ���߽��  ��jָ��i	�����
		ArcNode* p2 = new ArcNode;
		p2->adjvex = i;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	return OK;
}


void main() {
	AMGraph G;
	createUDN(G);
}