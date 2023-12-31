#include<iostream>
using namespace std;

typedef int Elemtype;

typedef struct LinkNode{
    Elemtype data;
    struct LinkNode* next;       //ָ����һ������ָ��
    //struct LinkNode* front, *roar;
}LinkNode;

typedef struct LinkQueue{
    LinkNode *front, *roar;      //�������еĶ�ͷ����βָ��  (ͬLinkNode *L����һ��ָ�������һ������ָ��,�൱�ں�������)
}LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front = Q.roar=(LinkNode *)malloc(sizeof(LinkNode));   //��front��roar��ָ��ͷ�ڵ�(����ͷ��㲻����洢�κ�����)
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.roar)    //front��roar�Ƿ�ָ��ͬһ�����
        return true;
    return false;
}

bool EnQueue(LinkQueue &Q, Elemtype x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));  //����һ���µĽ��(���ڴ�����һ���µĽڵ�)  
                                                        //LinkNode *sֻ��һ������������Ҫһ��ʵ�ʵĶ���;
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
    cout<<"�������������ӵ�����(����999ֹͣ):"<<endl;
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