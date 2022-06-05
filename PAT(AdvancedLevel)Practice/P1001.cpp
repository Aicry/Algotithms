/*#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string itos(int sum){
    stringstream s;
    s << sum ;
    return s.str();
}
int main(){
    int a, b, sum = 0;
    cin >> a >> b;
    sum = a + b;
    string s;
    s = itos(sum);
    for (int i = 0; i < s.length();++i){
        cout << s[i];
        if(s[i]=='-')
            continue;
            if((i+1)%3==s.length()%3&&i!=s.length()-1)
                cout << ',';
    }
    return 0;
}
*/
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main(){
int a,b;
    cin>>a>>b;
    long c=a+b;
   // cout << c<<endl;
    vector<int> res;
    if(c<0)
        {
            
            c = c*(-1);
            cout << '-';
        }
    if(c==0){
        cout<<0;
        return 0;
    }
    while(c){                       //c=1000的整数倍会出错
        res.push_back(c%1000);
        c = c / 1000;
    }
    cout << res[res.size()-1];
    for (int i = res.size() - 2; i >= 0;--i){
        if(res[i]>99)
            cout << ',' << res[i];
        if(res[i]<100&&res[i]>9)
            cout << ',' << 0 << res[i];
        if(res[i]<10)
            cout << ',' << 0 << 0 << res[i];
    }
}