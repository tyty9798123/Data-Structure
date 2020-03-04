#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
void BFSTraverse(MGraph G){
    int i, j;
    Queue Q;
    for ( i = 0; i < G.numVertexes; i++){
        visited[i] = FALSE;
    }
    initQueue(Q);
    
    for ( i = 0; i < G.numVertexse; i++){
        if ( !visited[i] ){
            //打印
            print( "%c", G.vex[i] );
            //標誌已訪問
            visited[i] = TRUE;
            //插入隊列
            EnQueue(&Q, i);
            //只要隊列不為空
            while ( !QueueEmpty(Q) ){
                //彈出隊列 存放於i
                DeQueue(&Q, &i);
                for (j = 0; j < G.numVertexes; j++){
                    //如果有邊連接起來 並且沒被訪問過
                    if (  G.art[i][j] == 1 &&  !visited[j] ){
                        //打印
                        print( "%c", G.vex[j] );
                        //標誌已訪問
                        visited[j] = TRUE;
                        //插入隊列
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
