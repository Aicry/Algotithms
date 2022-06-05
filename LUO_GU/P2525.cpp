#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

/*bool myPrevPermutation(T *start, T *end) { //[start,end)
	T *cur = end - 1, *pre = cur - 1; //pre指向partitionNumber 
	while (cur > start && *pre <= *cur) 
		--cur, --pre; //从右到左进行扫描，发现第一个违背非递增趋势的数字
	if (cur <= start) return false; //整个排列逆序, 不存在更小的排列 
	//从右到左进行扫描，发现第一个比partitionNumber小的数
	for (cur = end - 1; *cur >= *pre; --cur); //cur指向changeNumber  
	swap(*pre, *cur);
	reverse(pre + 1, end); //将尾部的逆序变成正序 
	return true; 
}*/

int main() {
    vector<int> data;
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n;++i)
    cin >> temp, data.push_back(temp);
    if (!prev_permutation(data.begin(), data.end()))
    {
        cout << "ERROR";
        return 0;
         }
         for (int i = 0; i < n;++i)
            {
                cout << data[i] << ' ';
            }
             return 0;	
}