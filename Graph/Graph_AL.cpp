#include<iostream>
using namespace std;
#define MaxVertexNum 100

typedef char VertexType;

//边表节点(有点像链表，指向下一个结点)
typedef struct ArcNode{
    int adjvex;            //该弧所指向的顶点的位置
    struct ArcNode *next;
}ArcNode;

//顶点表结点(链式队列的感觉？)
typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode, AdjList[MaxVertexNum];

//邻接表
typedef struct{
    AdjList vertices;      //邻接表
    int vexnum, arcnum;    //图的顶点数和弧数
}ALGraph;

void InitGraph(ALGraph &G){
	cout << "-----------------------------------------------------" << endl;
	cout << "请输入顶点数和边数" << endl;
    cin >> G.vexnum >> G.arcnum;
    cout << "请输入顶点" <<endl;

    for(int i = 0; i< G.vexnum; i++){
        cin >> G.vertices[i].data;
        G.vertices[i].first = NULL;
    }

    cout<<"请输入边(vi,vj)的下标i,j"<<endl;
    int i,j;
    ArcNode *p;
    for(int k = 0; k<G.arcnum;k++){
        cin>>i>>j;
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = j;              //该顶点指向第j个结点
        p->next = G.vertices[i].first;   //头插法
        G.vertices[i].first = p;

        //无向图要加上
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = i;
        p->next = G.vertices[j].first;
        G.vertices[j].first = p ;
    }

    cout <<" 邻接表如下:" <<endl;
    for(int i = 0 ; i<G.vexnum; i++){
        p=G.vertices[i].first;
        while(p){
            cout<<"<"<<G.vertices[i].data<<","<<G.vertices[p->adjvex].data<<"> ";
            p = p->next;          //输出的结果可以看成每一行都是一个链表
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