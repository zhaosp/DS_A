//
// Created by Administrator on 2019\6\1 0001.
//

#include "BinaryTree.h"
#include "../Stack/Stack.h"

/*
 * 二叉树采用二叉链表存储，先序遍历二叉树T的递归算法
 * */
Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType)) {
    if(T) {
        if(Visit(T->data))
            if(PreOrderTraverse(T->lchild, Visit))
                if(PostOrderTraverse(T->rchild, Visit))
                    return OK;
        else
            return ERROR;
    } else
        return OK;

    return 0;
}

Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType e)) {
    Stack S;
    S.InitStack();
//    S.Push(T);
    return OK;
}

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType)) {
    return 0;
}
