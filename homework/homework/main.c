//
//  main.c
//  homework
//
//  Created by Swift on 2020/2/14.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef char ElemType;
typedef struct QNode {
    ElemType data;
    struct QNode *Next;
} QNode, *QueuePtr;
typedef struct {
    QueuePtr front, rear;
} LinkQueue;
void initQueue(LinkQueue *q){
    q->front = q->rear = (QueuePtr)malloc( sizeof(QNode) );
    
    if ( !q->front ){
        exit(0);
    }
    
    q->front->Next = NULL;
}
void InsertQueue(LinkQueue *q, ElemType e){
    QueuePtr p;
    p = (QueuePtr)malloc( sizeof(QNode) );
    if( p == NULL){
        exit(0);
    }
    p->data = e;
    p->Next = NULL;
    q->rear->Next = p;
    q->rear = p;
}
void DeleteQueue(LinkQueue *q, ElemType *e){
    QueuePtr p;
    if ( q->front == q->rear ){
        return;
    }
    p = q->front->Next;
    *e = p->data;
    q->front->Next = p->Next;
    
    if (q->rear == p){
        q->rear = q->front;
    }
    
    free(p);
}
void DestroyQueue(LinkQueue *q){
    while (q->front) {
        q->rear = q->front->Next;
        free(q->front);
        q->front = q->rear;
    }
}


int main(int argc, const char * argv[]) {
    LinkQueue lq;
    initQueue(&lq);
    char c;
    char e;
    int size = 0;
    int sum = 0;
    while (1) {
        scanf("%c", &c);
        if (c == '\n'){
            printf("%d\n", sum);
            return 0;
        }
        if (c == ' '){
            int i;
            for(i = size - 1; i >= 0; i--){
                DeleteQueue(&lq, &e);
                int b = e-'0';
                sum += (b * pow(10, i));
            }
            size = 0;
            continue;
        }
        InsertQueue(&lq, c);
        size++;
    }
    return 0;
}
