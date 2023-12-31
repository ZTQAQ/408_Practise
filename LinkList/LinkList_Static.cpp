#include<iostream>
using namespace std;

#define MaxSize 10

typedef struct Node{
    int data;
    int next;   //ģ��ָ��
}SLinkList[MaxSize];               //Ҳ����struct Node a[MaxSize]
                                    //����SLinkList����һ������ΪMaxSize��Node������

void InitList(SLinkList L){
    for(int i=0;i<MaxSize;i++){
        L[i].next=-2;           //-2��ʾ�������������Ϊ��
    }
    L[0].next = -1;        //�����βΪ-1���൱��˫����������ı�βΪNULL
}

bool empty(SLinkList L){
    if(L[0].next == -1){
        return true;
    }
    return false;
}

//�õ���i��Ԫ�ص��±�(��next��ָ�롱һ����ȥ��)
int Get_Index(SLinkList L,int i){
    int j=0;  //ģ��nextָ��
    int n=0;
    while(j!=-1 && n<i){
        n++;
        j=L[j].next;
    }
    if(n!=i) return -1;
    return j;
}

//�õ���һ��������Ϊ�յĽڵ�
int Get_First_Empty_Node(SLinkList L){
    for(int i=1;i<MaxSize;i++){
        if(L[i].next==-2)
            return i;
    }
}

//�ڵ�i���������ֵΪe�Ľ��
bool InsertNode(SLinkList L,int i, int e){
    int j=Get_Index(L,i);
    //cout<<j<<endl;
    int k=Get_First_Empty_Node(L);
    //cout<<k<<endl;

    L[k].next=L[j].next;
    L[j].next=k;
    L[k].data=e;     //�ǲ��Ǻ�ָ��һģһ��??
    return true;
}

//ɾ����i���ڵ㣬e��ɾ����ֵ
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
    L[j].data=L[L[j].next].data;     //�͵������ɾ���ڵ㷽�����ƣ��ú�������ǰ�棬ɾ�����
    L[j].next=L[L[j].next].next;
    L[tmp].next=-2;          //�൱��free(q)
    return true;
}

//���룬Ĭ�Ͽ�ʼΪ��
bool List_Insert(SLinkList L){
    cout<<"����������(����ctrl zʱֹͣ)"<<endl;
    int p=1; 
    int q=0;
    int x;
    while(cin>>x ){
        L[p].data = x;
        L[p].next = -1;
        L[q].next = p;    //��ͷ���ָ����һ���ڵ�
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
    cout<<"�ڵڶ���Ԫ�غ����8"<<endl;
    InsertNode(L,2,8);
    ShowList(L);
    int e;
    cout<<"ɾ��������Ԫ��"<<endl;
    DeleteNode(L,3,e);
    cout<<e<<endl;
    ShowList(L);
    InsertNode(L,4,99);
    ShowList(L);
    return 0;
}