#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string a;
    string b;
    cin >> a >> b;
    int m = a.length();
    int n = b.length();
    int count = 0;
    for (int i = 0; i < n;++i){
        int pos = a.find(b[i]);
        if(pos>=0&&pos<m)
            a[pos] = '*';
        else count++;
    }
    if(count)
        cout << "No " << count;
    else
    {
        cout << "Yes " << m - n;
    }
    
}

