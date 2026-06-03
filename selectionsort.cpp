#include <bits/stdc++.h>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        long long int minidx=min_element(arr+i,arr+n)-arr;
        if(minidx!=i){
           swap(arr[i],arr[minidx]);
        }
    }
    return ;
}