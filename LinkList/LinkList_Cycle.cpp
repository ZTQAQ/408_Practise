#include<iostream>
using namespace std;

typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

bool InitList(DLinkList &L){
    L=(DNode *)malloc(sizeof(DNode));  //分配头结点
    if(L==NULL)
        return false;       //内存不足分配失败
    L-> prior = L;
    L->next = L;             //循环的关键，普通的双链表是指向NULL
    return true;
}

bool Empty(DLinkList L){
    if(L->next==L)
        return true;
    return false;
}

bool IsCycle(DLinkList L,DNode *p){        //判断p结点是不是循环双链表的表尾结点
    if(p->next==L)
        return true;
    return false;
}

bool InsertNode(DNode *p, DNode*s){   
    if (p==NULL||s==NULL)
        return false;       
    s->next=p->next;
    p->next->prior = s;        //这里不用像普通双链表判断p->next==NULL,
                               //原来是为了避免表尾结点为NULL没有prior，现在表尾结点是有数据域指针域的
    s->prior = p;
    p->next = s;
    return true;
}

bool DeleteNode(DNode *p){
    DNode *q=p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return q;
}

void ShowList(DLinkList L){
    DNode *p =L->next;
    while(p!=L){
        cout<<p->data<<" ";
        p=p->next;           //这个时候p指向表头L了已经
    }
    cout<<"从前往后结束"<<endl;
    
    DNode *s = L->prior;
    while(s!=L){
        cout<<s->data<<" ";
        s=s->prior;
    }
    cout<<"从后往前结束"<<endl; 
}

int main(){
    DLinkList L1;
    InitList(L1);
    int i;
    cin>>i;
    while(i>0){
        DNode *s=(DNode*)malloc(sizeof(DNode));
        cin>>s->data;
        InsertNode(L1,s);
        i--;
    }
    ShowList(L1);
    return 0;
}