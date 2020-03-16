//
//  main.c
//  SelectSort
//
//  Created by Swift on 2020/3/16.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>

void SelectSort(int k[], int n){
    int i, j, min,temp;
    
    for( i = 0; i < n-1; i++ ){
        min = i;
        for ( j = i + 1; j < n; j++ ){
            // k[j] 比 min小的話
            if ( k[j] < k[min] ){
                min = j;
            }
        }
        //min已更換，所以就交換
        if ( min != i ){
            temp = k[min];
            k[min] = k[i];
            k[i] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    int array[10] = {5, 6, 7, 8, 1 ,2 ,3 ,4 ,9 ,0};
    SelectSort(array, 10);
    int i;
    for ( i = 0; i < 10; i++ ){
        printf("%d", array[i]);
    }
    printf("\n");
    return 0;
}
