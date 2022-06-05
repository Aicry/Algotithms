#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
//vector<string> wordDict{"leet", "code"};
vector<string> wordDict{"apple", "pen"};
//vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> m(wordDict.begin(), wordDict.end());
    int n = wordDict.size();
    int max_size=0;
    for (int i = 0; i < n;++i){
         if(wordDict[i].size()>max_size)
             max_size = wordDict[i].size();
    }
   


    int k = s.size();

    vector<bool> dp(k+1, false);

    dp[0] = true; 

    for (int i = 0; i <= k;++i)
    {
        for (int j = max(i - max_size,0); j < i;++j)
        {
            if(dp[j]&&m.find(s.substr(j,i-j))!=m.end()){
                 dp[i] = true;
                break;
            }
        }
    }
      return dp[k];
    }
int main(){
    string s = "applepenapple";
    cout<<wordBreak(s, wordDict);
    
    }

/*
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/