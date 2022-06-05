#include <iostream>
#include<string>
#include<vector>
using namespace std;
bool isPrimeNum(int n) {
	for (int i = 2; i < n; ++i) {
		if (n % i == 0)return false;
	}
	return true;
}
void Luck_Word(string a) {
	int max = 0;
	int min = 100;
	vector<int> res(26, 0);
	for (int i = 0; i < a.size(); ++i) {
		int n = a[i] - 'a';
		res[n]++;
	}
	for (int i = 0; i < 26; ++i) {
		if (max < res[i])max = res[i];
		if (min > res[i] && res[i] > 0)min = res[i];
	}


	if ((max - min) > 1 && isPrimeNum(max - min)) {
		cout << "Lucky Word" << endl;
		cout << max - min;

	}
	else
	{
		cout << "No Answer" << endl;
		cout << 0;
	}
}
int main()
{
	string a;
	cin >> a;
	Luck_Word(a);
	return 0;
}
/*题目描述
笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！

这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，如果maxn-minn是一个质数，那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。

输入格式
一个单词，其中只可能出现小写字母，并且长度小于100100。

输出格式
共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出“No Answer”；

第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出00。

输入输出样例
输入 #1复制
error
输出 #1复制
Lucky Word
2
输入 #2复制
olympic
输出 #2复制
No Answer
0
说明/提示
【输入输出样例1解释】

单词error中出现最多的字母rr出现了33次，出现次数最少的字母出现了11次，3-1=23−1=2，22是质数。

【输入输出样例2解释】

单词olympic中出现最多的字母ii出现了11次，出现次数最少的字母出现了11次，1-1=01−1=0，00不是质数。

（本处原题面错误已经修正）

noip2008提高第一题*/