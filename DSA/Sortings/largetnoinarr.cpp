//Given an array of numbers, arrange them in a way that yields the largest value. For example, if the given numbers are {54, 546, 548, 60}, the arrangement 6054854654 gives the largest value.
#include<bits/stdc++.h>
using namespace std;
int mycompare(string x,string y){
    string xy = x.append(y);
    string yx = y.append(x);
    return xy.compare(yx)>0?1:0;
}
void printlargest(vector<string>&a){
    sort(a.begin(),a.end(),mycompare);
    for(auto it:a){
        cout<<it;
    }
}
int main(){
    int n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    printlargest(a);
}