#include<iostream>

using namespace std;

int r[100];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n;++i ){
        cin >> r[i];
    }
    int m = 0;
    int loc = 0;
    int sum = 0;
    while(m<n){
      if(r[m]>loc){
          sum += (r[m] - loc) * 6;
          loc = r[m];
           sum += 5;
      }
      if(r[m]<loc){
          sum += (loc-r[m]) * 4;
          loc = r[m];
          sum += 5;
      }

      if(r[m]==loc)
     

      m++;
    }

    cout << sum;

}

  