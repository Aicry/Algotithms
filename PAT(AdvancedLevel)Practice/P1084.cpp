#include<iostream>
#include<ctype.h>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    set<char> a;
    set<char> b;
    string s;
    cin >> s;
    for (int i = 0; i < s.size();++i){
        if(isalpha(s[i]))
            s[i] = toupper(s[i]);
        a.insert(s[i]);
    }
    string k;
    cin >> k;
    for (int i = 0; i < k.size();++i){
        if(isalpha(k[i]))
            k[i] = toupper(k[i]);
        b.insert(k[i]);
    }
    set<char> c;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
    for (int i = 0; i < s.size();++i){
        if(c.find(s[i])!=c.end())
            cout << *c.find(s[i]), c.erase(*c.find(s[i]));
    }
}