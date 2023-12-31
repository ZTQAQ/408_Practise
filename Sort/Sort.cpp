#include <iostream>
using namespace std;
#define Maxsize 10
typedef int Elemtype;

//直接插入排序带哨兵
void InsertSort(int a[], int n){            //函数参数是数组的话，是可以直接修改原地址的值，不需要用引用或指针，数组的本质就是指针
    int i,j;
    for(i=2;i<=n;i++){
        if(a[i]<a[i-1]){          //若A[i]的关键词小于它的前驱，目标升序排序  a[2]=34 < a[1]=45
            a[0] = a[i];
            for(j=i-1;a[0]<a[j];--j){               //从后往前寻找待插入的位置
                a[j+1]=a[j];                        //没找到就向后一直挪，腾个位置
            }
            a[j+1] = a[0];                          //找到
         }
    }
}

//直接插入排序，不带哨兵
void InsertSort2(int a[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        if(a[i-1]>a[i]){
            temp = a[i];
            for(j=i-1;j>=0&&a[j]>temp;j--){          //这个for循环加上temp或a[0]=a[i]，就是插入的思想，后面的都往后推，留个位置插入
                a[j+1]=a[j];
            }
            a[j+1]=temp;
        }
    }
}

//折半插入查找,带哨兵
void Half_Reduced_InsertSort(int a[],int n){
    int i,j,mid,low,high;
    for (i=2;i<=n;i++){
        a[0] = a[i];
        low = 1, high = i-1;
        while(high>=low){              //这里一定要high>=low，不能high>low,不然low少加个一，出来的结果是错的
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

//希尔排序，带哨兵
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
            }                                     //注意这里的if下括号出现在这里，和其他的插入排序下括号出现位置不同
                                                  //其他的一般性出现在a[0]=a[i]后面
        }    
    }
}


//交换排序
//冒泡排序，不带哨兵
void BubbleSort(int a[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        bool flag = false;
        for(j = n-1;j>i;j--){
            if(a[j]<a[j-1]){                        //稳定的，只有小于时候才换
                swap(a[j],a[j-1]);
                flag = true;
            }
        }
        if(flag==false)                      //在一趟遍历中（冒泡排序的遍历要走到大循环的i处，如果flag一直是false
                                             //则表示在本次循环中全都是a[j]>a[j-1]，已经有序
            return;
    }
}

void swap(int &a,int &b){
    int flag;
    flag = a;
    a=b;
    b=flag;
}


//快速排序
//用一个元素pivot将这个数组划分为两部分，左边的都比它小，右边的都比它大
int Partition(int a[], int low, int high){
    int pivot = a[low];                        //选取a[low]进行划分（将a[low]快速排序插入到数组中它应该的正确的位置）
    while(low<high){

        //从最右边开始high--找到一个比pivot小的元素,插入到a[low]的位置
        while(low<high && pivot<=a[high]){   
            high--;
        }
        a[low] = a[high];

        //从low的位置开始low++，找到一个比pivot大的元素，插入到a[high]的位置
        while(low<high && pivot>=a[low]){    
            low++;
        }
        a[high] = a[low];
    }
    //如果此时a[low]=a[high]，此时a[low]的位置就是pivot的位置
    a[low] = pivot;
    return low;             //low返回出来，快排的递归还要用

}

//快速排序
void QuickSort(int a[], int low, int high){
    if(low<high){
        int pivotpos = Partition(a, low, high);      //中枢，划分
        QuickSort(a,low,pivotpos-1);                 //对其左右子树进行划分
        QuickSort(a,pivotpos+1,high);
    }
}

//选择排序，选择排序的特点是选取数组中最小（大）的元素交换到队头（尾），交换次数会很少
//简单选择排序
void SelectSort(int a[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min = j;
            }
            if(min!=i){                            //确保算法的稳定性，如果相同的话就不交换了，节省次数
                swap(a[min],a[j]);              
            }
/*
            if(min>a[j]){               
                swap(min,a[j]);     //如果定义的min=a[i]就变成了冒泡，要交换很多很多次，选择的话一次遍历就交换一次
            }
*/
        }
    }
}

//堆排序,带哨兵
//将以k为根的子树调整为大根堆,a[k]是根节点
void HeadAdjust(int a[], int k, int n){
    a[0] =a[k];
    int i;
    for(i=2*k;i<=n;i*=2){               //i=2k是k的左子树,2k+1是右子树
        if(i<n &&a[i]<a[i+1]){
            i++;                          //选左子树和右子树中更大的那个
        }
        if(a[0]>a[i])    break;        
        else{
            a[k] = a[i];
            k=i;
        }
    }
    a[k] = a[0];
}

//建立大根堆
void BuildMaxHeap(int a[],int n){
    for(int i=n/2;i>0;i--){             //理解i=n/2，因为是完全二叉树，a[n/2]+1开始都是叶子节点
        HeadAdjust(a,i,n);
    }
}

//将大根堆的根节点（数组的最大值），交换出来放到数组的队尾
void HeapSort(int a[],int n){
    BuildMaxHeap(a,n);                 //初始建堆
    for(int i=n;i>1;i--){
        swap(a[1],a[i]);
        HeadAdjust(a,1,i-1);           //数组的最大值放到队尾之后，我们要重新对整个a[i-1]数组再次建立大根堆，找到最大值
    }
}

int main(){
    int a[] = {0,45,76,34,23,65};   //带哨兵
    int *p = a;
    int length = sizeof(a)/sizeof(a[0])-1;           //得到数组的长度,a[0]是哨兵，不计入数组长度
    InsertSort(a,length);
    cout<<"直接插入排序:"<<endl;
    for(int i=1;i<=length;i++){
        cout<<a[i]<<endl;        
    }

    Half_Reduced_InsertSort(p,length);
    cout<<"折半插入排序:"<<endl;
    for(int i=1;i<=length;i++){
        cout<<p[i]<<endl;        
    }

    int b[] = {45,76,34,23,65};                     //不带哨兵用b[]和length1，带哨兵用a[]和length
    int length1 = sizeof(b)/sizeof(b[0]);           //得到数组的长度,a[0]是哨兵，不计入数组长度
    InsertSort2(b,length1);
    cout<<"直接插入排序(不带哨兵):"<<endl;
    for(int i=0;i<length1;i++){
        cout<<b[i]<<endl;        
    }


    ShellSort(a,length);
    cout<<"希尔插入排序(带哨兵):"<<endl;
    for(int i=1;i<=length;i++){
        cout<<a[i]<<endl;        
    }

    BubbleSort(b,length1);
    cout<<"冒泡插入排序(不带哨兵):"<<endl;
    for(int i=0;i<length1;i++){
        cout<<b[i]<<endl;        
    }


    QuickSort(b,0,length1-1);
    cout<<"快速插入排序(不带哨兵):"<<endl;
    for(int i=0;i<length1;i++){
        cout<<b[i]<<endl;        
    }

    SelectSort(b,length1);
    cout<<"简单选择排序(不带哨兵):"<<endl;
    for(int i=0;i<length1;i++){
        cout<<b[i]<<endl;        
    }

    HeapSort(a,length);
    cout<<"堆排序(带哨兵):"<<endl;
    for(int i=1;i<=length;i++){
        cout<<a[i]<<endl;        
    }



    return 0;
}