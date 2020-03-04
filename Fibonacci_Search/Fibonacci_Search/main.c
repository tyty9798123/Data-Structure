//
//  main.c
//  Fibonacci_Search
//
//  Created by Swift on 2020/2/29.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>
   
#define FIB_SEARCH_MAX_LEN 20
int _fib(int n) {
 if(n == 0 || n==1)
     return n;
 return _fib(n-1) + _fib(n-2);
}

int fibSearch(int data[FIB_SEARCH_MAX_LEN], int key) {
    int index = 2;
    // 費氏數列的 k 值計算
    while(_fib(index) <= FIB_SEARCH_MAX_LEN)
        index++;
    index--;
    printf("Using key=%d...\n", index);
    int rootNode = _fib(index);
    int diff1 = _fib(index-1);  // 上一個費氏數
    int diff2 = _fib(index-2);  // 上兩個費氏數
    rootNode--;  // 配合陣列的索引是從 0 開始.
    printf("Root Node=%d...\n", rootNode);
 while(1) {
     printf("\tData[%d]=%d...\n", rootNode, data[rootNode]);
     if(key == data[rootNode]) {
         return rootNode;
     } else {
         if(index==2) break;  // 沒有找到
         if(key < data[rootNode]) {
             rootNode = rootNode - diff2; // 左子樹的新樹根
             printf("左子樹新樹根=%d...\n", rootNode);
             int temp = diff1;
             diff1 = diff2;              // 上一個費氏樹
             diff2 = temp - diff2; // 上兩個費氏樹
             index = index-1;
         } else {
             if(index==3) break;  // 沒有找到
             rootNode = rootNode + diff2; // 右子樹的新樹根
             printf("右子樹新樹根=%d...\n", rootNode);
             diff1 = diff1 - diff2;  // 上一個費氏樹
             diff2 = diff2 - diff1;  // 上兩個費氏樹
             index = index -2;
         }
     }
 }
 return -1;
}
int main() {
    int data[] = {5, 7, 12, 23, 25, 37, 48, 54, 68, 77, 91, 99, 102, 110, 118, 120, 130, 135, 136, 150};
    printf("Source data:\n");
    for(int i=0; i<4; i++) {
     for(int j=0; j<5; j++)
         printf("data[%2d] = %3d\t", i*5+j, data[i*5+j]);
     printf("\n");
    }
    int key = 0, num;
    while(1) {
        printf("請輸入搜尋值(1-150), 輸入-1結束: ");
        scanf("%d", &key);
        if(key<0)
            break;
            num = fibSearch(data, key);
        if(num>=0) {
         printf("在第%d個位置找到 ( data[' %d '] = %d .  \n", num, num, data[num] );
         //cout << "在第 " << num << "個位置找到 ( data[" << num << "]=" << data[num] << "." << endl;
        }
        else {
         printf("沒有找到%d\n", key);
         //cout << "##### 沒有找到 " << key << "#####" << endl;
        }
    }
    return 0;
}
