#include<iostream>
using namespace std;

#define MaxVertexNum 100    //顶点数目的最大值
typedef char VertexType;    //顶点的数据类型
typedef int EdgeType;       //带权的边的数据类型
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;

bool InitGraph(MGraph &G){
    int i,j;
    char c;
    int a;int b;
    cout<<"请输入总顶点数,总边数"<<endl;
    cin>>a>>b;
    G.vexnum = a;
    G.arcnum = b;
    //输入顶点信息
    cout<<"请输入顶点信息"<<endl;
    for(i=0;i<G.vexnum;i++){
        cin >> c ;
        G.Vex[i] = c;
        for(j=0;j<G.vexnum;j++){
            G.Edge[i][j] = 0;      //初始化全设为0
        } 
    }
    return true;
}

//定位顶点在矩阵中的位置
int LocateVex(MGraph G,char V){
    for(int i =0;i<G.vexnum;i++){
        if(G.Vex[i]==V){
            return i;
        }
    }
    return -1;
}

bool AddEdge(MGraph &G, char A, char B){
    int a,b;
    a=LocateVex(G,A);
    b=LocateVex(G,B);
    if(a==-1||b==-1){
        cout<<"输入的顶点不存在"<<endl;
        return false;
    }
    else{
        G.Edge[a][b]=1;
        G.Edge[b][a]=1;
    }
    return true;
}

bool ShowGraph(MGraph G){
    for(int i=0;i<G.vexnum;i++){
        for(int j = 0; j<G.vexnum; j++){
            cout<<G.Edge[i][j]<<" ";
        }
        cout<<endl;
    }
}

void test(){
    MGraph G;
    InitGraph(G);
    int x;
    char y,z;
    cout<<"请输入你想添加第几个顶点"<<endl;
    cin>>x;
    while(x!=999){
        cout<<"请输入有公共边的顶点"<<endl;
        cin>>y>>z;      //输入有公共边的顶点
        AddEdge(G,y,z);
        cout<<"请输入你想添加第几个顶点"<<endl;
        cin>>x;
    }
    //cout<<G.Edge[0][0]<<G.Edge[0][1]<<G.Edge[1][0]<<endl;
    ShowGraph(G);
}

int main(){
    test();
    
    return 0;
}