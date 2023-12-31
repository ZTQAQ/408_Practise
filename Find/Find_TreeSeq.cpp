#include<iostream>
using namespace std;
typedef int Elemtype;

typedef struct BSTNode{
    Elemtype data;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

//�ǵݹ����
BSTNode *BST_Search(BSTree T, Elemtype key){
    while(T!=NULL && key != T->data){
        if(key>T->data){
            T = T->rchild;
        }
        else{
            T = T->lchild;
        }
    }
    return T;
}

//�ݹ����
BSTNode *BSTSearch(BSTree T, Elemtype key){
    if(T ==NULL){
        return NULL;
    }
    else if(key == T->data){
        return T;
    }
    else if(key > T->data){
        return BSTSearch(T->rchild,key);
    }
    else{
        return BSTSearch(T->lchild,key);
    }
}

int BST_Insert(BSTree &T, Elemtype key){
    if(T==NULL){
        T=(BSTNode*)malloc(sizeof(BSTNode));
        T->data = key;
        T->lchild = T->rchild =NULL;
        return 1;
    }
    else if(T->data == key){
        return 0;
    }
    else if(key > T->data){
        return BST_Insert(T->rchild, key);
    }
    else{
        return BST_Insert(T->lchild, key);
    }
}

//���������ʾ���ĸ�Ԫ��
void Show(BSTree T){
    if(T!=NULL){
        Show(T->lchild);
        cout<<T->data<<" ";
        Show(T->rchild);
    }
}

void Create_BST(BSTree &T, Elemtype str[], int n){
    T=NULL;
    int i = 0;
    while(i<n){
        BST_Insert(T, str[i]);
        i++;
    }
}

void test(){
    BSTree T; BSTNode *N;
    //N =(BSTNode*)malloc(sizeof(BSTNode));
    int str[10], a, i=0,number;
    cout<<"����ĸ���С��10(����999ʱֹͣ����):"<<endl;
    cin>>a;
    while(a!=999){
        str[i] = a;
        i++;
        cin>>a;
    }
    Create_BST(T,str,i);
    cout<<"��������������Ϊ:"<<endl;
    Show(T);
    cout<<endl;
    cout<<"����������Ҫ���ҵ�Ԫ��"<<endl;
    cin>>number;
    N=BST_Search(T,number);
    if(N==NULL){
        cout<<"û�в鵽��Ԫ��"<<endl;
    }
    else{
        cout<<"�鵽��Ԫ��"<<N->data<<endl;
    }
    
}

int main(){
    test();
    return 0 ;
}