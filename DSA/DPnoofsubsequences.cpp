//given a string with '?' in it and replace them with 'a''b''c' and count all subsequences from all of 'abc' in it
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int e=1,ca=0,cab=0,cabc=0;//cx indicate count of subsequences of x and e is count of string
    for(int i=0;i<n;i++){
        if(s[i] == 'a'){
            ca+=e;
        }
        else if(s[i] == 'b'){
            cab+=ca;
        }
        else if(s[i] == 'c'){
            cabc+=cab;
        }
        else if(s[i] == '?'){
            cabc = 3*cabc+cab;
            cab = 3*cab+ca;
            ca = 3*ca+e;
        }
    }
    cout<<cabc<<"\n";
}