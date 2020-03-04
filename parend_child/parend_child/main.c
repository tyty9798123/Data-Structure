//
//  main.c
//  parend_child
//
//  Created by Swift on 2020/2/17.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>

#define MAX_TREE_SIZE 100

typedef char ElemType;
// 孩子節點
typedef struct CTNode{
    int child; //孩子的Index
    struct CTNode *next; //指向下一個孩子節點的指針
} *ChildPtr;

// 表頭結構
typedef struct {
    ElemType data; //存放在樹中節點的資料
    int parent;    //存放雙親的Index
    ChildPtr firstChild; //指向第一個孩子的指針
} CTBox;

// 樹結構
typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int r, n;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
