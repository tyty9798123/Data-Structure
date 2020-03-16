//
//  main.c
//  InsertSort
//
//  Created by Swift on 2020/3/16.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>

void shellSort(int k[], int n){
    int i, j, temp;
    int gap = n;
    
    do{
        gap = gap / 3 + 1;
        for ( i = gap; i < n; i++ ){
            if ( k[i] < k[i-gap] ){
                temp = k[i];
                //從i之前找往前找，找到適合放temp的地方
                for ( j = i - gap; k[j] > temp; j-=gap ){
                    k[j+gap] = k[j];
                }
                k[j+gap] = temp;
            }
        }
    
    }while(gap > 1);
}

void testd(int k[], int n){
    int i, j, temp;
    int gap = n;
    
    do {
        gap = gap / 3 + 1;
        for ( i = gap; i < n; i++){
            if( k[i] < k[i-gap] ){
                temp = k[i];
                for ( j = i - gap; k[j] > temp; j-=gap){
                    k[j+gap] = k[j];
                }
                k[j+gap] = temp;
            }
        }
    }while(gap > 1);
}

int main(int argc, const char * argv[]) {
    int array[10] = {5, 6, 7, 8, 1 ,2 ,3 ,4 ,9 ,0};
    testd(array, 10);
    int i;
    for ( i = 0; i < 10; i++ ){
        printf("%d", array[i]);
    }
    printf("\n");
    return 0;
}
