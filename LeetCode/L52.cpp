#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> columns, diagonals1, diagonals2;
        return backtrack(n, 0, columns, diagonals1, diagonals2);
    }

    int backtrack(int n, int row, unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2) {
        if (row == n) {
            return 1;
        } else {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (columns.find(i) != columns.end()) {
                    continue;
                }
                int diagonal1 = row - i;
                if (diagonals1.find(diagonal1) != diagonals1.end()) {
                    continue;
                }
                int diagonal2 = row + i;
                if (diagonals2.find(diagonal2) != diagonals2.end()) {
                    continue;
                }
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);
                count += backtrack(n, row + 1, columns, diagonals1, diagonals2);
                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
            return count;
        }
    }
};





    bool isvalid(int row, int col, vector<string>& board) {
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q')return false;
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (fabs(row - i) == fabs(col - j)) {
                if (board[i][j] == 'Q')return false;
            }
        }
    }
    return true;
}
void backtrack(vector<string>& board, int row, int& res) {
    if (row == board[0].size()) {
        res++;
        return;
    }
    for (int col = 0; col < board[0].size(); ++col) {
        if (!isvalid(row, col, board))
            continue;
        board[row][col] = 'Q';
        backtrack(board, row + 1, res);
        board[row][col] = '.';
    }
}
  int totalNQueens(int n) {
      int res=0;
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0, res);
    return res;
    }

int main(){
    cout << totalNQueens(4);
}