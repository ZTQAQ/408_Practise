#include<iostream>
using namespace std;

typedef struct DNode{
    int data;
    struct DNode *prior, *next;
}DNode, *DLinklist;

bool Init(DLinklist &L){    //��ʼ��������
    L=(DNode *) malloc(sizeof(DNode));
    if(L==NULL)
    return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

bool InsertNode(DNode *p, DNode *s){               //��p�������s���,�൱��ͷ�巨
    if(s==NULL)
    return false;
    s->next = p->next;
    if(p->next !=NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

bool DeleteNode(DNode *p){                            //ɾ��p������ĺ�̽ڵ�
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
    free(L);        //�ͷ�ͷ�ڵ�
    L = NULL;       //��ͷָ��ָ��NULL��
}

void ShowList(DLinklist L){
    DNode *p = L->next;
    while(p->next!=NULL)             //����д��while(p)��������
    {
        cout<<p->data<<" ";
        p=p->next;        
    }
    cout<<p->data<<" ";
    cout<<" "<<"����������"<<endl; 
    while(p->prior!=NULL)            //Ҫ��Ӻ���ǰ������p�ڴ�ǰ��������Ĺ����У�pһ��ָ���˱�βNULL��NULL��û��prior�ģ���˻ᱨ��
    {
        cout<<p->data<<" ";
        p=p->prior;
    }
    cout<<" "<<"��ǰ��������"<<endl;
}

int main(){
    int i;
    DLinklist L1;
    Init(L1);
    DNode *s;
    cout<<"��������������ֵ�ĸ���:"<<endl;
    cin>>i;
    cout<<"��������������ֵ:"<<endl;
    while(i>0){
        s = (DNode *)malloc(sizeof(DNode));
        cin>>s->data;
        InsertNode(L1,s);
        i--;
    }
    ShowList(L1);
    return 0;
}