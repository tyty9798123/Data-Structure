#include <stdio.h>

int main(int argc, const char * argv[]) {
    printf("%d\n", Fib(12));
    return 0;
}

int Fib(int i){
    if (i < 2){
        return i == 0 ? 0 : 1;
    }
    return Fib(i-1) + Fib(i-2);
}
