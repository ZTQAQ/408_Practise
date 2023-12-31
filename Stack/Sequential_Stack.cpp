#include <iostream>
using namespace std;

#define MaxSize 10

typedef struct{
    int data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S){
    S.top=-1;
}

bool Empty(SqStack S){
    if (S.top==-1)
        return true;
    return false;
}

bool Push(SqStack &S, int x){
    if(S.top == MaxSize-1){
        return false;
    }
    S.top++;
    S.data[S.top] = x;       
    //S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S,int &x){
    if(S.top==-1){
        return false;
    }
    x = S.data[S.top];
    S.top--;
    //x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, int &x){
    if(S.top==-1){
        return false;
    }
    x=S.data[S.top];
    return true;
}

int main(){
    SqStack S;
    InitStack(S);
    for(int i=0;i<=5;i++){
        Push(S,i);
    }
    int x;
    GetTop(S,x);
    cout<<x<<endl;
    while(Empty(S)==false){
        Pop(S,x);    
        cout<<x<<endl;     
    }
    return 0;
}

