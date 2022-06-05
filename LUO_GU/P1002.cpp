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

/*��Ŀ����
������ AA ����һ�������䣬��Ҫ�ߵ�Ŀ�� BB �㡣�����ߵĹ��򣺿������¡��������ҡ�ͬʱ�������� CC ����һ���Է������������ڵĵ��������Ծһ���ɴ�ĵ��Ϊ�Է���Ŀ��Ƶ㡣��˳�֮Ϊ�����������䡱��

�����������ʾ��AA �� (0, 0)(0,0)��BB �� (n, m)(n,m)��ͬ�����λ����������Ҫ�����ġ�



����Ҫ����������� AA ���ܹ����� BB ���·�����������������λ���ǹ̶������ģ�����������һ������һ����

�����ʽ
һ���ĸ����������ֱ��ʾ BB �������������ꡣ

�����ʽ
һ����������ʾ���е�·��������

�����������
���� #1����
6 6 3 3
��� #1����
6
˵��/��ʾ
���� 100 \%100% �����ݣ�1 \le n, m \le 201��n,m��20��0 \le0�� ������� \le 20��20��*/