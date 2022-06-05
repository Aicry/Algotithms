#include <iostream>
#include <string>
using namespace std;
string get(string s)
{
    string res;
    for (int i = 0, j = 0; j < s.length();)
    {
        while (j < s.length() && s[j] == s[i])
            j++;
        res.push_back('0' + j - i);
        res.push_back(s[i]);
        i = j;
    }
    return res;
}
string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string res = "1";
    while (--n)
    {
        res = get(res);
    }
    return res;
}
int main(){
    countAndSay(5);
}