//
//  main.c
//  InsertSort
//
//  Created by Swift on 2020/3/16.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>

void insertSort(int k[], int n){
    int i, j, temp;
    
    for ( i = 1; i < n; i++ ){
        if ( k[i] < k[i-1] ){
            temp = k[i];
            //從i之前找往前找，找到適合放temp的地方
            for ( j = i - 1; k[j] > temp ; j--){
                k[j+1] = k[j];
            }
            k[j+1] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    int array[10] = {5, 6, 7, 8, 1 ,2 ,3 ,4 ,9 ,0};
    insertSort(array, 10);
    int i;
    for ( i = 0; i < 10; i++ ){
        printf("%d", array[i]);
    }
    printf("\n");
    return 0;
}
