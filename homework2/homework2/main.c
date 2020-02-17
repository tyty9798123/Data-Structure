//
//  main.c
//  homework2
//
//  Created by Swift on 2020/2/15.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i;
    int sum = 0;
    char ch;
    
    printf("請輸入一串整數和任意數目的空格：");
    
    while ( scanf("%d", &i) == 1 ) {
        sum += i;
        ch = getchar();
        if (ch == '\n'){
            break;
        }
    }
    printf("結果是: %d", sum);
    printf("\n");
    return 0;
}
