#include<iostream>
using namespace std;
typedef int Elemtype;

typedef struct{
    Elemtype *elem;
    int TableLen;
}SStable;

int Search_Seq(SStable ST, Elemtype key){
    ST.elem[0] = key;   //哨兵
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
    ST.elem = (Elemtype*)malloc(sizeof(Elemtype) * ST.TableLen);    //这句话千万不要忘记，没有这句话elem[i]是不能赋值的
    cout<<"  ";
    for(int i =1; i<ST.TableLen;i++){
        ST.elem[i]=i*2;
        cout<<ST.elem[i]<<" ";
    }
    cout<<endl;
    cout<<"顺序查找值为4的元素为第"<<Search_Seq(ST,4)<<"个"<<endl;
    cout<<"顺序查找值为4的元素为第"<<Search_Binary(ST,4)<<"个"<<endl;
}




int main(){
    test();
    return 0;
}