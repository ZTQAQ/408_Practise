#include <iostream>
#include<string.h>
using namespace std;

typedef int Elemtype;
#define maxsize 10

typedef struct Stack{
    Elemtype data[maxsize];
    int top;
}Stack;

void InitStack(Stack &S){
    S.top=-1;
}

bool isEmpty(Stack &S){
    if(S.top==-1) 
        return true;
    return false;
}

//判断栈是否满了
bool isFull(Stack &S){
    if(S.top==maxsize){
        return true;
    }
    return false;
}

//入栈
bool Push(Stack &S, Elemtype x){
    if(isFull(S)) return false;
    S.data[++S.top] = x;
    return true;
}


//出栈
bool Pop(Stack &S, Elemtype &x){
    if(isEmpty(S)) return false;
    x=S.data[S.top--];
    return true;
}

bool GetTop(Stack S, Elemtype &x){
    if(isEmpty(S)) return false;
    x=S.data[S.top];
    return true;
}

//用栈实现括号匹配

bool BracketCheck(char str[], int length){
    Stack S;
    InitStack(S);
    for(int i=0;i<length;i++){
        if (str[i]=='('||str[i]=='{'||str[i]=='['){
            Push(S,str[i]);
        }
        else{
            if(isEmpty(S)) return false;

            cout<<str[i]<<endl;
            Elemtype topElem;
            Pop(S,topElem);
            cout<<topElem<<endl;
            if(str[i]==')'&&topElem!='(') return false;
            if(str[i]==']'&&topElem!='[') return false;
            if(str[i]=='}'&&topElem!='{') return false;
        }
    }
}

//后缀表达式的计算(输入15+27*3/+计算得10)
bool Postfix(char str[],int length){
    Stack S;
    InitStack(S);
    for(int i=0;i<length;i++){
        if(str[i]>='0'&&str[i]<='9'){
            Push(S,(str[i]-'0'));         //把char类型改成int     
        }else if(S.top>=1){
            int topElem1; 
            int topElem2;
            int result;
            switch(str[i]){
                case '+': 
                    Pop(S,topElem1);
                    Pop(S,topElem2);
                    result=topElem2+topElem1;
                    cout<<result<<endl;
                    Push(S,result);
                    break;
                case '-': 
                    Pop(S,topElem1);
                    Pop(S,topElem2);
                    result=topElem2-topElem1;
                    cout<<result<<endl;
                    Push(S,result);
                    break;
                case '/': 
                    Pop(S,topElem1);
                    Pop(S,topElem2);
                    result=topElem2/topElem1;
                    Push(S,result);
                    cout<<result<<endl;
                    break;  
                case '*': 
                    Pop(S,topElem1);
                    Pop(S,topElem2);
                    result=topElem2*topElem1;
                    cout<<result<<endl;
                    Push(S,result);
                    break;               
            }
        }
        else return false; 
    }
    int x;
    GetTop(S,x);
    cout<<x<<endl;   
}

int main(){
    char str[10];
    cout<<"请输入一个字符串（按回车结束)(输入15+27*3/+)"<<endl;
    cin>> str;
    int length=strlen(str);
    if(!Postfix(str,length)){
        cout<<"输入的后缀表达式有误"<<endl;
    }

/*
    if(BracketCheck(str,length)==false){
        cout<<"匹配失败"<<endl;
    }
*/
    return 0;
}