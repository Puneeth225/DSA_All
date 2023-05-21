//returns the no. of days where stock price(array) has less value then today's value
#include <bits/stdc++.h>
using namespace std;
vector<int> grtrpricofstck(vector<int> stckvals){
    vector<int> ans;
    stack<pair<int,int>> st;
    for(auto stckprice: stckvals){
        int days = 1;
        while(!st.empty()&& st.top().first<=stckprice){
            days+=st.top().second;
            st.pop();
        }
        st.push({stckprice,days});
        ans.push_back(days);
    }
    return ans;
}
int main(){
    vector<int> a1 = {100,80,60,70,60,75,85};
    for(auto i:grtrpricofstck(a1)){                 //vector<int> answer = grtrpricofstck(a1);
        cout<<i<<" ";                               //for(auto i: answer){cout<<i<<" ";}
    }cout<<"\n";
}

