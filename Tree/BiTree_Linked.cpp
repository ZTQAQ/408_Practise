#include<iostream>
using namespace std;

typedef char Elemtype;

typedef struct BitNode{
    Elemtype data;
    struct BitNode *lchild, *rchild;
}BitNode, *Bitree;

//��ʼ����
bool InitTree(Bitree &T){
    Elemtype ch;
    cout<<"������ch��ֵ"<<endl;   
    cin>>ch;
    if(ch=='#'){
        T=NULL;
    }
    else{
        T=(BitNode*)malloc(sizeof(BitNode));
        T->data=ch;
        InitTree(T->lchild);
        InitTree(T->rchild);
    }
}

//���������
int TreeDepth(Bitree T){
    if(T==NULL)  return 0 ;
    int l= TreeDepth(T->lchild);
    int r= TreeDepth(T->rchild);
    return l>r? l+1:r+1;
}



void test(){
    Bitree T;
    InitTree(T);
    cout<<TreeDepth(T);
}


int main(){
    test();
    return 0 ;
}


