#include <iostream>
#include <vector>
using namespace std;

int x[] = {0, 1, -1, 0};
int y[] = {1, 0, 0, -1};
char board[1000][1000];
int count = 0;

void dfs(int a, int b, int m, int n)
{
    if (board[a][b] == '#' || a < 0 || b < 0 || a >= m || b >= n)
        return;
    if (board[a][b] == '.')
    {
        count++;
        board[a][b] == '#';
         
    }
    for (int i = 0; i < 4; i++)
    {
        
            dfs(a + x[i], b + y[i], m, n);
    }
    return;
}
int main()
{
    int m, n;
    cin >> m >> n;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '@')
            {
                a = i;
                b = j;
            }
        }
    }
    dfs(a, b, m, n);
    cout << count;
}