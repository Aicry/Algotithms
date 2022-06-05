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

int map[20][20];
int temp;

int dfsw(int i, int j, int M, int N)
{
    if (i < M && i >= 0 && j < N && j >= 0 && map[i][j] == 1)
    {
        temp += 1;
        map[i][j] = 0;
        dfsw(i - 1, j, M, N);
        dfsw(i + 1, j, M, N);
        dfsw(i, j - 1, M, N);
        dfsw(i, j + 1, M, N);
        return 1;
    }
    return 0;
}

int dfsb(int i, int j, int M, int N)
{
    if (i < M && i >= 0 && j < N && j >= 0 && map[i][j] == 2)
    {
        temp += 1;
        map[i][j] = 0;
        dfsb(i - 1, j, M, N);
        dfsb(i + 1, j, M, N);
        dfsb(i, j - 1, M, N);
        dfsb(i, j + 1, M, N);
        return 1;
    }
    return 0;
}

int main()
{
    int M = 19, N = 19;

    int islandw = 0;
    int islandb = 0;
    temp = 0;

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
            if (dfsw(i, j, M, N))
            {
                islandw = max(temp, islandw);
            }
            else
            {
                islandw = max(temp, islandw);
                temp = 0;
            }
        }
    }
    temp = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dfsb(i, j, M, N))
            {
                islandb = max(temp, islandb);
            }
            else
            {
                islandw = max(temp, islandw);
                temp = 0;
            }
        }
    }
    cout << islandw << endl;
    cout << islandb << endl;
    if (islandw > islandb)
        cout << "white" << endl;
    else if (islandw < islandb)
        cout << "black" << endl;
    else
        cout << "equal" << endl;

    return 0;
}