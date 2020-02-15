//
//  main.c
//  factorial
//
//  Created by Swift on 2020/2/14.
//  Copyright © 2020 Swift. All rights reserved.
//

#include <stdio.h>

int factorial(int n);
int main(int argc, const char * argv[]) {
    printf( "%d\n", factorial(5) );
    return 0;
}

int factorial(int n){
    if( n == 0) return 1;
    else return n * factorial(n - 1);
}
