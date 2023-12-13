#include<bits/stdc++.h>
using namespace std;
int partition(int *arr,int s,int e){
    int count=0;
    int pivot=arr[s];
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count+=1;
        }
    }
    int pivotIndex=s+count;
    swap(arr[pivotIndex],arr[s]);
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}
void QuickSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);
    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);

}
int main(){
    int arr[5]={1,2,4,6,9};
    QuickSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}