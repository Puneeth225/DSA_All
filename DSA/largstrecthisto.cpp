#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxarea(vector<int>& nums) {
    int n = nums.size();
    stack<int> stk;
    int max_area = 0 , cur_area , height , k , width;

    for(int i = 0; i < n ; i++){
        while(!stk.empty() && nums[stk.top()] >= nums[i]){
            height = nums[stk.top()];
            stk.pop();
            k = stk.empty() ? -1 : stk.top();          //here st.top() returns after pop operation
            width = i - k - 1;
            cur_area = height * width;
            max_area = max(cur_area , max_area);
        }

        stk.push(i);
    }

    
    while(!stk.empty()){
        height = nums[stk.top()];
        stk.pop();
        k = stk.empty() ? -1 : stk.top();
        width = n - k - 1;
        cur_area = height * width;
        max_area = max(cur_area , max_area);
    }

    return max_area;
}
int main(){
    vector<int> a1 = {2,1,5,6,2,3};
    cout<<maxarea(a1);
    return 0;
}


/*#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int mxarea(vector<int> a){
    int n = a.size(),mxareaans=0,i=0;
    stack<int> st;
    a.push_back(0);
    while(i<n){
        while(!st.empty() && a[st.top()]>a[i]){
            int b = st.top();
            int c = a[b];
            st.pop();
            if(st.empty()){
                mxareaans = max(mxareaans,c*i);
            }
            else{
                int len = i-st.top()-1;
                mxareaans = max(mxareaans,c*len);
            }
            st.push(i);
            i++;
        }
    }
    return mxareaans;
}
int main(){
    vector<int> a1 = {2,1,5,6,2,3};
    cout<<mxarea(a1);
    return 0;
}*/
