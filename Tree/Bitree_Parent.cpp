#include<iostream>
using namespace std;

#define Max_Size 100
typedef char Elemtype;

typedef struct{
    Elemtype data;
    int parent;
}PTNode;

typedef struct{
    PTNode nodes[Max_Size];
    int n;    //节点个数
}PTree;

bool InitTree(PTree &T){
    int i,j,n;
    char ch;
    printf("请输出节点个数:\n");
    cin>>n;
    T.n = n;
    printf("请输入结点的值其双亲位于数组中的位置下标:\n");
    for(i=0;i<n;i++){
        cin>>ch;
        cin>>j;      //数组下标
        T.nodes[i].data=ch;
        T.nodes[i].parent = j;
    }
    return true;
}

void FindParent(PTree T){
    char a;
    int isfind = 0;
    cout<<"请输入要查询的结点值"<<endl;
    cin>>a;
    for(int i = 0; i<T.n;i++){
        if(T.nodes[i].data==a){
            isfind =1;
            int ad = T.nodes[i].parent;
            cout<<a<<"的父节点为"<<T.nodes[ad].data<<"存储下标为"<<ad<<endl;
            break;
        }
        }
    if(isfind ==0){
    cout<<"树中没有这个节点"<<endl;
    }
}

int main(){
    PTree tree;
    InitTree(tree);
    FindParent(tree);

/*
R -1
A 0
B 0
C 0
D 1
E 1
F 3
G 6
H 6
K 6
*/
    return 0;
}