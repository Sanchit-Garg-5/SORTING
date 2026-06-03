#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int left, int right, int mid){
    int n1=mid+1-left;
    int n2=right-mid;
    long long int arr1[n1]={}; long long int arr2[n2]={};
    for(int i=0;i<n1;i++){arr1[i]=arr[i+left];}
    for(int i=0;i<n2;i++){arr2[i]=arr[i+mid+1];}
    // created 2 temp arrays to store the values from arr while we are rebudikding arr
    long long int k=left,i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]>=arr2[j]){arr[k++]=arr2[j++];}
        else{arr[k++]=arr1[i++];}
    }
    while(i<n1){
        arr[k++]=arr1[i++];
    } 
    while(j<n2){
        arr[k++]=arr2[j++];
    }
    // purpose of above two loops is to add any remaining element sin both arr1,arr2 to arr.
}
void mergeSort(int arr[],int left,int right){

    if(left>=right){return;}
    //base case above, no need to go any further than 1 element. also alwayds place abse case just on tpp of the fucntion
    long long mid=left+(right-left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr,mid+1,right);

    merge(arr,left,right,mid);
}
int main(){
    mergeSort(array,0,n-1);
}