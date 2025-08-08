#include <stdio.h>
#include <stdlib.h>
void merge(int arr[],int lo,int mid,int hi){
    int i=lo;
    int j=mid+1;
    int k=0;
    int *temp=malloc(sizeof(int)*(hi-lo+1));
    while (i<=mid && j<=hi){
        if (arr[i] < arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while (i<=mid) temp[k++]=arr[i++];
    while(j<=hi)   temp[k++]=arr[j++];
    for(int i=lo;i<=hi;i++) arr[i]=temp[i-lo];
    free(temp);
}
void divide(int arr[],int lo,int hi){
    if (lo<hi){
        int mid=(lo+hi)/2;
        divide(arr,lo,mid);
        divide(arr,mid+1,hi);   
        merge(arr,lo,mid,hi);
    }
}
int main(){
    int arr[]={12,34,53,23,22,5221,1354,33,2};
    int lo=0,hi=sizeof(arr)/sizeof(arr[0])-1;
    divide(arr,lo,hi);
    for (int i = 0; i <= hi; i++) printf("%d ",arr[i]);
}
