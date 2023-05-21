//given n,m and array(consists of 0 or 1) of size n and m queries find kth one
//1 i means update ith index in array to its opposite value (0 for 1 and 1 for 0)
//2 i means find ith one in last updated array(indexing 0)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7,MOD = 1e9+7;
int a[N];
int tree[4*N];
void build(int node,int st,int end){
    if(st==end){
        tree[node] = a[st];
        return;
    }
    int mid = (st+end)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,end);
    tree[node] = tree[2*node]+tree[2*node+1];
}
void update(int node,int st,int end,int idx){
    if(st==end){
        if(a[st]==0){
            a[st]=1;
            tree[node] = 1;
        }
        else{
            a[st] = 0;
            tree[node] = 0;
        }
        return;
    }
    int mid = (st+end)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx);
    }
    else{
        update(2*node+1,mid+1,end,idx);
    }
    tree[node] = tree[2*node]+tree[2*node+1];
}
//descend the segment tree
int query(int node,int st,int end,int k){
    if(st==end){
        return st;
    }
    int mid = (st+end)/2;
    if(k<tree[2*node]){
        return query(2*node,st,mid,k);
    }
    else{
        return query(2*node+1,mid+1,end,k-tree[2*node]);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    for(int i=0;i<m;i++){
        int type;
        cin>>type;
        if(type==1){
            int idx;
            cin>>idx;
            update(1,0,n-1,idx);
        }
        else{
            int k;
            cin>>k;
            int ans = query(1,0,n-1,k);
            cout<<ans<<"\n";
        }
    }
} 