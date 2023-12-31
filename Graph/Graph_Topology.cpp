#include<iostream>
using namespace std;

typedef int Elemtype;
typedef int VertexType;
#define Maxsize 10

typedef struct LinkNode{
    Elemtype data;
    struct LinkNode* next;
}*LiStack, LinkNode;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode, AdjList[Maxsize];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}AlGraph;

bool InitStack(LiStack &S){
    S=NULL;
    return true;
}

bool IsEmpty(LiStack &S){
    if(S==NULL){
        return true;
    }
    return false;
}

bool push(LiStack &S, Elemtype x){
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    if(p==NULL) return false;
    p->data = x;
    p->next = S;
    S = p;
    return true;
}

bool pop(LiStack &S, Elemtype &x){
    if(IsEmpty(S)) return false;
    LinkNode *p = S;
    x = S->data;
    S = S->next;
    free(p);
    return true;
}

void InitGraph(AlGraph &G){
    cout<<"请输入顶点数和边数"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"请输入顶点"<<endl;

    for(int i = 0;i<G.vexnum; i++){
        cin>>G.vertices[i].data;
        G.vertices[i].first = NULL;
    }

    cout<<"请输入边vi和vj的下标i,j"<<endl;
    int i,j;
    ArcNode *p;
    for(int k = 0; k<G.vexnum; k++){
        cin>>i>>j;
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = j;
        p->next = G.vertices[i].first;
        G.vertices[i].first = p;
    }

    cout<<"邻接表如下"<<endl;
    for(int i =0;i<G.vexnum;i++){
        p= G.vertices[i].first;
        cout<< G.vertices[i].data;
        while(p){
            cout<<"->"<<G.vertices[p->adjvex].data;
            p = p->next;            
        }
        cout<<endl;
    }
}

//得到刚建立的邻接表的各节点的入度，注意写法，这样子才能返回一个数组
int* FirstIndegree(AlGraph G){
    int *indegree = new int[G.vexnum];     
    for(int i = 0;i<G.vexnum;i++){
        int cnt = 0 ;
        for (int j = 0; j<G.vexnum;j++){
            ArcNode *p = G.vertices[j].first;
            while(p){
                if(p->adjvex == i ){
                    cnt++;                
                }
                p = p->next;
            }
        }
        indegree[i] = cnt;
        cout<<indegree[i]<<endl;
    }
    return indegree;
}

//拓扑排序
bool TopologicalSort(AlGraph G,int *indegree){
    int print[G.vexnum];
    for(int j = 0; j<G.vexnum;j++){
        print[j] = -1;
    }
    LiStack S;
    InitStack(S);
    int i;
    for(i =0; i<G.vexnum;i++){
        if(indegree[i] == 0 )
            push(S,i);
    }
    int count = 0;
    while(!IsEmpty(S)){
        pop(S,i);
        print[count] =i;
        count++;
        ArcNode *p;
        for(p = G.vertices[i].first; p; p=p->next){
            int v=p->adjvex;
            indegree[v]--;
            if(indegree[v]==0){
                push(S,v);
            }
        }
    }

    cout<<"拓扑排序为: "<<endl;
    for(int j = 0; j<G.vexnum;j++){
        cout<<print[j]<<" ";
    }
    if (count<G.vexnum){
        return false;           //排序失败，有向图中有回路
    }
    return true;

}

int main(){
    AlGraph G;
    InitGraph(G);    
    int *indegree= FirstIndegree(G);
    TopologicalSort(G,indegree);


/*
    5 5

    A B C D E

    0 1
    1 3
    2 3
    2 4
    3 4

*/
    return 0;
}
