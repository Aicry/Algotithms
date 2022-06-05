#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

void fun(int n){
    vector<int> a(4, 0);
    int b = n;
    int i = 0;
    while (b)
    {
        a[i++] = b % 10;
        b = b / 10;
    }
    sort(a.begin(), a.end());
    int c = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
    int d = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
    if(c>d)
        {
            cout << setw(4) << setfill('0') << c << " - " << setw(4) << setfill('0')<< d << " = " << setw(4) << setfill('0')<< c - d << endl;
            if(c-d==6174)
                return;
            else
                fun(c - d);
        }
    else if(d>c)
        {
            cout << setw(4) << setfill('0') << d << " - " << setw(4) << setfill('0') << c << " = " <<setw(4) << setfill('0')<<  d - c << endl;
            if(d-c==6174)
                return;
            else
                fun(d - c);
        }
        else
        {
            cout << setw(4) << setfill('0') << d << " - " << c << " = " << setw(4) << setfill('0') << setw(4) << setfill('0')<< d - c << endl;
            return;
        }
        
}
int main(){
    int n;
    cin >> n;
    fun(n);
}