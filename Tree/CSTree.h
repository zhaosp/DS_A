//
// Created by Administrator on 2019\6\1 0001.
//

#ifndef DATA_STRUCTURE_CSTREE_H
#define DATA_STRUCTURE_CSTREE_H

//#include "utility.h"
typedef int ElemType;

typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;


#endif //DATA_STRUCTURE_CSTREE_H
