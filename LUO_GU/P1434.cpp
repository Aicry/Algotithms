#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dfs(int x, int y, vector<vector<int> >a, vector<vector<int> >& f, int n, int m)
{
    if (f[x][y]) return f[x][y];		//剪枝1
    int maxx = 1;
    int m_x[4] = { 1,-1,0,0 },
        m_y[4] = { 0,0,1,-1 };
    for (int i = 0; i < 4; i++) {
        int x_2 = x + m_x[i],
            y_2 = y + m_y[i];
        if (x_2 >= 0 && x_2 < n && y_2 >= 0 && y_2 <m && a[x][y] > a[x_2][y_2])		//剪枝2,3
            maxx = max(dfs(x_2, y_2, a, f, n, m) + 1, maxx);
    }
    f[x][y] = maxx;
    return maxx;
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int> >a(n, vector<int>(m));
    vector<vector<int> >f(n, vector<int>(m));
    int ans = 0;
    for (int i = 0; i < n; i++)


        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            f[i][j] = dfs(i, j, a, f, n, m);	//每个点都搜
            ans = max(f[i][j], ans);	//更新最大值
        }
    cout << ans;
    return 0;
}
/*题目描述
Michael 喜欢滑雪。这并不奇怪，因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael 想知道在一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子：

1   2   3   4   5
16  17  18  19  6
15  24  25  20  7
14  23  22  21  8
13  12  11  10  9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度会减小。在上面的例子中，一条可行的滑坡为 2424－1717－1616－11（从 2424 开始，在 11 结束）。当然 2525－2424－2323－\ldots…－33－22－11 更长。事实上，这是最长的一条。

输入格式
输入的第一行为表示区域的二维数组的行数 RR 和列数 CC。下面是 RR 行，每行有 CC 个数，代表高度(两个数字之间用 11 个空格间隔)。

输出格式
输出区域中最长滑坡的长度。

输入输出样例
输入 #1复制
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
输出 #1复制
25
说明/提示
对于 100\%100% 的数据，1\leq R,C\leq 1001≤R,C≤100。*/