#include<iostream>
using namespace std;
typedef int Elemtype;

typedef struct{
    Elemtype *elem;
    int TableLen;
}SStable;

int Search_Seq(SStable ST, Elemtype key){
    ST.elem[0] = key;   //�ڱ�
    int i;
    for(i=ST.TableLen; ST.elem[i]!=key; i--);
    return i;
}

int Search_Binary(SStable ST, Elemtype key){
    int low = 0, high = ST.TableLen, mid;
    while(low<=high){
        mid = (low+high)/2;
        if(ST.elem[mid]<key){
            low = mid + 1;
        }
        else if(ST.elem[mid]>key){
            high = mid - 1;
        }
        else if(ST.elem[mid]==key){
            return mid;
        }
    }
    return -1;
}

void test(){
    SStable ST;
    int len = 10;
    ST.TableLen = len;
    ST.elem = (Elemtype*)malloc(sizeof(Elemtype) * ST.TableLen);    //��仰ǧ��Ҫ���ǣ�û����仰elem[i]�ǲ��ܸ�ֵ��
    cout<<"  ";
    for(int i =1; i<ST.TableLen;i++){
        ST.elem[i]=i*2;
        cout<<ST.elem[i]<<" ";
    }
    cout<<endl;
    cout<<"˳�����ֵΪ4��Ԫ��Ϊ��"<<Search_Seq(ST,4)<<"��"<<endl;
    cout<<"˳�����ֵΪ4��Ԫ��Ϊ��"<<Search_Binary(ST,4)<<"��"<<endl;
}




int main(){
    test();
    return 0;
}