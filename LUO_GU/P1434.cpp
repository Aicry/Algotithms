#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dfs(int x, int y, vector<vector<int> >a, vector<vector<int> >& f, int n, int m)
{
    if (f[x][y]) return f[x][y];		//��֦1
    int maxx = 1;
    int m_x[4] = { 1,-1,0,0 },
        m_y[4] = { 0,0,1,-1 };
    for (int i = 0; i < 4; i++) {
        int x_2 = x + m_x[i],
            y_2 = y + m_y[i];
        if (x_2 >= 0 && x_2 < n && y_2 >= 0 && y_2 <m && a[x][y] > a[x_2][y_2])		//��֦2,3
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
            f[i][j] = dfs(i, j, a, f, n, m);	//ÿ���㶼��
            ans = max(f[i][j], ans);	//�������ֵ
        }
    cout << ans;
    return 0;
}
/*��Ŀ����
Michael ϲ����ѩ���Ⲣ����֣���Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael ��֪����һ����������Ļ��¡�������һ����ά��������������ÿ�����ִ�����ĸ߶ȡ�������һ�����ӣ�

1   2   3   4   5
16  17  18  19  6
15  24  25  20  7
14  23  22  21  8
13  12  11  10  9
һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶Ȼ��С��������������У�һ�����еĻ���Ϊ 2424��1717��1616��11���� 2424 ��ʼ���� 11 ����������Ȼ 2525��2424��2323��\ldots����33��22��11 ��������ʵ�ϣ��������һ����

�����ʽ
����ĵ�һ��Ϊ��ʾ����Ķ�ά��������� RR ������ CC�������� RR �У�ÿ���� CC �����������߶�(��������֮���� 11 ���ո���)��

�����ʽ
�������������µĳ��ȡ�

�����������
���� #1����
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
��� #1����
25
˵��/��ʾ
���� 100\%100% �����ݣ�1\leq R,C\leq 1001��R,C��100��*/