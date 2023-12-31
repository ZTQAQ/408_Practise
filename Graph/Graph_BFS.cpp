#include<iostream>
using namespace std;

typedef int Elemtype;
typedef char VertexType;

#define MaxSize 100

//循环队列
typedef struct {
    Elemtype data[MaxSize];
    int front, roar;
}Queue;

//边表节点
typedef struct ArcNode{
    int adjvex;         //该弧所指向的顶点的位置
    struct ArcNode *next;     //指针，指向该顶点连接出去的下一条弧
}ArcNode;

//链式队列，顶点
typedef struct VNode{
    VertexType data;     //顶点存放的字母
    ArcNode *first;       //指针，指向该顶点连接出去的第一条弧
}VNode, AdjList[MaxSize];

//邻接表
typedef struct{
    AdjList vertices;     //顶点元素
    int vexnum,arcnum;
}ALGraph;

void InitQueue(Queue &Q){
    Q.front = Q.roar = 0;
}

bool IsEmpty(Queue &Q){
    if(Q.roar == Q.front) return true;
    return false;
}

bool IsFull(Queue &Q){
    if((Q.roar+1)%MaxSize == Q.front)
        return true;
    return false;
}

bool EnQueue(Queue &Q, Elemtype x){
    if(IsFull(Q)){
        cout<<"队列已满"<<endl;
        return false;
    }
    else{
        Q.data[Q.roar]=x;
        Q.roar=(Q.roar+1)%MaxSize;
        return true;
    }
}

bool DeQueue(Queue &Q, Elemtype &x){
    if(IsEmpty(Q)){
        cout<<"队列为空"<<endl;
        return false;
    }
    else{
        x = Q.data[Q.front];
        Q.front = (Q.front+1)%MaxSize;
        return true;
    }
}

void InitGraph(ALGraph &G){
    cout<<"请输入顶点数和边数"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"请输入顶点"<<endl;

    for(int i=0; i<G.vexnum; i++){
        cin >>G.vertices[i].data;
        G.vertices[i].first = NULL;
    }
    
    cout<<"请输入边(vi,vj)的下标i,j"<<endl;
    int i,j;
    ArcNode *p;
    for (int k=0; k<G.arcnum;k++)
    {
        cin>>i>>j;
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = j;      //把j结点插到以i结点为头节点的链表后面
        p->next = G.vertices[i].first;
        G.vertices[i].first=p;

        //无向图
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = i;
        p->next = G.vertices[j].first;
        G.vertices[j].first = p;
    }

    cout<<"邻接表如下"<<endl;
    for(int i=0;i<G.vexnum;i++){
        p=G.vertices[i].first;
        while(p){
            cout<<"<"<<G.vertices[i].data<<","<<G.vertices[p->adjvex].data<<"> ";
            p = p->next;
        }
        cout<<endl;
    } 
}

//v结点的第一个邻接点
int FirstNeighbor(ALGraph G, int v){
    ArcNode *p;
    p = G.vertices[v].first;
    //cout<<p<<endl;
    if(p==NULL) return -1;
    else{
        //cout<<p->adjvex<<endl;
        return p->adjvex;
    } 
}

//输入的v为想要去找v的邻接点，W为已经通过FirstNeighbour找到的第一个邻结点
int NextNeighbor(ALGraph G, int v, int w){
    if(v != -1){
        ArcNode *p = G.vertices[v].first;
        while(p!=NULL &&p->adjvex!=w){
            p = p->next;
        }
        if(p !=NULL && p->next!=NULL){
            return p->next->adjvex;
        }
    }
    return -1;
}

void Visit(ALGraph G,int v){
    cout<<G.vertices[v].data<<" ";
}

bool visited[MaxSize];


//广度优先遍历
void BFS(ALGraph G, int v){
    Visit(G,v);    //访问顶点
    visited[v] = true;
    Queue Q;       //初始化复制队列
    InitQueue(Q);
    EnQueue(Q,v);         //顶点进入队列
    while(!IsEmpty(Q)){
        DeQueue(Q,v);     //顶点出队列，当队列为空时停止循环
        for(int w = FirstNeighbor(G,v); w>=0; w = NextNeighbor(G,v,w)){
            //w是广度遍历找到的下一个顶点，可能有好几个
            if(!visited[w]){            //w为v的从未访问过的邻接结点
                Visit(G,w);
                visited[w]=true;
                EnQueue(Q,w);           //w顶点进入队列
            }        

        }        
    }
}

//求顶点v到其他顶点的最小距离
void BFS_Min_Distance(ALGraph G, int v){
    int d[G.vexnum];
    int path[G.vexnum];
    for(int i = 0; i<G.vexnum;i++){
        d[i]=999;
        path[i] = -1;
    }
    Visit(G,v);
    d[v]=0;
    visited[v] = true;
    Queue Q;
    InitQueue(Q);
    EnQueue(Q,v);
    while(!IsEmpty(Q)){
        DeQueue(Q,v);
        for(int w = FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w)){
            if(!visited[w]){
                Visit(G,w);
                d[w] = d[v] +1;
                path[w]=v;
                visited[w] = true;
                EnQueue(Q,w);
            }
        }
    }
    cout<<endl;
    for(int i = 0; i<G.vexnum;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i<G.vexnum;i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

//开始广度优先遍历，调用这个函数，同时初始化一下visited[]数组
void BFSTraverse(ALGraph G){
    int i ;
    for(i =0; i<G.vexnum; i++){
        visited[i] = false;
    }
    /*
    for(i = 0;i<G.vexnum; i++){
        if(!visited[i]){
            //BFS(G,i);
            BFS_Min_Distance(G,i);
        }
    }
    */
    BFS_Min_Distance(G,1);
}

/*
void test(){
    Queue Q;
    InitQueue(Q);
    char A='A';
    char B='B';
    char D;
    EnQueue(Q,A);
    EnQueue(Q,B);
    DeQueue(Q,D);
    cout<<D<<endl;
    DeQueue(Q,D);
    cout<<D<<endl;
}
*/


int main(){
    //test();
    int w;
    ALGraph G;
    InitGraph(G);
    //cout<<G.vertices[FirstNeighbor(G,1)].data<<endl;
    //cout<<G.vertices[NextNeighbor(G,1,4)].data<<endl;
    BFSTraverse(G);

/*
    8 10

    A B C D E F G H

    0 1
    0 4
    1 5
    5 2
    5 6
    2 6
    2 3
    6 3
    6 7
    3 7
*/
    return 0;
}