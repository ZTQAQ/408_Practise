#include<iostream>
using namespace std;

typedef int Elemtype;

typedef struct LinkNode{
    Elemtype data;
    struct LinkNode* next;       //指向下一个结点的指针
    //struct LinkNode* front, *roar;
}LinkNode;

typedef struct LinkQueue{
    LinkNode *front, *roar;      //声明队列的队头，队尾指针  (同LinkNode *L声明一个指向单链表第一个结点的指针,相当于函数声明)
}LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front = Q.roar=(LinkNode *)malloc(sizeof(LinkNode));   //让front和roar都指向头节点(这里头结点不打算存储任何数据)
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.roar)    //front和roar是否指向同一个结点
        return true;
    return false;
}

bool EnQueue(LinkQueue &Q, Elemtype x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));  //增加一个新的结点(向内存申请一个新的节点)  
                                                        //LinkNode *s只是一句声明，它需要一个实际的东东;
    s->data = x;
    s->next = NULL;
    Q.roar->next=s;
    Q.roar=s;
    return true;
}

bool DeQueue(LinkQueue &Q, Elemtype &x){
    if (IsEmpty(Q)) return false;
    LinkNode *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.roar== p){
        Q.roar = Q.front;
    }
    free(p);
    return true;
}

bool GetHead(LinkQueue Q, Elemtype &x){
    if(IsEmpty(Q)) return false;
    x = Q.front->next->data;
    return true;
}

void test(){
    LinkQueue Q;
    InitQueue(Q);
    Elemtype n;
    Elemtype x;
    cout<<"请输入给队列添加的数据(输入999停止):"<<endl;
    cin>>n;
    while(n!=999){
        EnQueue(Q,n);
        cin>>n;
    }
    GetHead(Q,x);
    cout<<x<<endl;
    while(IsEmpty(Q)==false){
        DeQueue(Q,x);
        cout<<x<<endl;
    }
}

int main(){
    test();
    return 0;
}