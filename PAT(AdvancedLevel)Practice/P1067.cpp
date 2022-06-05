#include<iostream>
#include<vector>
using namespace std;
 int n;
 vector<int> s;
 bool order(vector<int> s)
 {
     for (int i = 0; i < n - 1; ++i)
     {
          if(s[i]>s[i+1])
              return false;
     }
     return true;
 }
int main(){  
    cin >> n;
    int k = 0;
    s.resize(n);
    for (int i = 0; i < n; ++i)
      {
          cin >> s[i];
          if(s[i]==0)
              k = i;
      }
      int res = 0;
      while (!order(s))
      {
          if (s[0] == 0)
          {
              for (int i = 1; i < n; ++i)
              {
                  if (s[i] != i)
                  {
                      swap(s[0], s[i]);
                      res++;
                      cout << "swap" << s[i] << " " << s[0] << endl;
                      k = i;
                      break;
                  }
              }
          }

          for (int i = 0; i < n; ++i)
          {
              if (s[i] == k)
              {
                  s[i] = 0;
                  s[k] = k;
                  res++;
                 cout << "swap" << s[i] << " " << s[k] << endl;
                  k = i;
                  break;
              }
          }
  
    }
    cout << res;

}