#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    getchar();
    vector<string> s(n);
    int size = 256;
    for (int i = 0; i < n;++i){
        getline(cin, s[i]);
        reverse(s[i].begin(), s[i].end());
        if(size<s[i].size())
            size = s[i].size();
    }
    string res;
    for (int i = 0; i < size;++i){
        char t = s[0][i];
        int j = 1;
        for ( j = 1; j < n;++j){
            if(s[j][i]==t)
                continue;
            else
                break;
        }
        if(j==n)
            res.push_back(t);
    }
    reverse(res.begin(), res.end());
    cout << res;
}