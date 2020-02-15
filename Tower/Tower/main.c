//
//  main.c
//  Tower
//
//  Created by Swift on 2020/2/15.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>

void tower(int n, char x, char y, char z){
    if( n == 1 ){//如果n只有一個，直接搬運
        printf("%c-->%c\n", x, z);
        return;
    }
    else{
        tower(n-1, x, z, y);        //將 n - 1 從x借助z移到y上
        printf("%c-->%c\n", x, z);  //將 第 n 個盤子從x移到 z上
        tower(n-1, y, x, z);        //將 n - 1 從y借助x移到z上
    }
}

int main(int argc, const char * argv[]) {
    int n;
    printf("請輸入層數:");
    scanf("%d", &n);
    tower(n, 'x', 'y', 'z');
    return 0;
}

