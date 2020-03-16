#include <stdio.h>
/*
void BubbleSort(int k[], int n){
    int i, j, temp;
    for ( i = 0; i < n - 1; i++ ){
        for ( j = i + 1; j < n; j++ ){
            if ( k[i] > k[j] ){
                temp = k[j];
                k[j] = k[i];
                k[i] = temp;
            }
        }
    }
}
*/
void BubbleSort(int k[], int n){
    int i, j, temp, flag;
    flag = 1;
    for ( i = 0; i < n - 1 && flag == 1; i++ ){
        for ( j = n - 1; j > i; j-- ){
            flag = 0;
            if ( k[j-1] > k[j] ){
                temp = k[j-1];
                k[j-1] = k[j];
                k[j] = temp;
                flag = 1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int i, a[10] = {5, 2, 6, 0 ,3 , 9, 1, 7, 4, 8};
    BubbleSort(a, 10);
    printf("排序過後的結果：");
    for ( i = 0; i < 10 ; i++){
        printf("%d", a[i]);
    }
    printf("\n\n");
}
