#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n){
for(int i=1;i<n;i++){
    int keyidx=i;
    for(int j=0;j<i;j++){
        if(arr[j]>arr[i]){keyidx=j; break;}
    }
    long long int temp=arr[i];
    for(int j=i;j>keyidx;j--){
        arr[j]=arr[j-1];
    }
    arr[keyidx]=temp;
}
return ;
}
