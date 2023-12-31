#include<iostream>
using namespace std;

typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

bool InitList(DLinkList &L){
    L=(DNode *)malloc(sizeof(DNode));  //����ͷ���
    if(L==NULL)
        return false;       //�ڴ治�����ʧ��
    L-> prior = L;
    L->next = L;             //ѭ���Ĺؼ�����ͨ��˫������ָ��NULL
    return true;
}

bool Empty(DLinkList L){
    if(L->next==L)
        return true;
    return false;
}

bool IsCycle(DLinkList L,DNode *p){        //�ж�p����ǲ���ѭ��˫����ı�β���
    if(p->next==L)
        return true;
    return false;
}

bool InsertNode(DNode *p, DNode*s){   
    if (p==NULL||s==NULL)
        return false;       
    s->next=p->next;
    p->next->prior = s;        //���ﲻ������ͨ˫�����ж�p->next==NULL,
                               //ԭ����Ϊ�˱����β���ΪNULLû��prior�����ڱ�β�������������ָ�����
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
        p=p->next;           //���ʱ��pָ���ͷL���Ѿ�
    }
    cout<<"��ǰ�������"<<endl;
    
    DNode *s = L->prior;
    while(s!=L){
        cout<<s->data<<" ";
        s=s->prior;
    }
    cout<<"�Ӻ���ǰ����"<<endl; 
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