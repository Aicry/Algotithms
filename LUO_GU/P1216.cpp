#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int Input(int n) {
	if (n == 1) {
		int res;
		cin >> res;
		return res;
	}
	vector<vector<int> > towel(n, vector<int>(n));
	int k = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> towel[i][j];
		}
		++k;
	}
	k = 1;
	vector<vector<int> > res(n, vector<int>(n));
	res[0][0] = towel[0][0];
	for (int i = 1; i < n; ++i) {
		res[i][0] = res[i - 1][0] + towel[i][0];
		res[i][i] = res[i - 1][i - 1] + towel[i][i];
		for (int j = 1; j < k; ++j) {
			res[i][j] = max(res[i - 1][j], res[i - 1][j - 1]) + towel[i][j];
		}
		++k;
	}
	int result = 0;
	for (int i = 0; i < n; ++i) {
		if (result < res[n - 1][i])result = res[n - 1][i];

	}
	return result;
}
int main()
{
	int n;
	cin >> n;
	cout << Input(n);
}
/*题目描述
观察下面的数字金字塔。

写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以走到左下方的点也可以到达右下方的点。

        7 
      3   8 
    8   1   0 
  2   7   4   4 
4   5   2   6   5 
在上面的样例中,从 7 \to 3 \to 8 \to 7 \to 57→3→8→7→5 的路径产生了最大

输入格式
第一个行一个正整数 rr ,表示行的数目。

后面每行为这个数字金字塔特定行包含的整数。

输出格式
单独的一行,包含那个可能得到的最大的和。

输入输出样例
输入 #1复制
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 
输出 #1复制
30
说明/提示
【数据范围】
对于 100\%100% 的数据，1\le r \le 10001≤r≤1000，所有输入在 [0,100][0,100] 范围内。

题目翻译来自NOCOW。

USACO Training Section 1.5

IOI1994 Day1T1*/