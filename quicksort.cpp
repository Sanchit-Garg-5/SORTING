#include <bits/stdc++.h>
using namespace std;
int func(int arr[],int left,int right){
    int ele=arr[left];
    int i=left,j=right;
    while(i<j){
        while(i<right+1){if(arr[i]>ele){break;} else{i++;}}
        while(j>-1){if(arr[j]<=ele){break;} else{j--;}} 
        if(i<j){swap(arr[i],arr[j]);i++;j--; }
        // once again check that if i<j because in above two lines we incremented i, decremented j,so after doing it for required time, we need to chekc if i still < than j
        else{break;} 
    }
    swap(arr[left],arr[j]);
    return j;
}

void quicksort(int arr[], int left, int right){
    if(left>=right){return;}
    else{
    int pidx=func(arr,left,right);
    quicksort(arr,left,pidx-1);
    quicksort(arr,pidx+1,right);
}}

int main(){
    quicksort(arr,0,n-1);
}