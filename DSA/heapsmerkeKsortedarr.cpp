// given K sorted arrays merge them correctly
// NC--------------NC-------------NC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    vector<vector<int>> noofarr(k);
    for(int i=0;i<k;i++){
        int sizeofeach;
        cin>>sizeofeach;
        noofarr[i] = vector<int>(sizeofeach);
        for(int j=0;j<sizeofeach;j++){
            cin>>noofarr[i][j];
        }
    }
    vector<int> idx(k,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<k;i++){
        pair<int,int> p;
        p.first = noofarr[i][0];
        p.second = i;
        pq.push(p);
        //pq.push({noofarr[i][0],i});
    }
    vector<int> ans;
    while(!pq.empty()){
        pair<int,int> x = pq.top();
        pq.pop();
        ans.push_back(x.first);
        if(idx[x.second]+1<noofarr[x.second].size()){
            pq.push({noofarr[x.second][idx[x.second]+1],x.second});
            idx[x.second]+=1;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}