//find indices of occurrunces of string s in string t
//O(s.size()+t.size())
//hash(i...j) = (hash(0...j)-hash(0...i-1))/p^i
// #include<bits/stdc++.h>
// using namespace std;
// int p = 31;
// const int N = 1e5+7,MOD = 1e9+7;
// vector<long long> powers(N);
// int main(){
//     string s = "nee";
//     string t = "hewlettpackerdneetynee";
//     int l1 = t.size();
//     int l2 = s.size();
//     vector<long long> h(l1+1,0);
//     powers[0]= 1;
//     for(int i=1;i<N;i++){
//         powers[i] = (powers[i-1]*p)%MOD;
//     }
//     for(int i=0;i<l1;i++){
//         h[i+1] = (h[i]+(t[i]-'a'+1)*powers[i])%MOD;
//     }
//     long long hashofS = 0;
//     for(int i=0;i<l2;i++){
//         hashofS = (hashofS+(s[i]-'a'+1)*powers[i])%MOD;
//     }
//     for(int i=0;i+l2-1<l1;i++){
//         long long curr_h = (h[i+l2]-h[i]+MOD)%MOD;
//         if(curr_h == (hashofS*powers[i])%MOD){
//             cout<<"Found at "<<i<<"\n";
//         }
//     }

// }







#include<bits/stdc++.h>
using namespace std;
int p = 31;
const int N = 1e5+7,MOD = 1e9+7;
vector<long long> powers(N);
int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<long long> h(n+1,0);
    powers[0]= 1;
    for(int i=1;i<N;i++){
        powers[i] = (powers[i-1]*p)%MOD;
    }
    for(int i=0;i<n;i++){
        h[i+1] = (h[i]+(s[i]-'a'+1)*powers[i])%MOD;
    }
    // for(int i=1;i<h.size();i++){
    //     cout<<h[i]<<" ";
    // }
    cout<<h[h.size()-1];
}