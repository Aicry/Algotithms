#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int x[] = {-1, 0, 1, 0};
int y[] = {0, -1, 0, 1};

int dfs(int _x, int _y, int steps, int k, double count, float &sum, int M, int N)
{

    if (steps > k)
        return 0;

    if (_x < 0 || _x > N - 1 || _y < 0 || _y > M - 1)
    {
        sum += count;

        return 0;
    }

    for (int i = 0; i < 4; i++)
    {

        dfs(_x + x[i], _y + y[i], steps + 1, k, count / 4, sum, M, N);
    }
    return 0;
}
int main()
{
    int N, M, X, Y, K;
    double count = 1;
    float sum = 0;
    cin >> N >> M >> X >> Y >> K;
    dfs(X, Y, 0, K, count, sum, M, N);
    if (sum)
        printf("%.6f", sum);
}