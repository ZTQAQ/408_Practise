#include <iostream>
using namespace std;

typedef int Elemtype;
#define Maxsize 10

//循环队列
typedef struct SeQueue{
    Elemtype data[Maxsize];
    int front,roar;
}SeQueue;

void InitQueue(SeQueue &Q){
    Q.front=Q.roar=0;
}

bool IsEmpty(SeQueue Q){
    if(Q.front==Q.roar)
        return true;
    return false;
}

bool IsFull(SeQueue Q){
    if((Q.roar+1) % Maxsize == Q.front)       //这里的表尾指针永远指向表尾数据的后一个位置，因此data[Maxsize]是不存放数据的
        return true;
    return false;
}

bool EnQueue(SeQueue &Q, Elemtype x){
    if(IsFull(Q)) return false;
    Q.data[Q.roar]=x;
    Q.roar = (Q.roar+1) % Maxsize;       //循环队列的写法，不能直接写Q.roar++    （9+1）%10=0
    return true;
}

bool DeQueue(SeQueue &Q, Elemtype &x){
    if(IsEmpty(Q)) return false;
    x=Q.data[Q.front];
    Q.front = (Q.front+1) % Maxsize;
    return true;
}

bool GetHead(SeQueue Q, Elemtype &x){
    if(IsEmpty(Q)) return false;
    x=Q.data[Q.front];
    return true;
}

int GetSize(SeQueue Q){
    return (Q.roar + Maxsize - Q.front) % Maxsize;
}

void test(){
    SeQueue Q;
    InitQueue(Q);
    Elemtype data;
    int x;
    for(int i=0;i<6;i++){
        cin>>data;
        EnQueue(Q,data);
    }
    EnQueue(Q,777);
    EnQueue(Q,888);
    EnQueue(Q,999);
    EnQueue(Q,10);
    EnQueue(Q,11);
    cout<<GetSize(Q)<<endl;
    while(IsEmpty(Q)==false){
        DeQueue(Q,x);
        cout<<x<<endl;
    }
    cout<<GetSize(Q)<<endl;
}

int main(){
    test();
    return 0;
}