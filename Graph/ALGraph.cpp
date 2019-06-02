//
// Created by Administrator on 2019\5\31 0031.
//

#include "ALGraph.h"
#include "AMLGraph.h"
#include "../Stack/Stack.h"

#include <stdio.h>

static bool visitedArr[MAX_VERTEX_NUM];

/*
 * 连通图G以邻接表作为存储结构
 * 查找并输出G的全部关节点
 * 全局变量count统计访问计数
 *
 * */

int count;
int low[MAX_VERTEX_NUM];  // fixme: 这个数组是干啥的

void ALGraph::FindArticul() {
    count = 1;
    visitedArr[0] = 1; // 0号顶点为生成树的根
    for(int i=1; i<vexnum; i++) {
        visitedArr[i] = 0;  // 其余顶点未访问
    }

    ArcNode *p = vertices[0].firstarc;
    int v = p->adjvex; // 弧所指向的顶点的下标
    DFSArticul(v);

    if(count < vexnum) {
        printf("%d, %d", 0, vertices[0].data);
        while (p->nextarc) {
            p = p->nextarc;
            v = p->adjvex;
            if(visitedArr[v] == 0)
                DFSArticul(v);
        }
    }
}

/*
 * 从第v0个顶点出发，深度优先遍历图G，查找并输出关节点
 *
 * */
void ALGraph::DFSArticul(int v0) {
    // v0是第count个访问的顶点
    int min = ++count;
    visitedArr[v0] = min;

    for(ArcNode* p = vertices[v0].firstarc; p; p=p->nextarc) {
        int w = p->adjvex; // v0的每个邻接点w
        if(visitedArr[w] == 0) { // 如果w未访问，就是v0的孩子
            DFSArticul(w);
            if(low[w] < min)
                min = low[w];
            if(low[w] >= visitedArr[v0])
                printf("%d %c", v0, vertices[v0].data);
        } else if (visitedArr[w] < min) // w已访问，是v0在生成树上的祖先
            min = visitedArr[w];
    }
    low[v0] = min;
}

/*
 * 有向图G采用邻接表存储结构
 * 若G无回路，输出G的顶点的一个拓扑排序，否则返回ERROR
 *
 * */
Status ALGraph::TopologicalSort() {
    int indegree[vexnum];
    FindInDegree(indegree);  // 对各个顶点求入度

    Stack S;  // 存储入度为0
    S.InitStack();
    for(int i=0; i<vexnum; i++)
        if(!indegree[i])
            S.Push(i); // 入度为0者，进栈

    int count(0);  // 对输出顶点计数
    while (!S.StackEmpty()) {
        int i;
        S.Pop(i);
        printf("%d, %c", i, vertices[i].data);  // 输出i号顶点
        ++count;

        // i是度为0的节点，遍历他的边，邻接顶点的入度减1,（如果为0，进栈，下一趟遍历）
        for(ArcNode* p = vertices[i].firstarc; p; p=p->nextarc) {
            int k = p->adjvex;
            if(!(--indegree[k]))
                S.Push(k);
        }
    }

    if(count < vexnum)  // 还有节点没有处理
        return ERROR;

    return OK;
}

void ALGraph::FindInDegree(int *indegree) {

}

/*
 * 有向图G采用邻接表存储
 * 求各顶点事件的最早发生时间ve
 * T为拓扑序列的顶点栈，S为入度为0的顶点栈
 * 若G无回路，则栈T返回G的一个拓扑序列，返回值OK，否则返回ERROR
 *
 * */
Status ALGraph::TopologicalOrder(Stack &T) {
    // 求各顶点入度
    int indegree[vexnum];
    FindInDegree(indegree);

    // 初始化拓扑序列顶点栈
    T.InitStack();
    int count(0);
    for(int i=0; i<vexnum; i++)
        ve[i] = 0;

    while (!S.StackEmpty()) {
        int j;
        S.Pop(j);
        T.Push(j);
        ++count;

        for(ArcNode* p = vertices[j].firstarc; p; p=p->nextarc) {
            int k = p->adjvex;
            if(--indegree[k] == 0)
                S.Push(k);

            // fixme: 这是要干啥？
            if(ve[j] + *(p->info) > ve[k])
                ve[k] = ve[j] + *(p->info);
        }
    }

    if(count < vexnum)
        return ERROR;

    return OK;
}

/*
 * 有向图G采用邻接表存储
 * 输出G的各项关键活动
 *
 * */
Status ALGraph::CriticalPath() {
    Stack T;
    if(!TopologicalOrder(T))
        return ERROR;

    // 初始化顶点事件的最迟发生时间
    for(int i=0; i<vexnum; i++)
        vl[i] = ve[i];

    while (!T.StackEmpty()) {// 按拓扑逆序求各顶点的vl值
        int j;
        T.Pop(j);
        for(ArcNode* p = vertices[j].firstarc; p; p = p->nextarc) {
            int k = p->adjvex;
            int dut = *(p->info);

            // fixme: 这是要干啥？
            if(vl[k]-dut < vl[j])
                vl[j] = vl[k] - dut;
        }

        for(int j=0; j<vexnum; j++) {
            for(ArcNode *p = vertices[j].firstarc; p; p=p->nextarc) {
                int k = p->adjvex;
                int dut = *(p->info);
                int ee = ve[j];  // 最早开始时间
                int el = vl[k] - dut;  // 最迟开始时间
                char tag = ee == el?'*':' '; // 关键活动 打印*号
                printf("%d %d %d %d %d %c", j, k, dut, ee, el, tag);
            }
        }
    }

    return OK;
}