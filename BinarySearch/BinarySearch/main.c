//
//  main.c
//  BinarySearch
//
//  Created by Swift on 2020/2/14.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x);
int main(int argc, const char * argv[]) {
    int numbers[5] = {
        1, 2 , 3 , 4 ,5
    };
    int position = binarySearch(numbers, 0, 5-1, 3);
    
    printf("%d\n", position);
    return 0;
}

int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}
