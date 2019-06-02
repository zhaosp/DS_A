//
// Created by Administrator on 2019\5\30 0030.
//

#ifndef DATA_STRUCTURE_GRAPH_H
#define DATA_STRUCTURE_GRAPH_H

#include <stdio.h>

#include <winnt.h>

#include "utility.h"
#include "../Tree/CSTree.h"

BOOLEAN visited[MAX_VERTEX_NUM];

Status (*VisitFunc)(int v); // 函数变量 fixme: 这是啥玩意？

/*
 * 一般操作
 * CreateGraph(&G, V, VR)
 * DestroyGraph(&G)
 * LocateVex(G, u)
 * GetVex(G, v)
 * PutVex(&G, v, value)
 * FirstAdjVex(G, v)
 * NextAdjVex(G, v, w)
 * InsertVex(&G, v)
 * DeleteVex(&G, v)
 * InsertArc(&G, v, w)
 * DeleteArc(&G, v, w)
 * DFSTraverse(G, Visit())
 * BFSTraverse(G, Visit())
 * */
class Graph {
public:
    void DFSForest(CSTree T);
    int GetVex(int v);
    void DFSTree(int v, CSTree pRoot);
public:
    int vexnum, arcnum;
};


void DFS(Graph G, int v);
void DFSTraverse(Graph G, Status (*Visit)(int v));
int FirstAdjVex(Graph &G, int v);
int NextAdjVex(Graph &G, int v, int w);
void BFSTraverse(Graph G, Status (*Visit)(int v));
void DFSForest(Graph G, CSTree T);
int GetVex(Graph G, int v);
void DFSTree(Graph G, int v, CSTree p);

// todo:克鲁斯塔尔算法


#endif //DATA_STRUCTURE_GRAPH_H
