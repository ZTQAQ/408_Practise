#include<iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

LinkList Init(LinkList &L)          //头插法创建链表（逆向建立，逆置，输入2，3，4，5，链表为5，4，3，2）
{
    LNode *s ; 
    int x;
    L = (LinkList)malloc(sizeof(LNode));  //创建头节点
    L-> next = NULL;
    cin >> x ;
    while(x!=-1)
    {
        s=(LNode*)malloc(sizeof(LNode));  //创建新节点
        s->data = x;
        s->next = L->next;                  //正常情况都是要LNode *new str =L,因为L是链表固定头节点，
                                            //如果在Show（）这种函数里不设定新指针，而是L=L->next，那么链表之后是不能再操作的，此时L指向了表尾，不是表头
        L->next = s;
        cin >> x;
    }
}

LinkList Tail_Init(LinkList &L)        //尾插法创建链表
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    // L->next = NULL             //尾插法不用这句，但也最好加上（养成好习惯），在头插法不加这句的话L->next变成野指针
    LNode *s ; 
    LNode *r=L;               //r为表尾指针
    cin>>x;
    while(x!=-1){
        s=(LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;          //让下一个节点指向s，此时s就成为下一个节点
        r =s;                 //让指针r成为下一个节点s（这样循环，才能让新的s不断成为r后面的节点）可以理解为r = r->next
        cin>>x;
    }
    r->next = NULL;
}

void Show(LinkList &L)
{
    LNode *r =L;              
    r=r->next;
    cout<<"链表为";
    while(r)
    {
        cout<<r->data<<" ";
        r = r->next;
    }
    cout<<endl;

}
LNode * GetElem(LinkList L, int i)     //查找元素位置
{
    if (i<=0){
        cout<<"查不到数据"<<endl;
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

bool ListInsert(LinkList &L, int i, int e)    //在L链表中第i个位置插入e
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

bool ListDelete(LinkList &L,int i)             //删除在L链表中第i个位置的数据
{
    LNode *p;
    p = GetElem(L,i);      //这里是i不是i-1,i-1的话把p->data = q->data删掉就行，效果一样
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
    LNode *p = L1->next;       //不是LNode *p=L1,因为L1的头节点没有数据，存放指针的地址（大概）
                               //，这样写的话会变成5，4，3，2，1765545（最后一个是地址，错的数据）    
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
    cout<<"你好,请输入链表的值(-1停止)"<<endl;
    LinkList L1;          //这里并没有创建结点（创建节点是L1 = (LNode*)malloc(sizeof(LNode))
    //Init(L1);
    Tail_Init(L1);
    Show(L1);
    cout<<"请输入想查找的元素位置:";
    cin >> i;
    p = GetElem(L1,i);
    cout<<"该链表第"<<i<<"个元素为:"<<p->data<<endl;
    cout<<"在链表第二个位置插入一个值4"<<endl;
    ListInsert(L1,2,46);    //在链表第二个位置插入一个值46
    Show(L1);
    ListDelete(L1,2);
    Show(L1);
    cout<<"现在链表长度为"<<Length(L1)<<endl;
    LinkList L2;
    ListReverse(L2,L1);
    Show(L2);
    cout<<"现在链表长度为"<<Length(L2)<<endl;
    return 0;
    
}