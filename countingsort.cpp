#include <bits/stdc++.h>
using namespace std;
void countingSort(int arr[],int n){
    long long int maxi=*max_element(arr,arr+n); 
    long long int mini=*min_element(arr,arr+n); 
    long long int arr1[maxi-mini+1]={};
    // intialize the above arr1 to zero, otheriwse rnadom value and it should hold max element number of elemetns icnlduing zero
// making the arr1 for only lowest to highest elements in the arr
    for(int i=0;i<n;i++){
    arr1[arr[i]-mini]++;
}
long long int k=0;
for(int i=0;i<maxi-mini+1;i++){
    long long int count=0;
    while(count<arr1[i] &&arr1[i]!=0){
        arr[k++]=i+mini; count++;
    }
}
return ;
}