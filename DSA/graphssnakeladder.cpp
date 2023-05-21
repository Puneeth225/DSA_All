//same as snake and ladder game reach 100 in minimum number of dice throws and dice throw can get any number you need
#include <bits/stdc++.h>
using namespace std;
int main(){
    int ladders,snakes,moves=0;
    queue<int> q;
    cin>>ladders;
    map<int,int> l;
    map<int,int> s;
    for(int i=0;i<ladders;i++){
        int u,v;
        cin>>u>>v;
        l[u] = v;
    }
    cin>>snakes;
    for(int i=0;i<snakes;i++){
        int u,v;
        cin>>u>>v;
        s[u] = v;
    }
    q.push(1);
    bool reached_end = false;
    vector<int> visited(101,0);
    visited[1] = 1;
    while(!reached_end && !q.empty()){
        int sz = q.size();
        while(sz--){
            int t = q.front();
            q.pop();
            for(int die = 1;die<=6;die++){
                if(t+die == 100){
                    reached_end = true;
                }
                if(t+die<=100 && l[t+die] && !visited[l[t+die]]){
                    visited[l[t+die]] == true;
                    if(l[t+die] == 100){
                        reached_end == true;
                    }
                    q.push(l[t+die]);
                }
                else if(t+die<=100 && s[t+die] && !visited[s[t+die]]){
                    visited[s[t+die]] == true;
                    if(s[t+die] == 100){
                        reached_end == true;
                    }
                    q.push(s[t+die]);
                }
                else if(t+die<=100 && !visited[t+die] && !s[t+die] && !l[t+die]){
                    visited[t+die] = true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }
    if(reached_end){
        cout<<moves<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }
}