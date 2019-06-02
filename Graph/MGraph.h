//
// Created by Administrator on 2019\6\1 0001.
//

#ifndef DATA_STRUCTURE_MGRAPH_H
#define DATA_STRUCTURE_MGRAPH_H

#include "utility.h"

typedef struct ArcCell {
    VRType adj; // 对于带权的图，是权值类型；对于无权图，用1/0表示相邻否
    InfoType *info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

/*
 * 图的邻接矩阵表示
 *
 * */
class MGraph {
public:
    Status CreateGraph();
    Status CreateDG();
    Status CreateDN();
    Status CreateUDG();
    Status CreateUDN();
    int LocateVex(VertexType v);
    void Input(InfoType info);
public:
    VertexType vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum, arcnum;
    GraphKind kind;
};

void MiniSpanTree_PRIM(MGraph G, VertexType u);
int LocateVex(MGraph G, VertexType u);


// 普利姆算法的辅助数组，定义代价最小的边
typedef struct {
    VertexType adjvex;
    VRType lowcost;
}closedge[MAX_VERTEX_NUM];

closedge ce;

int minimum(closedge c);

#endif //DATA_STRUCTURE_MGRAPH_H
