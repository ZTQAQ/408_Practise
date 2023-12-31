#include<iostream>
using namespace std;

int Partition(int a[], int left,int right){
    int mid=a[0];
    while(left<=right){
        while(mid<=a[right]){
            a[right]--;
        }
        while(mid>=a[left]){
            a[left]++;
        }        
    }
    a[mid]=a[left];
    return mid;
}

void QuickSort(int a[], int left, int right){
    if(left<=right){
        int mid = Partition(a,left, right);
        QuickSort(a,left,mid-1);
        QuickSort(a,mid+1,right);        
    }
}

