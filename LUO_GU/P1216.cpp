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
/*��Ŀ����
�۲���������ֽ�������

дһ�����������Ҵ���ߵ㵽�ײ����⴦������·����ʹ·���������ֵĺ����ÿһ�������ߵ����·��ĵ�Ҳ���Ե������·��ĵ㡣

        7 
      3   8 
    8   1   0 
  2   7   4   4 
4   5   2   6   5 
�������������,�� 7 \to 3 \to 8 \to 7 \to 57��3��8��7��5 ��·�����������

�����ʽ
��һ����һ�������� rr ,��ʾ�е���Ŀ��

����ÿ��Ϊ������ֽ������ض��а�����������

�����ʽ
������һ��,�����Ǹ����ܵõ������ĺ͡�

�����������
���� #1����
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 
��� #1����
30
˵��/��ʾ
�����ݷ�Χ��
���� 100\%100% �����ݣ�1\le r \le 10001��r��1000������������ [0,100][0,100] ��Χ�ڡ�

��Ŀ��������NOCOW��

USACO Training Section 1.5

IOI1994 Day1T1*/