#include <bits/stdc++.h>
using namespace std;
void bubblesort(long long int arr[],int n){

    for(int i=0;i<n-1;i++){
        bool swapped=false;
        
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){long long temp=arr[j]; arr[j]=arr[j+1]; arr[j+1]=temp; swapped=true;}   
        }

        if(!swapped){break;}
    }
}
