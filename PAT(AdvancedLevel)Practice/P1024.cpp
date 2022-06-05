#include <iostream>
#include <algorithm>
using namespace std;
string add(string a){
    string ans=a;
    reverse(a.begin(),a.end());
    int i=a.length()-1,carry=0;
    while(i>=0){
        int tmp=a[i]-'0'+ans[i]-'0';
        ans[i]=(carry+tmp)%10+'0';
        carry=(tmp+carry)/10;
        i--;
    }
    if(carry) ans.insert(0,"1");
    return ans;
}
int main(){
    string s;
    int k;
    cin>>s>>k;
    string tmp=s;
    reverse(tmp.begin(),tmp.end());
    if(tmp==s) cout<<tmp<<endl<<0;
    else{
        int i=0;
        while(i<k){
            s=add(tmp);
            i++;
            tmp=s;
            reverse(tmp.begin(),tmp.end());
            if(tmp==s) break;
        }
        cout<<s<<endl<<i;
    } 
    return 0;
}


/*#include<iostream>
using namespace std;

bool Palindromic(long long n){
    long long t = n;
    long long sum = 0;
    while(n){
        sum = sum*10+n % 10;
        n /= 10;
    }
    if(t==sum)
        return true;
    return false;
}
long long reversed(long long n){
    long long sum = 0;
    while(n){
        sum = sum*10+n % 10;
        n /= 10;
    }
    return sum;
}
int main(){
    long long n, k;
    cin >> n >> k;
    long long cnt = 0;
    while(cnt<k){
        if(Palindromic(n))
            break;
        else  n += reversed(n);
        cnt++;
    }
    if(cnt<k){
        cout << n << endl
             << cnt;
    }
    else
        cout << n << endl
             << k;
}/*