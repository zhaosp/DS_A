//
// Created by Administrator on 2019\5\31 0031.
//

#ifndef DATA_STRUCTURE_TMP_H
#define DATA_STRUCTURE_TMP_H

// 图的十字链表存储结构
#include "Graph/utility.h"

typedef struct ArcBox {
    int headvex, tailvex; // 弧头/弧尾在vertices中的下标
    struct ArcBox *hlink, *tlink; // 弧头相同的下一个弧
    InfoType *info;
}ArcBox;

typedef struct VexNode {
    VertexType data; // 结点的名字之类的数据
    ArcBox *firstin, *firstout; // 第一个出弧/入弧
}VexNode, AdjVex[MAX_VERTEX_NUM];

typedef struct {
    VexNode xlist[MAX_VERTEX_NUM];
    int vexnum, arcnum;
}OLGraph;


#endif //DATA_STRUCTURE_TMP_H
