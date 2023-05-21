//always flush the I/O stream 
//guess a number b/w two numbers l and h;
#include<bits/stdc++.h>
using namespace std;
int main(){
    int l = 0;
    int h = 1000000;
    int ans = -1;
    while(l<=h){
        int mid = (l+h)/2;
        cout<<mid<<"\n";
        cout<<flush;
        string s;
        cin>>s;
        if(s=="<"){
            h = mid-1;
        }
        else{
            //>=
            ans = max(ans,mid);
            l = mid+1;
        }
    }
    cout<<"! "<<ans<<"\n";
    cout<<flush;
}

//in java to flush use System.out.flush();