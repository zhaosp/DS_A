//
// Created by Administrator on 2019\5\30 0030.
//

#include "Graph.h"
#include "../Queue/Queue.h"


/*
 * fixme: 这是个什么操作？
 * */
void Input(InfoType info) {

}

void DFS(Graph G, int v) {
    visited[v] = TRUE;
    VisitFunc(v);
    for(int w=FirstAdjVex(G, v); w>=0; w=NextAdjVex(G, v, w))
        if(!visited[w])
            DFS(G, w);
}

void DFSTraverse(Graph G, Status (*Visit)(int v)) {
    VisitFunc = Visit;  // 初始化访问函数
    for(int i=0; i<G.vexnum; i++)  // 初始化mark数组
        visited[i] = FALSE;
    for(int i=0; i<G.vexnum; i++)
        if(!visited[i])  // 如果没有访问，深度优先遍历
            DFS(G, i);
}

// todo
int FirstAdjVex(Graph &G, int v) {
    return 0;
}

// todo
int NextAdjVex(Graph &G, int v, int w) {
    return 0;
}

void BFSTraverse(Graph G, Status (*Visit)(int v)) {
    for(int v=0; v<G.vexnum; v++)
        visited[v] = false;

    Queue Q;
    InitQueue(Q);

    for(int v=0; v<G.vexnum; v++) {
        if(!visited[v]) {
            visited[v] = true;
            Visit(v);
            EnQueue(Q, v);
            while (!QueueEmpty(Q)) {
                int u;
                DeQueue(Q, u);
                for(int w=FirstAdjVex(G, u); w>=0; w=NextAdjVex(G, u, w))
                    if(!visited[w]) {
                        visited[w] = true;
                        Visit(w);
                        EnQueue(Q, w);
                    }
            }
        }

    }
}

// todo
/*
 * 建立无向图G的深度优先生成森林
 * （最左）孩子（右）兄弟链表T
 * */
void DFSForest(Graph G, CSTree T) {

}

// todo
int GetVex(Graph G, int v) {
    return 0;
}

/*
 * 从第v个顶点出发，深度优先遍历图G，建立以T为根的生成树
 *
 * */
void DFSTree(Graph G, int v, CSTree T) {
    visited[v] = true;
    bool first = true;
    for(int w=FirstAdjVex(G, v); w>=0; w=NextAdjVex(G, v, w)) {
        if(!visited[w]) {
            CSTree p = new CSNode();
            p->data = GetVex(G, w);
            p->firstchild = NULL;
            p->nextsibling = NULL;
            if(first) {// 如果w是v的第一个未被访问的邻接节点，则是左孩子
                T->firstchild = p;
                first = false;
            } else {
                T->nextsibling = p;
            }

            DFSTree(G, w, p);
        }
    }
}

void Graph::DFSForest(CSTree T) {
    T = NULL;
    for(int v=0; v<vexnum; v++)
        visited[v] = false;
    for(int v=0; v<vexnum; v++) {
        if(!visited[v]) { // v是新的生成树的根节点，fixme: why
            CSTree pRoot = new CSNode();
            pRoot->data = GetVex(v);
            pRoot->firstchild = NULL;
            pRoot->nextsibling = NULL;

            if(!T)
                T = pRoot;  // 第一颗生成树的根
            else
                T->nextsibling = pRoot;  // 是其他生成树的根, fixme: 这是我自己改的，和书上不一样
            DFSTree(v, pRoot);
        }
    }
}

// todo
int Graph::GetVex(int v) {
    return 0;
}

// todo
void Graph::DFSTree(int v, CSTree pRoot) {

}
