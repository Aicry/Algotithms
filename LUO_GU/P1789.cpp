#include<iostream>
#include <vector>
#include<cmath>
using namespace std;

int main() {

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > board(n, vector<int>(n, 0));
    while (m--) {
        int x, y;
        cin >> x >> y;
        for (int i = x - 2; i <= x + 2; ++i) {
            for (int j = y - 2; j <= y + 2; ++j) {
                if ((fabs(i - x) + fabs(j - y)) < 3 && i >= 0 &&i<n&&j<n&& j >= 0)
                    board[i][j] = 1;
            }
        }

    }
    while (k--) {
        int x, y;
        cin >> x >> y;
        for (int i = x - 2; i <= x + 2; ++i) {
            for (int j = y - 2; j <= y + 2; ++j) {
                if (i >= 0 && j >= 0 &&i<n&&j<n)
                    board[i][j] = 1;
            }
        }

    }
    int count = 0;
    for (auto i : board)
        for (auto j : i)if (j == 0)count++;
    cout << count;
}

