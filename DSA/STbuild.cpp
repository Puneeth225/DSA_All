#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7,MOD = 1e9+7;
int a[N],tree[4*N];
void build(int node,int st,int end){
    if(st==end){
        tree[node] = a[st];//or tree[node] = a[end]
        return;
    }
    int mid = (st+end)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,end);
    tree[node] = tree[2*node]+tree[2*node+1];
}

//function to return sum from index i to j
int query(int node,int st,int end,int l, int r){ //l=i,j=r
    if(st>r||end<l){
        return 0; //range do not overlap  st...end l...r or l...r st...end
    }
    if(st>=l&& end<=r){   //l st en r
        return tree[node];
    }
    int mid = (st+end)/2;   //st l end r or l st r end
    int q1 = query(2*node,st,mid,l,r);
    int q2 = query(2*node+1,mid+1,end,l,r);
    return q1+q2;   
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    // for(int i=1;i<15;i++){
    //     cout<<tree[i]<<"\n";
    // }
    while(1){
        int choice;
        cin>>choice;
        if(choice==-1){
            break;
        }
        if(choice==1){
            int l,r;
            cin>>l>>r;
            int ans = query(1,0,n-1,l,r);
            cout<<ans<<"\n";
        }
    }
}