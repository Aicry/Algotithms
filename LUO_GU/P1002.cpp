#include<iostream>
using namespace std;
const int fx[] = { 0, -2, -1, 1, 2, 2, 1, -1, -2 };
const int fy[] = { 0, 1, 2, 2, 1, -1, -2, -2, -1 };
int bx, by, mx, my;
long int f[30][30];
bool s[30][30];
int main() {
	cin >> bx >> by >> mx >> my;
	bx += 2; by += 2; mx += 2; my += 2;
	f[2][1] = 1;
	s[mx][my] = 1;
	for (int i = 1; i <= 8; i++)
		s[mx + fx[i]][my + fy[i]] = 1;
	for (int i = 2; i <= bx; ++i) {
		for (int j = 2; j <= by; ++j) {
			if (s[i][j])continue;
			f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	cout << f[bx][by];
	return 0;
}
/*#include<iostream>
#include <vector>
using namespace std;
int m, n, x, y;
bool is_safe(int a, int b) {
	if (((a - x) * (a - x) + (b - y) * (b - y)) != 5&&!(a==x&&b==y))
		return true;
	return false;
}
int path_num(int a, int b) {
	if (a == 0 && b == 0)return 1;
	if (a >0 && b == 0) {
		if (is_safe(a - 1, 0))return path_num(a - 1, 0);
		if (!is_safe(a - 1, 0))return 0;
	}
	if (a == 0 && b > 0) {
		if (is_safe(0, b-1))return path_num(0, b-1);
		if (!is_safe(0, b-1))return 0;
	}
	if (a > 0 && b > 0) {
		if (is_safe(a - 1, b) && is_safe(a, b - 1)) { return path_num(a - 1, b) + path_num(a, b - 1); }
		if (is_safe(a - 1, b) && !is_safe(a, b - 1)) { return path_num(a - 1, b); }
		if (!is_safe(a - 1, b) && is_safe(a, b - 1)) { return path_num(a, b - 1); }
		if (!is_safe(a - 1, b) && !is_safe(a, b - 1)) { return 0; }
	}

}
int main() {

	cin >> m >> n >> x >> y;
	cout << path_num(m, n);
	return 0;
}*/

/*题目描述
棋盘上 AA 点有一个过河卒，需要走到目标 BB 点。卒行走的规则：可以向下、或者向右。同时在棋盘上 CC 点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。

棋盘用坐标表示，AA 点 (0, 0)(0,0)、BB 点 (n, m)(n,m)，同样马的位置坐标是需要给出的。



现在要求你计算出卒从 AA 点能够到达 BB 点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。

输入格式
一行四个正整数，分别表示 BB 点坐标和马的坐标。

输出格式
一个整数，表示所有的路径条数。

输入输出样例
输入 #1复制
6 6 3 3
输出 #1复制
6
说明/提示
对于 100 \%100% 的数据，1 \le n, m \le 201≤n,m≤20，0 \le0≤ 马的坐标 \le 20≤20。*/