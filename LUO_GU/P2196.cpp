#include<iostream>
#include <vector>
using namespace std;
int num[20];
int link[20][20];
vector<vector<int> > path;
vector<int> road;

void DFS(int a, int n) {
	if (n == 1)road.push_back(a);
	if (a == n-1)
	{
		path.push_back(road);
		return;
	}
	
	for (int i = a; i < n; ++i) {
		if(road.size()==0)road.push_back(i);
		int mark = 0;
		for (int j = i+1 ; j < n; ++j) {
			if (link[i][j] == 0) continue;
			road.push_back(j);
			DFS(j, n);
			road.pop_back();
			mark = 1;
		}
		if (!mark && road.size() == 1) { path.push_back(road); }
		if (!mark && road.size() != 1) { path.push_back(road); return; }
	    if (road.size() == 1)road.pop_back();
		else return;
	}

}
int main() {
	int n;
	cin >> n;
	if (n == 0)return 0;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	for (int i = 0; i < n-1; ++i) {
		for (int j = i+1; j < n; ++j) {
			cin >> link[i][j];
		}
	}
	
	DFS(0, n);
for (auto i : path) {
		for (auto j : i) {
			cout << j<<ends;
		}
		cout << endl;
	}
	
	int res = 0;
	int maxPath[50];
	int k = 0;
	for (int i = 0; i < path.size(); ++i) {
		int sum = 0;
		for (int j = 0; j < path[i].size(); ++j) {
			sum += num[path[i][j]];
		}
		if (sum > res) {
			res = sum;
			k = i;
		}
	}
	for (int j = 0; j < path[k].size()-1; ++j) {
		cout << path[k][j]+1 << ends;
	}
	cout << path[k][path[k].size() - 1]+1;
	cout << endl << res;
	return 0;
}

/*题目描述
在一个地图上有NN个地窖(N \le 20)(N≤20)，每个地窖中埋有一定数量的地雷。同时，给出地窖之间的连接路径。当地窖及其连接的数据给出之后，某人可以从任一处开始挖地雷，然后可以沿着指出的连接往下挖（仅能选择一条路径），当无连接时挖地雷工作结束。设计一个挖地雷的方案，使某人能挖到最多的地雷。

输入格式
有若干行。

第11行只有一个数字，表示地窖的个数NN。

第22行有NN个数，分别表示每个地窖中的地雷个数。

第33行至第N+1N+1行表示地窖之间的连接情况：

第33行有n-1n−1个数（00或11），表示第一个地窖至第22个、第33个、…、第nn个地窖有否路径连接。如第33行为1 1 0 0 0 … 011000…0，则表示第11个地窖至第22个地窖有路径，至第33个地窖有路径，至第44个地窖、第55个、…、第nn个地窖没有路径。

第44行有n-2n−2个数，表示第二个地窖至第33个、第44个、…、第nn个地窖有否路径连接。

… …

第n+1n+1行有11个数，表示第n-1n−1个地窖至第nn个地窖有否路径连接。（为00表示没有路径，为11表示有路径）。

输出格式
有两行

第一行表示挖得最多地雷时的挖地雷的顺序，各地窖序号间以一个空格分隔，不得有多余的空格。

第二行只有一个数，表示能挖到的最多地雷数。

输入输出样例
输入 #1复制
5
10 8 4 7 6
1 1 1 0
0 0 0
1 1
1
输出 #1复制
1 3 4 5
27*/