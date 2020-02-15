#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct DualNode{ //雙向循環鏈表
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode, *DuLinkList;

Status InitList(DuLinkList *L){
    DualNode *p, *q;
    
    int i;
    
    *L = (DuLinkList)malloc( sizeof(DuLinkList) );
    
    if (!*L){
        return ERROR;
    }
 
    (*L)->next = (*L)->prior = NULL;
    
    p = (*L);
    
    for( i = 0; i < 26 ; i++) {
        q = (DualNode *)malloc(sizeof(DualNode));
        
        if (!q){
            return ERROR;
        }
        //只有雙向，沒有循環
        q->data = 'A'+i;
        q->prior = p;
        q->next = p->next;
        p->next = q;
        
        p = q;
    }
    
    //形成環
    
    //最後的下一個指到第一個的上一個 (這邊也被騙了，因為他是指向第二個元素，而不是第一個L)
    p->next = (*L)->next;
    //第一個的上一個指向最後一個
    //這裏為什麼要next呢，我也被騙了
    //因為第一個是沒Data的，所以是從第二個開始
    (*L)->next->prior = p;
    
    return OK;
}

void Caesar(DuLinkList *L, int i){
    if (i > 0){
        //因為從第二個開始 所以用do while 不然要寫兩遍
        do{
            (*L) = (*L)->next;
        }while( --i );
    }
    
    if (i < 0){
        (*L) = (*L)->next->prior;
        int index;
        for ( index = 0; index < i*(-1); index++ ){
            (*L) = (*L)->prior;
        }
    }
}

int main(int argc, const char * argv[]) {
    DuLinkList L;
    int i, n;
    InitList(&L);
    printf("請輸入一個整數：");
    scanf("%d", &n);
    printf("\n");
    Caesar(&L, n);
    
    for ( i = 0; i < 26; i++ ){
        L = L->next;
        printf("%c", L->data);
    }
    
    printf("\n");
    return 0;
}
