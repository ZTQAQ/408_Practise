#include<iostream>
using namespace std;

#define MaxVertexNum 100    //������Ŀ�����ֵ
typedef char VertexType;    //�������������
typedef int EdgeType;       //��Ȩ�ıߵ���������
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;

bool InitGraph(MGraph &G){
    int i,j;
    char c;
    int a;int b;
    cout<<"�������ܶ�����,�ܱ���"<<endl;
    cin>>a>>b;
    G.vexnum = a;
    G.arcnum = b;
    //���붥����Ϣ
    cout<<"�����붥����Ϣ"<<endl;
    for(i=0;i<G.vexnum;i++){
        cin >> c ;
        G.Vex[i] = c;
        for(j=0;j<G.vexnum;j++){
            G.Edge[i][j] = 0;      //��ʼ��ȫ��Ϊ0
        } 
    }
    return true;
}

//��λ�����ھ����е�λ��
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
        cout<<"����Ķ��㲻����"<<endl;
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
    cout<<"������������ӵڼ�������"<<endl;
    cin>>x;
    while(x!=999){
        cout<<"�������й����ߵĶ���"<<endl;
        cin>>y>>z;      //�����й����ߵĶ���
        AddEdge(G,y,z);
        cout<<"������������ӵڼ�������"<<endl;
        cin>>x;
    }
    //cout<<G.Edge[0][0]<<G.Edge[0][1]<<G.Edge[1][0]<<endl;
    ShowGraph(G);
}

int main(){
    test();
    
    return 0;
}