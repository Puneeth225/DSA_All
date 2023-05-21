/*#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> dq1;
    dq1.push_back(44);
    dq1.push_back(88);
    dq1.push_front(10);
    dq1.push_front(20);
    dq1.push_back(66);
    for(int i=0;i<dq1.size();i++){            //for(auto i:dq1){cout<<i<<" ";}
        cout<<dq1[i]<<" ";
    }cout<<"\n";
    dq1.pop_back();
    dq1.pop_front();
    for(int i=0;i<dq1.size();i++){            
        cout<<dq1[i]<<" ";
    }cout<<"\n";

}*/


//----------------SLIDING WINDOW-----------------------------//
//                    ||
//                    ||
//                    \/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &i: v){
        cin>>i;
    }
    //----------using set-----------------//
    /*multiset<int,greater<int>>s;
    vector<int> ans;
    for(int i= 0;i<k;i++){
        s.insert(v[i]);
    }
    ans.push_back(*s.begin());
    for(int i=k;i<n;i++){
        s.erase(s.lower_bound(v[i-k]));
        s.insert(v[i]);
        ans.push_back(*s.begin());
    }
    for(auto i: ans){
        cout<<i<<" ";
    }*/
    //---------using deque------------------//
    deque<int> q;
    vector<int> ans;
    for(int i=0;i<k;i++){
        while(!q.empty() and v[q.back()]<v[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(v[q.front()]);
    for(int i=k;i<n;i++){
        if(q.front()==i-k){
            q.pop_front();
        }
        while(!q.empty() and v[q.back()]<v[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(v[q.front()]);
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
}



