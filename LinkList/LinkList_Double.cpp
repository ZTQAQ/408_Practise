#include<iostream>
using namespace std;

typedef struct DNode{
    int data;
    struct DNode *prior, *next;
}DNode, *DLinklist;

bool Init(DLinklist &L){    //初始化空链表
    L=(DNode *) malloc(sizeof(DNode));
    if(L==NULL)
    return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

bool InsertNode(DNode *p, DNode *s){               //在p结点后插入s结点,相当于头插法
    if(s==NULL)
    return false;
    s->next = p->next;
    if(p->next !=NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

bool DeleteNode(DNode *p){                            //删除p结点后面的后继节点
    if(p==NULL)
    return false;
    DNode *q = p->next;
    if(q==NULL)
    return false;
    p->next = q->next;
    if(q->next !=NULL)
    q->next->prior = p;
    free(q);
    return true;
}

void DestoryList(DLinklist L){
    while(L->next!=NULL)
        DeleteNode(L);
    free(L);        //释放头节点
    L = NULL;       //让头指针指向NULL；
}

void ShowList(DLinklist L){
    DNode *p = L->next;
    while(p->next!=NULL)             //不能写成while(p)，看下面
    {
        cout<<p->data<<" ";
        p=p->next;        
    }
    cout<<p->data<<" ";
    cout<<" "<<"向后遍历结束"<<endl; 
    while(p->prior!=NULL)            //要想从后往前遍历，p在从前往后遍历的过程中，p一旦指向了表尾NULL，NULL是没有prior的，因此会报错
    {
        cout<<p->data<<" ";
        p=p->prior;
    }
    cout<<" "<<"向前遍历结束"<<endl;
}

int main(){
    int i;
    DLinklist L1;
    Init(L1);
    DNode *s;
    cout<<"请输入插入链表的值的个数:"<<endl;
    cin>>i;
    cout<<"请依次输入插入的值:"<<endl;
    while(i>0){
        s = (DNode *)malloc(sizeof(DNode));
        cin>>s->data;
        InsertNode(L1,s);
        i--;
    }
    ShowList(L1);
    return 0;
}