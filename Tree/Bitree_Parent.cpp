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
    int n;    //�ڵ����
}PTree;

bool InitTree(PTree &T){
    int i,j,n;
    char ch;
    printf("������ڵ����:\n");
    cin>>n;
    T.n = n;
    printf("���������ֵ��˫��λ�������е�λ���±�:\n");
    for(i=0;i<n;i++){
        cin>>ch;
        cin>>j;      //�����±�
        T.nodes[i].data=ch;
        T.nodes[i].parent = j;
    }
    return true;
}

void FindParent(PTree T){
    char a;
    int isfind = 0;
    cout<<"������Ҫ��ѯ�Ľ��ֵ"<<endl;
    cin>>a;
    for(int i = 0; i<T.n;i++){
        if(T.nodes[i].data==a){
            isfind =1;
            int ad = T.nodes[i].parent;
            cout<<a<<"�ĸ��ڵ�Ϊ"<<T.nodes[ad].data<<"�洢�±�Ϊ"<<ad<<endl;
            break;
        }
        }
    if(isfind ==0){
    cout<<"����û������ڵ�"<<endl;
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