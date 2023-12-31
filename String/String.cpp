#include <iostream>
using namespace std;

#define Maxlen 255

typedef struct{
    char ch[Maxlen];
    int length;
}SString;

typedef struct{
    char *ch;
    int length;
}HString;

void InitString(HString &S){
    S.ch = (char*)malloc(Maxlen*sizeof(char));
    S.length=0;
}

//赋值操作，把串T复制为chars
bool StrAssign(HString &T, char* chars){
    T.length = 0;
    for(int i = 1; chars[i]; i++){
        T.ch[i]=chars[i];
        T.length++;
    }
    return true;
}

bool StrCopy(HString &T, HString S){
    T=S;
    return true;
}

bool StrEmpty(HString S){
    if(S.length==0) return true;
    return false;
}

//若字符串S>T，返回值大于0，S=T，返回值等于0，S<T，返回值小于0
int StrCompare(HString S, HString T){
    int i=1;
    while(i<S.length &&i<T.length){
        if(S.ch[i]!=T.ch[i]){
            return S.ch[i]-T.ch[i];
        }
        i++;
    }
    return S.length-T.length;
}

int StrLength(HString S){
    return S.length;
}

//求子串，用Sub返回串S的第pos个字符起长度为len的子串
bool SubString(HString &Sub, HString S,int pos,int len){
        if(pos+len-1>S.length) return false;
        for(int i=1; i<=len; i++){
            Sub.ch[i]=S.ch[pos+i-1];
        } 
        Sub.ch[len+1] = '\0';
        Sub.length = len;
        return true;
}

//字符串拼接,用T返回由S1和S2连接的新串
bool Concat(HString &T, HString S1, HString S2){
    for(int i=1; i<=S1.length;i++){
        T.ch[i]=S1.ch[i];
    }         
    for(int i=1; i<=S2.length;i++){
        T.ch[S1.length+i]=S2.ch[i];
    }
    T.length=S1.length+S2.length;
    return true;
}

//返回串T在S中第一次出现的位置，不存在返回0
int Index(HString S, HString T){
    int i=1, n = StrLength(S), m=StrLength(T);
    HString Sub;
    InitString(Sub);
    while(i<= n-m+1){
        SubString(Sub,S,i,m);
        //cout<<Sub.ch+1<<endl;
        if(StrCompare(T,Sub)!=0)   i++;
        else return i;
    }
    return 0;
}

//朴素模式算法，返回串T在S中第一次出现的位置，不存在返回0
int Index2(HString S,HString T){
    int i=1,j=1;
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        }
        else{
            i=i-j+2;      //若当前子串匹配失败时，主串指针i指向下一个子串的第一个位置，模式串指针i指回第一个位置
            j=1;
        }
    }
    if(j>T.length){
        return i-T.length;
    }
    if(i>S.length){
        return 0;
    }
}

//KMP算法，难在求next数组
int Index_KMP(HString S, HString T, int next[]){
    int i=1,j=1;
    while(i<=S.length&&j<=T.length){
        if(j==0 || S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        }
        else{
            j=next[j];         //模式串向右移动,主串指针不移动
        }
    }
    if(j>T.length){
        return i-T.length;
    }
    else return 0;
}

//求next[]数组,看门牌算法
void Get_Next(HString T, int *next){
    int i=1,j=0;
    next[1]=0;
    while(i<T.length){        //注意不是i<=T.length，因为next[1]已经有值了，之后是从next[2]开始==
        if(j==0||T.ch[i]==T.ch[j]){
            ++i;
            ++j;
            next[i]=j;
        }
        else j=next[j];       //匹配不到就是找自己的“门牌”
    }    
}

void Get_Nextval(HString T, int *next){
    int i=1,j=0;
    next[1]=0;
    while(i<T.length){
        if(T==0||T.ch[i]==T.ch[j]){
            ++i;
            ++j;
            if(T.ch)
        }
    }
}

//清空操作
bool ClearString(HString &S){
    S.length = 0;
    return true;
}

//销毁串
bool DestoryString(HString &S){
    free(S.ch);
    S.length = 0;
    return true;
}

void test(){

    HString s,t;
    InitString(s);
    InitString(t);
    int next[255];
    char *sr =" aaabaaaab";
    char *tr =" aaaab";
    StrAssign(s,sr);
    cout<<sr<<endl;
    StrAssign(t,tr);
    cout<<Index2(s,t)<<endl;
    cout<<Index(s,t)<<endl;
    Get_Next(t,next);
    cout<<Index_KMP(s,t,next)<<endl;

    
}

int main(){
    test();
    return 0;
}