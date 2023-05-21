#include<bits/stdc++.h>
using namespace std;
//given an array and print all subarray elements of size k as a single element which is divisible by 3
void divisibleby3number(vector<int> arr, int k){
    pair<int,int> ans;
    int sum = 0;
    for(int i=0;i<k;i++){
        sum += arr[i];
    }
    bool isdivisibleby3 = false;
    if(sum % 3 == 0){
        ans = make_pair(0,k-1);
        isdivisibleby3 = true;
    }
    for(int i=k;i<arr.size();i++){
        if(isdivisibleby3){
            break;
        }
        sum = sum +arr[i] - arr[i-k];
        if(sum % 3 == 0){
            ans = make_pair(i-k+1,i);
            isdivisibleby3 = true;
        }
    }
    if(!isdivisibleby3){
        ans = make_pair(-1,0);
    }
    if(ans.first == -1){
        cout<<"No such number found"<<"\n";
    }
    else{
        for(int i= ans.first;i<=ans.second;i++){
            cout<<arr[i];
        }
        cout<<"\n";
    }
}
int main(){
    vector<int>a = {84,23,45,12,56,82};
    int k=3;
    divisibleby3number(a,k);
}