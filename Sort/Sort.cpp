#include <iostream>
using namespace std;
#define Maxsize 10
typedef int Elemtype;

//ֱ�Ӳ���������ڱ�
void InsertSort(int a[], int n){            //��������������Ļ����ǿ���ֱ���޸�ԭ��ַ��ֵ������Ҫ�����û�ָ�룬����ı��ʾ���ָ��
    int i,j;
    for(i=2;i<=n;i++){
        if(a[i]<a[i-1]){          //��A[i]�Ĺؼ���С������ǰ����Ŀ����������  a[2]=34 < a[1]=45
            a[0] = a[i];
            for(j=i-1;a[0]<a[j];--j){               //�Ӻ���ǰѰ�Ҵ������λ��
                a[j+1]=a[j];                        //û�ҵ������һֱŲ���ڸ�λ��
            }
            a[j+1] = a[0];                          //�ҵ�
         }
    }
}

//ֱ�Ӳ������򣬲����ڱ�
void InsertSort2(int a[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        if(a[i-1]>a[i]){
            temp = a[i];
            for(j=i-1;j>=0&&a[j]>temp;j--){          //���forѭ������temp��a[0]=a[i]�����ǲ����˼�룬����Ķ������ƣ�����λ�ò���
                a[j+1]=a[j];
            }
            a[j+1]=temp;
        }
    }
}

//�۰�������,���ڱ�
void Half_Reduced_InsertSort(int a[],int n){
    int i,j,mid,low,high;
    for (i=2;i<=n;i++){
        a[0] = a[i];
        low = 1, high = i-1;
        while(high>=low){              //����һ��Ҫhigh>=low������high>low,��Ȼlow�ټӸ�һ�������Ľ���Ǵ��
            mid = (low + high)/2;
            if(a[mid]>a[0]){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        for(j = i-1; j>=low; j--){
            a[j+1] = a[j];
        }
        a[j+1] =a[0];
    }
}

//ϣ�����򣬴��ڱ�
void ShellSort(int a[], int n){
    int d,i,j;
    for(d=n/2;d>=1;d=d/2){
        for(i=d+1;i<=n;i++){
            if(a[i]<a[i-d]){    
                a[0] = a[i];
                for(j=i-d;j>0&&a[j]>a[0];j-=d){
                    a[j+d] = a[j];
                }
                a[j+d] = a[0];
            }                                     //ע�������if�����ų���������������Ĳ������������ų���λ�ò�ͬ
                                                  //������һ���Գ�����a[0]=a[i]����
        }    
    }
}


//��������
//ð�����򣬲����ڱ�
void BubbleSort(int a[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        bool flag = false;
        for(j = n-1;j>i;j--){
            if(a[j]<a[j-1]){                        //�ȶ��ģ�ֻ��С��ʱ��Ż�
                swap(a[j],a[j-1]);
                flag = true;
            }
        }
        if(flag==false)                      //��һ�˱����У�ð������ı���Ҫ�ߵ���ѭ����i�������flagһֱ��false
                                             //���ʾ�ڱ���ѭ����ȫ����a[j]>a[j-1]���Ѿ�����
            return;
    }
}

void swap(int &a,int &b){
    int flag;
    flag = a;
    a=b;
    b=flag;
}


//��������
//��һ��Ԫ��pivot��������黮��Ϊ�����֣���ߵĶ�����С���ұߵĶ�������
int Partition(int a[], int low, int high){
    int pivot = a[low];                        //ѡȡa[low]���л��֣���a[low]����������뵽��������Ӧ�õ���ȷ��λ�ã�
    while(low<high){

        //�����ұ߿�ʼhigh--�ҵ�һ����pivotС��Ԫ��,���뵽a[low]��λ��
        while(low<high && pivot<=a[high]){   
            high--;
        }
        a[low] = a[high];

        //��low��λ�ÿ�ʼlow++���ҵ�һ����pivot���Ԫ�أ����뵽a[high]��λ��
        while(low<high && pivot>=a[low]){    
            low++;
        }
        a[high] = a[low];
    }
    //�����ʱa[low]=a[high]����ʱa[low]��λ�þ���pivot��λ��
    a[low] = pivot;
    return low;             //low���س��������ŵĵݹ黹Ҫ��

}

//��������
void QuickSort(int a[], int low, int high){
    if(low<high){
        int pivotpos = Partition(a, low, high);      //���࣬����
        QuickSort(a,low,pivotpos-1);                 //���������������л���
        QuickSort(a,pivotpos+1,high);
    }
}

//ѡ������ѡ��������ص���ѡȡ��������С���󣩵�Ԫ�ؽ�������ͷ��β�����������������
//��ѡ������
void SelectSort(int a[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min = j;
            }
            if(min!=i){                            //ȷ���㷨���ȶ��ԣ������ͬ�Ļ��Ͳ������ˣ���ʡ����
                swap(a[min],a[j]);              
            }
/*
            if(min>a[j]){               
                swap(min,a[j]);     //��������min=a[i]�ͱ����ð�ݣ�Ҫ�����ܶ�ܶ�Σ�ѡ��Ļ�һ�α����ͽ���һ��
            }
*/
        }
    }
}

