#include<iostream>
using namespace std;
void rgb(int r){
     if(r<10)
        cout << 0 << r;
     else if(r<13)
         cout << 0 << char('A' + r - 10);
     else{
        int k = r % 13;
        int t = r / 13;
        if(t<10)
            cout << t;
        else if(t<13)
            cout << char('A' + t - 10);
        if(k<10)
            cout << k;
        else if(k<13)
         cout << char('A' + k - 10);
    }
   

}
int main(){
    int r, g, b;
    cin >> r >> g >> b;
    cout << "#";
    rgb(r);
    rgb(g);
    rgb(b);
}