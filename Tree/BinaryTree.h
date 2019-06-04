//
// Created by Administrator on 2019\6\1 0001.
//

#ifndef DATA_STRUCTURE_BINARYTREE_H
#define DATA_STRUCTURE_BINARYTREE_H

#include "utility.h"

class BinaryTree {
public:
    /*
     * 二叉树的基本操作
     * */
    InitBiTree();
    DestroyBiTree();
    CreateBiTree();
    ClearBiTree();
    BiTreeEmpty();
    BiTreeDepth();
    Root();
    Value();
    Assign();
    Parent();
    LeftChild();
    RightChild();
    LeftSibling();
    RightSibling();
    InsertChild();
    DeleteChild();
    PreOrderTraverse();
    InOrderTraverse();
    PostOrderTraverse();
    LevelOrderTraverse();
};

/*
 * 二叉树的顺序存储表示，仅适用于完全二叉树，对于单支树特别浪费存储空间
 * */
typedef TElemType SqBiTree[MAX_TREE_SIZE];  // 0号单元存储根节点
SqBiTree bt;

/*
 * 二叉树的二叉链表存储表示
 * */
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
Status CreateBiTree(BiTree &T);
Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType e));
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));

#endif //DATA_STRUCTURE_BINARYTREE_H
