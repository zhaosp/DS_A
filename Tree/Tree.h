//
// Created by Administrator on 2019\6\1 0001.
//

#ifndef DATA_STRUCTURE_TREE_H
#define DATA_STRUCTURE_TREE_H


class Tree {
public:
    /*
     * 以下是树的基本操作
     * */
    bool InitTree();
    bool DestroyTree();
    bool CreateTree();
    bool ClearTree();
    bool TreeEmpty();
    int TreeDepth();
    void Root(); // 返回root结点
    int Value(int cur_e);
    void Assign();

    void Parent(int cur_e);
    LeftChild(int cur_e);
    RightSibling(int cur_e);
    InsertChild();
    DeleteChild();
    TraverseTree();
};


#endif //DATA_STRUCTURE_TREE_H
