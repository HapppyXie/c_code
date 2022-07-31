#include"数据结构10_图.cpp";

//深度优先遍历
//使用邻接矩阵表示图进行深度优先搜索遍历
bool visited1[MVNum];
void DFS_AM(AMGraph G, int v) {
	printf("%c", G.vexs[v]);
	visited1[v] = true;	//访问第v个顶点		确定行,下面依次访问列，访问一行完，访问下一个顶点(和上一个顶点相连的)的行
	for (int w = 0; w < G.vexnum; w++) {
		if ((G.arcs[v][w] != MaxInt) && (!visited1[w])) {
			DFS_AM(G, w);
		}
	}
}

bool visited2[MVNum];
//使用邻接表表表示图的深度优先搜索遍历
void DFS_AL(ALGraph G, int v) {
	printf("%c", G.vertices[v]);
	visited2[v] = true;			//访问第v个顶点，并设置对应的标志数组为true
	ArcNode* p = G.vertices[v].firstarc;
	while (p != NULL) {		//p为头结点的边结点，不为空说明有边		即v到w的边
		int w = p->adjvex;	
		if (!visited2[w]) {	//如果没被访问，则递归访问
			DFS_AL(G,w);	
		}
		p = p->nextarc;
	}
}

/////////////////////////////////////////////////////
//广度优先遍历
//使用广度优先搜索遍历连通图

	
