#include<iostream>

using namespace std;

int a[50][50];

int main(){
    int count = 1;
    int level = 1;
   while (level < 50)
	{
		for (int i = 1, j = level; i <= level; ++i,--j)
		{
			level & 1 ? a[j][i] = count++ : a[i][j] = count++;
		}
		++level;
	}
    cout << a[20][20];
}