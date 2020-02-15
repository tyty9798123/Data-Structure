#include <stdio.h>
void point(){
    char a;
    scanf("%c", &a);
    if (a != '#') point();
    if (a != '#') printf("%c", a);
}

int main(int argc, const char * argv[]) {
    point();
    return 0;
}
