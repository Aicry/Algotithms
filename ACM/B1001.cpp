
#include<iostream>
using namespace std;
int main(){
    int a[10] = {0};
    for (int i = 1; i <= 2020;++i){
        int t = i;
        while (t)
        {
            a[t % 10]++;
            t = t / 10;
           }
    }
    cout << a[2];
}
//624