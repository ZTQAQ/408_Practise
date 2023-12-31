#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#pragma region ������ʽ�洢�����������ֵܱ�ʾ����

#define MaxSize 100
#define ElemType char
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct Node { //���Ľ��
    ElemType val;
    Node* firstchild;
    Node* nextsibling;
}CSNode, * CSTree;

void CreateCSTree(CSTree& T)//Ҫ�ı�ָ�룬C++���԰�ָ������ô�����
{
    ElemType ch;

    cin >> ch;

    if (ch == '#')
        T = NULL;
    else
    {
        T = new CSNode;
        T->val = ch;
        CreateCSTree(T->firstchild);
        CreateCSTree(T->nextsibling);
    }
}


void visit(CSNode* BiCSNode) {
    cout << BiCSNode->val << " ";
}

void InOrder(CSTree T) {
    if (T) {
        InOrder(T->firstchild);
        visit(T);
        InOrder(T->nextsibling);
    }
}

void PostOrder(CSTree T) {
    if (T) {
        PostOrder(T->firstchild);
        PostOrder(T->nextsibling);
        visit(T);
    }
}

void FindX(CSTree T, ElemType X, CSNode*& r) {
    if (T) {
        FindX(T->firstchild, X, r);
        if (T->val == X)
            r = T;
        FindX(T->nextsibling, X, r);
    }
}

#pragma endregion

//P177.5
//������Ժ����ֵܱ�ʾ���洢��ɭ�ֵ�Ҷ�ӽ����

queue<CSNode*> q;
stack<CSNode*> s;

int GetLeaves(CSTree T) {
    if (!T)
        return 0;
    if (!T->firstchild)
        return 1 + GetLeaves(T->nextsibling);
    else
        return GetLeaves(T->firstchild) + GetLeaves(T->nextsibling);
}

int main()
{
    CSTree T;
    cout << "�������������˳���¸�������ֵ,'#'��ʾû�н��(T1):" << endl;
    //  input(�������ֵ�): A B # C # D # # E F # # G H # # I # #
    CreateCSTree(T);
    cout << "���������" << endl;
    InOrder(T);
    cout << endl;
    cout << "ɭ�ֵ�Ҷ�ӽ����Ϊ��" << GetLeaves(T) << endl;
    return 0;
}
