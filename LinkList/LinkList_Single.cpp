#include<iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

LinkList Init(LinkList &L)          //ͷ�巨�������������������ã�����2��3��4��5������Ϊ5��4��3��2��
{
    LNode *s ; 
    int x;
    L = (LinkList)malloc(sizeof(LNode));  //����ͷ�ڵ�
    L-> next = NULL;
    cin >> x ;
    while(x!=-1)
    {
        s=(LNode*)malloc(sizeof(LNode));  //�����½ڵ�
        s->data = x;
        s->next = L->next;                  //�����������ҪLNode *new str =L,��ΪL������̶�ͷ�ڵ㣬
                                            //�����Show�������ֺ����ﲻ�趨��ָ�룬����L=L->next����ô����֮���ǲ����ٲ����ģ���ʱLָ���˱�β�����Ǳ�ͷ
        L->next = s;
        cin >> x;
    }
}

LinkList Tail_Init(LinkList &L)        //β�巨��������
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    // L->next = NULL             //β�巨������䣬��Ҳ��ü��ϣ����ɺ�ϰ�ߣ�����ͷ�巨�������Ļ�L->next���Ұָ��
    LNode *s ; 
    LNode *r=L;               //rΪ��βָ��
    cin>>x;
    while(x!=-1){
        s=(LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;          //����һ���ڵ�ָ��s����ʱs�ͳ�Ϊ��һ���ڵ�
        r =s;                 //��ָ��r��Ϊ��һ���ڵ�s������ѭ�����������µ�s���ϳ�Ϊr����Ľڵ㣩�������Ϊr = r->next
        cin>>x;
    }
    r->next = NULL;
}

void Show(LinkList &L)
{
    LNode *r =L;              
    r=r->next;
    cout<<"����Ϊ";
    while(r)
    {
        cout<<r->data<<" ";
        r = r->next;
    }
    cout<<endl;

}
LNode * GetElem(LinkList L, int i)     //����Ԫ��λ��
{
    if (i<=0){
        cout<<"�鲻������"<<endl;
        return NULL;
    }
    LNode *p;
    int j = 0;
    p = L;
    while(p && j<i){
        p = p->next;
        j++;
    }
    return p;
}

bool ListInsert(LinkList &L, int i, int e)    //��L�����е�i��λ�ò���e
{
    LNode *p;
    p = GetElem(L, i-1);
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e ; 
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(LinkList &L,int i)             //ɾ����L�����е�i��λ�õ�����
{
    LNode *p;
    p = GetElem(L,i);      //������i����i-1,i-1�Ļ���p->data = q->dataɾ�����У�Ч��һ��
    if (p == NULL)
    return false;
    if (p->next == NULL)  
    return false;
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;  
    free(q);
    return true;
}

int Length(LinkList &L)
{
    LNode *p = L->next;
    int len = 0;
    while(p!=NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

LinkList ListReverse(LinkList &L2,LinkList &L1)
{
    LNode *p = L1->next;       //����LNode *p=L1,��ΪL1��ͷ�ڵ�û�����ݣ����ָ��ĵ�ַ����ţ�
                               //������д�Ļ�����5��4��3��2��1765545�����һ���ǵ�ַ��������ݣ�    
    L2 = (LinkList)malloc(sizeof(LNode));
    L2->next = NULL;
    while (p)
    {
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = p->data;
        s->next = L2->next;
        L2->next = s;
        p=p->next;
    }

}

int main(){
    int i ;LNode *p;
    cout<<"���,�����������ֵ(-1ֹͣ)"<<endl;
    LinkList L1;          //���ﲢû�д�����㣨�����ڵ���L1 = (LNode*)malloc(sizeof(LNode))
    //Init(L1);
    Tail_Init(L1);
    Show(L1);
    cout<<"����������ҵ�Ԫ��λ��:";
    cin >> i;
    p = GetElem(L1,i);
    cout<<"�������"<<i<<"��Ԫ��Ϊ:"<<p->data<<endl;
    cout<<"������ڶ���λ�ò���һ��ֵ4"<<endl;
    ListInsert(L1,2,46);    //������ڶ���λ�ò���һ��ֵ46
    Show(L1);
    ListDelete(L1,2);
    Show(L1);
    cout<<"����������Ϊ"<<Length(L1)<<endl;
    LinkList L2;
    ListReverse(L2,L1);
    Show(L2);
    cout<<"����������Ϊ"<<Length(L2)<<endl;
    return 0;
    
}