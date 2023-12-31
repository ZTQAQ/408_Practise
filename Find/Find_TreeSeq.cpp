#include<iostream>
using namespace std;
typedef int Elemtype;

typedef struct BSTNode{
    Elemtype data;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

//非递归查找
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

//递归查找
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

//中序遍历显示树的各元素
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
    cout<<"输入的个数小于10(输入999时停止输入):"<<endl;
    cin>>a;
    while(a!=999){
        str[i] = a;
        i++;
        cin>>a;
    }
    Create_BST(T,str,i);
    cout<<"树的中序遍历结果为:"<<endl;
    Show(T);
    cout<<endl;
    cout<<"请输入你想要查找的元素"<<endl;
    cin>>number;
    N=BST_Search(T,number);
    if(N==NULL){
        cout<<"没有查到该元素"<<endl;
    }
    else{
        cout<<"查到该元素"<<N->data<<endl;
    }
    
}

int main(){
    test();
    return 0 ;
}