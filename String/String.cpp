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

//��ֵ�������Ѵ�T����Ϊchars
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

//���ַ���S>T������ֵ����0��S=T������ֵ����0��S<T������ֵС��0
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

//���Ӵ�����Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
bool SubString(HString &Sub, HString S,int pos,int len){
        if(pos+len-1>S.length) return false;
        for(int i=1; i<=len; i++){
            Sub.ch[i]=S.ch[pos+i-1];
        } 
        Sub.ch[len+1] = '\0';
        Sub.length = len;
        return true;
}

//�ַ���ƴ��,��T������S1��S2���ӵ��´�
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

//���ش�T��S�е�һ�γ��ֵ�λ�ã������ڷ���0
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

//����ģʽ�㷨�����ش�T��S�е�һ�γ��ֵ�λ�ã������ڷ���0
int Index2(HString S,HString T){
    int i=1,j=1;
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        }
        else{
            i=i-j+2;      //����ǰ�Ӵ�ƥ��ʧ��ʱ������ָ��iָ����һ���Ӵ��ĵ�һ��λ�ã�ģʽ��ָ��iָ�ص�һ��λ��
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

//KMP�㷨��������next����
int Index_KMP(HString S, HString T, int next[]){
    int i=1,j=1;
    while(i<=S.length&&j<=T.length){
        if(j==0 || S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        }
        else{
            j=next[j];         //ģʽ�������ƶ�,����ָ�벻�ƶ�
        }
    }
    if(j>T.length){
        return i-T.length;
    }
    else return 0;
}

//��next[]����,�������㷨
void Get_Next(HString T, int *next){
    int i=1,j=0;
    next[1]=0;
    while(i<T.length){        //ע�ⲻ��i<=T.length����Ϊnext[1]�Ѿ���ֵ�ˣ�֮���Ǵ�next[2]��ʼ==
        if(j==0||T.ch[i]==T.ch[j]){
            ++i;
            ++j;
            next[i]=j;
        }
        else j=next[j];       //ƥ�䲻���������Լ��ġ����ơ�
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

//��ղ���
bool ClearString(HString &S){
    S.length = 0;
    return true;
}

//���ٴ�
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