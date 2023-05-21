//given an array and two indices of array return maximum between given two indices
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7,MOD = 1e9+7;
int tree[4*N],a[N];
void build(int node,int st,int end){
    if(st==end){
        tree[node] = a[st];
        return;
    }
    int mid = (st+end)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,end);
    tree[node] = max(tree[2*node],tree[2*node+1]);
}
//to find max b/w l and r indices
int query(int node,int st,int end,int l,int r){
    if(st>r||end<l){
        return INT_MIN;
    }
    if(l<=st&&end<=r){
        return tree[node];
    }
    int mid = (st+end)/2;
    int q1 = query(2*node,st,mid,l,r);
    int q2 = query(2*node+1,mid+1,end,l,r);
    return max(q1,q2);
}
//to update ith index with new value
void update(int node,int st,int end,int idx,int val){
    if(st==end){
        a[st] = val;
        tree[node] = val;
        return;
    }
    int mid = (st+end)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }
    else{
        update(2*node+1,mid+1,end,idx,val);
    }
    tree[node] = max(tree[2*node],tree[2*node+1]);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    while(1){
        int type;
        cin>>type;//if type=1 query if 2 update if -1 exit
        if(type==-1){
            break;
        }
        if(type==1){
            int l,r;
            cin>>l>>r;
            int ans = query(1,0,n-1,l,r);
            cout<<ans<<"\n";
        }
        if(type==2){
            int idx,val;
            cin>>idx>>val;
            update(1,0,n-1,idx,val);
            cout<<query(1,0,n-1,0,n-1);
        }
    }
}