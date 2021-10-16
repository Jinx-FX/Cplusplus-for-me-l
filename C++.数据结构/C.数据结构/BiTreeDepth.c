// 1.编写一个递归函数计算二叉树的高度。

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TElemType int

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

// 递归计算二叉树的高度。
int BiTreeDepth(BiTree T) {
    int ldepth=0, rdepth=0;
    if( T != NULL) {
        ldepth += (1 + BiTreeDepth(T->lchild));
        rdepth += (1 + BiTreeDepth(T->rchild));
    }
    return (ldepth > rdepth) ? ldepth : rdepth;
}

// 构造二叉树的函数有点粗糙，见谅
void CreateBiTree(BiTree *T) {
    *T=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data=1;
    (*T)->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->data=2;
    (*T)->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->data=3;
    (*T)->rchild->lchild=NULL;
    (*T)->rchild->rchild=NULL;
    (*T)->lchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data=4;
    (*T)->lchild->lchild->lchild=NULL;
    (*T)->lchild->lchild->rchild=NULL;
    (*T)->lchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data=5;
    (*T)->lchild->rchild->lchild=NULL;
    (*T)->lchild->rchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->rchild->data=6;
    (*T)->lchild->rchild->rchild->lchild=NULL;
    (*T)->lchild->rchild->rchild->rchild=NULL;
}

int main() {
    BiTree T;
    CreateBiTree(&T);
    // printf("%d",T->lchild->lchild->data);
    int i;
    i = BiTreeDepth(T);
    printf("%d",i);

    return 0;
}

