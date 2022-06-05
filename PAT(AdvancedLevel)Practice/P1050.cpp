#include<iostream>
#include<map>
#include<vector>
#include<string.h>
using namespace std;
map<char, int> m;
int main(){
    string s1;
    getline(cin, s1);
    string s2;
    getline(cin, s2);
    int n = s2.size();
    for (int i = 0; i < n;++i){
        m[s2[i]] = 1;
    }
    n = s1.size();
    vector<char> res;
    for (int i = 0; i < n;++i){
        if(m.find(s1[i])==m.end())
            res.push_back(s1[i]);
    }
    for (int i = 0; i < res.size();++i){
        cout << res[i];
    }
}