#include <stdio.h>

void swap(int k[], int i, int j){
    int temp = k[i];
    k[i] = k[j];
    k[j] = temp;
}

void HeapAdjest(int k[], int s, int n){
    int i, temp;
    temp = k[s];
    for ( i = 2 *s; i <=n; i *= 2){
        if ( i < n && k[i] < k[i+1] ){
            i++;
        }
        if ( temp >= k[i] ){
            break;
        }
        k[s] = k[i];
        s=i;
    }
    k[s] = temp;
}
void HeapSort(int k[], int n){
    //從下往上，從右往左
    int i;
    for ( i = n/2; i > 0; i-- ){
        HeapAdjest(k, i, n);
    }
    for ( i = n; i > 1; i--){
        swap(k, 1, i);
        HeapAdjest(k, 1, i-1);
    }
}

int main(int argc, const char * argv[]) {
    //小到大=>大頂堆
    int i, a[10] = {-1, 5, 2, 6, 0, 3, 9, 1, 7, 4};
    HeapSort(a, 9);
    
    printf("排序後的結果是：");
    
    for( i = 1; i < 10; i++ ){
        printf("%d", a[i]);
    }
    printf("\n\n");
    
    return 0;
}