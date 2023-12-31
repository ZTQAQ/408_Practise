#include<iostream>
using namespace std;
#define MaxVertexNum 100

typedef char VertexType;

//�߱�ڵ�(�е�������ָ����һ�����)
typedef struct ArcNode{
    int adjvex;            //�û���ָ��Ķ����λ��
    struct ArcNode *next;
}ArcNode;

//�������(��ʽ���еĸо���)
typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode, AdjList[MaxVertexNum];

//�ڽӱ�
typedef struct{
    AdjList vertices;      //�ڽӱ�
    int vexnum, arcnum;    //ͼ�Ķ������ͻ���
}ALGraph;

void InitGraph(ALGraph &G){
	cout << "-----------------------------------------------------" << endl;
	cout << "�����붥�����ͱ���" << endl;
    cin >> G.vexnum >> G.arcnum;
    cout << "�����붥��" <<endl;

    for(int i = 0; i< G.vexnum; i++){
        cin >> G.vertices[i].data;
        G.vertices[i].first = NULL;
    }

    cout<<"�������(vi,vj)���±�i,j"<<endl;
    int i,j;
    ArcNode *p;
    for(int k = 0; k<G.arcnum;k++){
        cin>>i>>j;
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = j;              //�ö���ָ���j�����
        p->next = G.vertices[i].first;   //ͷ�巨
        G.vertices[i].first = p;

        //����ͼҪ����
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = i;
        p->next = G.vertices[j].first;
        G.vertices[j].first = p ;
    }

    cout <<" �ڽӱ�����:" <<endl;
    for(int i = 0 ; i<G.vexnum; i++){
        p=G.vertices[i].first;
        while(p){
            cout<<"<"<<G.vertices[i].data<<","<<G.vertices[p->adjvex].data<<"> ";
            p = p->next;          //����Ľ�����Կ���ÿһ�ж���һ������
        }
        cout<<endl;
    }
}

int main(){
    ALGraph G;
    InitGraph(G);
/*
    5 7

    A B C D E

    0 1
    0 2
    0 3
    1 3
    2 3
    1 4
    3 4
*/
    return 0;
}