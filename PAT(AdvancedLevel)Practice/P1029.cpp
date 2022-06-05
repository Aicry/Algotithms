#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    vector<long> a,b,c;
    int m, n;
    cin >> m;
    long t;
    for (int i = 0; i < m;++i){
        cin >> t;
        a.push_back(t);
    }
    cin >> n;
    for (int i = 0; i < n;++i){
        cin >> t;
        b.push_back(t);
    }
    int i = 0, j = 0;
    int s1 = a.size(), s2 = b.size();
    while(i<s1&&j<s2){
        if(a[i]>b[j])
            c.push_back(b[j]), j++;
        else
            c.push_back(a[i]), i++;  
    }
    while(i<s1) c.push_back(a[i]), i++; 
    while(j<s2) c.push_back(b[j]), j++;
    if((m+n)%2)
        cout << c[(m + n) / 2];
    else
        cout << c[(m + n) / 2-1];
}