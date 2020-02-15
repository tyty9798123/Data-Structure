//
//  main.c
//  CircularQueue
//
//  Created by Swift on 2020/2/13.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef char ElemType;
typedef struct {
    ElemType *base; //這邊也可以當成數Array
    int front;
    int rear;
} cycleQueue;

void initQueue(cycleQueue *q){
    q->base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if (!q->base){
        exit(0);
    }
    q->front = q->rear = 0;
}

void InsertQueue(cycleQueue *q, ElemType e){
    // assume max-size = 5 rear = 5
    // if (5%5)+1 == 1 (滿了, %已經在上次insert時做完了)
    if( (q->rear+1)%MAXSIZE == q->front ){
        return; //隊列已滿
    }
    q->base[q->rear] = e;
    q->rear = (q->rear+1) % MAXSIZE;
}

void DeleteQueue(cycleQueue *q, ElemType *e){
    if(q->front == q->rear){
        return;
    }
    *e = q->base[q->front];
    q->front = (q->front + 1) % MAXSIZE;
}

int main(int argc, const char * argv[]) {
    return 0;
}
