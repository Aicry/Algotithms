#include<iostream>
using namespace std;

int main(){
    string a;
    string b;
    cin >> a >> b;
    int m = a.length();
    int n = b.length();
    int count = 0;
    for (int i = 0; i < m;++i){
        string t;
        t = a.substr(i,  n);

        if(t==b){
            count++;
        }
        if(count==2)
            {
                cout << i + 1 << endl;
                break;
            }
    }
    return 0;
}