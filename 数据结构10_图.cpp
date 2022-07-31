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

//图的邻接矩阵表示法
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;

//图的邻接表存储表示法
typedef char OtherInfo;
typedef struct ArcNode {	//边结点
	int adjvex;					//改变所指向的顶点位置
	struct ArcNode* nextarc;	//下一个边结点的地址
	OtherInfo info;				//其他信息
}ArcNode;
typedef struct VNode {		//头结点
	VerTexType data;		//信息
	ArcNode* firstarc;		//第一个边结点的位置
}VNode,AdjList[MVNum];
typedef struct {		//邻接表
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;



//根据顶点的值查找其在顶点表中的下标，创建无向邻接矩阵的辅助方法
int LocateVex(AMGraph G, VerTexType vex) {
	for (int i = 0; i < G.vexnum; ++i) {
		if (vex == G.vexs[i]) {
			return i;
		}
	}
}
//创建无向邻接矩阵
Status createUDN(AMGraph &G) {
	//输入顶点数和总边数
	printf("请输入顶点数:");
	scanf_s("%d",&G.vexnum);
	printf("请输入总边数:");
	scanf_s("%d", &G.arcnum);

	for (int i = 0; G.vexnum; ++i) {
		printf("循环创建定点表:");
		scanf_s("%d",&G.vexs[i]);
	}
	for (int i = 0; i < G.vexnum; ++i) {
		for (int j = 0; j < G.vexnum; ++j) {
			G.arcs[i][j] = MaxInt;	//初始化邻接矩阵
		}
	}
	for (int k = 0; k < G.arcnum; ++k) {
		//输入两个顶点的关键值，查找其边，再对边赋值，无边保留无穷大
		VerTexType v1;
		VerTexType v2;
		printf("请输入第一条边的关键字");
		scanf_s("%d", &v1);
		printf("请输入另一条边的关键字");
		scanf_s("%d", &v2);
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		printf("请输入改变权重:");
		ArcType weight;
		scanf_s("%d", &weight);
		G.arcs[i][j] = weight;
		G.arcs[j][i] = weight;
	}
	return OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//根据顶点的值查找其在顶点表中的下标，创建无向邻接表的辅助方法
int LocateVex2(ALGraph G, VerTexType vex) {
	for (int i = 0; i < G.vexnum; ++i) {
		if (vex == G.vertices[i].data) {
			return i;
		}
	}
}
//使用临街表创建无向图
Status CreateUDG(ALGraph& G) {
	//输入顶点数和总边数
	printf("请输入顶点数:");
	scanf_s("%d", &G.vexnum);
	printf("请输入总边数:");
	scanf_s("%d", &G.arcnum);
	for(int i=0;i<G.vexnum;++i){
			//输入顶点信息 data
		G.vertices[i].data = 'x';
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; ++k) {
		//输入两个顶点的关键值，查找其边，再对边赋值，无边保留无穷大
		VerTexType v1;
		VerTexType v2;
		printf("请输入第一条边的关键字");
		scanf_s("%d", &v1);
		printf("请输入另一条边的关键字");
		scanf_s("%d", &v2);
		int i = LocateVex2(G, v1);
		int j = LocateVex2(G, v2);
		//生成一个边结点		由i指向j
		ArcNode* p1 = new ArcNode;	
		p1->adjvex = j;		//指向下标j的头结点
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;		//头插法，插入i的头结点的后面
		//生成一个边结点  由j指向i	无向边
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