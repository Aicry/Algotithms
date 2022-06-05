#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int m, n, k;

int main(){

    cin >> m >> n >> k;
    for (int i = 0; i < k;++i){
        vector<int> sqe;
        stack<int> s;
        int t;
        for (int j = 0; j < n;++j){
            cin >> t;
            sqe.push_back(t);
        }
        int flag = 0;
        int pos = 0;
        for (int i = 1; i <= n;++i){
             s.push(i);
             if(s.size()>m)                        
                   break;
            
            while(!s.empty()&&s.top()==sqe[pos])
            {
                s.pop();
                pos++;
            }        
            
        }
         if(pos==n)
             flag = 1;
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        

    }


}