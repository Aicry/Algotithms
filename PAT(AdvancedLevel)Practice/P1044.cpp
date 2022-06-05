#include<iostream>
#include<vector>
using namespace std;
/*16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13*/

int n, sum;
vector<int> s,resArr;
void binarysearch(int i,int& j,int& tempsum){
    int l = i, h = n;
    while(l<h){
        int mid = (l + h) / 2;
        if((s[mid]-s[i-1])>=sum)
            h = mid;
        else
            l = mid + 1;
    }
    j = h;
    tempsum = s[j] - s[i - 1];
}
   
    
int main(){
    cin >> n >> sum;
    s.resize(n + 1);
    for (int i = 1; i <= n;++i){
        cin >> s[i];
        s[i] += s[i - 1];
    }
    int minans = s[n];
    for (int i = 1; i <= n;++i){
        int j, tempsum;
        binarysearch(i, j, tempsum);
        if(tempsum > minans) continue;
        if(tempsum >= sum) {
            if(tempsum < minans) {
                resArr.clear();
                minans = tempsum;
            }
            resArr.push_back(i);
            resArr.push_back(j);
        }
    }
    for(int i = 0; i < resArr.size(); i += 2)
        printf("%d-%d\n", resArr[i], resArr[i+1]);
    return 0;

    
}