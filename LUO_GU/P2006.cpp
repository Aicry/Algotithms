#include<iostream>
#include <vector>
#include<cmath>
using namespace std;

int main() {
    int k, m, n;
    cin >> k >> m >> n;
    vector<int> a(m), b(m);
    int mark = 0;
    for (int i = 0; i < m;++i){
        cin >> a[i] >> b[i];
        if((!a[i]&&b[i])||(a[i]&&((k/a[i])*b[i])>=n))
              {cout << i+1 << ' ';
                mark = 1;}
           
    }
      if(!mark)
          cout << -1;
      return 0;
}