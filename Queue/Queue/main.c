//
//  main.c
//  Queue
//
//  Created by Swift on 2020/2/13.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

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
    char c;
    printf("please enter a string:");
    initQueue(&lq);
    int counter = 0;
    
    while (1) {
        scanf("%c", &c);
        if(c == '#'){
            break;
        }
        InsertQueue(&lq, c);
        counter+=1;
    }
     
    int i;
    for (i = 0; i < counter; i++){
        ElemType e;
        DeleteQueue(&lq, &e);
        printf("%c\n", e);
    }
    
    return 0;
}
