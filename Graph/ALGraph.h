//
// Created by Administrator on 2019\5\31 0031.
//

#ifndef DATA_STRUCTURE_ALGRAPH_H
#define DATA_STRUCTURE_ALGRAPH_H

#include "utility.h"

typedef struct ArcNode {
    int adjvex; // 弧所指向顶点的位置，也就是VertexType[]数组的下标，也就是vertices的下标
    struct ArcNode* nextarc;  // 指向下一条弧的指针
    InfoType* info;  // 该弧相关的信息
}ArcNode;

typedef struct VNode {// 头结点
    VertexType data;
    ArcNode* firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

/*
 * 图的邻接表存储表示
 *
 * */
class ALGraph {
public:
    void FindArticul();
    void DFSArticul(int v);
    Status TopologicalSort();
    void FindInDegree(int* indegree);
public:
    AdjList vertices;  // 头结点数组
    int vexnum, arcnum;
    GraphKind kind;
};

#endif //DATA_STRUCTURE_ALGRAPH_H