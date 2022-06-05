#include<iostream>
#include <vector>
#include<cmath>
using namespace std;
int n=0, m=0, x=0, y=0;
int a[100], b[100], c[100], d[100];
int point[100][100];
int last[100][100];
int main() {
    cin >> n >> m >> x >> y;
    
    
    for(int i=0;i<x;++i){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        for (int x = a[i]; x <= c[i];++x)
         for (int y = b[i]; y <= d[i];++y)
        {
            point[x][y]++;
            last[x][y] = i + 1;
            }
    }
   for(int i=0;i<y;++i) {
        int x = 0, y = 0;
        cin >> x >> y;
        if (point[x][y])
            cout << "Y" << ends << point[x][y] << ends << last[x][y] << endl;
        else cout << "N" << endl;

    }
    
}