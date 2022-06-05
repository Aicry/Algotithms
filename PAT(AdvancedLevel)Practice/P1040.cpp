#include<iostream>
#include<string>
using namespace std;


int longestPalindrome(string s)
{
    int n = s.size();
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
    return maxLen + 1;
}

int main(){

    string s;
    getline(cin, s);

    int a = longestPalindrome(s);
    cout << a;
}