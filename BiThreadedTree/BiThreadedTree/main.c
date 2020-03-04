#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

// 線索存儲標誌位
// Link(0) 表示指向左右孩子只的指針
// Thread(1) 表示指向前驅後繼地線索
typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild, *rchild;
    PointerTag ltag;
    PointerTag rtag;
} BiThrNode, *BiThrTree;


//全局變量，始終指向剛剛訪問過的節點
BiThrTree pre;

// 創建一棵二元樹，約定用戶遵照前序遍歷的方式輸入數據
void CreateBiThrTree( BiThrTree *T ){
    char c;
    scanf("%c", &c);
    if (' ' == c){
        *T = NULL;
    }
    else{
        *T = (BiThrNode *)malloc( sizeof(BiThrNode) );
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;
        
        CreateBiThrTree( &(*T)->lchild );
        CreateBiThrTree( &(*T)->rchild );
    }
}

// 中序遍歷線索化
void InThreading(BiThrTree T){
    if ( T ){
        InThreading( T->lchild );
        
        //如果lchild是null
        if ( !T->lchild ){
            T->ltag = Thread;
            //設置lchild為上一個
            T->lchild = pre;
        }
        //如果上一個rchild是null
        if ( !pre->rchild ){
            pre->rtag = Thread;
            //把上一個rchild指向目前的
            pre->rchild = T;
        }
        
        pre = T;
        
        InThreading( T->rchild );
    }
}

void InOrderThreading( BiThrTree *p , BiThrTree T){
    *p = (BiThrTree)malloc( sizeof(BiThrNode) );
    // pre 在 root的上方
    // pre.ltag是Link 因為lchild會指向root
    // pre.rtag是Thread 因為rchild會指向遍歷的最後一個（線索）
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    
    //如果是空樹，指向自己
    if ( !T ){
        (*p)->lchild = *p;
    }
    else{
        (*p)->lchild = T;
        pre = *p;
        InThreading(T);
        
        //收尾，最後一個指向p(root之前的)
        pre->rchild = *p;
        pre->rtag = Thread;
    }
}

void visit ( char c ){
    printf("%c", c);
}
//中序遍歷二元樹，非遞歸
void InOrderTraverse( BiThrTree T ){
    BiThrTree p;
    // T = pre
    // now, p = root
    p = T->lchild;
    //t是頭節點 p
    while ( p != T ){
        //先找到左下角
        while ( p->ltag == Link) {
            p = p->lchild;
        }
        visit(p->data);
        //如果是thread就能找回去
        while ( p->rtag == Thread && p->rchild != T) {
            p = p->rchild;
            visit(p->data);
        }
        p = p->rchild;
    }
}

int main(int argc, const char * argv[]) {
    BiThrTree P, T = NULL;
    CreateBiThrTree( &T );
    InOrderThreading(&P, T);
    
    
    InOrderTraverse(P);
    printf("\n");
    return 0;
}
