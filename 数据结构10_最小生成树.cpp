#include"数据结构10_图.cpp"

//最小生成树：在一个连通网的所有生成树中，各边的代价之和最小的那颗生成树称为该连通网的最小代价生成树（最小生成树）
//构造最小生成树的方法
//prim普利姆算法
struct {
	VerTexType adjvex;	//最小边在U中的那个顶点
	ArcType lowcost;	//最小边上的权值
}closedge[MVNum];	//U集



void MinSpanTree_Prim(AMGraph G, VerTexType u) {
//无向图G以邻接矩阵形式存储，从顶点u出发构造最小生成树T，输出T的各边	
	int k = LocateVex(G,u);	//找出u在顶点表中的下标k
	for (int j = 0; j < G.vexnum; ++j) {
		if (j != k) {
			closedge[j] = { u,G.arcs[k][j]};		//初始化closedge结构数组（存储k顶点和k相连的顶点）,将k和其他的顶点的边和权重赋值到此结构数组
		}
	}//for
	closedge[k].lowcost = 0;//权重为0代表加入U集

	for (int i = 1; i < G.vexnum; ++i) {
		//k = Min(closedge);	//在结构数组中寻找到顶点权重最小的顶点，返回其下标k
		int u0 = closedge[k].adjvex;	//最小边的一个顶点	u0属于U
		int v0 = G.vexs[k];				//最小边的另一个顶点	v0属于V-U
		//输出u0,v0
		closedge[k].lowcost = 0;	//将第k个顶点加入U集
		for (int j = 0; j < G.vexnum; ++j) {	//此处邻接矩阵有权，有权记其权，无权记无穷大MaxInt
			if (G.arcs[k][j]<closedge[j].lowcost) {
	//在新找到的k顶点的各路权--和--前一个找到的顶点各路权相比,如果前一个的权大，则新找到的k顶点权覆盖其在辅助结构数组中的位置
				closedge[j] = { G.vexs[k],G.arcs[k][j] };
			}
		}//for
	}//for

}

//最短路径问题-单源最短路径
//迪杰斯特拉算法
void ShortestPath_DIJ(AMGraph G, int v0) {
	//求有向网G的v0顶点到其余顶点的最短路径
	int n = G.vexnum;
	bool *S = new bool[n];	//如果最短路径经过该点则为true，否则为false
	int *Path = new int[n];	//记录从源点v0到终点vi的直接前驱	如果v0到vi有弧，则vi的直接前驱为v0,否则为-1
	int *D = new int[n];	//记录从源点v0到vi的当前最短路径，有弧及其权重，否则记无穷大MaxInt
	
	for (int v = 0; v < n; ++v) {
		S[v] = false;
		D[v] = G.arcs[v0][v];
		if (D[v] < MaxInt) { Path[v] = v0; }
		else { Path[v] = -1; }
	}
	S[v0] = true;
	D[v0] = 0;

	//初始化结束
	for (int i = 1; i < n; ++i) {
		int min = MaxInt;
		int v;
		for (int w = 0; w < n; ++w) {
			if (!S[w] && D[w] < min) {
				v = w; min = D[w];	//循环结束,min为最小
			}
		}//for

		S[v] = true;
		for (int w = 0; w < n; ++w) {	//更新v0出发到集合V-S上所有顶点的最短路径长度
			if (!S[w] && (D[v] + G.arcs[v][w] < D[w])) {
				D[w] = D[v] + G.arcs[v][w];
				Path[w] = v;
			}
		}//for

	}//for
}