#include<iostream>
using namespace std;

#define MaxSize 10

typedef struct Node{
    int data;
    int next;   //模拟指针
}SLinkList[MaxSize];               //也可以struct Node a[MaxSize]
                                    //可用SLinkList定义一个长度为MaxSize的Node型数组

void InitList(SLinkList L){
    for(int i=0;i<MaxSize;i++){
        L[i].next=-2;           //-2表示这个结点的数据域为空
    }
    L[0].next = -1;        //链表表尾为-1，相当于双（单）链表的表尾为NULL
}

bool empty(SLinkList L){
    if(L[0].next == -1){
        return true;
    }
    return false;
}

//得到第i个元素的下标(用next“指针”一个个去找)
int Get_Index(SLinkList L,int i){
    int j=0;  //模拟next指针
    int n=0;
    while(j!=-1 && n<i){
        n++;
        j=L[j].next;
    }
    if(n!=i) return -1;
    return j;
}

//得到第一个数据域为空的节点
int Get_First_Empty_Node(SLinkList L){
    for(int i=1;i<MaxSize;i++){
        if(L[i].next==-2)
            return i;
    }
}

//在第i个结点后插入值为e的结点
bool InsertNode(SLinkList L,int i, int e){
    int j=Get_Index(L,i);
    //cout<<j<<endl;
    int k=Get_First_Empty_Node(L);
    //cout<<k<<endl;

    L[k].next=L[j].next;
    L[j].next=k;
    L[k].data=e;     //是不是和指针一模一样??
    return true;
}

//删除第i个节点，e是删除的值
bool DeleteNode(SLinkList L,int i, int &e){
    int j = Get_Index(L,i);
    if (L[j].next==-1){
        int k=Get_Index(L,i-1);
        L[j].next = -2;
        e=L[j].data;
        L[k].next = -1;
        return true;
    }
    e=L[j].data;
    int tmp=L[j].next;
    L[j].data=L[L[j].next].data;     //和单链表的删除节点方法类似，用后面的替代前面，删后面的
    L[j].next=L[L[j].next].next;
    L[tmp].next=-2;          //相当于free(q)
    return true;
}

//插入，默认开始为空
bool List_Insert(SLinkList L){
    cout<<"请输入数据(输入ctrl z时停止)"<<endl;
    int p=1; 
    int q=0;
    int x;
    while(cin>>x ){
        L[p].data = x;
        L[p].next = -1;
        L[q].next = p;    //让头结点指向下一个节点
        q = p++;
    }
    return true;
}

void ShowList(SLinkList L){
    int i =L[0].next;
    while(i!=-1){
        cout<<i<<".."<<L[i].data<<"->"<<L[i].next<<"  ";
        i = L[i].next;
    }
    cout<<endl;
}

int main(){
    SLinkList L;
    InitList(L);
    List_Insert(L);
    ShowList(L);
    //InsertNode(L,0,1);
    cout<<"在第二个元素后插入8"<<endl;
    InsertNode(L,2,8);
    ShowList(L);
    int e;
    cout<<"删除第三个元素"<<endl;
    DeleteNode(L,3,e);
    cout<<e<<endl;
    ShowList(L);
    InsertNode(L,4,99);
    ShowList(L);
    return 0;
}