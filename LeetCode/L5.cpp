#include<iostream>
#include<string>
using namespace std;

 string longestPalindrome(string s) {
    int n = s.size();
    if(n<=1)
        return s;
    int dp[n][n];
    int maxLen = 0;
    int begin = 0;
    for (int j = 1; j < n;++j){
        for (int i = 0; i < j;++i){
            if(s[i]!=s[j])
                dp[i][j] = 0;
            else{
                if(j-i<3)
                    dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
            }

            if (dp[i][j] && j - i  > maxLen) {
                    maxLen = j - i ;
                    begin = i;
           }

       }
    }
    return s.substr(begin, maxLen+1);
}
int main(){
    string a = "cbb";
    cout<<longestPalindrome(a);
}