//������,���ڱ�
//����kΪ������������Ϊ�����,a[k]�Ǹ��ڵ�
void HeadAdjust(int a[], int k, int n){
    a[0] =a[k];
    int i;
    for(i=2*k;i<=n;i*=2){               //i=2k��k��������,2k+1��������
        if(i<n &&a[i]<a[i+1]){
            i++;                          //ѡ���������������и�����Ǹ�
        }
        if(a[0]>a[i])    break;        
        else{
            a[k] = a[i];
            k=i;
        }
    }
    a[k] = a[0];
}

//���������
void BuildMaxHeap(int a[],int n){
    for(int i=n/2;i>0;i--){             //���i=n/2����Ϊ����ȫ��������a[n/2]+1��ʼ����Ҷ�ӽڵ�
        HeadAdjust(a,i,n);
    }
}

//������ѵĸ��ڵ㣨��������ֵ�������������ŵ�����Ķ�β
void HeapSort(int a[],int n){
    BuildMaxHeap(a,n);                 //��ʼ����
    for(int i=n;i>1;i--){
        swap(a[1],a[i]);
        HeadAdjust(a,1,i-1);           //��������ֵ�ŵ���β֮������Ҫ���¶�����a[i-1]�����ٴν�������ѣ��ҵ����ֵ
    }
}

int main(){
    int a[] = {0,45,76,34,23,65};   //���ڱ�
    int *p = a;
    int length = sizeof(a)/sizeof(a[0])-1;           //�õ�����ĳ���,a[0]���ڱ������������鳤��
    InsertSort(a,length);
    cout<<"ֱ�Ӳ�������:"<<endl;
    for(int i=1;i<=length;i++){
        cout<<a[i]<<endl;        
    }

    Half_Reduced_InsertSort(p,length);
    cout<<"�۰��������:"<<endl;
    for(int i=1;i<=length;i++){
        cout<<p[i]<<endl;        
    }

    int b[] = {45,76,34,23,65};                     //�����ڱ���b[]��length1�����ڱ���a[]��length
    int length1 = sizeof(b)/sizeof(b[0]);           //�õ�����ĳ���,a[0]���ڱ������������鳤��
    InsertSort2(b,length1);
    cout<<"ֱ�Ӳ�������(�����ڱ�):"<<endl;
    for(int i=0;i<length1;i++){
        cout<<b[i]<<endl;        
    }


    ShellSort(a,length);
    cout<<"ϣ����������(���ڱ�):"<<endl;
    for(int i=1;i<=length;i++){
        cout<<a[i]<<endl;        
    }

    BubbleSort(b,length1);
    cout<<"ð�ݲ�������(�����ڱ�):"<<endl;
    for(int i=0;i<length1;i++){
        cout<<b[i]<<endl;        
    }


    QuickSort(b,0,length1-1);
    cout<<"���ٲ�������(�����ڱ�):"<<endl;
    for(int i=0;i<length1;i++){
        cout<<b[i]<<endl;        
    }

    SelectSort(b,length1);
    cout<<"��ѡ������(�����ڱ�):"<<endl;
    for(int i=0;i<length1;i++){
        cout<<b[i]<<endl;        
    }

    HeapSort(a,length);
    cout<<"������(���ڱ�):"<<endl;
    for(int i=1;i<=length;i++){
        cout<<a[i]<<endl;        
    }



    return 0;
}