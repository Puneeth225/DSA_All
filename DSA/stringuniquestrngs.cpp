//find no of unique strings from given strings set
//normal method O(nmlog(n))
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<string>s = {"a","ab","a","ba","ba","ab","abc"};
//     sort(s.begin(),s.end());
//     int uniquecount=0;
//     for(int i=0;i<s.size();i++){
//         if(i==0 || s[i]!=s[i-1]){
//             uniquecount++;
//         }
//     }
//     cout<<uniquecount<<"\n";
// }

//using hashes
#include<bits/stdc++.h>
using namespace std;
int p = 31;  //it can be anyvalue
const int N = 1e5+2,MOD = 1e9+7;
vector<long long>powers(N);
long long findhash(string s){
    long long hash = 0;
    for(int i=0;i<s.size();i++){
        hash = (hash+(s[i]-'a'+1)*powers[i])%MOD;
    }
    return hash;
}
int main(){
    powers[0] = 1;
    for(int i=0;i<N;i++){
        powers[i] = (powers[i-1]*p)%MOD;
    }
    vector<string>s = {"a","ab","a","ba","ba","ab","abc"};
    vector<long long> hashes;
    for(auto w:s){
        hashes.push_back(findhash(w));
    } //after inserting hashes use remove duplicates function from array
    sort(hashes.begin(),hashes.end());
    int uniquecount = 0;
    for(int i=0;i<hashes.size();i++){
        if(i==0||hashes[i]!=hashes[i-1]){
            uniquecount++;
        }
    }
    cout<<uniquecount<<"\n";
}