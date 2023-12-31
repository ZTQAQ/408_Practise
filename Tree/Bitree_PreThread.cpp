#include<iostream>
using namespace std;

typedef char Elemtype;

typedef struct ThreadNode{
    Elemtype data;
    struct ThreadNode* lchild, *rchild;
    int ltag,rtag;
}ThreadNode, *ThreadTree;

ThreadNode *pre;

void InitTree(ThreadTree &T){
    Elemtype ch;
    cin>>ch;
    if(ch=='#'){
        T=NULL;
    }
    else{
        T = (ThreadNode*)malloc(sizeof(ThreadNode));
        T->data = ch;
        T->ltag = 0;
        T->rtag = 0;
        InitTree(T->lchild);
        InitTree(T->rchild);
    }
}

void visit(ThreadNode *q){
    cout<<q->data<<endl;
    if(q->lchild == NULL){
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL&&pre->rchild ==NULL){
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

void PreThread(ThreadTree T){
    if(T!=NULL){
        visit(T);
        if(T->ltag == 0){   //lchild不是前驱节点
            PreThread(T->lchild);
        }
        PreThread(T->rchild);
    }
}

void CreatPreThread(ThreadTree T){
    pre =NULL;
    if(T!=NULL){
        PreThread(T);
        if(pre->rchild==NULL){
            pre->rtag =1;
        }
    }
}

//先序线索二叉树找先序后继
//找线序线索二叉树结点p的先序后继
ThreadNode* NextNode(ThreadNode *p){
    if(p->rtag==1) return p->rchild;
    else{
        if(p->lchild==NULL){
            return p->rchild;
        }
        else{
            return p->lchild;
        }
    }
}

//遍历先序线索二叉树
void PreOrder(ThreadTree T){
    for(ThreadNode *p = T; p!=NULL; p=NextNode(p)){
        cout<<p->data<<" ";
    }
    cout<<endl;
}

void test(){
    ThreadTree T;
    //T=(ThreadNode*)malloc(sizeof(ThreadNode));
    InitTree(T);
    CreatPreThread(T);
    PreOrder(T);
}

int main(){
    test();
    return 0 ;
}