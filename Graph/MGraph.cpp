//
// Created by Administrator on 2019\6\1 0001.
//

#include "MGraph.h"

#include <stdio.h>

int MGraph::LocateVex(VertexType v) {
    return 0;
}

Status MGraph::CreateGraph() {
    scanf("%d", &kind);
    switch (kind) {
        case DG: return CreateDG();
        case DN: return CreateDN();
        case UDG: return CreateUDG();
        case UDN: return CreateUDN();
        default:
            return ERROR;
    }
}

Status MGraph::CreateUDN() {
    bool incInfo; // fixme: 不知道这个是干啥的？
    scanf("%d %d %d", &vexnum, &arcnum, &incInfo);

    // 赋值顶点
    for(int i=0; i<vexnum; i++)
        scanf("%c", &vexs[i]);

    // 初始化边，权值定为无穷大，这是时间消耗的大头
    for(int i=0; i<vexnum; i++)
        for (int j = 0; j < vexnum; ++j)
            arcs[i][j] = {INFINITY, NULL};  // 直接给结构体赋值

    // 构造邻接矩阵
    for(int k=0; k<arcnum; k++) {
        VertexType v1, v2;
        double w;
        scanf("%c %c %f", &v1, &v2, &w);
        int i = LocateVex(v1);
        int j = LocateVex(v2);
        arcs[i][j].adj = w; // adj放权值
        if(incInfo)
            Input(*arcs[i][j].info); // 就是不知道这个操作是干啥的？
        arcs[j][i] = arcs[i][j];
    }

    return true;
}

Status MGraph::CreateUDG() {
    return 0;
}

Status MGraph::CreateDN() {
    return 0;
}

Status MGraph::CreateDG() {
    return 0;
}

void MGraph::Input(InfoType info) {

}

/*
 * 迪杰斯特拉算法，求有向网G的v0顶点到其余顶点v的最短路径P[v]及其带权长度D[v]
 * 若P[v][w]==true，则w是从v0到v当前求得最短路径上的顶点
 * final[v]==true，当且仅当v属于S，即已经求得v0到v的最短路径
 *
 * */
void MGraph::ShortestPath_DIJ(int v0, PathMatrix &P, ShortPathTable &D) {
    bool final[vexnum];  // fixme: 这个数组是干嘛的？
    for(int v=0; v<vexnum; v++) {
        final[v] = false;
        D[v] = arcs[v0][v];
        for(int w=0; w<vexnum; w++) {
            P[v][w] = false;  // 设空路径
            if(*(D[v].info) < INFINITY) { // fixme: 这个判断是我改的，和书上不一样
                P[v][v0] = true;
                P[v][v] = true;
            }
        }
    }

    *(D[v0].info) = 0;
    final[v0] = true;

    // 每次求得v0到某个v顶点的最短路径，并加v到S集
    for(int i=1; i<vexnum; i++) {
        int v;
        int min = INFINITY;
        for(int w=0; w<vexnum; w++)
            if(!final[w])
                if(*(D[w].info) < min) {
                    v = w;
                    min = *(D[w].info);
                }
        final[v] = true;
        for(int w=0; w<vexnum; w++) {
            if(!final[w] && (min + *(arcs[v][w].info))) {
                *(D[w].info) = min + *(arcs[v][w].info);
//                P[w] = P[v]; // fixme: 这是要干啥，
                P[w][v] = true;
            }
        }
    }
}

/*
 * 佛洛依德算法，求有向网G中各对顶点v和w之间的最短路径P[v][w]及其带权长度D[v][w]
 *
 * */
void MGraph::ShortestPath_FLOYD(PathMatrix P[], DistancMatrix &D) {
    for(int v=0; v<vexnum; v++) {
        for(int w=0; w<vexnum; w++) {
            D[v][w] = *(arcs[v][w].info);  // 初始带权长度
            for(int u=0; u<vexnum; u++)
                P[v][w][u] = false;
            if(D[v][w] < INFINITY) {
                P[v][w][v] = true;
                P[v][w][w] = true;
            }
        }
    }

    for(int u=0; u<vexnum; u++)
        for(int v=0; v<vexnum; v++)
            for(int w=0; w<vexnum; w++)
                if(D[v][u] + D[u][w] < D[v][w]) {// 从v经u到w的一条路径更短，fixme: 这是要比较什么
                    D[v][w] = D[v][u] + D[u][w];
                    for(int i=0; i<vexnum; i++)
                        P[v][w][i] = P[v][u][i] || P[u][w][i];  // fixme: 这是要比较什么
                }
}

/*
 * 普利姆算法
 * 依据MST性质，从第u个顶点出发，构造网G的求最小生成树T，输出T的各条边
 *
 * */
void MiniSpanTree_PRIM(MGraph G, VertexType u) {
    int k = LocateVex(G, u);
    for(int j=0; j<G.vexnum; j++)
        if(j!=k)
            ce[j] = {u, G.arcs[k][j].adj}; // {adjvex, lowcost}
    ce[k].lowcost = 0;
    for(int i=1; i<G.vexnum; i++) {
        k = minimum(ce);  // 求出T的下一个节点，第k顶点，fixme: why?
        printf("%c, %c", ce[k].adjvex, G.vexs[k]);
        ce[k].lowcost = 0;  // 第k顶点并入U集
        for(int j=0; j<G.vexnum; j++) {
            if(G.arcs[k][j].adj < ce[j].lowcost)  // 新顶点并入U后重新选择最小边 fixme：很难理解这是干啥的
                ce[j] = {G.vexs[k], G.arcs[k][j].adj};
        }
    }
}

// todo
int LocateVex(MGraph G, VertexType u) {
    return 0;
}

int minimum(closedge c) {
    return 0;
}
