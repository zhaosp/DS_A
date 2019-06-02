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
