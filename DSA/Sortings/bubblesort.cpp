#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int toleavelast = 1;
    while(toleavelast<n){
        for(int i = 0;i<n-toleavelast;i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        toleavelast++;
    }
    for(int i= 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<"\n";
}