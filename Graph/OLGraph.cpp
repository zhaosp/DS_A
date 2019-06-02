//
// Created by Administrator on 2019\5\31 0031.
//

#include "OLGraph.h"

#include <stdio.h>

Status OLGraph::CreateDG() {
    bool IncInfo;
    scanf("%d %d %d", &vexnum, &arcnum, &IncInfo);

    // 构造表头向量, 初始化
    for(int i=0; i<vexnum; i++) {
        scanf("%c", xlist[i].data);
        xlist[i].firstin = NULL;
        xlist[i].firstout = NULL;
    }

    for(int k=0; k<arcnum; k++) {
        VertexType v1, v2;
        scanf("%c %c", &v1, &v2);
        int i = LocateVex(v1);
        int j = LocateVex(v2);

        // 构造弧
        ArcBox* p = new ArcBox();
        p->tailvex = i;
        p->headvex = j;
        p->hlink = xlist[j].firstin; // 这里其实就是NULL，因为上边才初始化
        p->tlink = xlist[i].firstout;
        p->info = NULL;

        xlist[j].firstin = p;
        xlist[i].firstout = p;

        if(IncInfo)
            Input(p->info);
    }

    return 0;
}

int OLGraph::LocateVex(VertexType v) {
    return 0;
}

void OLGraph::Input(InfoType *info) {

}
