#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int f(int n){
    int count = 0;
    if(n==0)
        return 1;
    while (n)
    {
        n = n / 10;
        count++;
    }
    return count;
}
int main(){

    int n;
    cin >> n;
    for (int i = 0; i < n;++i){
        int a, b, c;
        cin >> a >> b >> c;
        int k1 = f(a);
        int k2 = f(b);
        int k3 = f(c);
        a = a + a * pow(10, k1);
        b = b + b * pow(10, k2) + b * pow(10, 2 * k2);
        c = c + c * pow(10, k3) + c * pow(10, k3 * 2);
        cout << a + b + c << endl;
        }
        return 0;
}