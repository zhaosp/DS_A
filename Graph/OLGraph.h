//
// Created by Administrator on 2019\5\31 0031.
//

#ifndef DATA_STRUCTURE_OLGRAPH_H
#define DATA_STRUCTURE_OLGRAPH_H

#include "utility.h"

/*
 * 有向图的十字链表存储表示
 *
 * */

typedef struct ArcBox {
    int tailvex, headvex; // 尾头节点在xlist的下标
    struct ArcBox* hlink, *tlink; // fixme: ?
    InfoType *info;
}ArcBox;

typedef struct VexNode {
    VertexType data;
    ArcBox *firstin, *firstout;  // 第一条入弧，出弧
}VexNode;

class OLGraph {
public:
    Status CreateDG();
    void Input(InfoType* info);
    int LocateVex(VertexType v);
public:
    VexNode xlist[MAX_VERTEX_NUM]; // 表头向量
    int vexnum, arcnum;
};

#endif //DATA_STRUCTURE_OLGRAPH_H