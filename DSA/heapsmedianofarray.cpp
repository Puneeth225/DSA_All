// given a array find the median of array after every insertion of element
// NC--------------NC-------------NC
#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;
void insert1(int x){
    if(pqmax.size() == pqmin.size()){
        if(pqmax.size()==0){
            pqmax.push(x);
            return;
        }
        if(x<pqmax.top()){
            pqmax.push(x);
        }
        else{
            pqmin.push(x);
        }
    }
    else{
        if(pqmax.size()>pqmin.size()){
            if(x>=pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else{
            if(x<=pqmin.top()){
                pqmax.push(x);
            }
            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}
double findMedian(){
    if(pqmax.size()==pqmax.size()){
        return (pqmax.top()+pqmin.top())/2.0;
    }
    else if(pqmax.size()>pqmin.size()){
        return pqmax.top();
    }
    else{
        return pqmin.top();
    }
    
}
int main(){
    insert1(10.0);
    cout<<findMedian()<<"\n";
    insert1(15);
    cout<<findMedian()<<"\n";
    insert1(21);
    cout<<findMedian()<<"\n";
    insert1(30);
    cout<<findMedian()<<"\n";
    insert1(18);
    cout<<findMedian()<<"\n";
}