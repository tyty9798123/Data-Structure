#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* String;

//https://www.bilibili.com/video/av2975983?p=39
void get_next(String T,int *next){
    int i=0,j=1;//i表示前綴，j表示後綴
    int T_len=strlen(T)-1;
    next[1]=0;
    while(j<T[0]){
        if(0==i || T[i]==T[j]){
            ++i;
            ++j;
            if ( T[i] != T[j] ){
                next[j] = i;
            }
            else
            {
                //
                next[j]=next[i];
            }
        }
        else{
            i=next[i];
        }
    }
}
//https://www.bilibili.com/video/av2975983?p=40
int Index_KMP(String S,String T,int pos){
    int i=pos;
    int S_len=strlen(S)-1;
    int T_len=strlen(T)-1;
    int j=1;
    int next[255];
    
    //把表中的next填上去
    get_next(T,next);
    
    while(i<=S_len && j<=T_len){
        if(0==j || S[i]==T[j]){
            ++i;
            ++j;
        }
        else {
            j=next[j];
        }
    }
    if(j>T_len)
        return i-T_len;
    else
        return 0;
}

int main(int argc, char *argv[]) {
    String S = "aaaabcde";
    String T = "bcde";
    printf("%d ",Index_KMP(S,T,1));
    return 0;
}
