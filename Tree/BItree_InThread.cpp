#include<iostream>
using namespace std;

typedef char Elemtype;

typedef struct ThreadNode{
    Elemtype data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;

ThreadNode *pre;

void InitTree(ThreadTree &T){
    Elemtype ch;
    cin>>ch;
    if(ch=='#'){
        T = NULL;
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
    cout<<q->data<<" ";
    if(q->lchild==NULL){     
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild = q;
        pre->rtag = 1;
    }
    if(pre!=NULL){
        cout<<pre->data<<endl;
    }
    else{
        cout<<endl;
    }
    pre = q;

}

void InThread(ThreadTree T){
    if(T==NULL) return;
    InThread(T->lchild);
    visit(T);
    InThread(T->rchild);
}

void CreatInThread(ThreadTree T){
    pre=NULL;
    if(T!=NULL){
        InThread(T);
        pre->rchild =NULL;
        pre->rtag =1;
    }
}


//����������������������
//�ҵ���PΪ���ڵ�������У���һ��������������ʵĽ��
ThreadNode *FirstNode(ThreadNode *p){
    //ѭ���ҵ������µĽ�㣬��һ����Ҷ�ڵ�
    while(p->ltag==0){
        p=p->lchild;
    }
    return p;
}

//�������������������ҵ����p�ĺ�̽ڵ�
ThreadNode *NextNode(ThreadNode *p){
    if(p->rtag==1) return p->rchild;
    else return FirstNode(p->rchild);
}

//����������������������������������������зǵݹ����
void InOrder(ThreadNode *T){
    for(ThreadNode *p = FirstNode(T); p!=NULL;p=NextNode(p)){
        cout<<p->data<<endl;
    }
    cout<<endl;
}

//��������������������ǰ��
//�ҵ���pΪ���ڵ�������У����һ�������ʵ��Ľ��
ThreadNode* LastNode(ThreadNode *p){
    while (p->rtag == 0) 
    {
        p=p->rchild;
    }
    return p;
}

//�������������������ҵ����p��ǰ���ڵ�
ThreadNode* PreNode(ThreadNode *p){
    if(p->ltag ==1){
        return p->lchild;
    }
    if(p->ltag ==0){
        return LastNode(p->lchild);
    }
}

//�����������������
void RevInOrder(ThreadTree T){
    cout<<endl;
    for(ThreadNode *p=LastNode(T);p!=NULL; p=PreNode(p)){
        cout<<p->data<<" ";
    }
    cout<<endl;
}


void test(){
    ThreadTree T;
    InitTree(T);
    CreatInThread(T);
    InOrder(T);
    RevInOrder(T);
}

int main(){
    test();
    return 0;
}

