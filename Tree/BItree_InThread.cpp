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


//中序线索二叉树找中序后继
//找到以P为根节点的子树中，第一个被中序遍历访问的结点
ThreadNode *FirstNode(ThreadNode *p){
    //循环找到最左下的结点，不一定是叶节点
    while(p->ltag==0){
        p=p->lchild;
    }
    return p;
}

//在中序线索二叉树中找到结点p的后继节点
ThreadNode *NextNode(ThreadNode *p){
    if(p->rtag==1) return p->rchild;
    else return FirstNode(p->rchild);
}

//对中序线索二叉树进行中序遍历，利用线索进行非递归遍历
void InOrder(ThreadNode *T){
    for(ThreadNode *p = FirstNode(T); p!=NULL;p=NextNode(p)){
        cout<<p->data<<endl;
    }
    cout<<endl;
}

//中序线索二叉树找中序前驱
//找到以p为根节点的子树中，最后一个被访问到的结点
ThreadNode* LastNode(ThreadNode *p){
    while (p->rtag == 0) 
    {
        p=p->rchild;
    }
    return p;
}

//在中序线索二叉树中找到结点p的前驱节点
ThreadNode* PreNode(ThreadNode *p){
    if(p->ltag ==1){
        return p->lchild;
    }
    if(p->ltag ==0){
        return LastNode(p->lchild);
    }
}

//逆向遍历线索二叉树
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

