#include<iostream>
using namespace std;

//第二章线性表2.3.7第24题


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

//用空间换时间，构造一个辅助数组，链表每次到下一个元素时和辅助数组进行一次比较，
//若a[i]=1，代表之前已经出现过了，将该点删除
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
    cout<<"链表为:";
    while(L->link !=NULL){
        cout<< L->link->data <<" ";
        L= L->link;
    }
    cout<<endl;
}

int main(){
    cout<<"你好,请输入链表的值(请输入10个以内比10小的数字,输入-999停止):"<<endl;
    LinkList L1;
    Initial(L1);
    Show(L1);
    Refresh(L1,10);
    Show(L1);
    
    return 0;
}


