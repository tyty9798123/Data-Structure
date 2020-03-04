//
//  main.c
//  Tree
//
//  Created by Swift on 2020/2/21.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//創建一個二元樹
void CreateBiTree(BiTree *T){
    char c;
    scanf("%c", &c);
    if ( ' ' == c ){
        *T = NULL;
    }else{
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = c;
        CreateBiTree( &(*T)->lchild ); // 建立左節點
        CreateBiTree( &(*T)->rchild ); // 建立右節點
    }
}
//訪問二元樹節點的具體操作
void visit(char c, int level){
    printf("%c 位於第 %d 層\n", c, level);
}

//前序遍歷二元樹
void PreOrderTraverse(BiTree T, int level){
    if (T){
        // 前序遍歷 : 中 => 左 => 右
        //中
        visit( T->data, level );
        //左
        PreOrderTraverse( T->lchild, level + 1 );
        //右
        PreOrderTraverse( T->rchild, level + 1 );
    }
}
//中序遍歷二元樹
void InOrderTraverse(BiTree T, int level){
    if (T){
        // 中序遍歷 : 左 => 中 => 右
        
        InOrderTraverse( T->lchild, level + 1 );
        visit( T->data, level );
        InOrderTraverse( T->rchild, level + 1 );
    }
}
//後序遍歷二元樹
void PostOrderTraverse(BiTree T, int level){
    if (T){
        PostOrderTraverse( T->lchild, level + 1 );
        PostOrderTraverse( T->rchild, level + 1 );
        visit( T->data, level );
    }
}



int main(int argc, const char * argv[]) {
    
    int level = 1;
    BiTree T = NULL;
    CreateBiTree(&T);
    PreOrderTraverse(T, level);
    return 0;
}
