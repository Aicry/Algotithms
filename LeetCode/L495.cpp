#include<iostream>
#include<vector>
using namespace std;

 int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int res=0;
    
    int n=timeSeries.size();
    if(n==0)return 0;
    for (int i = 1; i < n; ++i){
        int t=timeSeries[i] - timeSeries[i - 1];
       res += t > duration ? duration :t;
                }
     res += duration;
     return res;
}


int main(){
    vector<int> time{1, 4, 5, 7,8,9,11,12};
    int dur = 3;
    cout << findPoisonedDuration(time, dur);
}