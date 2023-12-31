#include<iostream>
using namespace std;

//�ڶ������Ա�2.3.7��24��


typedef struct LNode{
    int data;
    struct LNode *link;
}LNode, *LinkList;

void Initial(LinkList &L){
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    LNode *r = L;
    //L->link = NULL;
    cin>>x;
    while(x!=-999){
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->link = s;
        r = s;
        cin>>x;
    }
    r->link = NULL;
}

int ABS(int a){
    if(a>=0) return a;
    else return -a;
}

//�ÿռ任ʱ�䣬����һ���������飬����ÿ�ε���һ��Ԫ��ʱ�͸����������һ�αȽϣ�
//��a[i]=1������֮ǰ�Ѿ����ֹ��ˣ����õ�ɾ��
void Refresh(LinkList &L, int n){
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=0;
    }
    LNode *r =L;
    while(r->link!=NULL){
        LNode *q = r->link;
        if(a[ABS(q->data)]==1){
            
            r->link = q->link;
            free(q);
        }
        else{
            a[ABS(q->data)]=1;
            r = r->link;
        }
    }
}


void Show(LinkList L){
    cout<<"����Ϊ:";
    while(L->link !=NULL){
        cout<< L->link->data <<" ";
        L= L->link;
    }
    cout<<endl;
}

int main(){
    cout<<"���,�����������ֵ(������10�����ڱ�10С������,����-999ֹͣ):"<<endl;
    LinkList L1;
    Initial(L1);
    Show(L1);
    Refresh(L1,10);
    Show(L1);
    
    return 0;
}


