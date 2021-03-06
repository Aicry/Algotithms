#include <iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    n = n % 26;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            a[i]++;
            if (a[i] > 'z')a[i] -= 26;
        }
    }
    cout << a;
    return 0;

}
/*题目背景
某蒟蒻迷上了“小书童”，有一天登陆时忘记密码了（他没绑定邮箱or手机），于是便把问题抛给了神犇你。

题目描述
蒟蒻虽然忘记密码，但他还记得密码是由一个字符串组成。密码是由原文字符串（由不超过 50 个小写字母组成）中每个字母向后移动 nn 位形成的。z 的下一个字母是 a，如此循环。他现在找到了移动前的原文字符串及 nn，请你求出密码。

输入格式
第一行：n。第二行：未移动前的一串字母

输出格式
一行，是此蒟蒻的密码

输入输出样例
输入 #1复制
1
qwe
输出 #1复制
rxf
说明/提示
字符串长度<=50*/