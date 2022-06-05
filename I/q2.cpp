#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

char map[1201][1201];

int dfs(int i, int j, int M, int N)
{
    if (i < M && i >= 0 && j < N && j >= 0 && map[i][j] == 'C')
    {
        map[i][j] = '*';
        dfs(i - 1, j, M, N);
        dfs(i + 1, j, M, N);
        dfs(i, j - 1, M, N);
        dfs(i, j + 1, M, N);
        dfs(i - 1, j - 1, M, N);
        dfs(i - 1, j + 1, M, N);
        dfs(i + 1, j - 1, M, N);
        dfs(i + 1, j + 1, M, N);
        return 1;
    }
    return 0;
}

int main()
{
    int M, N;
    cin >> M >> N;
    int fengcao = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dfs(i, j, M, N))
            {
                fengcao += 1;
                cout << i << " " << j << endl;
            }
        }
    }
    cout << fengcao << endl;
    return fengcao;
}