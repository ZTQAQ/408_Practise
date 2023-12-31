#include<iostream>
using namespace std;

typedef int Elemtype;

typedef struct LinkNode{
    Elemtype data;
    struct LinkNode* next;
}*LiStack, LinkNode;    //Listack是指向struct LinkNode的指针 相当于int *p=null;

bool InitStack(LiStack &S){
    S=NULL;            //此时没有一个节点，只有一个指针,此时的S也就没有data和next（那些是结点才有的）
    return true;
}

bool IsEmpty(LiStack S){
    if(S==NULL){
        return true;
    }
    return false;
}

//不带头结点的入栈
bool push(LiStack &S, Elemtype x){
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));   //分配新结点
    if (p==NULL) return false;
    p->data=x;
    p->next=S;
    S=p;                        //注意和带头结点之间的差别，这里是p（data为e）先指向S原来指的第一个元素a，S再指向p  S->data(e)->data(a)
                                //p->next = S->next;  S->next = p;(带头结点)    S->data(头节点的地址)->data(e)->data(a)
    return true;
}


bool pop(LiStack &S,Elemtype &x){
    if(IsEmpty(S)) return false;
    LinkNode *p =S;
    x=S->data;
    S=S->next;
    free(p);
    return true;
}

bool GetTop(LiStack S, Elemtype &x){
    if(IsEmpty(S)) return false;
    x=S->data;
    return true;
}

bool destory(LiStack &S){
    while(S!=NULL){
        LinkNode *p=S;
        S=S->next;
        free(p);
    }
    free(S);
    S=NULL;
    return true;
}

void test(){
    LiStack S;   
    Elemtype x;
    InitStack(S);
    cout<<"请输入数字"<<endl;
    for(int i=0;i<=5;i++){
        cin>>x;
        push(S,x);
    }
    Elemtype d;
    GetTop(S,d);
    cout<<d<<endl;
    while(IsEmpty(S)==false){
        pop(S,d);
        cout<<d<<endl;        
    }
}

int main(){
    test();
    return 0;
}
