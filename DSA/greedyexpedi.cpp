//a truck will reach town and between there are some stops for fuel which has the fuel capacity specified in fuel bank , truck can fill as much fuel as infinity in it find the minimum stops truck will take to reach the town
// we use maxheap with quantity of fuel at fuel bank and sort the stops in order in which they come first to truck
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool flag = 0;
        vector<pair<int,int>> fuelbank(n); // it stores the first the distance from town and second the capacity of fuel that stop can provide
        for(int i=0;i<n;i++){
            cin>>fuelbank[i].first>>fuelbank[i].second;
        }
        int distoftruckfromtown, initialfuelintruck;
        cin>>distoftruckfromtown>>initialfuelintruck;
        for(int i=0;i<n;i++){
            fuelbank[i].first = distoftruckfromtown - fuelbank[i].first;
        }
        sort(fuelbank.begin(),fuelbank.end());
        int minstop = 0;
        int currfuel = initialfuelintruck;
        priority_queue<int,vector<int>> fuelcapacityinbank;
        for(int i=0;i<n;i++){
            if(currfuel>=distoftruckfromtown){
                break;
            }
            while(currfuel< fuelbank[i].first){
                if(fuelcapacityinbank.empty()){
                    flag = 1;
                    break;
                }
                minstop++;
                currfuel += fuelcapacityinbank.top();
                fuelcapacityinbank.pop();
            }
            if(flag){
                break;
            }
            fuelcapacityinbank.push(fuelbank[i].second);
        }
        if(flag){
            cout<<"You can't reach"<<"-1"<<"\n";
            continue;
        }
        while(!fuelcapacityinbank.empty()&& currfuel<distoftruckfromtown){ // to check for the last stop
            currfuel += fuelcapacityinbank.top();
            fuelcapacityinbank.pop();
            minstop++;
        }
        if(currfuel<distoftruckfromtown){
            cout<<"You can't reach"<<"-1"<<"\n";
        }
        cout<<minstop<<"\n";
    }
}