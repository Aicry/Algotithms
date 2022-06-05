#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "asda.++";
    int c = 0;
    for (int i = 0; i < s.length();i++)
        if ('a' <= s[i] <= 'z' || 'A' <= s[i] <= 'Z')
            c++;
    cout << c;
}