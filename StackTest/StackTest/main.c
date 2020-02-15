#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int ElemType;
typedef struct{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void initStack(sqStack *s){
    s->base = (ElemType *)malloc( STACK_INIT_SIZE * sizeof(ElemType) );
    if (!s->base){
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e){
    
    if( s->top - s->base >= s->stackSize ){
        s->base = (ElemType *)realloc(s->base
                                      , (s->stackSize + STACK_INIT_SIZE) * sizeof(ElemType));
        if (!s->base){
            exit(0);
        }
        
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }

    *(s->top) = e;
    s->top++;
}

void Pop(sqStack *s, ElemType *e){
    if ( s->top == s->base ){
        return;
    }
    //*e = *--(s->top);
    *e = *(s->top - 1); //先找到指標後取值
    s->top = s->top - 1;
}

void ClearStack(sqStack *s){
    s->top = s->base;
}

void DestroyStack(sqStack *s){
    free(s->base);
    s->base = s->top = NULL;
    s->stackSize = 0;
}

long StackLen (sqStack s){
    return (s.top - s.base);
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
