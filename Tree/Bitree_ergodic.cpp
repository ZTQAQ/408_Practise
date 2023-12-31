#include<iostream>
using namespace std;

typedef char Elemtype;

typedef struct BitNode{
    Elemtype data;
    struct BitNode *lchild,*rchild;
}BitNode, *Bitree;

bool InitBitree(Bitree &T){
    Elemtype ch;
    cin>>ch;
    if(ch=='#'){
        T=NULL;
    }
    else{
        T=(BitNode*)malloc(sizeof(BitNode));
        T->data = ch;
        InitBitree(T->lchild);
        InitBitree(T->rchild);
    }
    return true;
}

void visit(BitNode *p){
    cout<<p->data<< " ";
}

void PreOrder(Bitree T){
    if(T==NULL)
        return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

void Inorder(Bitree T){
    if(T==NULL) return;
    else{
        Inorder(T->lchild);
        visit(T);
        Inorder(T->rchild);
    }
}

void PostOrder(Bitree T){
    if(T==NULL) return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
}

void test(){
    Bitree T;
    InitBitree(T);
    cout<<"先序遍历"<<endl;
    PreOrder(T);
    cout<<endl;

    cout<<"中序遍历"<<endl;
    Inorder(T);
    cout<<endl;

    cout<<"后序遍历"<<endl;
    PostOrder(T);
    cout<<endl;
}

int main(){
    test();
    return 0;
}