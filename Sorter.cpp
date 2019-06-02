//
// Created by Administrator on 2019\5\30 0030.
//

#include "Sorter.h"

void Sorter::SimpleSelectSort(int* data, int size) {
    for(int i=0; i<size; i++) {
        int minValIdx(i);
        for(int j=i+1; j<size; j++) {
            if(data[minValIdx] > data[j])
                minValIdx = j;
        }

        // swap i, minValIdx
        if(i != minValIdx) {
            int tmp = data[i];
            data[i] = data[minValIdx];
            data[minValIdx] = tmp;
        }
    }
}
