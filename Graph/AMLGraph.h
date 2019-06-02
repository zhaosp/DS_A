//
// Created by Administrator on 2019\6\1 0001.
//

#ifndef DATA_STRUCTURE_AMLGRAPH_H
#define DATA_STRUCTURE_AMLGRAPH_H

#include "utility.h"

typedef enum {unvisited, visited} VisitIf;

typedef struct EBox {
    VisitIf mark;
    int ivex, jvex;  // 该边依附的两个顶点的位置
    struct EBox *ilink, *jlink;  // 依附的两个顶点的下一条边
    InfoType *info;
}EBox;

typedef struct VexBox {
    VertexType data;
    EBox *firstedge;
}VexBox;

class AMLGraph {
public:
    VexBox adjmulist[MAX_VERTEX_NUM];
    int vexnum, edgenum;
    static bool visitedArr[MAX_VERTEX_NUM];
};

#endif //DATA_STRUCTURE_AMLGRAPH_H