#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string a;
    cin >> a;
    int n = a.length();
    int h = (n + 2) / 3;
    int w = n - 2 * h;
    vector<vector<char>> map(h, vector<char>(w + 2, ' ')); //必须初始化为' ';
    int k = 0;
    for (int i = 0; i < h;++i){
        map[i][0] = a[k++];
    }
    for (int i = 1; i <= w;++i){
        map[h - 1][i] = a[k++];
    }
    for (int i = h - 1; i >= 0;--i){
        map[i][w+1] = a[k++];
    }
    for (int i = 0; i < h;++i){
        for (int j = 0; j <= w+1;++j)
            cout << map[i][j];

        cout << endl;
        }
    }
