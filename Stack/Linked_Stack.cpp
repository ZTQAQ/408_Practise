#include<iostream>
using namespace std;

typedef int Elemtype;

typedef struct LinkNode{
    Elemtype data;
    struct LinkNode* next;
}*LiStack, LinkNode;    //Listack��ָ��struct LinkNode��ָ�� �൱��int *p=null;

bool InitStack(LiStack &S){
    S=NULL;            //��ʱû��һ���ڵ㣬ֻ��һ��ָ��,��ʱ��SҲ��û��data��next����Щ�ǽ����еģ�
    return true;
}

bool IsEmpty(LiStack S){
    if(S==NULL){
        return true;
    }
    return false;
}

//����ͷ������ջ
bool push(LiStack &S, Elemtype x){
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));   //�����½��
    if (p==NULL) return false;
    p->data=x;
    p->next=S;
    S=p;                        //ע��ʹ�ͷ���֮��Ĳ��������p��dataΪe����ָ��Sԭ��ָ�ĵ�һ��Ԫ��a��S��ָ��p  S->data(e)->data(a)
                                //p->next = S->next;  S->next = p;(��ͷ���)    S->data(ͷ�ڵ�ĵ�ַ)->data(e)->data(a)
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
    cout<<"����������"<<endl;
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
