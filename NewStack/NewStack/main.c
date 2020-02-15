#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MAXBUFFER 10

typedef char ElemType;
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
    sqStack s;
    char c, e;
    
    initStack( &s );
    
    printf("請輸入中綴表達式，以#作為結束標誌：");
    
    scanf("%c", &c);
    
    while ( c!= '#' ) {
        while ( isdigit(c) ){
            printf("%c", c);
            scanf("%c", &c);
            
            if ( !isdigit(c) ){
                printf(" ");
            }
        }
        if ( c == ')' ){
            Pop(&s, &e);
            while ( e != '(' ) {
                printf("%c", e);
                Pop(&s, &e);
            }
        }
        else if ( '+' == c || '-' == c ){
            if (!StackLen(s)){
                Push(&s, c);
            }
            else{
                
                do{
                    Pop(&s, &e);
                    if (e == '('){
                        Push(&s, e);
                    }
                    else{
                        printf("%c", e);
                    }
                }while( StackLen(s) && '(' != e );
                Push(&s, c);
            }
        }
        else if ( '*' == c || '/' == c || '(' == c ){
            Push(&s, c);
        }
        else if ( '#' == c){
            break;
        }
        else{
            printf("\n輸入格式錯誤\n");
            return -1;
        }
        scanf("%c", &c);
    }
    
    while ( StackLen(s)) {
        Pop(&s, &e);
        printf("%c", e);
    }
    printf("\n");

    return 0;
}
