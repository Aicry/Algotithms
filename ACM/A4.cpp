#include<iostream>
#include<vector>

using namespace std;
int m[10001];
int main(){
    int n;
    cin >> n;
    int a, b, sum = 0;
    for (int i = 0; i < n;++i){
        cin >> a;
        if(a==1)
        {
            cin >> b;
            for (int i = 1; i * b < 10001;++i){
                m[i * b]++;
            }
        }
        if(a==2){
             cin >> b;
             sum += m[b];
            }
        }
    }
   =
}