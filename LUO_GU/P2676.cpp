#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> cows;
int n, total;
int main(){
    cin >> n >> total;
    int t;

    for (int i = 0; i < n;++i)
      {
          cin >> t;
          cows.push_back(t);
      }

    sort(cows.rbegin(), cows.rend());
    int sum = 0;
    for (int i = 0; i < n;++i){
        sum += cows[i];
        if(sum>=total)
           {cout << i + 1;
             break;
           }
    }

}