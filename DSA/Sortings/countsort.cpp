#include<bits/stdc++.h>
using namespace std;
void countsort(int arr[],int n){
    int k = arr[0];
    for(int i=0;i<n;i++){
        k = max(k,arr[i]);
    }
    int count[100] = {0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }
    int sorted[n];
    for(int i=n-1;i>=0;i--){
        sorted[--count[arr[i]]] = arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i] = sorted[i];
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    countsort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}