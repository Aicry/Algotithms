#include <iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); ++i) {
        if (islower(a[i]))
            a[i] = toupper(a[i]);
    }
    cout << a;
    return 0;

}
/*题目描述
大家都知道一些办公软件有自动将字母转换为大写的功能。输入一个长度不超过 100 且不包括空格的字符串。要求将该字符串中的所有小写字母变成大写字母并输出。

输入格式
无

输出格式
无

输入输出样例
输入 #1复制
Luogu4!
输出 #1复制
LUOGU4!*/