#include <iostream>
using namespace std;

typedef char Elemtype;

typedef struct BitNode{
    Elemtype data;
    struct BitNode *lchild, *rchild;
}BitNode,*Bitree;

typedef struct LinkNode{
    BitNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
    LinkNode *front, *rear;
}LinkQueue;

bool InitBitree(Bitree &T){
    Elemtype ch;
    cin>>ch;
    if(ch=='#'){
        T = NULL;
    }
    else{
        T = (BitNode*)malloc(sizeof(BitNode));
        T->data=ch;
        InitBitree(T->lchild);
        InitBitree(T->rchild);
    }
}

void InitQueue(LinkQueue &Q){
    Q.front = Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool QueueEmpty(LinkQueue &Q){
    if(Q.front==Q.rear){
        return true;
    }else return false;
}

bool EnQueue(LinkQueue &Q, BitNode *C){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data= C;
    s->next= NULL;
    Q.rear->next = s;
    Q.rear=Q.rear->next;
    return true;
}

bool DeQueue(LinkQueue &Q, BitNode *&C){
    if(QueueEmpty(Q)) return false;
    LinkNode *q=Q.front->next;
    C=q->data;
    Q.front->next = q->next;
    if(Q.rear == q){
        Q.rear=Q.front;
    }
    free(q);
    return true;
}

void visit(BitNode *p){
    cout<<p->data<<" ";
}

void LevelOrder(Bitree T){
    LinkQueue Q;
    InitQueue (Q);
    Bitree p;
    EnQueue(Q,T);
    while(!QueueEmpty(Q)){
        DeQueue(Q,p);
        visit(p);
        if(p->lchild!=NULL){
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL)    
        {
            EnQueue(Q,p->rchild);
        }
    }
}

void test(){
    Bitree T;
    InitBitree(T);
    LevelOrder(T);
}

int main(){
    test();
    return 0;
}