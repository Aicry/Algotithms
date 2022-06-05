#include<iostream>
#include<vector>
using namespace std;
struct user
{
    string id;
    string password;
};
int main(){
    int n;
    cin >> n;
    int count = 0;
    vector<user> res;
    for (int i = 0; i < n;++i){
        string a, b;
        int flag = 0;
        cin >> a >> b;
        for (int j = 0; j < b.length();++j){
               if(b[j]=='1')
                   b[j] = '@',flag=1;
                if(b[j]=='0')
                   b[j] = '%',flag=1;
                if(b[j]=='l')
                   b[j] = 'L',flag=1;
                 if(b[j]=='O')
                   b[j] = 'o',flag=1;
                
        }
       if(flag==1){
        count++;
        user t;
        t.id = a;
        t.password = b;
        res.push_back(t);
        flag = 0;
         }
    }
    if(count){
        cout << count << endl;
        for (int i = 0; i < count;++i){
            cout << res[i].id << " " << res[i].password << endl;
        }
    }
    else
    {
        if(n<=1) cout << "There is " << n << " account and no account is modified";
         else  cout << "There are " << n << " accounts and no account is modified";//is are
    }
    
}
