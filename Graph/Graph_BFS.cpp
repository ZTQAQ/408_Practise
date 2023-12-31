#include<iostream>
using namespace std;

typedef int Elemtype;
typedef char VertexType;

#define MaxSize 100

//ѭ������
typedef struct {
    Elemtype data[MaxSize];
    int front, roar;
}Queue;

//�߱�ڵ�
typedef struct ArcNode{
    int adjvex;         //�û���ָ��Ķ����λ��
    struct ArcNode *next;     //ָ�룬ָ��ö������ӳ�ȥ����һ����
}ArcNode;

//��ʽ���У�����
typedef struct VNode{
    VertexType data;     //�����ŵ���ĸ
    ArcNode *first;       //ָ�룬ָ��ö������ӳ�ȥ�ĵ�һ����
}VNode, AdjList[MaxSize];

//�ڽӱ�
typedef struct{
    AdjList vertices;     //����Ԫ��
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
        cout<<"��������"<<endl;
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
        cout<<"����Ϊ��"<<endl;
        return false;
    }
    else{
        x = Q.data[Q.front];
        Q.front = (Q.front+1)%MaxSize;
        return true;
    }
}

void InitGraph(ALGraph &G){
    cout<<"�����붥�����ͱ���"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"�����붥��"<<endl;

    for(int i=0; i<G.vexnum; i++){
        cin >>G.vertices[i].data;
        G.vertices[i].first = NULL;
    }
    
    cout<<"�������(vi,vj)���±�i,j"<<endl;
    int i,j;
    ArcNode *p;
    for (int k=0; k<G.arcnum;k++)
    {
        cin>>i>>j;
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = j;      //��j���嵽��i���Ϊͷ�ڵ���������
        p->next = G.vertices[i].first;
        G.vertices[i].first=p;

        //����ͼ
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = i;
        p->next = G.vertices[j].first;
        G.vertices[j].first = p;
    }

    cout<<"�ڽӱ�����"<<endl;
    for(int i=0;i<G.vexnum;i++){
        p=G.vertices[i].first;
        while(p){
            cout<<"<"<<G.vertices[i].data<<","<<G.vertices[p->adjvex].data<<"> ";
            p = p->next;
        }
        cout<<endl;
    } 
}

//v���ĵ�һ���ڽӵ�
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

//�����vΪ��Ҫȥ��v���ڽӵ㣬WΪ�Ѿ�ͨ��FirstNeighbour�ҵ��ĵ�һ���ڽ��
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


//������ȱ���
void BFS(ALGraph G, int v){
    Visit(G,v);    //���ʶ���
    visited[v] = true;
    Queue Q;       //��ʼ�����ƶ���
    InitQueue(Q);
    EnQueue(Q,v);         //����������
    while(!IsEmpty(Q)){
        DeQueue(Q,v);     //��������У�������Ϊ��ʱֹͣѭ��
        for(int w = FirstNeighbor(G,v); w>=0; w = NextNeighbor(G,v,w)){
            //w�ǹ�ȱ����ҵ�����һ�����㣬�����кü���
            if(!visited[w]){            //wΪv�Ĵ�δ���ʹ����ڽӽ��
                Visit(G,w);
                visited[w]=true;
                EnQueue(Q,w);           //w����������
            }        

        }        
    }
}

//�󶥵�v�������������С����
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

//��ʼ������ȱ������������������ͬʱ��ʼ��һ��visited[]����
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