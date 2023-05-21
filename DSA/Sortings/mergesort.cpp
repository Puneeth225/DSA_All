#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid, int r){
    int sz1 = mid-l+1;
    int sz2 = r-mid;
    int a[sz1],b[sz2];
    for(int i = 0;i<sz1;i++){
        a[i] = arr[l+i];
    }
    for(int i = 0;i<sz2;i++){
        b[i] = arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<sz1&&j<sz2){
        if(a[i]<b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while(i<sz1){
         arr[k] = a[i];
            k++;
            i++;
    }
    while(j<sz2){
         arr[k] = b[j];
            k++;
            j++;
    }
}
void mergesort(int arr[],int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //int arr[] = {6,5,4,3,2,1,22,1111,1356,668,89,100};
    mergesort(arr,0,n-1);
    for(int i= 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<"\n";

}   